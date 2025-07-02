import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const TestRoute(),
    );
  }
}

class TestRoute extends StatelessWidget {
  const TestRoute({Key? key}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text("transport"),
      ),
      body: Center(
        child: Column(
          children: <Widget>[
            //复合型Container，它是DecoratedBox、ConstrainedBox、Transform、Padding、Align等组件组合的一个多功能容器，所以我们只需通过一个Container组件可以实现同时需要装饰、变换、限制的场景
            Container(
              margin: EdgeInsets.only(top: 50.0, left: 120.0),
              constraints: BoxConstraints.tightFor(
                width: 200.0,
                height: 150.0,
              ), //卡片大小
              decoration: BoxDecoration(
                //背景装饰
                gradient: RadialGradient(
                  //背景径向渐变
                  colors: [Colors.red, Colors.orange],
                  center: Alignment.topLeft,
                  radius: .98,
                ),
                boxShadow: [
                  //卡片阴影
                  BoxShadow(
                    color: Colors.black54,
                    offset: Offset(2.0, 2.0),
                    blurRadius: 4.0,
                  ),
                ],
              ),
              transform: Matrix4.rotationZ(.2), //卡片倾斜变换
              alignment: Alignment.center, //卡片内文字居中
              child: Text(
                //卡片文字
                "5.20",
                style: TextStyle(color: Colors.white, fontSize: 40.0),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
