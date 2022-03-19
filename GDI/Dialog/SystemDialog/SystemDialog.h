#pragma once

#include "resource.h"
#include<commdlg.h>
#include<string>

static DWORD rgbCurrent; 								//��ǰ��ɫ
static HFONT hFont;											//��ǰ����
COLORREF ChooseClrDlg(HWND hOwner)
{
	CHOOSECOLOR dlgClr = { 0 };									//������ɫѡ��Ի���
	static COLORREF acrCustClr[16] = { 0 };			//��ɫ�Ի����·���16���Զ�����ɫ��������Ҫ�洢�ռ�

	dlgClr.lStructSize = sizeof(dlgClr);
	dlgClr.hwndOwner = hOwner;
	dlgClr.lpCustColors = (LPDWORD)acrCustClr;
	dlgClr.rgbResult = rgbCurrent;
	dlgClr.Flags = CC_FULLOPEN | CC_RGBINIT;
	//�������ȷ�����򷵻�ѡ������ɫ
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
	cf.hwndOwner = hwnd;					//���öԻ�����Ϊ��ӵ���߾��
	cf.lpLogFont = &lf;							//ָ��һ���߼�����
	cf.rgbColors = rgbCurrent;					//������ɫ
	cf.Flags = CF_SCREENFONTS | CF_EFFECTS;					//��������Ի���ѡ��
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
	ofn.lpstrFile = szFile;					//�����ļ����ֻ�����
	ofn.lpstrFile[0] = '\0';					//���������0����ʼ��ʱ��ͻ�Ĭ��ѡ��szFile
	ofn.nMaxFile = MAX_PATH;			//�ļ�·����������С
	ofn.lpstrFilter = _T("�����ļ�\0*.*\0�ı��ĵ�\0*.TXT\0\0");					//���ù����ַ���
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = _T("C:");						//Ĭ��·��
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;			//���ñ��
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
	ofn.lpstrFile = szFile;					//�����ļ����ֻ�����
	ofn.lpstrFile[0] = '\0';					//���������0����ʼ��ʱ��ͻ�Ĭ��ѡ��szFile
	ofn.nMaxFile = MAX_PATH;			//�ļ�·����������С
	ofn.lpstrFilter = _T("�����ļ�\0*.*\0�ı��ĵ�\0*.TXT\0\0");					//���ù����ַ���
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = _T("C:");						//Ĭ��·��
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;			//���ñ��
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
	pd.nCopies = 1;					//��ӡһ��
	pd.nFromPage = 1;					//���ô�ӡ��ʼҳ
	pd.nToPage = 10;					//���ô�ӡ����ҳ��
	pd.nMinPage = 1;
	pd.nMaxPage = 0xFFFF;
	if (PrintDlg(&pd))
	{
		//��ʼʵ�ʴ�ӡ...
		DeleteDC(pd.hDC);				//��ӡ��Ҫɾ��DC
	}
}