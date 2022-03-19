#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "FreeImage.h"

//srcPicPath  source picture path
//rscWidth    width you want rescale
//rscHeight   height you want rescale
//rscPicPath  rescaled picture save path


int RescalePic(const char *srcPicPath, int rscWidth, int rscHeight, const char *rscPicPath)
{
	if (rscWidth <= 0 || rscHeight <= 0)
		return 423;		//you input a wrong size, the rscWidth/rscHeight must be bigger than zero

	FIBITMAP *sourcePic = NULL, *rescalePic = NULL, *finalPic = NULL;
	FreeImage_Initialise();
	FREE_IMAGE_FORMAT picType = FIF_UNKNOWN;
	picType = FreeImage_GetFileType(srcPicPath, 0);
	if (picType == FIF_UNKNOWN)
	{
		FreeImage_DeInitialise();
		return 421;
	}
	bool typeSupport = FreeImage_FIFSupportsReading(picType);
	if (typeSupport == FALSE)
	{
		FreeImage_DeInitialise();
		return 422;		//not support image type
	}

	sourcePic = FreeImage_Load(picType, srcPicPath, NULL);
	if (!sourcePic)
	{
		FreeImage_DeInitialise();
		return 499;
	}
	double originalWidth, originalHeight;
	unsigned int finalWidth, finalHeight;
	originalWidth = FreeImage_GetWidth(sourcePic);
	originalHeight = FreeImage_GetHeight(sourcePic);
	if (originalWidth*originalHeight == 0)
	{
		FreeImage_Unload(sourcePic);
		sourcePic = NULL;
		FreeImage_DeInitialise();
		return 425;
	}
	//	finalWidth  = rscWidth;
	//	finalHeight = rscHeight;
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
	//	rsc = FreeImage_ConvertToType(src,FIT_BITMAP,true);
	rescalePic = FreeImage_Rescale(sourcePic, finalWidth, finalHeight, FILTER_BOX);//rescale size: 165x130
	if (!rescalePic)
	{
		return FALSE;//
	}
	finalPic = FreeImage_ConvertTo24Bits(rescalePic); //this is important,if no this,the rescaled gif cannot flash
	if (!finalPic)
	{
		FreeImage_Unload(rescalePic);
		rescalePic = NULL;
		return FALSE;//
	}
	int returnValue = 0;
	if (!FreeImage_Save(FIF_JPEG, finalPic, rscPicPath, JPEG_DEFAULT))	//save rescaled picture
		returnValue = 499;
	FreeImage_Unload(sourcePic);
	FreeImage_Unload(rescalePic);
	FreeImage_Unload(finalPic);
	sourcePic = NULL;
	rescalePic = NULL;
	finalPic = NULL;
	FreeImage_DeInitialise();
	return returnValue;
}