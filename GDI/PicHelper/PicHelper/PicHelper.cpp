#include"PicHelper.h"
#include<ShObjIdl.h>
#include <ShlDisp.h>
CImage PicHelper::GetScreenSnap(const RECT * const pRect)
{
	CImage image;
	HDC hDC = NULL;
	HDC hDCMem = NULL;
	HBITMAP hBitMap = NULL;
	HBITMAP hOldMap = NULL;
	unsigned int picWidth = 0;
	unsigned int picHeight = 0;
	do
	{
		hDC = GetDC(NULL);
		if (hDC == NULL)
		{
			break;
		}
		if (pRect != nullptr)
		{
			picWidth = pRect->right - pRect->left;
			picHeight = pRect->bottom - pRect->top;
		}
		else
		{
			picWidth = GetDeviceCaps(hDC, HORZRES);
			picHeight = GetDeviceCaps(hDC, VERTRES);
		}
		hDCMem = CreateCompatibleDC(hDC);
		if (hDCMem == NULL)
		{
			break;
		}
		hBitMap = CreateCompatibleBitmap(hDC, picWidth, picHeight);
		if (hBitMap == NULL)
		{
			break;
		}
		hOldMap = (HBITMAP)SelectObject(hDCMem, hBitMap);
		if (hOldMap == NULL)
		{
			break;
		}
		unsigned short beginX = 0;
		if (pRect != nullptr)
		{
			beginX = pRect->left;
		}
		unsigned short beginY = 0;
		if (pRect != nullptr)
		{
			beginY = pRect->top;
		}
		SetStretchBltMode(hDCMem, HALFTONE);
		if (StretchBlt(hDCMem, 0, 0, picWidth, picHeight,
			hDC, beginX, beginY, picWidth, picHeight, SRCCOPY) == false)
		{
			break;
		}
		image.Attach(hBitMap);
	} while (false);
	if (hDCMem != NULL && hOldMap != NULL)
	{
		SelectObject(hDCMem, hOldMap);
	}
	if (hBitMap != NULL)
	{
		DeleteObject(hBitMap);
	}
	if (hDCMem != NULL)
	{
		DeleteDC(hDCMem);
	}
	if (hDC != NULL)
	{
		DeleteDC(hDC);
	}
	return image;
}
HRESULT PicHelper::GetScreenSnap(const stdstr& picName, const RECT * const pRect)
{
	bool ret = false;
	HDC hDC = NULL;
	HDC hDCMem = NULL;
	HBITMAP hBitMap = NULL;
	HBITMAP hOldMap = NULL;
	unsigned int picWidth = 0;
	unsigned int picHeight = 0;
	do
	{
		hDC = GetDC(NULL);
		if (hDC == NULL)
		{
			break;
		}
		if (pRect != nullptr)
		{
			picWidth = pRect->right - pRect->left;
			picHeight = pRect->bottom - pRect->top;
		}
		else
		{
			picWidth = GetDeviceCaps(hDC, HORZRES);
			picHeight = GetDeviceCaps(hDC, VERTRES);
		}
		hDCMem = CreateCompatibleDC(hDC);
		if (hDCMem == NULL)
		{
			break;
		}
		hBitMap = CreateCompatibleBitmap(hDC, picWidth, picHeight);
		if (hBitMap == NULL)
		{
			break;
		}
		hOldMap = (HBITMAP)SelectObject(hDCMem, hBitMap);
		if (hOldMap == NULL)
		{
			break;
		}
		unsigned short beginX = 0;
		if (pRect != nullptr)
		{
			beginX = pRect->left;
		}
		unsigned short beginY = 0;
		if (pRect != nullptr)
		{
			beginY = pRect->top;
		}
		SetStretchBltMode(hDCMem, HALFTONE);
		if (StretchBlt(hDCMem, 0, 0, picWidth, picHeight,
			hDC, beginX, beginY, picWidth, picHeight, SRCCOPY) == false)
		{
			break;
		}
		CImage image;
		image.Attach(hBitMap);
		ret = image.Save(picName.c_str());
		image.Detach();
	} while (false);
	if (hDCMem != NULL && hOldMap != NULL)
	{
		SelectObject(hDCMem, hOldMap);
	}
	if (hBitMap != NULL)
	{
		DeleteObject(hBitMap);
	}
	if (hDCMem != NULL)
	{
		DeleteDC(hDCMem);
	}
	if (hDC != NULL)
	{
		DeleteDC(hDC);
	}
	return ret;
}

//获取Encoder的CLSID的方法
BOOL PicHelper::GetEncoderClsid(const WCHAR* format, CLSID* pCLSID)
{
	UINT num = 0;
	UINT size = 0;
	Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;
	Gdiplus::GetImageEncodersSize(&num, &size);
	if (size == 0)
		return FALSE;
	pImageCodecInfo = (Gdiplus::ImageCodecInfo *)(malloc(size));
	if (pImageCodecInfo == NULL)
		return FALSE;
	GetImageEncoders(num, size, pImageCodecInfo);
	for (UINT i = 0; i < num; ++i)
	{
		if (wcscmp(pImageCodecInfo[i].MimeType, format) == 0)
		{
			*pCLSID = pImageCodecInfo[i].Clsid;
			free(pImageCodecInfo);
			return TRUE;
		}
	}
	free(pImageCodecInfo);
	return FALSE;
}

bool PicHelper::CompressImagePixel(
	const WCHAR* pszOriFilePath,
	const WCHAR* pszDestFilePah,
	UINT ulNewHeigth,
	UINT ulNewWidth)
{
	// Initialize GDI+.
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::Status stat = Gdiplus::GenericError;
	stat = Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	if (Gdiplus::Ok != stat)
	{
		return false;
	}
	// 重置状态
	stat = Gdiplus::GenericError;

	// Get an image from the disk.
	Gdiplus::Image* pImage = new Gdiplus::Image(pszOriFilePath);

	do
	{
		if (NULL == pImage)
		{
			break;
		}

		// 获取长宽
		UINT unOriHeight = pImage->GetHeight();
		UINT unOriWidth = pImage->GetWidth();

		do
		{
			CLSID encoderClsid;
			if (unOriWidth < 1 || unOriHeight < 1)
			{
				break;
			}

			// Get the CLSID of the JPEG encoder.
			if (!GetEncoderClsid(L"image/jpeg", &encoderClsid))
			{
				break;
			}

			Gdiplus::REAL fSrcX = 0.0f;
			Gdiplus::REAL fSrcY = 0.0f;
			Gdiplus::REAL fSrcWidth = (Gdiplus::REAL)unOriWidth;
			Gdiplus::REAL fSrcHeight = (Gdiplus::REAL)unOriHeight;
			Gdiplus::RectF RectDest(0.0f, 0.0f, (Gdiplus::REAL)ulNewWidth, (Gdiplus::REAL)ulNewHeigth);

			Gdiplus::Bitmap* pTempBitmap = new Gdiplus::Bitmap(ulNewWidth, ulNewHeigth);
			Gdiplus::Graphics* graphics = NULL;

			do
			{
				if (!pTempBitmap)
				{
					break;
				}

				graphics = Gdiplus::Graphics::FromImage(pTempBitmap);
				if (!graphics)
				{
					break;
				}

				stat = graphics->SetInterpolationMode(Gdiplus::InterpolationModeHighQuality);
				if (Gdiplus::Ok != stat)
				{
					break;
				}

				stat = graphics->SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
				if (Gdiplus::Ok != stat)
				{
					break;
				}

				stat = graphics->DrawImage(pImage, RectDest, fSrcX, fSrcY, fSrcWidth, fSrcHeight,
					Gdiplus::UnitPixel, NULL, NULL, NULL);
				if (Gdiplus::Ok != stat)
				{
					break;
				}

				stat = pTempBitmap->Save(pszDestFilePah, &encoderClsid, NULL);
				if (Gdiplus::Ok != stat)
				{
					break;
				}

			} while (0);

			if (NULL != graphics)
			{
				delete graphics;
				graphics = NULL;
			}

			if (NULL != pTempBitmap)
			{
				delete pTempBitmap;
				pTempBitmap = NULL;
			}
		} while (0);
	} while (0);

	if (pImage)
	{
		delete pImage;
		pImage = NULL;
	}

	Gdiplus::GdiplusShutdown(gdiplusToken);

	return ((Gdiplus::Ok == stat) ? true : false);
}

bool PicHelper::CompressImageQuality(
	const WCHAR* pszOriFilePath,
	const WCHAR* pszDestFilePah,
	ULONG quality)
{
	// Initialize GDI+.
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::Status stat = Gdiplus::GenericError;
	stat = GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	if (Gdiplus::Ok != stat)
	{
		return false;
	}

	// 重置状态
	stat = Gdiplus::GenericError;

	// Get an image from the disk.
	Gdiplus::Image* pImage = new Gdiplus::Image(pszOriFilePath);
	do
	{
		if (NULL == pImage)
		{
			break;
		}

		// 获取长宽
		UINT ulHeight = pImage->GetHeight();
		UINT ulWidth = pImage->GetWidth();
		if (ulWidth < 1 || ulHeight < 1)
		{
			break;
		}

		// Get the CLSID of the JPEG encoder.
		CLSID encoderClsid;
		if (!GetEncoderClsid(L"image/jpeg", &encoderClsid))
		{
			break;
		}

		// The one EncoderParameter object has an array of values.
		// In this case, there is only one value (of type ULONG)
		// in the array. We will let this value vary from 0 to 100.
		Gdiplus::EncoderParameters encoderParameters;
		encoderParameters.Count = 1;
		encoderParameters.Parameter[0].Guid = Gdiplus::EncoderQuality;
		encoderParameters.Parameter[0].Type = Gdiplus::EncoderParameterValueTypeLong;
		encoderParameters.Parameter[0].NumberOfValues = 1;
		encoderParameters.Parameter[0].Value = &quality;
		stat = pImage->Save(pszDestFilePah, &encoderClsid, &encoderParameters);
	} while (0);

	if (pImage)
	{
		delete pImage;
		pImage = NULL;
	}

	Gdiplus::GdiplusShutdown(gdiplusToken);

	return ((stat == Gdiplus::Ok) ? true : false);
}

BOOL PicHelper::SetImaeTextDate(const WCHAR* pszOriFilePath, const WCHAR* pszDestFilePah,
	const wchar_t* content, const wchar_t* fontName,
	const Gdiplus::Color& col, unsigned fontSize, Gdiplus::FontStyle style, Gdiplus::Unit unit)
{
	// Initialize GDI+.
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::Status stat = Gdiplus::GenericError;
	stat = GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	if (Gdiplus::Ok != stat)
	{
		return false;
	}
	// 重置状态
	stat = Gdiplus::GenericError;
	Gdiplus::Image* pImage = new Gdiplus::Image(pszOriFilePath);
	do
	{
		if (NULL == pImage)
		{
			break;
		}
		//写字
		Gdiplus::FontFamily fontFamily(fontName);
		Gdiplus::Font font(&fontFamily, fontSize, style, unit);

		CLSID clsid;
		if (!GetEncoderClsid(L"image/jpeg", &clsid))
		{
			break;
		}
		Gdiplus::Graphics imageGraphics(pImage);
		stat = imageGraphics.SetTextRenderingHint(Gdiplus::TextRenderingHintAntiAlias);

		Gdiplus::SolidBrush blackBrush(col);
		Gdiplus::PointF school_site(10.0f, 10.0f);
		Gdiplus::StringFormat format;
		stat = format.SetAlignment(Gdiplus::StringAlignmentNear);

		stat = imageGraphics.DrawString(content, wcslen(content) + 1, &font, school_site, &format, &blackBrush);
		if (stat != Gdiplus::Ok)
		{
			break;
		}

		stat = pImage->Save(pszDestFilePah, &clsid, NULL);
	} while (0);
	if (pImage)
	{
		delete pImage;
		pImage = nullptr;
	}
	Gdiplus::GdiplusShutdown(gdiplusToken);
	return ((stat == Gdiplus::Ok) ? true : false);
}

BOOL PicHelper::Convert(const TCHAR* picPath, const TCHAR* fileExten)
{
	stdstr str(picPath);
	size_t nPos = str.find(_T('.'));
	str = str.substr(0, nPos + 1);
	str += fileExten;
	CImage img;
	if (SUCCEEDED(img.Load(picPath)))
	{
		if (SUCCEEDED(img.Save(str.c_str())))
		{
			return TRUE;
		}
	}

	return FALSE;
}
BOOL PicHelper::Convert2Bmp(const TCHAR* picPath)
{
	return Convert(picPath, _T("bmp"));
}

BOOL PicHelper::Convert2ICO(const TCHAR* picPath)
{
	return Convert(picPath, _T("ico"));
}

HICON PicHelper::GetExeIcon(const TCHAR* exePath)
{
	//提取应用程序中的图标
	return  ::ExtractIcon(GetModuleHandle(NULL), exePath, 0);
}

bool PicHelper::ChangeLinkIcon(const WCHAR* strLnkName, const TCHAR* strIconPath)
{
	HRESULT hres;
	IShellLink *psl = NULL;
	IPersistFile *pPf = NULL;
	int id;
	LPITEMIDLIST pidl;
	bool bRet = false;
	do
	{
		hres = CoInitialize(NULL);
		if (FAILED(hres))
		{
			break;
		}
		hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLinkW, (LPVOID*)&psl);
		if (FAILED(hres))
		{
			break;
		}
		hres = psl->QueryInterface(IID_IPersistFile, (LPVOID*)&pPf);
		if (FAILED(hres))
		{
			break;
		}
		hres = pPf->Load(strLnkName, STGM_READWRITE);
		if (FAILED(hres))
		{
			break;
		}
		hres = psl->SetIconLocation(strIconPath, 0);
		if (FAILED(hres))
		{
			break;
		}
		pPf->Save(strLnkName, TRUE);
		if (FAILED(hres))
		{
			break;
		}
		bRet = true;
	} while (0);
	if (pPf != NULL)
	{
		pPf->Release();
	}
	if (psl != NULL)
	{
		psl->Release();
	}
	CoUninitialize();
	return bRet;
}