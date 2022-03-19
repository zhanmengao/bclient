// LView.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "LView.h"
#include<CommCtrl.h>
#pragma commect(lib,"comctl32.lib")

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;                                // ��ǰʵ��
WCHAR szTitle[MAX_LOADSTRING];                  // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING];            // ����������
bool gbPreeEscKey = false;

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
	LoadStringW(hInstance, IDC_LVIEW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LVIEW));

	MSG msg;

	// ����Ϣѭ��: 
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			if (msg.message == WM_KEYDOWN)
			{
				if (VK_ESCAPE == msg.wParam)
				{
					gbPreeEscKey = true;						//��ʱ����esc
				}
			}
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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LVIEW));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LVIEW);
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
HWND hListView = NULL;

TCHAR strRaw[1024] = { 0 };				//�����ǰ���ı�
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		hListView = CreateWindow(L"SysListView32", NULL,
			WS_CHILD | WS_BORDER | WS_VISIBLE | LVS_REPORT | LVS_EDITLABELS,
			20, 10, 260, 100, hWnd, (HMENU)10000, hInst, NULL);
		//������չ���
		DWORD dwStyle = ListView_GetExtendedListViewStyle(hListView);
		dwStyle |= LVS_EX_FULLROWSELECT;					//ѡ�е��и���
		dwStyle |= LVS_EX_GRIDLINES;						//������
		dwStyle |= LVS_EX_CHECKBOXES;						//itemǰ���ɸ�ѡ��ؼ�
		//������չ���
		ListView_SetExtendedListViewStyleEx(hListView, 0, dwStyle);

		//�����һ����ͷ
		LVCOLUMN colInfo = { 0 };
		colInfo.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_FMT;
		colInfo.iSubItem = 0;
		colInfo.fmt = LVCFMT_CENTER;
		colInfo.cx = 100;
		colInfo.pszText = _T("����");
		colInfo.cchTextMax = 60;
		SendMessage(hListView, LVM_INSERTCOLUMN, 0, (LPARAM)(&colInfo));
		//����ڶ�����ͷ
		colInfo.cx = 50;
		colInfo.pszText = _T("����");
		colInfo.cchTextMax = 20;
		SendMessage(hListView, LVM_INSERTCOLUMN, 1, (LPARAM)(&colInfo));
		//�����һ������
		LVITEM item = { 0 };
		item.mask = LVIF_TEXT;
		item.pszText = _T("����");
		item.iItem = 0;
		item.iSubItem = 0;
		SendMessage(hListView, LVM_INSERTITEM, 0, (LPARAM)(&item));
		item.pszText = _T("31");
		item.iSubItem = 1;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)(&item));
		//����ڶ�������
		item.mask = LVIF_TEXT;
		item.pszText = _T("����");
		item.iItem = 1;
		item.iSubItem = 0;
		SendMessage(hListView, LVM_INSERTITEM, 0, (LPARAM)(&item));
		item.pszText = _T("49");
		item.iSubItem = 1;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)(&item));
		//�������������
		item.mask = LVIF_TEXT;
		item.pszText = _T("����");
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
		// �����˵�ѡ��: 
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
			//�Ƿ���˫���¼�
			if (((LPNMHDR)lParam)->code == NM_DBLCLK)
			{
				//��ȡ��ǰѡ������
				LRESULT result = SendMessage(hListView, LVM_GETNEXTITEM, -1, LVNI_SELECTED);
				if (result == -1)
				{
					MessageBox(hWnd, L"���ĳ��˫��", L"Error", MB_OK | MB_ICONINFORMATION);
					break;
				}
				//Ϊ��ȡ���ı������ṹ
				LVITEM item = { 0 };
				TCHAR text[1024] = { 0 };
				TCHAR itemName[256] = { 0 };
				TCHAR subName[256] = { 0 };
				item.mask = LVIF_TEXT;
				item.iItem = result;
				item.iSubItem = 0;
				item.pszText = text;
				item.cchTextMax = 256;
				//��ȡ���ı�
				SendMessage(hListView, LVM_GETITEMTEXT, result, (LPARAM)(&item));
				//�ݴ�
				_stprintf_s(itemName, text);

				//��ȡ�����ı�
				item.iSubItem = 1;
				SendMessage(hListView, LVM_GETITEMTEXT, result, (LPARAM)(&item));
				//�ݴ�
				_stprintf_s(subName, _T(" %s"), text);
				_tcscat_s(itemName, subName);
				MessageBox(hWnd, itemName, L"Data", MB_OK);
			}
			//�ڿؼ��ﰴ���̣��ᷢ��Ϣ
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
					//ɾ��ָ������
					ListView_DeleteItem(hListView, result);
				}
			}
			//�ж��Ƿ��ǿ�ʼ�༭�¼�
			else if (((LPNMHDR)lParam)->code == LVN_BEGINLABELEDIT)
			{
				HWND hEdit = ListView_GetEditControl(hListView);					//��ȡ����༭�򴰿�

				GetWindowText(hEdit, strRaw, sizeof(strRaw));
			}
			//�ж��Ƿ��ǽ����༭�¼�
			else if(((LPNMHDR)lParam)->code == LVN_ENDLABELEDIT)
			{
				HWND hEdit = ListView_GetEditControl(hListView);					//��ȡ����༭�򴰿�
				int iIndex = 0;
				TCHAR buf[1024] = { 0 };
				//��ȡ��ǰ����
				auto result = SendMessage(hListView, LVM_GETNEXTITEM, -1, LVNI_FOCUSED);
				if (result == -1)
				{
					break;
				}
				LVITEM item = { 0 };
				//�ж��Ƿ���ESC������������Ϊ��ǰ���ı�
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
