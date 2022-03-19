#include"PicHelper.h"

#define PIC_NAME _T("aaa.jpg")
#define PIC_PIXEL_NAME _T("bbb.jpg")
#define PIC_QUAL_NAME _T("ccc.jpg")
#define PIC_TEXT_NAME _T("ddd.jpg")
void main()
{
	PicHelper::GetScreenSnap(PIC_NAME);

	PicHelper::CompressImagePixel(PIC_NAME, PIC_PIXEL_NAME, 200, 200);

	PicHelper::CompressImageQuality(PIC_NAME, PIC_QUAL_NAME, 10);

	BOOL bRet = PicHelper::SetImaeTextDate(PIC_NAME, PIC_TEXT_NAME, L"QQAQAQA1E11341");

	bRet = PicHelper::Convert2ICO(_T("C:\\Users\\Administrator\\Documents\\VECloudAPP\\AppICO\\litnbdurqjgklcwo.jpg"));
	DWORD dwRet = GetLastError();
	system("pause");
}