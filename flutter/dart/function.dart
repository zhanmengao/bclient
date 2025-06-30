bool isNoble(int i) {
  return i > 0;
}

//函数指针
var cb = isNoble;

void execute(var cb) {
  cb();
}

//函数作为对象
var say = (str) {
  print(str);
};

//用[]标记为可选的位置参数，并放在参数列表的最后面
String say2(String from, String msg, [String? device]) {
  var result = '$from says $msg';
  if (device != null) {
    result = '$result with a $device';
  }
  return result;
}

//可选命名参数：使用{param1, param2, …}，放在参数列表的最后面，用于指定命名参数
void enableFlags({bool bold = false, bool hidden = true}) {
  // ...
}

void main() {
  print(cb(1));
  execute(() => say("execute")); //只有一行的函数可以简写
  say("hello");
  print(say2('Bob', 'Howdy')); //结果是： Bob says Howdy
  print(
    say2('Bob', 'Howdy', 'smoke signal'),
  ); //结果是：Bob says Howdy with a smoke signal
}
