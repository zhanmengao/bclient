import 'dart:math';

import 'package:flutter/material.dart';
import 'package:english_words/english_words.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});
  //这是一个路由表 key为路由的名字，是个字符串；value是个builder回调函数，用于生成相应的路由widget
  static final Map<String, WidgetBuilder> routes = {
    "new_page": (context) => NewRoute(),
    "tip": (context) => TipRoute(text: "tip"), // TipRoute需要接受text参数
    //"/": (context) => MyHomePage(title: "route root"),
  };
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
      routes: routes,
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
  int _counter = 0;

  void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
    return Scaffold(
      appBar: AppBar(
        // TRY THIS: Try changing the color here to a specific color (to
        // Colors.amber, perhaps?) and trigger a hot reload to see the AppBar
        // change color while the other colors stay the same.
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text('You have pushed the button this many times:'),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headlineMedium,
            ),
            TextButton(
              child: Text("open new route"),
              onPressed: () {
                //导航到新路由
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) {
                      return NewRoute();
                    },
                  ),
                );
              },
            ),
            ElevatedButton(
              child: Text("Tip Route"),
              onPressed: () async {
                var result = await Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) {
                      return TipRoute(text: WordPair.random().toString());
                    },
                  ),
                );
                //输出`TipRoute`路由返回结果
                print("路由返回值: $result");
              },
            ),
            TextButton(
              onPressed: () {
                final routeName = MyApp.routes.keys.elementAt(
                  Random().nextInt(MyApp.routes.length),
                );
                Navigator.pushNamed(context, routeName);
              },
              child: Text("route map"),
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: const Icon(Icons.add),
      ), // This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}

class NewRoute extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("New route")),
      body: Center(child: Text("This is new route")),
    );
  }
}

//路由返回值
class TipRoute extends StatelessWidget {
  TipRoute({
    Key? key,
    required this.text, // 接收一个text参数
  }) : super(key: key);
  final String text;
  static int i = 0;
  @override
  Widget build(BuildContext context) {
    i++;
    return Scaffold(
      appBar: AppBar(title: Text("提示")),
      body: Padding(
        padding: EdgeInsets.all(18),
        child: Center(
          child: Column(
            children: <Widget>[
              Text(text),
              ElevatedButton(
                onPressed: () => Navigator.pop(context, "我是返回值%$i"),
                child: Text("返回"),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
