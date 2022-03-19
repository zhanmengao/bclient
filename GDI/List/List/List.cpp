// List.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "List.h"

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
    LoadStringW(hInstance, IDC_LIST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LIST));

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

    return (int) msg.wParam;
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
HWND hLBox = NULL;
HWND hMULBox = NULL;
TCHAR buf[1024] = { 0 };
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{
		//�����б��
		 hLBox = CreateWindow(L"listbox", NULL, 
			WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_TABSTOP | LBS_STANDARD,
			20, 20, 60, 80, hWnd, (HMENU)10000, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		//���б���������
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("�й�"));
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("����"));
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("Ӣ��"));

		//�Ի��б��LBS_OWNERDRAWFIXED
		hLBox = CreateWindow(L"listbox", NULL,
			WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_TABSTOP  | LBS_OWNERDRAWFIXED | LBS_HASSTRINGS,
			100, 20, 60, 120, hWnd, (HMENU)10001, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("�Ĵ�"));
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("����"));
		SendMessage(hLBox, LB_ADDSTRING, 0, (LPARAM)_T("����"));

		//�����б��
		hMULBox = CreateWindow(L"listbox", NULL,
			WS_CHILD | WS_VISIBLE | LBS_MULTICOLUMN | WS_TABSTOP | WS_BORDER,
			200, 20, 420, 100, hWnd, (HMENU)10003, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		//����ÿ�п��
		SendMessage(hMULBox, LB_SETCOLUMNWIDTH,100, 0);
		//����ÿ������
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
		lpmis->itemHeight = 30;				//����ÿ��item�ĸ߶�
	}
	break;
	case WM_DRAWITEM:
	{
		if (wParam == 10001)
		{
			LPDRAWITEMSTRUCT pDI = (LPDRAWITEMSTRUCT)lParam;
			COLORREF col = RGB(240 + pDI->itemID, 80 * pDI->itemID, 80 * pDI->itemID);
			HBRUSH brush = CreateSolidBrush(col);					//��ˢ
			FillRect(pDI->hDC, &pDI->rcItem, brush);					//ÿ�еľ��δ�С��ˢ�����
			DeleteObject(brush);

			SetBkMode(pDI->hDC, TRANSPARENT);					//���ñ���͸��
			SendMessage(hLBox, LB_GETTEXT, pDI->itemID, (LPARAM)(buf));			//��ȡ�ı�
			const DWORD dwStyle = DT_LEFT | DT_SINGLELINE | DT_NOPREFIX | DT_END_ELLIPSIS;
			DrawText(pDI->hDC, buf, _tcslen(buf), &pDI->rcItem, dwStyle);					//�����ı�
		}
	}
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);				//��λ���ؼ�id
			int eventId = HIWORD(wParam);			//��λ���¼���
			HWND targetHwnd = (HWND)lParam;
            // �����˵�ѡ��: 
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
					//��ȡ��ǰѡ��������
					LRESULT nCurIndex = SendMessage(targetHwnd, LB_GETCURSEL, 0, 0);
					SendMessage(targetHwnd, LB_GETTEXT, nCurIndex, (LPARAM)buf);
					MessageBox(NULL, buf, L"ѡ��", MB_OK);
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
            // TODO: �ڴ˴����ʹ�� hdc ���κλ�ͼ����...
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
