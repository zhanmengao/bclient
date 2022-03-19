#include"FreeImage.h"
#include<Windows.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
#include"Other.h"
void main()
{
	BOOL bRet;
	DWORD dwRet = 0;
	{
		FreeImage img;
		img.Load("D:\\Space\\Paint\\QT\\resources\\browser.png");
		bRet = img.Save(FREE_IMAGE_FORMAT::FIF_ICO, 
			"C:\\Users\\Administrator\\Documents\\VECloudAPP\\AppICO\\browser.ico");
	}

	{
		//RescalePic("C:\\Users\\Administrator\\Documents\\VECloudAPP\\AppICO\\nlvvrngfpvlwnuxa.jpg", 64, 64, "C:\\Users\\Administrator\\Documents\\VECloudAPP\\AppICO\\nlvvrngfpvlwnuxa.png");
	}
	{
		FreeImage img;
		img.Load("C:\\Users\\Administrator\\Documents\\VECloudAPP\\AppICO\\nlvvrngfpvlwnuxa.jpg");
		printf("w = %u h = %u \n", img.Width(), img.Height());
		img.Scale(64, 64);
		bRet = img.Save(FREE_IMAGE_FORMAT::FIF_ICO, 
			"C:\\Users\\Administrator\\Documents\\VECloudAPP\\AppICO\\nlvvrngfpvlwnuxa.ico");
		dwRet = errno;
		bRet = img.Save(FREE_IMAGE_FORMAT::FIF_PNG, 
			"C:\\Users\\Administrator\\Documents\\VECloudAPP\\AppICO\\nlvvrngfpvlwnuxa.png");
	}

	{
		FreeImage img;
		img.Load("C:\\Users\\Administrator\\Documents\\VECloudAPP\\AppICO\\litnbdurqjgklcwo.bmp");
		printf("w = %u h = %u \n", img.Width(), img.Height());
		img.Scale(64, 64);
		bRet = img.Save(FREE_IMAGE_FORMAT::FIF_ICO,
			"C:\\Users\\Administrator\\Documents\\VECloudAPP\\AppICO\\litnbdurqjgklcwo.ico");
		dwRet = errno;
		bRet = img.Save(FREE_IMAGE_FORMAT::FIF_PNG,
			"C:\\Users\\Administrator\\Documents\\VECloudAPP\\AppICO\\litnbdurqjgklcwo.png");
	}

	{
		FreeImage img;
		img.Load("D:\\Space\\Network\\RDP\\CDesktopVAPPICO\\Release\\res\\LOGO.bmp");
		printf("w = %u h = %u \n", img.Width(), img.Height());

		bRet = img.Save(FREE_IMAGE_FORMAT::FIF_PNG,
			"D:\\Space\\Network\\RDP\\CDesktopVAPPICO\\Release\\res\\LOGO_256.png");

		FreeImage img150;
		img.Scale(150, 150, img150);
		bRet = img150.Save(FREE_IMAGE_FORMAT::FIF_PNG,
			"D:\\Space\\Network\\RDP\\CDesktopVAPPICO\\Release\\res\\LOGO_150.png");

		FreeImage img128;
		img.Scale(128, 128, img128);
		bRet = img128.Save(FREE_IMAGE_FORMAT::FIF_PNG,
			"D:\\Space\\Network\\RDP\\CDesktopVAPPICO\\Release\\res\\LOGO_128.png");

		FreeImage img70;
		img.Scale(70, 70, img70);
		bRet = img70.Save(FREE_IMAGE_FORMAT::FIF_PNG,
			"D:\\Space\\Network\\RDP\\CDesktopVAPPICO\\Release\\res\\LOGO_70.png");

		FreeImage img64;
		img.Scale(64, 64, img64);
		bRet = img64.Save(FREE_IMAGE_FORMAT::FIF_PNG,
			"D:\\Space\\Network\\RDP\\CDesktopVAPPICO\\Release\\res\\LOGO_64.png");

		FreeImage img48;
		img.Scale(48, 48, img48);
		bRet = img48.Save(FREE_IMAGE_FORMAT::FIF_PNG,
			"D:\\Space\\Network\\RDP\\CDesktopVAPPICO\\Release\\res\\LOGO_48.png");

		FreeImage img32;
		img.Scale(32, 32, img32);
		bRet = img32.Save(FREE_IMAGE_FORMAT::FIF_PNG,
			"D:\\Space\\Network\\RDP\\CDesktopVAPPICO\\Release\\res\\LOGO_32.png");

		FreeImage img24;
		img.Scale(24, 24, img24);
		bRet = img24.Save(FREE_IMAGE_FORMAT::FIF_PNG,
			"D:\\Space\\Network\\RDP\\CDesktopVAPPICO\\Release\\res\\LOGO_24.png");

		FreeImage img16;
		img.Scale(16,16, img16);
		bRet = img16.Save(FREE_IMAGE_FORMAT::FIF_PNG,
			"D:\\Space\\Network\\RDP\\CDesktopVAPPICO\\Release\\res\\LOGO_16.png");
	}

	system("pause");
}