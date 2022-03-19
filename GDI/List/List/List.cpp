// List.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "List.h"

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
    LoadStringW(hInstance, IDC_LIST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LIST));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LIST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LIST);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
HWND hLBox = NULL;
HWND hMULBox = NULL;
TCHAR buf[1024] = { 0 };
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{
		//创建列表框，
		 hLBox = CreateWindow(L"listbox", NULL, 
			WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_TABSTOP | LBS_STANDARD,
			20, 20, 60, 80, hWnd, (HMENU)10000, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		//向列表框添加数据
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("中国"));
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("美国"));
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("英国"));

		//自画列表框：LBS_OWNERDRAWFIXED
		hLBox = CreateWindow(L"listbox", NULL,
			WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_TABSTOP  | LBS_OWNERDRAWFIXED | LBS_HASSTRINGS,
			100, 20, 60, 120, hWnd, (HMENU)10001, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("四川"));
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("云南"));
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("海南"));

		//多列列表框
		hMULBox = CreateWindow(L"listbox", NULL,
			WS_CHILD | WS_VISIBLE | LBS_MULTICOLUMN | WS_TABSTOP | WS_BORDER,
			200, 20, 420, 100, hWnd, (HMENU)10003, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		//设置每列宽度
		SendMessage(hMULBox, LB_SETCOLUMNWIDTH,100, 0);
		//设置每列数据
		for (unsigned i = 0; i < 20; i++)
		{
			_stprintf_s(buf, L"%d : abcdefg", i);
			SendMessage(hMULBox, LB_ADDSTRING, 0, (LPARAM)buf);
		}
	}
		break;
	case WM_MEASUREITEM:
	{
		LPMEASUREITEMSTRUCT lpmis = (LPMEASUREITEMSTRUCT)lParam;
		lpmis->itemHeight = 30;				//设置每个item的高度
	}
	break;
	case WM_DRAWITEM:
	{
		if (wParam == 10001)
		{
			LPDRAWITEMSTRUCT pDI = (LPDRAWITEMSTRUCT)lParam;
			COLORREF col = RGB(240 + pDI->itemID, 80 * pDI->itemID, 80 * pDI->itemID);
			HBRUSH brush = CreateSolidBrush(col);					//画刷
			FillRect(pDI->hDC, &pDI->rcItem, brush);					//每行的矩形大小用刷子填充
			DeleteObject(brush);

			SetBkMode(pDI->hDC, TRANSPARENT);					//设置背景透明
			SendMessage(hLBox, LB_GETTEXT, pDI->itemID, (LPARAM)(buf));			//获取文本
			const DWORD dwStyle = DT_LEFT | DT_SINGLELINE | DT_NOPREFIX | DT_END_ELLIPSIS;
			DrawText(pDI->hDC, buf, _tcslen(buf), &pDI->rcItem, dwStyle);					//画出文本
		}
	}
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);				//低位，控件id
			int eventId = HIWORD(wParam);			//高位，事件码
			HWND targetHwnd = (HWND)lParam;
            // 分析菜单选择: 
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
			case 10000:
				if (eventId == LBN_SELCHANGE)
				{
					//获取当前选中项索引
					LRESULT nCurIndex = SendMessage(targetHwnd, LB_GETCURSEL, 0, 0);
					SendMessage(targetHwnd, LB_GETTEXT, nCurIndex, (LPARAM)buf);
					MessageBox(NULL, buf, L"选中", MB_OK);
				}
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
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
