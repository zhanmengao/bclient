#pragma once
#include"../../../../lib/gl/lib/freeImage/FreeImage.h"
#pragma comment(lib,"FreeImage.lib")
class FreeImage
{
public:
	FreeImage()
	{

	}
	FreeImage(const char* filePath)
	{
		Load(filePath);
	}
	~FreeImage()
	{
		Free();
	}
	BOOL Load(const char* filePath)
	{
		FreeImage_Initialise();
		//1 获取图片格式
		FREE_IMAGE_FORMAT fifmt = FreeImage_GetFileType(filePath, 0);
		//2 加载图片
		pImage = FreeImage_Load(fifmt, filePath, 0);
		return pImage != nullptr;
	}
	BOOL Save(FREE_IMAGE_FORMAT fif,const char* filePath)
	{
		if (pImage)
		{
			return FreeImage_Save(fif, pImage, filePath);
		}
		return 0;
	}
	BOOL Scale(unsigned rscWidth, unsigned rscHeight, FreeImage& rescalePic)
	{
		double originalWidth, originalHeight;
		unsigned int finalWidth, finalHeight;
		originalWidth = FreeImage_GetWidth(pImage);
		originalHeight = FreeImage_GetHeight(pImage);
		if (originalWidth*originalHeight == 0)
		{
			return FALSE;
		}
		if (originalWidth <= rscWidth && originalHeight <= rscHeight)
		{
			finalWidth = originalWidth;
			finalHeight = originalHeight;
		}
		else
		{
			if (rscWidth * (originalHeight / originalWidth) > rscHeight)
			{
				finalWidth = rscHeight * (originalWidth / originalHeight);
				finalHeight = rscHeight;
			}
			else
			{
				finalWidth = rscWidth;
				finalHeight = rscWidth * (originalHeight / originalWidth);
			}
		}
		rescalePic.pImage = FreeImage_Rescale(pImage, finalWidth, finalHeight, FILTER_BOX);
		if (!rescalePic.pImage)
		{
			return FALSE;
		}
		return TRUE;
	}
	BOOL Scale(unsigned rscWidth, unsigned rscHeight)
	{
		FreeImage pic;
		BOOL bRet = Scale(rscWidth, rscHeight, pic);
		//交换两个资源指针，栈变量离开函数后被析构
		auto pData = pImage;
		pImage = pic.PImage();
		pic.pImage = pData;
		return bRet;
	}
	unsigned Width() const
	{
		if (pImage)
		{
			return FreeImage_GetWidth(pImage);
		}
		return 0;
	}
	unsigned Height() const
	{
		if (pImage)
		{
			return FreeImage_GetHeight(pImage);
		}
		return 0;
	}
	BYTE* Data()
	{
		if (pImage)
		{
			return FreeImage_GetBits(pImage);
		}
		return nullptr;
	}
	FIBITMAP* PImage()
	{
		return pImage;
	}
	void Free()
	{
		if (pImage)
		{
			FreeImage_Unload(pImage);
			pImage = nullptr;
		}
	}
private:
	FIBITMAP* pImage;
};