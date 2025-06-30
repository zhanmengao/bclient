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
  bool _switchSelected = true; //维护单选开关状态
  bool _checkboxSelected = true; //维护复选框状态
  //定义一个controller
  TextEditingController _unameController = TextEditingController();
  FocusNode focusNode1 = FocusNode();
  FocusNode focusNode2 = FocusNode();
  FocusScopeNode? focusScopeNode;
  GlobalKey _formKey = GlobalKey<FormState>();

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
            Image.asset("resources/chat.png"),
            Image(
              image: NetworkImage(
                "https://avatars2.githubusercontent.com/u/20411648?s=460&v=4",
              ),
              width: 100.0,
            ),
            Switch(
              value: _switchSelected, //当前状态
              onChanged: (value) {
                //重新构建页面
                setState(() {
                  _switchSelected = value;
                });
              },
            ),
            Checkbox(
              value: _checkboxSelected,
              activeColor: Colors.red, //选中时的颜色
              onChanged: (value) {
                setState(() {
                  _checkboxSelected = value!;
                });
              },
            ),

            //用表单做内容检测
            Form(
              key: _formKey,
              autovalidateMode: AutovalidateMode.onUserInteraction,
              child: Column(
                children: <Widget>[
                  TextFormField(
                    autofocus: true,
                    controller: _unameController, //通过controller获取输入框内容
                    focusNode: focusNode1,
                    decoration: InputDecoration(
                      labelText: "用户名",
                      hintText: "用户名或邮箱",
                      prefixIcon: Icon(Icons.person),
                      // 未获得焦点下划线设为灰色
                      enabledBorder: UnderlineInputBorder(
                        borderSide: BorderSide(color: Colors.grey),
                      ),
                      //获得焦点下划线设为蓝色
                      focusedBorder: UnderlineInputBorder(
                        borderSide: BorderSide(color: Colors.blue),
                      ),
                    ),
                    onChanged: (value) => {print(value)}, //通过回调获取内容or监听文本变化
                    // 校验用户名
                    validator: (v) {
                      return v!.trim().isNotEmpty ? null : "用户名不能为空";
                    },
                  ),

                  TextFormField(
                    decoration: InputDecoration(
                      labelText: "密码",
                      hintText: "您的登录密码",
                      prefixIcon: Icon(Icons.lock),
                    ),
                    obscureText: true,
                    focusNode: focusNode2,
                    //校验密码
                    validator: (v) {
                      return v!.trim().length > 5 ? null : "密码不能少于6位";
                    },
                  ),
                  Padding(
                    padding: const EdgeInsets.only(top: 28.0),
                    child: Row(
                      children: <Widget>[
                        Expanded(
                          child: ElevatedButton(
                            child: Padding(
                              padding: const EdgeInsets.all(16.0),
                              child: Text("登录"),
                            ),
                            onPressed: () {
                              // 通过_formKey.currentState 获取FormState后，
                              // 调用validate()方法校验用户名密码是否合法，校验
                              // 通过后再提交数据。
                              if ((_formKey.currentState as FormState)
                                  .validate()) {
                                //验证通过提交数据
                              }
                            },
                          ),
                        ),
                      ],
                    ),
                  ),
                ],
              ),
            ),
            //焦点管理
            Builder(
              builder: (ctx) {
                return Column(
                  children: <Widget>[
                    ElevatedButton(
                      child: Text("移动焦点"),
                      onPressed: () =>
                          FocusScope.of(context).requestFocus(focusNode2),
                    ),
                    ElevatedButton(
                      child: Text("隐藏键盘"),
                      onPressed: () {
                        // 当所有编辑框都失去焦点时键盘就会收起
                        focusNode1.unfocus();
                        focusNode2.unfocus();
                      },
                    ),
                  ],
                );
              },
            ),
            // 模糊进度条(会执行一个动画)
            LinearProgressIndicator(
              backgroundColor: Colors.grey[200],
              valueColor: AlwaysStoppedAnimation(Colors.blue),
            ),
            //进度条显示50%
            LinearProgressIndicator(
              backgroundColor: Colors.grey[200],
              valueColor: AlwaysStoppedAnimation(Colors.blue),
              value: .5,
            ),
            // 模糊进度条(会执行一个旋转动画)
            CircularProgressIndicator(
              backgroundColor: Colors.grey[200],
              valueColor: AlwaysStoppedAnimation(Colors.blue),
            ),
            //进度条显示50%，会显示一个半圆
            CircularProgressIndicator(
              backgroundColor: Colors.grey[200],
              valueColor: AlwaysStoppedAnimation(Colors.blue),
              value: .5,
            ),
            // 线性进度条高度指定为3
            SizedBox(
              height: 3,
              child: LinearProgressIndicator(
                backgroundColor: Colors.grey[200],
                valueColor: AlwaysStoppedAnimation(Colors.blue),
                value: .5,
              ),
            ),
            // 圆形进度条直径指定为100
            SizedBox(
              height: 100,
              width: 100,
              child: CircularProgressIndicator(
                backgroundColor: Colors.grey[200],
                valueColor: AlwaysStoppedAnimation(Colors.blue),
                value: .7,
              ),
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
