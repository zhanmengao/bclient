import 'package:flutter/material.dart';

/*
如何决定使用哪种管理方法？下面是官方给出的一些原则可以帮助你做决定：

    如果状态是用户数据，如复选框的选中状态、滑块的位置，则该状态最好由父 Widget 管理。
    如果状态是有关界面外观效果的，例如颜色、动画，那么状态最好由 Widget 本身来管理。
    如果某一个状态是不同 Widget 共享的则最好由它们共同的父 Widget 管理。

在 Widget 内部管理状态封装性会好一些，而在父 Widget 中管理会比较灵活。有些时候，如果不确定到底该怎么管理状态，那么推荐的首选是在父 Widget 中管理（灵活会显得更重要一些）。
*/
void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'state',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: TapboxA(),
    );
  }
}

class TapboxA extends StatefulWidget {
  TapboxA({Key? key}) : super(key: key);

  @override
  _TapboxAState createState() => _TapboxAState();
}

/*一个 StatefulWidget 类会对应一个 State 类，State表示与其对应的 StatefulWidget 要维护的状态，State 中的保存的状态信息可以：
    在 widget 构建时可以被同步读取。
    在 widget 生命周期中可以被改变，当State被改变时，可以手动调用其setState()方法通知Flutter 框架状态发生改变，
    Flutter 框架在收到消息后，会重新调用其build方法重新构建 widget 树，从而达到更新UI的目的。
State 中有两个常用属性：
    widget，它表示与该 State 实例关联的 widget 实例，由Flutter 框架动态设置。
    注意，这种关联并非永久的，因为在应用生命周期中，UI树上的某一个节点的 widget 实例在重新构建时可能会变化，但State实例只会在第一次插入到树中时被创建，
    当在重新构建时，如果 widget 被修改了，Flutter 框架会动态设置State. widget 为新的 widget 实例。
    context。StatefulWidget对应的 BuildContext，作用同StatelessWidget 的BuildContext。*/
class _TapboxAState extends State<TapboxA> {
  bool _active = false;
  int _counter = 0;
  void _handleTap() {
    setState(() {
      _active = !_active;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("state")),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            // 您原有的GestureDetector容器
            GestureDetector(
              onTap: () => setState(() => _active = !_active),
              child: Container(
                child: Center(child: Text(_active ? 'Active' : 'Inactive')),
                width: 200,
                height: 200,
                decoration: BoxDecoration(
                  color: _active ? Colors.lightGreen[700] : Colors.grey[600],
                ),
              ),
            ),

            SizedBox(height: 20), // 添加间距
            // 新增的按钮
            TextButton(
              child: Text('$_counter'),
              //点击后计数器自增
              onPressed: () => setState(() => ++_counter),
            ),
          ],
        ),
      ),
    );
  }

  @override
  void didUpdateWidget(TapboxA oldWidget) {
    super.didUpdateWidget(oldWidget);
    print("didUpdateWidget ");
  }

  @override
  void deactivate() {
    super.deactivate();
    print("deactivate");
  }

  @override
  void dispose() {
    super.dispose();
    print("dispose");
  }

  @override
  void reassemble() {
    super.reassemble();
    print("reassemble");
  }

  @override
  void didChangeDependencies() {
    super.didChangeDependencies();
    print("didChangeDependencies");
  }
}

// ParentWidget 为 TapboxB 管理状态.
//对于父Widget来说，管理状态并告诉其子Widget何时更新通常是比较好的方式。 例如，IconButton是一个图标按钮，但它是一个无状态的Widget，因为我们认为父Widget需要知道该按钮是否被点击来采取相应的处理。
//在以下示例中，TapboxB通过回调将其状态导出到其父组件，状态由父组件管理，因此它的父组件为StatefulWidget。但是由于TapboxB不管理任何状态，所以TapboxB为StatelessWidget。
//------------------------ ParentWidget --------------------------------
///ParentWidgetState 类:
//     为TapboxB 管理_active状态。
//     实现_handleTapboxChanged()，当盒子被点击时调用的方法。
//     当状态改变时，调用setState()更新UI。
class ParentWidget extends StatefulWidget {
  @override
  _ParentWidgetState createState() => _ParentWidgetState();
}

class _ParentWidgetState extends State<ParentWidget> {
  bool _active = false;

  void _handleTapboxChanged(bool newValue) {
    setState(() {
      _active = newValue;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      child: TapboxB(active: _active, onChanged: _handleTapboxChanged),
    );
  }
}

//------------------------- TapboxB ----------------------------------
// TapboxB 类:
//     继承StatelessWidget类，因为所有状态都由其父组件处理。
//     当检测到点击时，它会通知父组件。

class TapboxB extends StatelessWidget {
  const TapboxB({
    // 添加 const 构造函数
    super.key, // 使用 super.key 简化语法
    this.active = false, // 将冒号(:)改为等号(=)作为默认值
    required this.onChanged,
  });

  final bool active;
  final ValueChanged<bool> onChanged;

  void _handleTap() {
    onChanged(!active);
  }

  @override // 显式添加 override 注解
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: _handleTap,
      child: Container(
        child: Center(
          child: Text(
            active ? 'Active' : 'Inactive',
            style: TextStyle(fontSize: 32.0, color: Colors.white),
          ),
        ),
        width: 200.0,
        height: 200.0,
        decoration: BoxDecoration(
          color: active ? Colors.lightGreen[700] : Colors.grey[600],
        ),
      ),
    );
  }
}
