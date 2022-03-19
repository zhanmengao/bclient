#include<ximaico.h>
#include<ximage.h>
#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib, "User32.lib")

void main()
{
	CxImage image;
	if (image.Load(
		TEXT("D:\\Space\\Paint\\FreeImage\\FreeImageUtils\\FreeImageUtils\\browser.ico"), CXIMAGE_FORMAT_ICO))
	{
		image.Save(TEXT("browser.bmp"), CXIMAGE_FORMAT_BMP);
	}

	//Ðý×ª
	CxImage smallImage;
	image.Rotate(90, &smallImage);										//Ðý×ª90£¬²¢ÇÒ±£´æµ½smallImageÖÐ   
	smallImage.Save(TEXT("browser_rotate.bmp"), CXIMAGE_FORMAT_BMP);

	//¾µÏñ
	{
		CxImage ImgTmp = image;
		if (ImgTmp.Mirror())
		{
			//image.Draw(...., .....);
			ImgTmp.Save(TEXT("browser_Mirror.bmp"), CXIMAGE_FORMAT_BMP);
		}
	}


	//¼ô¼­
	{
		CxImage smallImg;
		RECT rt = { 0 };
		rt.top = 10;
		rt.bottom = 40;
		rt.left = 10;
		rt.right = 40;
		image.Crop(rt, &smallImg);
		smallImg.Save(TEXT("¼ô¼­Í¼Æ¬.tga"), CXIMAGE_FORMAT_TGA);
	}

	//»ìºÏ
	{
		CxImage tempimage;
		tempimage.Mix(image, CxImage::OpAvg, 0, 0, true);
		tempimage.Save(TEXT("Mix»ìºÏ.tga"), CXIMAGE_FORMAT_TGA);
	}

}