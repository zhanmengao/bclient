import 'dart:async';
import 'dart:convert';
import 'dart:io';
import 'package:dio/dio.dart';
import 'package:dio/io.dart';
import 'package:flutter/material.dart';
import 'package:flutter_application_1/models/index.dart';
import 'package:flutter_application_1/models/user.dart';
import 'vars.dart';
export 'package:dio/dio.dart' show DioError;

class Git {
  // 在网络请求过程中可能会需要使用当前的context信息，比如在请求失败时
  // 打开一个新路由，而打开新路由需要context信息。
  BuildContext? context;
  late Options _options;
  static Dio dio = new Dio(
    BaseOptions(
      baseUrl: "https://api.github.com",
      headers: {
        HttpHeaders.acceptCharsetHeader:
            "application/vnd.github.squirrel-girl-preview,"
            "application/vnd.github.symmetra-preview+json",
      },
    ),
  );

  Git([this.context]) {
    _options = Options(extra: {"context": context});
  }

  static void init() {
    //设置缓存实现
    dio.interceptors.add(Global.netCache);
    //设置用户token
    dio.options.headers[HttpHeaders.authorizationHeader] = Global.profile.token;

    //在调试模式下会使用代理，所以禁用HTTPS证书校验
    if (!Global.isRelease) {
      (dio.httpClientAdapter as DefaultHttpClientAdapter).onHttpClientCreate =
          (client) {
            client.badCertificateCallback =
                (X509Certificate cert, String host, int port) => true;
          };
    }
  }

  //实现登录
  Future<User> Login(String login, String pwd) async {
    String basic = 'Basic ${base64Encode(utf8.encode('$login:$pwd'))}';
    var r = await dio.get(
      "/user",
      options: _options.copyWith(
        headers: {Headers.acceptHeader: basic},
        extra: {
          "noCache": true, //登录接口不缓存
        },
      ),
    );
    //登录成功后更新公共头部
    dio.options.headers[HttpHeaders.acceptCharsetHeader] = basic;
    Global.profile.token = basic;
    return User.fromJson(r.data);
  }

  //获取项目列表
  Future<List<Repo>> GetRepoList({
    Map<String, dynamic>? qeuryParameters,
    refresh = false,
  }) async {
    //下拉列表刷新的情况。需要清理缓存
    if (refresh) {
      _options.extra!.addAll({"refresh": true, "list": true});
    }
    var r = await dio.get<List>(
      "user/repos",
      queryParameters: qeuryParameters,
      options: _options,
    );
    return r.data!.map((e) => Repo.fromJson(e)).toList();
  }
}
