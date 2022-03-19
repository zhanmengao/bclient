// LView.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "LView.h"
#include<CommCtrl.h>
#pragma commect(lib,"comctl32.lib")

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
bool gbPreeEscKey = false;

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
	LoadStringW(hInstance, IDC_LVIEW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LVIEW));

	MSG msg;

	// 主消息循环: 
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			if (msg.message == WM_KEYDOWN)
			{
				if (VK_ESCAPE == msg.wParam)
				{
					gbPreeEscKey = true;						//此时按下esc
				}
			}
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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LVIEW));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LVIEW);
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
HWND hListView = NULL;

TCHAR strRaw[1024] = { 0 };				//存放以前的文本
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		hListView = CreateWindow(L"SysListView32", NULL,
			WS_CHILD | WS_BORDER | WS_VISIBLE | LVS_REPORT | LVS_EDITLABELS,
			20, 10, 260, 100, hWnd, (HMENU)10000, hInst, NULL);
		//设置拓展风格
		DWORD dwStyle = ListView_GetExtendedListViewStyle(hListView);
		dwStyle |= LVS_EX_FULLROWSELECT;					//选中的行高亮
		dwStyle |= LVS_EX_GRIDLINES;						//网格线
		dwStyle |= LVS_EX_CHECKBOXES;						//item前生成复选框控件
		//设置拓展风格
		ListView_SetExtendedListViewStyleEx(hListView, 0, dwStyle);

		//插入第一列列头
		LVCOLUMN colInfo = { 0 };
		colInfo.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_FMT;
		colInfo.iSubItem = 0;
		colInfo.fmt = LVCFMT_CENTER;
		colInfo.cx = 100;
		colInfo.pszText = _T("姓名");
		colInfo.cchTextMax = 60;
		SendMessage(hListView, LVM_INSERTCOLUMN, 0, (LPARAM)(&colInfo));
		//插入第二列列头
		colInfo.cx = 50;
		colInfo.pszText = _T("年龄");
		colInfo.cchTextMax = 20;
		SendMessage(hListView, LVM_INSERTCOLUMN, 1, (LPARAM)(&colInfo));
		//插入第一行数据
		LVITEM item = { 0 };
		item.mask = LVIF_TEXT;
		item.pszText = _T("李四");
		item.iItem = 0;
		item.iSubItem = 0;
		SendMessage(hListView, LVM_INSERTITEM, 0, (LPARAM)(&item));
		item.pszText = _T("31");
		item.iSubItem = 1;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)(&item));
		//插入第二行数据
		item.mask = LVIF_TEXT;
		item.pszText = _T("张三");
		item.iItem = 1;
		item.iSubItem = 0;
		SendMessage(hListView, LVM_INSERTITEM, 0, (LPARAM)(&item));
		item.pszText = _T("49");
		item.iSubItem = 1;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)(&item));
		//插入第三行数据
		item.mask = LVIF_TEXT;
		item.pszText = _T("王五");
		item.iItem = 1;
		item.iSubItem = 0;
		SendMessage(hListView, LVM_INSERTITEM, 0, (LPARAM)(&item));
		item.pszText = _T("63");
		item.iSubItem = 1;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)(&item));
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
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_NOTIFY:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case 10000:
		{
			//是否是双击事件
			if (((LPNMHDR)lParam)->code == NM_DBLCLK)
			{
				//获取当前选中索引
				LRESULT result = SendMessage(hListView, LVM_GETNEXTITEM, -1, LVNI_SELECTED);
				if (result == -1)
				{
					MessageBox(hWnd, L"请对某行双击", L"Error", MB_OK | MB_ICONINFORMATION);
					break;
				}
				//为获取项文本，填充结构
				LVITEM item = { 0 };
				TCHAR text[1024] = { 0 };
				TCHAR itemName[256] = { 0 };
				TCHAR subName[256] = { 0 };
				item.mask = LVIF_TEXT;
				item.iItem = result;
				item.iSubItem = 0;
				item.pszText = text;
				item.cchTextMax = 256;
				//获取项文本
				SendMessage(hListView, LVM_GETITEMTEXT, result, (LPARAM)(&item));
				//暂存
				_stprintf_s(itemName, text);

				//获取子项文本
				item.iSubItem = 1;
				SendMessage(hListView, LVM_GETITEMTEXT, result, (LPARAM)(&item));
				//暂存
				_stprintf_s(subName, _T(" %s"), text);
				_tcscat_s(itemName, subName);
				MessageBox(hWnd, itemName, L"Data", MB_OK);
			}
			//在控件里按键盘，会发消息
			else if (((LPNMHDR)lParam)->code == LVN_KEYDOWN)
			{
				auto keyEvent = (LPNMLVKEYDOWN)lParam;
				if (keyEvent->wVKey == VK_DELETE)
				{
					auto result = SendMessage(hListView, LVM_GETNEXTITEM, -1, LVNI_SELECTED);
					if (result == -1)
					{
						break;
					}
					//删除指定的行
					ListView_DeleteItem(hListView, result);
				}
			}
			//判断是否是开始编辑事件
			else if (((LPNMHDR)lParam)->code == LVN_BEGINLABELEDIT)
			{
				HWND hEdit = ListView_GetEditControl(hListView);					//获取主项编辑框窗口

				GetWindowText(hEdit, strRaw, sizeof(strRaw));
			}
			//判断是否是结束编辑事件
			else if(((LPNMHDR)lParam)->code == LVN_ENDLABELEDIT)
			{
				HWND hEdit = ListView_GetEditControl(hListView);					//获取主项编辑框窗口
				int iIndex = 0;
				TCHAR buf[1024] = { 0 };
				//获取当前焦点
				auto result = SendMessage(hListView, LVM_GETNEXTITEM, -1, LVNI_FOCUSED);
				if (result == -1)
				{
					break;
				}
				LVITEM item = { 0 };
				//判断是否按下ESC，按下则重置为以前的文本
				if (!gbPreeEscKey)
				{
					item.pszText = buf;
					item.cchTextMax = 1024;
					GetWindowText(hEdit, buf, sizeof(buf));
					SendMessage(hListView, LVM_SETITEMTEXT, (WPARAM)result, (LPARAM)(&item));
				}
				else
				{
					item.pszText = strRaw;
					SendMessage(hListView, LVM_SETITEMTEXT, (WPARAM)result, (LPARAM)(&item));
					gbPreeEscKey = false;
				}
			}
		}
		break;
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此处添加使用 hdc 的任何绘图代码...
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
