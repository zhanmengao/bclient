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

	//��ת
	CxImage smallImage;
	image.Rotate(90, &smallImage);										//��ת90�����ұ��浽smallImage��   
	smallImage.Save(TEXT("browser_rotate.bmp"), CXIMAGE_FORMAT_BMP);

	//����
	{
		CxImage ImgTmp = image;
		if (ImgTmp.Mirror())
		{
			//image.Draw(...., .....);
			ImgTmp.Save(TEXT("browser_Mirror.bmp"), CXIMAGE_FORMAT_BMP);
		}
	}


	//����
	{
		CxImage smallImg;
		RECT rt = { 0 };
		rt.top = 10;
		rt.bottom = 40;
		rt.left = 10;
		rt.right = 40;
		image.Crop(rt, &smallImg);
		smallImg.Save(TEXT("����ͼƬ.tga"), CXIMAGE_FORMAT_TGA);
	}

	//���
	{
		CxImage tempimage;
		tempimage.Mix(image, CxImage::OpAvg, 0, 0, true);
		tempimage.Save(TEXT("Mix���.tga"), CXIMAGE_FORMAT_TGA);
	}

}