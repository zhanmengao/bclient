#pragma once
#include<Windows.h>
#include<Gdiplus.h>
#include<atlimage.h>
#include<string>
#include"../../../../C++space/StringTools/StringTools/StringHead.h"
#pragma comment(lib, "gdiplus.lib")


class PicHelper
{
public:
	static HRESULT GetScreenSnap(const stdstr& picName, const RECT * const pRect = nullptr);

	static bool CompressImagePixel(
		const WCHAR* pszOriFilePath,
		const WCHAR* pszDestFilePah,
		UINT ulNewHeigth,
		UINT ulNewWidth);

	static bool CompressImageQuality(
		const WCHAR* pszOriFilePath,
		const WCHAR* pszDestFilePah,
		ULONG quality);
	static BOOL SetImaeTextDate(const WCHAR* pszOriFilePath,const WCHAR* pszDestFilePah, 
		const wchar_t* content, const wchar_t* fontName = L"Î¢ÈíÑÅºÚ",
		const Gdiplus::Color& col = Gdiplus::Color::Black,
		unsigned fontSize = 20, Gdiplus::FontStyle style = Gdiplus::FontStyle::FontStyleRegular,Gdiplus::Unit unit = Gdiplus::Unit::UnitPoint);
	static HICON GetExeIcon(const TCHAR* exePath);
	static BOOL Convert2Bmp(const TCHAR* picPath);
	static BOOL Convert2ICO(const TCHAR* picPath);
	static bool ChangeLinkIcon(const WCHAR* strLnkName, const TCHAR* strIconPath);
private:
	static BOOL GetEncoderClsid(const WCHAR* format, CLSID* pCLSID);
	static CImage GetScreenSnap(const RECT * const pRect = nullptr);
	static BOOL Convert(const TCHAR* picPath, const TCHAR* fileExten);
};

