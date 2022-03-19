#pragma once

#include "resource.h"
#include<commdlg.h>
#include<string>

static DWORD rgbCurrent; 								//当前颜色
static HFONT hFont;											//当前字体
COLORREF ChooseClrDlg(HWND hOwner)
{
	CHOOSECOLOR dlgClr = { 0 };									//定义颜色选择对话框
	static COLORREF acrCustClr[16] = { 0 };			//颜色对话框下方有16个自定义颜色，它们需要存储空间

	dlgClr.lStructSize = sizeof(dlgClr);
	dlgClr.hwndOwner = hOwner;
	dlgClr.lpCustColors = (LPDWORD)acrCustClr;
	dlgClr.rgbResult = rgbCurrent;
	dlgClr.Flags = CC_FULLOPEN | CC_RGBINIT;
	//如果单击确定，则返回选定的颜色
	if (ChooseColor(&dlgClr))
	{
		rgbCurrent = dlgClr.rgbResult;
		return dlgClr.rgbResult;
	}
	else
	{
		return 0;
	}
}


static LOGFONT lf = { 0 };
HFONT hfontPrev;
CHOOSEFONT MChooseFont(HWND hwnd)
{
	CHOOSEFONT cf = { 0 };
	cf.lStructSize = sizeof(cf);
	cf.hwndOwner = hwnd;					//设置对话框句柄为其拥有者句柄
	cf.lpLogFont = &lf;							//指向一个逻辑字体
	cf.rgbColors = rgbCurrent;					//字体颜色
	cf.Flags = CF_SCREENFONTS | CF_EFFECTS;					//设置字体对话框选项
	if (ChooseFont(&cf))
	{
		hFont = CreateFontIndirect(cf.lpLogFont);
	}
	return cf;
}

std::wstring ChooseFile(HWND hwnd)
{
	TCHAR szFile[MAX_PATH] = { 0 };
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFile = szFile;					//设置文件名字缓冲区
	ofn.lpstrFile[0] = '\0';					//如果不设置0，则开始的时候就会默认选择szFile
	ofn.nMaxFile = MAX_PATH;			//文件路径缓冲区大小
	ofn.lpstrFilter = _T("所有文件\0*.*\0文本文档\0*.TXT\0\0");					//设置过滤字符串
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = _T("C:");						//默认路径
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;			//设置标记
	if (GetOpenFileName(&ofn))
	{
		return ofn.lpstrFile;
	}
	else
	{
		return L"";
	}
}

std::wstring SaveFile(HWND hwnd)
{
	TCHAR szFile[MAX_PATH] = { 0 };
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFile = szFile;					//设置文件名字缓冲区
	ofn.lpstrFile[0] = '\0';					//如果不设置0，则开始的时候就会默认选择szFile
	ofn.nMaxFile = MAX_PATH;			//文件路径缓冲区大小
	ofn.lpstrFilter = _T("所有文件\0*.*\0文本文档\0*.TXT\0\0");					//设置过滤字符串
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = _T("C:");						//默认路径
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;			//设置标记
	if (GetSaveFileName(&ofn))
	{
		return ofn.lpstrFile;
	}
	else
	{
		return L"";
	}
}


void OpenPrint(HWND hwnd)
{
	PRINTDLG pd = { 0 };
	pd.lStructSize = sizeof(pd);
	pd.hwndOwner = hwnd;
	pd.hDevMode = NULL;
	pd.hDevNames = NULL;
	pd.Flags = PD_USEDEVMODECOPIESANDCOLLATE | PD_RETURNDC;
	pd.nCopies = 1;					//打印一份
	pd.nFromPage = 1;					//设置打印起始页
	pd.nToPage = 10;					//设置打印结束页号
	pd.nMinPage = 1;
	pd.nMaxPage = 0xFFFF;
	if (PrintDlg(&pd))
	{
		//开始实际打印...
		DeleteDC(pd.hDC);				//打印完要删除DC
	}
}