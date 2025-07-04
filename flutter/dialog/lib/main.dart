import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(home: HomePage());
  }
}

class HomePage extends StatelessWidget {
  HomePage({super.key});
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('对话框演示')),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            TextButton(
              child: const Text("AlertDialog"),
              onPressed: () => showAlertDialog(context),
            ),
            ElevatedButton(
              onPressed: () => showSimpleDialog(context),
              style: ElevatedButton.styleFrom(
                padding: const EdgeInsets.symmetric(
                  horizontal: 32,
                  vertical: 16,
                ),
                textStyle: const TextStyle(fontSize: 18),
              ),
              child: const Text('选择语言'),
            ),
            TextButton(
              child: const Text("Dialog"),
              onPressed: () => showListDialog(context),
            ),
            TextButton(
              child: const Text("GeneralDialog"),
              onPressed: () => {
                showCustomDialog<bool>(
                  context: context,
                  builder: (context) {
                    return AlertDialog(
                      title: Text("提示"),
                      content: Text("您确定要删除当前文件吗?"),
                      actions: <Widget>[
                        TextButton(
                          child: Text("取消"),
                          onPressed: () => Navigator.of(context).pop(),
                        ),
                        TextButton(
                          child: Text("删除"),
                          onPressed: () {
                            // 执行删除操作
                            Navigator.of(context).pop(true);
                          },
                        ),
                      ],
                    );
                  },
                ),
              },
            ),
            ElevatedButton(
              child: Text("话框3（复选框可点击）"),
              onPressed: () async {
                //弹出删除确认对话框，等待用户确认
                bool? deleteTree = await showDeleteConfirmDialog(context);
                if (deleteTree == null) {
                  print("取消删除");
                } else {
                  print("同时删除子目录: $deleteTree");
                }
              },
            ),
            ElevatedButton(
              child: Text("底部菜单"),
              onPressed: () async {
                int? type = await _showModalBottomSheet(context);
                print(type);
              },
            ),
            ElevatedButton(
              child: Text("Loading"),
              onPressed: () => showLoadingDialog(context),
            ),
            ElevatedButton(
              child: Text("选日期"),
              onPressed: () async {
                var ret = await _showDatePicker1(context);
                print(ret);
              },
            ),
          ],
        ),
      ),
    );
  }

  void showAlertDialog(BuildContext context) {
    showDialog(
      context: context,
      builder: (context) => const AlertDialogRoute(),
    ).then((value) {
      if (value == true) {
        print("用户点击了删除");
      } else {
        print("用户取消操作");
      }
    });
  }

  Future<void> showSimpleDialog(BuildContext context) async {
    int? i = await showDialog<int>(
      context: context,
      builder: (BuildContext context) {
        return SimpleDialog(
          title: const Text('请选择语言'),
          children: <Widget>[
            SimpleDialogOption(
              onPressed: () {
                Navigator.pop(context, 1);
              },
              child: const Padding(
                padding: EdgeInsets.symmetric(vertical: 6),
                child: Text('中文简体'),
              ),
            ),
            SimpleDialogOption(
              onPressed: () {
                Navigator.pop(context, 2);
              },
              child: const Padding(
                padding: EdgeInsets.symmetric(vertical: 6),
                child: Text('美国英语'),
              ),
            ),
          ],
        );
      },
    );

    if (i != null) {
      print("选择了：${i == 1 ? "中文简体" : "美国英语"}");
      // 这里可以添加实际切换语言的逻辑
    }
  }

  Future<void> showListDialog(BuildContext context) async {
    int? index = await showDialog<int>(
      context: context,
      builder: (BuildContext context) {
        var child = Column(
          children: <Widget>[
            ListTile(title: Text("请选择")),
            Expanded(
              child: ListView.builder(
                itemCount: 30,
                itemBuilder: (BuildContext context, int index) {
                  return ListTile(
                    title: Text("$index"),
                    onTap: () => Navigator.of(context).pop(index),
                  );
                },
              ),
            ),
          ],
        );
        //使用AlertDialog会报错
        //return AlertDialog(content: child);
        return Dialog(child: child);
      },
    );
    if (index != null) {
      print("点击了：$index");
    }
  }

  //打开一个普通风格的对话框：showDialog方法正是showGeneralDialog的一个封装，定制了Material风格对话框的遮罩颜色和动画。
  //Material风格对话框打开/关闭动画是一个Fade（渐隐渐显）动画，如果我们想使用一个缩放动画就可以通过transitionBuilder来自定义。
  Future<T?> showCustomDialog<T>({
    required BuildContext context,
    bool barrierDismissible = true,
    required WidgetBuilder builder,
    ThemeData? theme,
  }) {
    final ThemeData dialogTheme = theme ?? Theme.of(context);
    return showGeneralDialog<T>(
      context: context,
      pageBuilder:
          (
            BuildContext buildContext,
            Animation<double> animation,
            Animation<double> secondaryAnimation,
          ) {
            final Widget pageChild = Builder(builder: builder);
            return SafeArea(
              child: Theme(data: dialogTheme, child: pageChild),
            );
          },
      barrierDismissible: barrierDismissible,
      barrierLabel: MaterialLocalizations.of(context).modalBarrierDismissLabel,
      barrierColor: Colors.black87,
      transitionDuration: const Duration(milliseconds: 150),
      transitionBuilder: _buildMaterialDialogTransitions,
    );
  }

  Widget _buildMaterialDialogTransitions(
    BuildContext context,
    Animation<double> animation,
    Animation<double> secondaryAnimation,
    Widget child,
  ) {
    return ScaleTransition(
      scale: CurvedAnimation(parent: animation, curve: Curves.easeOut),
      child: FadeTransition(opacity: animation, child: child),
    );
  }

  Future<bool?> showDeleteConfirmDialog(BuildContext context) {
    return showDialog<bool>(
      context: context,
      builder: (context) {
        return DeleteConfirmDialog();
      },
    );
  }

  // 弹出底部菜单列表模态对话框
  Future<int?> _showModalBottomSheet(BuildContext context) {
    return showModalBottomSheet<int>(
      context: context,
      builder: (BuildContext context) {
        return ListView.builder(
          itemCount: 30,
          itemBuilder: (BuildContext context, int index) {
            return ListTile(
              title: Text("$index"),
              onTap: () => Navigator.of(context).pop(index),
            );
          },
        );
      },
    );
  }

  showLoadingDialog(BuildContext context) {
    showDialog(
      context: context,
      barrierDismissible: false, //点击遮罩不关闭对话框
      builder: (context) {
        return AlertDialog(
          content: Column(
            mainAxisSize: MainAxisSize.min,
            children: <Widget>[
              CircularProgressIndicator(),
              Padding(
                padding: const EdgeInsets.only(top: 26.0),
                child: Text("正在加载，请稍后..."),
              ),
            ],
          ),
        );
      },
    );
  }

  Future<DateTime?> _showDatePicker1(BuildContext context) {
    var date = DateTime.now();
    return showDatePicker(
      context: context,
      initialDate: date,
      firstDate: date,
      lastDate: date.add(
        //未来30天可选
        Duration(days: 30),
      ),
    );
  }
}

class AlertDialogRoute extends StatelessWidget {
  const AlertDialogRoute({super.key});

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      title: const Text("提示"),
      content: const Text("您确定要删除当前文件吗?"),
      actions: <Widget>[
        TextButton(
          child: const Text("取消"),
          onPressed: () => Navigator.of(context).pop(),
        ),
        TextButton(
          child: const Text("删除"),
          onPressed: () => Navigator.of(context).pop(true),
        ),
      ],
    );
  }
}

class DeleteConfirmDialog extends StatefulWidget {
  const DeleteConfirmDialog({super.key});

  @override
  // ignore: library_private_types_in_public_api
  _DeleteConfirmDialogState createState() => _DeleteConfirmDialogState();
}

class _DeleteConfirmDialogState extends State<DeleteConfirmDialog> {
  bool _withTree = false;

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      title: const Text("提示"),
      content: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        mainAxisSize: MainAxisSize.min,
        children: <Widget>[
          const Text("您确定要删除当前文件吗?"),
          Row(
            children: <Widget>[
              const Text("同时删除子目录？"),
              Checkbox(
                value: _withTree,
                onChanged: (bool? value) {
                  setState(() {
                    _withTree = value ?? false;
                  });
                },
              ),
            ],
          ),
        ],
      ),
      actions: <Widget>[
        TextButton(
          child: const Text("取消"),
          onPressed: () => Navigator.of(context).pop(),
        ),
        TextButton(
          child: const Text("删除"),
          onPressed: () => Navigator.of(context).pop(_withTree),
        ),
      ],
    );
  }
}
