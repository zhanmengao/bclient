// RadioButton.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "RadioButton.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 在此放置代码。

	// 初始化全局字符串
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_RADIOBUTTON, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RADIOBUTTON));

	MSG msg;

	// 主消息循环: 
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RADIOBUTTON));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_RADIOBUTTON);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 将实例句柄存储在全局变量中

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
int x = 20;
int y = 20;
int w = 110;
int h = 16;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		//第一组单选按钮
		CreateWindow(L"Button", L"0--50公斤",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO1, hInst, NULL);
		y += 20;
		CreateWindow(L"Button", L"50--100公斤",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO2, hInst, NULL);
		y += 20;
		CreateWindow(L"Button", L"100公斤以上",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO3, hInst, NULL);

		//第二组单选按钮
		x += 150;
		y = 20;
		CreateWindow(L"Button", L"0--100厘米",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO4, hInst, NULL);
		y += 20;
		CreateWindow(L"Button", L"100--200厘米",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO5, hInst, NULL);
		y += 20;
		CreateWindow(L"Button", L"200厘米以上",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO6, hInst, NULL);
	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 分析菜单选择: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDC_RADIO1:
			MessageBox(hWnd, L"IDC_RADIO1", L"Title", MB_OKCANCEL);
			break;
		case IDC_RADIO2:
			MessageBox(hWnd, L"IDC_RADIO2", L"Title", MB_OKCANCEL);
			break;
		case IDC_RADIO3:
			MessageBox(hWnd, L"IDC_RADIO3", L"Title", MB_OKCANCEL);
			break;
		case IDC_RADIO4:
			MessageBox(hWnd, L"IDC_RADIO4", L"Title", MB_OKCANCEL);
			break;
		case IDC_RADIO5:
			MessageBox(hWnd, L"IDC_RADIO5", L"Title", MB_OKCANCEL);
			break;
		case IDC_RADIO6:
			MessageBox(hWnd, L"IDC_RADIO6", L"Title", MB_OKCANCEL);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		RECT rt;
		GetClientRect(hWnd, &rt);
		DrawText(hdc, L"请选择体重范围和身高范围", -1, &rt, 
			DT_SINGLELINE | DT_TOP | DT_LEFT);					//在左上角绘制字符串
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
