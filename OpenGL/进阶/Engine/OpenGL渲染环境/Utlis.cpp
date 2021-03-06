#include "Utils.h"
#include "SOIL.h"



unsigned char* DecodeBMP(unsigned char* bmpFileData, int& width, int& height)
{
	//如果文件头是0X4D42 说明是BMP文件
	if (0x4D42 == *((unsigned short*)bmpFileData))
	{
		int pixelDataOffset = (*(int*)(bmpFileData + 10));								//像素数据的偏移值
		width = (*(int*)(bmpFileData + 18));													//图片宽
		height = (*(int*)(bmpFileData + 22));													//图片高
		unsigned char* pixelData = bmpFileData + pixelDataOffset;						//像素数据起始地址
		//由BGR->RGB
		for (int i = 0; i < width*height * 3; i += 3)
		{
			unsigned char temp = pixelData[i];						//b
			pixelData[i] = pixelData[i + 2];								//b=r
			pixelData[i + 2] = temp;												//r=b
		}
		return pixelData;
	}
	return nullptr;
}


//读一个文件 返回其在内存中的指针、文件长度
bool LoadFileContent(const char* path, int& filesize, char* content)
{
	if (content == nullptr)
	{
		return 0;
	}
	filesize = 0;
	FILE* pFile = fopen(path, "rb");
	//按二进制打开文件，只读
	if (pFile)
	{
		fseek(pFile, 0, SEEK_END);//移动到文件尾
		int nLen = ftell(pFile);
		if (nLen > 0)
		{
			rewind(pFile);//移到文件头部
			fread(content, sizeof(unsigned char), nLen, pFile);
			content[nLen] = '\0';
			filesize = nLen;
		}
		fclose(pFile);
		return 1;
	}
	return 0;
}

void Debug(const char* fmt, ...)
{
	va_list ap;
	const char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);// ap point head

	for (p = fmt; (*p); p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 's':
			for (sval = va_arg(ap, char*); *sval; sval++)
			{
				putchar(*sval);
			}
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		default:
			break;
		}
	}
	va_end(ap);
}