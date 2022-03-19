#pragma once

#include "resource.h"
#include<CommCtrl.h>
TCHAR iBuf[16] = { 0 };
INT_PTR ret = 0;
HWND hDlgModeless = NULL;				//是否已创建非模态对话框
bool bOK = false;
//模态dialog消息函数
INT_PTR CALLBACK DiglogWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		SetWindowPos(hwnd, NULL, 50, 100, 0, 0, SWP_NOSIZE);					//创建的时候调整位置
		return TRUE;																//已处理的消息返回TRUE
	case WM_COMMAND:
	{
		auto lp = LOWORD(wParam);
		if (lp == IDOK)
		{
			EndDialog(hwnd, TRUE);							//模态对话框结束关闭
			return TRUE;											//消息已经处理了
		}
		else if (lp == IDCANCEL)
		{
			EndDialog(hwnd, FALSE);							//模态对话框结束关闭
			return TRUE;											//消息已经处理了
		}
	}
	break;
	}
	return FALSE;				//消息没有被处理，返回false交给父窗口继续处理
}
//非模态对话框消息处理函数
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		SetWindowPos(hwnd, NULL, 200, 200, 0, 0, SWP_NOSIZE);					//创建的时候调整位置
		return TRUE;																							//表示已经初始化
	case WM_COMMAND:
	{
		auto lp = LOWORD(wParam);
		if (lp == IDOK)
		{
			bOK = true;
			DestroyWindow(hwnd);
			return TRUE;											//消息已经处理了
		}
		else if (lp == IDCANCEL)
		{
			bOK = false;
			DestroyWindow(hwnd);
			return TRUE;											//消息已经处理了
		}
	}
	break;
	case WM_DESTROY:
		hDlgModeless = NULL;
		return TRUE;
	}
	return FALSE;				//消息没有被处理，返回false交给父窗口继续处理
}

TV_INSERTSTRUCT tvinsert;			//要插入节点的信息结构体
HTREEITEM hParent;								//树形控件节点父句柄
												//模态Treedialog消息函数
INT_PTR CALLBACK DiglogTreeProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		SetWindowPos(hwnd, NULL, 50, 100, 0, 0, SWP_NOSIZE);					//创建的时候调整位置
		HWND hTreeView = GetDlgItem(hwnd, IDC_TREE1);						//获取树形控件句柄
																			//初始化根节点数据
		tvinsert.hParent = NULL;
		tvinsert.hInsertAfter = TVI_ROOT;					//表示这是一个根节点
		tvinsert.item.mask = TVIF_TEXT;
		tvinsert.item.pszText = _T("亚洲");
		tvinsert.item.iImage = 0;
		tvinsert.item.iSelectedImage = 0;
		//向树形控件发送消息插入节点
		hParent = (HTREEITEM)SendMessage(hTreeView, TVM_INSERTITEM, 0, (LPARAM)&tvinsert);

		tvinsert.hParent = hParent;						//上面插入的节点做父节点
		tvinsert.hInsertAfter = TVI_LAST;					//在末尾插入节点
		tvinsert.item.pszText = _T("中国");
		SendMessage(hTreeView, TVM_INSERTITEM, 0, (LPARAM)&tvinsert);
		tvinsert.item.pszText = _T("日本");
		SendMessage(hTreeView, TVM_INSERTITEM, 0, (LPARAM)&tvinsert);
		tvinsert.item.pszText = _T("韩国");
		SendMessage(hTreeView, TVM_INSERTITEM, 0, (LPARAM)&tvinsert);
		tvinsert.item.pszText = _T("朝鲜");
		SendMessage(hTreeView, TVM_INSERTITEM, 0, (LPARAM)&tvinsert);
		return TRUE;																//已处理的消息返回TRUE
	}
	break;
	case WM_COMMAND:
	{
		auto lp = LOWORD(wParam);
		if (lp == IDOK)
		{
			EndDialog(hwnd, TRUE);							//模态对话框结束关闭
			return TRUE;											//消息已经处理了
		}
		else if (lp == IDCANCEL)
		{
			EndDialog(hwnd, FALSE);							//模态对话框结束关闭
			return TRUE;											//消息已经处理了
		}
	}
	break;
	}
	return FALSE;				//消息没有被处理，返回false交给父窗口继续处理
}