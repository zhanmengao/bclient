//Dart 是不支持多继承的
//定义一个 Person 类，实现吃饭、说话、走路和写代码功能
class Person {
  say() {
    print('say');
  }
}

//mixin 可以 “组合” 多个类
mixin Eat {
  eat() {
    print('eat');
  }
}

mixin Walk {
  walk() {
    print('walk');
  }
}

mixin Code {
  code() {
    print('key');
  }
}

//同时定义一个 Dog 类，实现吃饭、和走路功能
class Dog with Eat, Walk {}

//如果多个mixin 中有同名方法，with 时，会默认使用最后面的 mixin 的
class Man extends Person with Eat, Walk, Code {}
