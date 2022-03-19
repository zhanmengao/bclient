#pragma once
#include <GLTools.h>
#include <GLShaderManager.h>
#include <GLFrustum.h>
#include <GLBatch.h>
#include <GLMatrixStack.h>
#include <GLGeometryTransform.h>
#include <StopWatch.h>
#include <math.h>
#include <stdio.h>

#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif


#pragma  comment(lib,"freeglut_static.lib")
#pragma  comment(lib,"gltools.lib")

GLint gltWriteTGA(const char* szFileName)
{
	unsigned long imageSize = 0;				//图片大小（字节）
	GLbyte *pBits = nullptr;						//指向像素的指针（位）
	GLint iViewport[4];								//视口
	GLint lastBuffer;								//当前的读取缓冲区

	//获取视口大小
	glGetIntegerv(GL_VIEWPORT, iViewport);

	imageSize = iViewport[2] * 3 * iViewport[3];				//rgb 所以大小为桌面分辨率*3

	pBits = (GLbyte *)malloc(imageSize);

	//从颜色缓冲区读取位
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glPixelStorei(GL_PACK_ROW_LENGTH, 0);
	glPixelStorei(GL_PACK_SKIP_ROWS, 0);
	glPixelStorei(GL_PACK_SKIP_PIXELS, 0);

	//抓取当前读取缓冲区设置并保存
	//切换到前台缓冲区进行读操作，最后恢复读取缓冲区状态
	glGetIntegerv(GL_READ_BUFFER, &lastBuffer);
	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, iViewport[2], iViewport[3], GL_BGR, GL_UNSIGNED_BYTE, pBits);
	glReadBuffer(lastBuffer);

	free(pBits);
	return 1;
}