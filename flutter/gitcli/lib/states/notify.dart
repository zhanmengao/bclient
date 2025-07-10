import 'package:flutter/material.dart';
import '../common/vars.dart';
import '../models/index.dart';

class ProfileChangeNotifier extends ChangeNotifier {
  Profile get profile => Global.profile;

  void saveProfile() async {
    await Global.saveProfile(); // 子类按需调用
  }
}

class UserModel extends ProfileChangeNotifier {
  User? get user => profile.user;

  bool get isLogin => user != null;

  set user(User? newUser) {
    if (profile.user != newUser) {
      profile.lastLogin = profile.user?.login;
      profile.user = newUser;
      saveProfile(); // 显式保存
      notifyListeners();
    }
  }
}

class ThemeModel extends ProfileChangeNotifier {
  // 获取当前主题，如果为设置主题，则默认使用蓝色主题
  ColorSwatch get theme => Global.themes.firstWhere(
    (e) => e.value == profile.theme,
    orElse: () => Colors.blue,
  );

  // 主题改变后，通知其依赖项，新主题会立即生效
  set theme(ColorSwatch color) {
    if (color != theme) {
      profile.theme = color[500]!.toARGB32();
      saveProfile(); // 显式保存
      notifyListeners();
    }
  }
}

class LocaleModel extends ProfileChangeNotifier {
  // 获取当前用户的APP语言配置Locale类，如果为null，则语言跟随系统语言
  Locale? getLocale() {
    if (profile.locale == null) {
      return null;
    }
    var t = profile.locale?.split("_");
    return Locale(t![0], t[1]);
  }

  // 获取当前Locale的字符串表示
  String? get localeString => profile.locale;

  // 用户改变APP语言后，通知依赖项更新，新语言会立即生效
  set locale(String locale) {
    if (locale != profile.locale) {
      profile.locale = locale;
      saveProfile(); // 显式保存
      notifyListeners();
    }
  }
}
