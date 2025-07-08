import 'package:flutter/gestures.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: '手势检测Demo',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: const GestureTest(),
    );
  }
}

class GestureTest extends StatefulWidget {
  const GestureTest({super.key});

  @override
  // ignore: library_private_types_in_public_api
  _GestureTestState createState() => _GestureTestState();
}

class _GestureTestState extends State<GestureTest> {
  String _operation = "请操作我"; // 保存事件名
  Color _bgColor = Colors.blue; // 背景色
  double _scale = 1.0; // 缩放比例
  double _rotation = 0.0; // 旋转角度

  double _top = 0.0; //距顶部的偏移
  double _left = 0.0; //距左边的偏移
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('手势检测Demo')),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            // 基础手势检测
            GestureDetector(
              onTap: () => _updateState("点击", Colors.blue),
              onDoubleTap: () => _updateState("双击", Colors.green),
              onLongPress: () => _updateState("长按", Colors.orange),
              onTapDown: (details) => _updateState("按下", Colors.red),
              onTapUp: (details) => _updateState("抬起", Colors.purple),
              onTapCancel: () => _updateState("取消", Colors.grey),
              child: Container(
                width: 200,
                height: 100,
                alignment: Alignment.center,
                decoration: BoxDecoration(
                  color: _bgColor,
                  borderRadius: BorderRadius.circular(10),
                ),
                child: Text(
                  _operation,
                  style: const TextStyle(color: Colors.white, fontSize: 20),
                ),
              ),
            ),
            const SizedBox(height: 30),
            // 缩放和旋转手势
            Transform(
              transform: Matrix4.identity()
                ..scale(_scale)
                ..rotateZ(_rotation),
              alignment: Alignment.center,
              child: GestureDetector(
                onScaleUpdate: (details) {
                  setState(() {
                    _scale = details.scale.clamp(0.5, 2.0);
                    _rotation = details.rotation;
                  });
                },
                onScaleEnd: (details) {
                  setState(() {
                    _scale = 1.0;
                    _rotation = 0.0;
                  });
                },
                child: Container(
                  width: 200,
                  height: 100,
                  alignment: Alignment.center,
                  decoration: BoxDecoration(
                    color: Colors.deepPurple,
                    borderRadius: BorderRadius.circular(10),
                  ),
                  child: const Text(
                    '双指缩放/旋转我',
                    style: TextStyle(color: Colors.white, fontSize: 18),
                  ),
                ),
              ),
            ),
            const SizedBox(height: 20),
            // 拖动手势
            Draggable(
              feedback: Container(
                width: 100,
                height: 100,
                decoration: BoxDecoration(
                  color: Colors.amber.withOpacity(0.8),
                  borderRadius: BorderRadius.circular(10),
                ),
                child: const Center(child: Text("拖动中...")),
              ),
              childWhenDragging: Container(
                width: 100,
                height: 100,
                decoration: BoxDecoration(
                  color: Colors.grey.withOpacity(0.5),
                  borderRadius: BorderRadius.circular(10),
                ),
                child: const Center(child: Text("原始位置")),
              ),
              child: Container(
                width: 100,
                height: 100,
                decoration: BoxDecoration(
                  color: Colors.amber,
                  borderRadius: BorderRadius.circular(10),
                ),
                child: const Center(child: Text("拖动我")),
              ),
              onDragCompleted: () => _updateState("拖动完成", Colors.blue),
            ),
          ],
        ),
      ),
    );
  }

  void _updateState(String operation, Color color) {
    setState(() {
      _operation = operation;
      _bgColor = color;
    });
  }
}

//可拖动的A
class _Drag extends StatefulWidget {
  @override
  _DragState createState() => _DragState();
}

class _DragState extends State<_Drag> with SingleTickerProviderStateMixin {
  double _top = 0.0; //距顶部的偏移
  double _left = 0.0; //距左边的偏移

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: <Widget>[
        Positioned(
          top: _top,
          left: _left,
          child: GestureDetector(
            child: CircleAvatar(child: Text("A")),
            //手指按下时会触发此回调
            onPanDown: (DragDownDetails e) {
              //打印手指按下的位置(相对于屏幕)
              print("用户手指按下：${e.globalPosition}");
            },
            //手指滑动时会触发此回调
            onPanUpdate: (DragUpdateDetails e) {
              //用户手指滑动时，更新偏移，重新构建
              setState(() {
                _left += e.delta.dx; //处理水平拖动
                _top += e.delta.dy; //处理垂直拖动
              });
            },
            onPanEnd: (DragEndDetails e) {
              //打印滑动结束时在x、y轴上的速度
              print(e.velocity);
            },
          ),
        ),
      ],
    );
  }
}

//手势缩放图片
class _Scale extends StatefulWidget {
  const _Scale({Key? key}) : super(key: key);

  @override
  _ScaleState createState() => _ScaleState();
}

class _ScaleState extends State<_Scale> {
  double _width = 200.0; //通过修改图片宽度来达到缩放效果

  @override
  Widget build(BuildContext context) {
    return Center(
      child: GestureDetector(
        //指定宽度，高度自适应
        child: Image.asset("./images/sea.png", width: _width),
        onScaleUpdate: (ScaleUpdateDetails details) {
          setState(() {
            //缩放倍数在0.8到10倍之间
            _width = 200 * details.scale.clamp(.8, 10.0);
          });
        },
      ),
    );
  }
}

//点击时给文本变色
class _GestureRecognizer extends StatefulWidget {
  const _GestureRecognizer({Key? key}) : super(key: key);
  @override
  _GestureRecognizerState createState() => _GestureRecognizerState();
}

class _GestureRecognizerState extends State<_GestureRecognizer> {
  TapGestureRecognizer _tapGestureRecognizer = TapGestureRecognizer();
  bool _toggle = false; //变色开关

  @override
  void dispose() {
    //用到GestureRecognizer的话一定要调用其dispose方法释放资源
    _tapGestureRecognizer.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Text.rich(
        TextSpan(
          children: [
            TextSpan(text: "你好世界"),
            TextSpan(
              text: "点我变色",
              style: TextStyle(
                fontSize: 30.0,
                color: _toggle ? Colors.blue : Colors.red,
              ),
              recognizer: _tapGestureRecognizer
                ..onTap = () {
                  setState(() {
                    _toggle = !_toggle;
                  });
                },
            ),
            TextSpan(text: "你好世界"),
          ],
        ),
      ),
    );
  }
}
