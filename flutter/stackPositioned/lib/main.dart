import 'package:flutter/material.dart';

void main() {
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const HomePage(title: 'LAYOUT'),
    );
  }
}

class HomePage extends StatefulWidget {
  const HomePage({super.key, required this.title});

  final String title;

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  //定义一个redBox，它是一个背景颜色为红色的盒子，不指定它的宽度和高度
  Widget redBox = DecoratedBox(decoration: BoxDecoration(color: Colors.red));

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,

        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            //层叠布局：子组件可以根据距父容器四个角的位置来确定自身的位置
            //允许子组件按照代码中声明的顺序堆叠起来。Flutter中使用Stack和Positioned这两个组件来配合实现绝对定位
            Expanded(
              child: Stack(
                alignment: Alignment.center,
                children: [
                  Container(
                    color: Colors.red,
                    child: const Text(
                      "Stack1",
                      style: TextStyle(color: Colors.white),
                    ),
                  ),
                  const Positioned(left: 18.0, child: Text("Stack2")),
                  const Positioned(top: 18.0, child: Text("Stack3")),
                ],
              ),
            ),
            Expanded(
              child: Stack(
                alignment: Alignment.center,
                children: [
                  Container(
                    color: Colors.blue,
                    child: const Text(
                      "Stack4",
                      style: TextStyle(color: Colors.white),
                    ),
                  ),
                  const Positioned(left: 18.0, child: Text("Stack5")),
                  const Positioned(top: 18.0, child: Text("Stack6")),
                ],
              ),
            ),
            Container(
              height: 120.0,
              width: 120.0,
              color: Colors.blue.shade50,
              child: Align(
                alignment: Alignment.topRight,
                child: FlutterLogo(size: 60),
              ),
            ),
            //Alignment继承自AlignmentGeometry，表示矩形内的一个点，他有两个属性x、y，分别表示在水平和垂直方向的偏移
            Container(
              height: 120.0,
              width: 120.0,
              color: Colors.blue[50],
              child: Align(
                widthFactor: 2,
                heightFactor: 2,
                alignment: Alignment(2, 0.0),
                child: FlutterLogo(size: 60),
              ),
            ),
            //FractionalOffset 继承自 Alignment，它和 Alignment唯一的区别就是坐标原点不同！FractionalOffset 的坐标原点为矩形的左侧顶点，这和布局系统的一致
            Container(
              height: 120.0,
              width: 120.0,
              color: Colors.blue[50],
              child: Align(
                alignment: FractionalOffset(0.2, 0.6),
                child: FlutterLogo(size: 60),
              ),
            ),
            //DeepSeek教学使用双坐标系
            // 左侧标准坐标系
            Expanded(child: _LeftStandardCoordinate()),
            // 右侧数学坐标系
            Expanded(child: _RightMathCoordinate()),
          ],
        ),
      ),
    );
  }

  Widget _LeftStandardCoordinate() {
    return Container(
      margin: const EdgeInsets.all(10),
      decoration: BoxDecoration(
        border: Border.all(color: Colors.blue, width: 2),
      ),
      child: Stack(
        children: [
          const Positioned(
            left: 0,
            top: 0,
            child: Text("标准坐标系 (0,0)", style: TextStyle(color: Colors.blue)),
          ),
          Positioned(
            left: 50,
            top: 30,
            child: Container(width: 10, height: 10, color: Colors.blue),
          ),
        ],
      ),
    );
  }

  Widget _RightMathCoordinate() {
    return Container(
      margin: const EdgeInsets.all(10),
      decoration: BoxDecoration(
        border: Border.all(color: Colors.red, width: 2),
      ),
      child: LayoutBuilder(
        builder: (context, constraints) {
          final height = constraints.maxHeight;
          return Stack(
            children: [
              Positioned(
                left: 0,
                top: height - 20,
                child: const Text(
                  "数学坐标系 (0,0)",
                  style: TextStyle(color: Colors.red),
                ),
              ),
              Positioned(
                left: 50,
                top: height - 30 - 10, // y=30 → top=height-30
                child: Container(width: 10, height: 10, color: Colors.red),
              ),
            ],
          );
        },
      ),
    );
  }
}

class TestStack extends State<HomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,

        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            //通过ConstrainedBox来确保Stack占满屏幕
            ConstrainedBox(
              constraints: BoxConstraints.expand(),
              child: Stack(
                alignment: Alignment.center, //指定未定位或部分定位widget的对齐方式
                children: <Widget>[
                  Container(
                    color: Colors.red,
                    child: Text(
                      "Stack1",
                      style: TextStyle(color: Colors.white),
                    ),
                  ),
                  Positioned(left: 18.0, child: Text("Stack2")),
                  Positioned(top: 18.0, child: Text("Stack3")),
                ],
              ),
            ),
            Stack(
              alignment: Alignment.center,
              fit: StackFit.expand, //未定位widget占满Stack整个空间
              children: <Widget>[
                Positioned(left: 18.0, child: Text("Stack4")),
                Container(
                  color: Colors.red,
                  child: Text("Stack5", style: TextStyle(color: Colors.white)),
                ),
                Positioned(top: 18.0, child: Text("Stack6")),
              ],
            ),
          ],
        ),
      ),
    );
  }
}

//通过 LayoutBuilder，我们可以在布局过程中拿到父组件传递的约束信息，然后我们可以根据约束信息动态的构建不同的布局
//实现一个响应式的 Column 组件 ResponsiveColumn，它的功能是当当前可用的宽度小于 200 时，将子组件显示为一列，否则显示为两列
class ResponsiveColumn extends StatelessWidget {
  const ResponsiveColumn({Key? key, required this.children}) : super(key: key);

  final List<Widget> children;

  @override
  Widget build(BuildContext context) {
    // 通过 LayoutBuilder 拿到父组件传递的约束，然后判断 maxWidth 是否小于200
    return LayoutBuilder(
      builder: (BuildContext context, BoxConstraints constraints) {
        if (constraints.maxWidth < 200) {
          // 最大宽度小于200，显示单列
          return Column(children: children, mainAxisSize: MainAxisSize.min);
        } else {
          // 大于200，显示双列
          var _children = <Widget>[];
          for (var i = 0; i < children.length; i += 2) {
            if (i + 1 < children.length) {
              _children.add(
                Row(
                  children: [children[i], children[i + 1]],
                  mainAxisSize: MainAxisSize.min,
                ),
              );
            } else {
              _children.add(children[i]);
            }
          }
          return Column(children: _children, mainAxisSize: MainAxisSize.min);
        }
      },
    );
  }
}

class LayoutBuilderRoute extends StatelessWidget {
  const LayoutBuilderRoute({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    var _children = List.filled(6, Text("A"));
    // Column在本示例中在水平方向的最大宽度为屏幕的宽度
    return Column(
      children: [
        // 限制宽度为190，小于 200
        SizedBox(width: 190, child: ResponsiveColumn(children: _children)),
        ResponsiveColumn(children: _children),
        LayoutLogPrint(child: Text("xx")),
      ],
    );
  }
}

class LayoutLogPrint<T> extends StatelessWidget {
  const LayoutLogPrint({Key? key, this.tag, required this.child})
    : super(key: key);

  final Widget child;
  final T? tag; //指定日志tag

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(
      builder: (_, constraints) {
        // assert在编译release版本时会被去除
        assert(() {
          print('${tag ?? key ?? child}: $constraints');
          return true;
        }());
        return child;
      },
    );
  }
}
