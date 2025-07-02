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
            //线性布局：Column可以在垂直方向排列其子组件。参数和Row一样，不同的是布局方向为垂直，主轴纵轴正好相反
            Column(
              //测试Row对齐方式，排除Column默认居中对齐的干扰
              crossAxisAlignment: CrossAxisAlignment.start,
              children: <Widget>[
                Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: <Widget>[Text("Row"), Text("Row2")],
                ),
                Row(
                  mainAxisSize: MainAxisSize.min,
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: <Widget>[Text("Row3"), Text("Row4")],
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.end,
                  textDirection: TextDirection.rtl,
                  children: <Widget>[Text("Row5"), Text("Row6")],
                ),
                Row(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  verticalDirection: VerticalDirection.up,
                  children: <Widget>[
                    Text("Row7", style: TextStyle(fontSize: 30.0)),
                    Text("Row8"),
                  ],
                ),
              ],
            ),
            //弹性布局：Flex组件可以沿着水平或垂直方向排列子组件
            Column(
              children: <Widget>[
                //Flex的两个子widget按1：2来占据水平空间
                Flex(
                  direction: Axis.horizontal,
                  children: <Widget>[
                    Text("Flex"),
                    //Expanded 只能作为 Flex 的孩子,它可以按比例“扩伸”Flex子组件所占用的空间。因为 Row和Column 都继承自 Flex
                    //flex参数为弹性系数，如果为 0 或null，则child是没有弹性的，即不会被扩伸占用的空间。如果大于0，所有的Expanded按照其 flex 的比例来分割主轴的全部空闲空间
                    Expanded(
                      flex: 1,
                      child: Container(height: 30.0, color: Colors.red),
                    ),
                    Expanded(
                      flex: 2,
                      child: Container(height: 30.0, color: Colors.green),
                    ),
                  ],
                ),
                Padding(
                  padding: const EdgeInsets.only(top: 20.0),
                  child: SizedBox(
                    height: 100.0,
                    //Flex的三个子widget，在垂直方向按2：1：1来占用100像素的空间
                    child: Flex(
                      direction: Axis.vertical,
                      children: <Widget>[
                        Expanded(
                          flex: 2,
                          child: Container(height: 30.0, color: Colors.red),
                        ),
                        Spacer(flex: 1),
                        Expanded(
                          flex: 1,
                          child: Container(height: 30.0, color: Colors.green),
                        ),
                      ],
                    ),
                  ),
                ),
              ],
            ),
            //流式布局Wrap：Row 换成Wrap后溢出部分则会自动折行
            Wrap(
              spacing: 8.0, // 主轴(水平)方向间距
              runSpacing: 4.0, // 纵轴（垂直）方向间距
              alignment: WrapAlignment.center, //沿主轴方向居中
              children: <Widget>[
                Chip(
                  avatar: CircleAvatar(
                    backgroundColor: Colors.blue,
                    child: Text('A'),
                  ),
                  label: Text('Wrap'),
                ),
                Chip(
                  avatar: CircleAvatar(
                    backgroundColor: Colors.blue,
                    child: Text('M'),
                  ),
                  label: Text('Wrap'),
                ),
                Chip(
                  avatar: CircleAvatar(
                    backgroundColor: Colors.blue,
                    child: Text('H'),
                  ),
                  label: Text('Wrap'),
                ),
                Chip(
                  avatar: CircleAvatar(
                    backgroundColor: Colors.blue,
                    child: Text('J'),
                  ),
                  label: Text('Wrap'),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}

//我们一般很少会使用Flow，因为其过于复杂，需要自己实现子 widget 的位置转换，在很多场景下首先要考虑的是Wrap是否满足需求。
class TestFlowDelegate extends FlowDelegate {
  EdgeInsets margin;

  TestFlowDelegate({this.margin = EdgeInsets.zero});

  double width = 0;
  double height = 0;

  @override
  void paintChildren(FlowPaintingContext context) {
    var x = margin.left;
    var y = margin.top;
    //计算每一个子widget的位置
    for (int i = 0; i < context.childCount; i++) {
      var w = context.getChildSize(i)!.width + x + margin.right;
      if (w < context.size.width) {
        context.paintChild(i, transform: Matrix4.translationValues(x, y, 0.0));
        x = w + margin.left;
      } else {
        x = margin.left;
        y += context.getChildSize(i)!.height + margin.top + margin.bottom;
        //绘制子widget(有优化)
        context.paintChild(i, transform: Matrix4.translationValues(x, y, 0.0));
        x += context.getChildSize(i)!.width + margin.left + margin.right;
      }
    }
  }

  @override
  Size getSize(BoxConstraints constraints) {
    // 指定Flow的大小，简单起见我们让宽度尽可能大，但高度指定为200，
    // 实际开发中我们需要根据子元素所占用的具体宽高来设置Flow大小
    return Size(double.infinity, 200.0);
  }

  @override
  bool shouldRepaint(FlowDelegate oldDelegate) {
    return oldDelegate != this;
  }
}
