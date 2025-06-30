//Dart类库有非常多的返回Future或者Stream对象的函数。 这些函数被称为异步函数：它们只会在设置好一些耗时操作之后返回，比如像 IO操作。而不是等到这个操作完成。

//async和await关键词支持了异步编程，允许您写出和同步代码很像的异步代码。

//Future与JavaScript中的Promise非常相似，表示一个异步操作的最终完成（或失败）及其结果值的表示。
//简单来说，它就是用于处理异步操作的，异步处理成功了就执行成功的操作，异步处理失败了就捕获错误或者停止后续操作。
//一个Future只会对应一个结果，要么成功，要么失败。

import 'dart:async';

Future<String> login(String un, String pwd) async {
  // 模拟登录逻辑
  await Future.delayed(Duration(seconds: 1)); // 模拟网络请求 async 自动包装为 Future
  return "ok";
}

Future<String> getUserInfo(String id) async {
  // 模拟获取用户信息
  await Future.delayed(Duration(milliseconds: 500)); // 模拟网络请求
  return '{"id": "$id", "name": "John Doe"}';
}

Future<bool> saveUserInfo(String ui) async {
  // 模拟保存用户信息
  await Future.delayed(Duration(milliseconds: 300)); // 模拟IO操作
  return true;
}

//Future.delayed:创建延时任务（实际场景会是一个真正的耗时任务，比如一次网络请求）

//Future.wait：有些时候，我们需要等待多个异步任务都执行结束后才进行一些操作，比如我们有一个界面，需要先分别从两个网络接口获取数据，获取成功后，我们需要将两个接口数据进行特定的处理后再显示到UI界面上，应该怎么做？
//答案是Future.wait，它接受一个Future数组参数，只有数组中所有Future都执行成功后，才会触发then的成功回调，只要有一个Future执行失败，就会触发错误回调。
void task0() {
  Future.delayed(Duration(seconds: 2), () {
        //return "hi world!";
        throw AssertionError("Error");
      })
      .then((data) {
        //执行成功会走到这里
        print(data);
      })
      .catchError((e) {
        //执行失败会走到这里
        print(e);
      })
      .whenComplete(() {
        //无论成功或失败都会走到这里
      });
}

//如果异步依赖过多，就会形成回调地狱。解决方案1：使用Future消除Callback Hell
void task1() {
  login("alice", "******")
      .then((id) {
        return getUserInfo(id);
      })
      .then((userInfo) {
        return saveUserInfo(userInfo);
      })
      .then((e) {
        //执行接下来的操作
      })
      .catchError((e) {
        //错误处理
        print(e);
      });
}

//使用 async/await 消除 callback hell：async用来表示函数是异步的，定义的函数会返回一个Future对象，可以使用 then 方法添加回调函数。
//await 后面是一个Future，表示等待该异步任务完成，异步完成后才会往下走；await必须出现在 async 函数内部。
task() async {
  try {
    String id = await login("alice", "******");
    String userInfo = await getUserInfo(id);
    await saveUserInfo(userInfo);
    //执行接下来的操作
  } catch (e) {
    //错误处理
    print(e);
  }
}

//Stream可以接收多个异步操作的结果，常用于会多次读取数据的异步任务场景，如网络内容下载、文件读写等
taskStream() async {
  Stream.fromFutures([
    // 1秒后返回结果
    Future.delayed(Duration(seconds: 1), () {
      return "hello 1";
    }),
    // 抛出一个异常
    Future.delayed(Duration(seconds: 2), () {
      throw AssertionError("Error");
    }),
    // 3秒后返回结果
    Future.delayed(Duration(seconds: 3), () {
      return "hello 3";
    }),
  ]).listen(
    (data) {
      print(data);
    },
    onError: (e) {
      print(e.message);
    },
    onDone: () {},
  );
}

void main() {
  taskStream();
  Future.delayed(Duration(seconds: 10));
}
