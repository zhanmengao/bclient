import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    String icons = "";
    // accessible: 0xe03e
    icons += "\uE03e";
    // error:  0xe237
    icons += " \uE237";
    // fingerprint: 0xe287
    icons += " \uE287";
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,

        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              "Hello world",
              textAlign: TextAlign.left, //textAlign：文本的对齐方式；可以选择左对齐、右对齐还是居中
            ),
            Text(
              "Hello world! I'm Jack. " * 4,
              maxLines: 1,
              overflow: TextOverflow.ellipsis,
              style: TextStyle(
                color: Colors.blue,
                fontSize: 18.0,
                height: 1.2,
                fontFamily: "Courier",
                background: Paint()..color = Colors.yellow,
                decoration: TextDecoration.underline,
                decorationStyle: TextDecorationStyle.dashed,
              ),
            ),
            Text.rich(
              TextSpan(
                children: [
                  TextSpan(text: "Home: "), //字符串片段
                  TextSpan(
                    text: "https://flutterchina.club",
                    style: TextStyle(
                      color: Colors.blue,
                      fontFamily: "微软雅黑", //字体
                    ),
                  ),
                ],
              ),
            ),
            DefaultTextStyle(
              //1.设置文本默认样式
              style: TextStyle(color: Colors.red, fontSize: 20.0),
              textAlign: TextAlign.start,
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: <Widget>[
                  Text("hello world"),
                  Text("I am Jack"),
                  Text(
                    "I am Jack",
                    style: TextStyle(
                      inherit: false, //2.不继承默认样式
                      color: Colors.grey,
                    ),
                  ),
                ],
              ),
            ),

            ElevatedButton(
              child: Text(
                icons,
                style: TextStyle(
                  fontFamily: "MaterialIcons",
                  fontSize: 24.0,
                  color: Colors.green,
                ),
              ),
              onPressed: () {},
            ),
            ElevatedButton.icon(
              icon: Icon(Icons.send),
              label: Text("ElevatedButton"),
              onPressed: () {},
            ), //"漂浮"按钮，它默认带有阴影和灰色背景。按下后，阴影会变大
            TextButton(child: Text("TextButton"), onPressed: () {}),
            TextButton.icon(
              icon: Icon(Icons.info),
              label: Text("TextButton"),
              onPressed: () {},
            ), //文本按钮，默认背景透明并不带阴影。按下后，会有背景色
            OutlinedButton(child: Text("OutlinedButton"), onPressed: () {}),
            OutlinedButton.icon(
              icon: Icon(Icons.add),
              label: Text("OutlinedButton"),
              onPressed: () {},
            ), //默认有一个边框，不带阴影且背景透明。按下后，边框颜色会变亮、同时出现背景和阴影(较弱)
            IconButton(
              icon: Icon(Icons.thumb_up),
              onPressed: () {},
            ), //是一个可点击的Icon，不包括文字，默认没有背景，点击后会出现背景，如图3-9所示：
            //Image组件来加载并显示图片，Image的数据源可以是asset、文件、内存以及网络。Image组件来加载并显示图片，Image的数据源可以是asset、文件、内存以及网络。
            Image.asset("resources/chat.png"),
            Image(
              image: NetworkImage(
                "https://avatars2.githubusercontent.com/u/20411648?s=460&v=4",
              ),
              width: 100.0,
            ),
          ],
        ),
      ),
    );
  }
}

class ImageAndIconRoute extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    var img = AssetImage("resources/users.png");
    return SingleChildScrollView(
      child: Column(
        children:
            <Image>[
              Image(image: img, height: 50.0, width: 100.0, fit: BoxFit.fill),
              Image(image: img, height: 50, width: 50.0, fit: BoxFit.contain),
              Image(image: img, width: 100.0, height: 50.0, fit: BoxFit.cover),
              Image(
                image: img,
                width: 100.0,
                height: 50.0,
                fit: BoxFit.fitWidth,
              ),
              Image(
                image: img,
                width: 100.0,
                height: 50.0,
                fit: BoxFit.fitHeight,
              ),
              Image(
                image: img,
                width: 100.0,
                height: 50.0,
                fit: BoxFit.scaleDown,
              ),
              Image(image: img, height: 50.0, width: 100.0, fit: BoxFit.none),
              Image(
                image: img,
                width: 100.0,
                color: Colors.blue,
                colorBlendMode: BlendMode.difference,
                fit: BoxFit.fill,
              ),
              Image(
                image: img,
                width: 100.0,
                height: 200.0,
                repeat: ImageRepeat.repeatY,
              ),
            ].map((e) {
              return Row(
                children: <Widget>[
                  Padding(
                    padding: EdgeInsets.all(16.0),
                    child: SizedBox(width: 100, child: e),
                  ),
                  Text(e.fit.toString()),
                ],
              );
            }).toList(),
      ),
    );
  }
}
