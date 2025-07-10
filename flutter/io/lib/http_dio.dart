import 'package:dio/dio.dart';

void main() async {
  final dio = Dio(
    BaseOptions(
      baseUrl: 'https://jsonplaceholder.typicode.com',
      connectTimeout: const Duration(seconds: 5),
      receiveTimeout: const Duration(seconds: 3),
    ),
  );

  // 添加日志拦截器
  dio.interceptors.add(LogInterceptor(responseBody: true));

  try {
    // GET 请求
    Response response = await dio.get('/posts/1');
    print('GET 响应: ${response.data}');

    // POST 请求
    Response postResponse = await dio.post(
      '/posts',
      data: {'title': 'foo', 'body': 'bar', 'userId': 1},
    );
    print('POST 响应: ${postResponse.data}');
  } on DioException catch (e) {
    print('请求出错: ${e.message}');
    if (e.response != null) {
      print('错误响应数据: ${e.response?.data}');
    }
  }
}
