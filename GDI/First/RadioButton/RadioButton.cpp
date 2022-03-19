// RadioButton.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "RadioButton.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;                                // ��ǰʵ��
WCHAR szTitle[MAX_LOADSTRING];                  // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING];            // ����������

// �˴���ģ���а����ĺ�����ǰ������: 
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

	// TODO: �ڴ˷��ô��롣

	// ��ʼ��ȫ���ַ���
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_RADIOBUTTON, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RADIOBUTTON));

	MSG msg;

	// ����Ϣѭ��: 
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
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
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
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

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
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_PAINT    - ����������
//  WM_DESTROY  - �����˳���Ϣ������
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
		//��һ�鵥ѡ��ť
		CreateWindow(L"Button", L"0--50����",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO1, hInst, NULL);
		y += 20;
		CreateWindow(L"Button", L"50--100����",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO2, hInst, NULL);
		y += 20;
		CreateWindow(L"Button", L"100��������",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO3, hInst, NULL);

		//�ڶ��鵥ѡ��ť
		x += 150;
		y = 20;
		CreateWindow(L"Button", L"0--100����",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO4, hInst, NULL);
		y += 20;
		CreateWindow(L"Button", L"100--200����",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO5, hInst, NULL);
		y += 20;
		CreateWindow(L"Button", L"200��������",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			x, y, w, h, hWnd, (HMENU)IDC_RADIO6, hInst, NULL);
	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// �����˵�ѡ��: 
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
		DrawText(hdc, L"��ѡ�����ط�Χ����߷�Χ", -1, &rt, 
			DT_SINGLELINE | DT_TOP | DT_LEFT);					//�����Ͻǻ����ַ���
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

// �����ڡ������Ϣ�������
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
