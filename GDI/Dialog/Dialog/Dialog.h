#pragma once

#include "resource.h"
#include<CommCtrl.h>
TCHAR iBuf[16] = { 0 };
INT_PTR ret = 0;
HWND hDlgModeless = NULL;				//�Ƿ��Ѵ�����ģ̬�Ի���
bool bOK = false;
//ģ̬dialog��Ϣ����
INT_PTR CALLBACK DiglogWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		SetWindowPos(hwnd, NULL, 50, 100, 0, 0, SWP_NOSIZE);					//������ʱ�����λ��
		return TRUE;																//�Ѵ������Ϣ����TRUE
	case WM_COMMAND:
	{
		auto lp = LOWORD(wParam);
		if (lp == IDOK)
		{
			EndDialog(hwnd, TRUE);							//ģ̬�Ի�������ر�
			return TRUE;											//��Ϣ�Ѿ�������
		}
		else if (lp == IDCANCEL)
		{
			EndDialog(hwnd, FALSE);							//ģ̬�Ի�������ر�
			return TRUE;											//��Ϣ�Ѿ�������
		}
	}
	break;
	}
	return FALSE;				//��Ϣû�б���������false���������ڼ�������
}
//��ģ̬�Ի�����Ϣ������
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		SetWindowPos(hwnd, NULL, 200, 200, 0, 0, SWP_NOSIZE);					//������ʱ�����λ��
		return TRUE;																							//��ʾ�Ѿ���ʼ��
	case WM_COMMAND:
	{
		auto lp = LOWORD(wParam);
		if (lp == IDOK)
		{
			bOK = true;
			DestroyWindow(hwnd);
			return TRUE;											//��Ϣ�Ѿ�������
		}
		else if (lp == IDCANCEL)
		{
			bOK = false;
			DestroyWindow(hwnd);
			return TRUE;											//��Ϣ�Ѿ�������
		}
	}
	break;
	case WM_DESTROY:
		hDlgModeless = NULL;
		return TRUE;
	}
	return FALSE;				//��Ϣû�б���������false���������ڼ�������
}

TV_INSERTSTRUCT tvinsert;			//Ҫ����ڵ����Ϣ�ṹ��
HTREEITEM hParent;								//���οؼ��ڵ㸸���
												//ģ̬Treedialog��Ϣ����
INT_PTR CALLBACK DiglogTreeProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		SetWindowPos(hwnd, NULL, 50, 100, 0, 0, SWP_NOSIZE);					//������ʱ�����λ��
		HWND hTreeView = GetDlgItem(hwnd, IDC_TREE1);						//��ȡ���οؼ����
																			//��ʼ�����ڵ�����
		tvinsert.hParent = NULL;
		tvinsert.hInsertAfter = TVI_ROOT;					//��ʾ����һ�����ڵ�
		tvinsert.item.mask = TVIF_TEXT;
		tvinsert.item.pszText = _T("����");
		tvinsert.item.iImage = 0;
		tvinsert.item.iSelectedImage = 0;
		//�����οؼ�������Ϣ����ڵ�
		hParent = (HTREEITEM)SendMessage(hTreeView, TVM_INSERTITEM, 0, (LPARAM)&tvinsert);

		tvinsert.hParent = hParent;						//�������Ľڵ������ڵ�
		tvinsert.hInsertAfter = TVI_LAST;					//��ĩβ����ڵ�
		tvinsert.item.pszText = _T("�й�");
		SendMessage(hTreeView, TVM_INSERTITEM, 0, (LPARAM)&tvinsert);
		tvinsert.item.pszText = _T("�ձ�");
		SendMessage(hTreeView, TVM_INSERTITEM, 0, (LPARAM)&tvinsert);
		tvinsert.item.pszText = _T("����");
		SendMessage(hTreeView, TVM_INSERTITEM, 0, (LPARAM)&tvinsert);
		tvinsert.item.pszText = _T("����");
		SendMessage(hTreeView, TVM_INSERTITEM, 0, (LPARAM)&tvinsert);
		return TRUE;																//�Ѵ������Ϣ����TRUE
	}
	break;
	case WM_COMMAND:
	{
		auto lp = LOWORD(wParam);
		if (lp == IDOK)
		{
			EndDialog(hwnd, TRUE);							//ģ̬�Ի�������ر�
			return TRUE;											//��Ϣ�Ѿ�������
		}
		else if (lp == IDCANCEL)
		{
			EndDialog(hwnd, FALSE);							//ģ̬�Ի�������ر�
			return TRUE;											//��Ϣ�Ѿ�������
		}
	}
	break;
	}
	return FALSE;				//��Ϣû�б���������false���������ڼ�������
}