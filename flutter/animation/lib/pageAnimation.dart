import 'package:flutter/material.dart';

void main() {
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: HomePage(), // 使用独立的 HomePage，确保 Navigator 可用
    );
  }
}

// 新增 HomePage，确保 Scaffold 在 Navigator 范围内
class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Column(
        children: [
          ElevatedButton(
            onPressed: () {
              Navigator.push(
                context,
                PageRouteBuilder(
                  transitionDuration: const Duration(milliseconds: 500),
                  pageBuilder:
                      (
                        BuildContext context,
                        Animation<double> animation,
                        Animation<double> secondaryAnimation,
                      ) {
                        return FadeTransition(
                          opacity: animation,
                          child: const PageB(),
                        );
                      },
                ),
              );
            },
            child: const Text("PageRouteBuilder"),
          ),
          ElevatedButton(
            onPressed: () {
              Navigator.push(
                context,
                FadeRoute(
                  builder: (context) => const PageB(),
                  barrierColor: Colors.transparent, // 修正 barrierColor
                  barrierLabel: 'PageRoute',
                ),
              );
            },
            child: const Text("PageRoute"),
          ),
        ],
      ),
    );
  }
}

class FadeRoute extends PageRoute {
  FadeRoute({
    required this.builder,
    this.transitionDuration = const Duration(milliseconds: 300),
    this.opaque = true,
    this.barrierDismissible = false,
    required this.barrierColor,
    required this.barrierLabel,
    this.maintainState = true,
  });

  final WidgetBuilder builder;

  @override
  final Duration transitionDuration;

  @override
  final bool opaque;

  @override
  final bool barrierDismissible;

  @override
  final Color barrierColor;

  @override
  final String barrierLabel;

  @override
  final bool maintainState;

  @override
  Widget buildPage(
    BuildContext context,
    Animation<double> animation,
    Animation<double> secondaryAnimation,
  ) => builder(context);

  @override
  Widget buildTransitions(
    BuildContext context,
    Animation<double> animation,
    Animation<double> secondaryAnimation,
    Widget child,
  ) {
    return FadeTransition(
      opacity: animation,
      child: child,
    ); // 使用 child 而不是 builder(context)
  }
}

class PageB extends StatelessWidget {
  const PageB({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text("New route")),
      body: const Center(child: Text("This is new route")),
    );
  }
}
