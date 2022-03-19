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
	unsigned long imageSize = 0;				//ͼƬ��С���ֽڣ�
	GLbyte *pBits = nullptr;						//ָ�����ص�ָ�루λ��
	GLint iViewport[4];								//�ӿ�
	GLint lastBuffer;								//��ǰ�Ķ�ȡ������

	//��ȡ�ӿڴ�С
	glGetIntegerv(GL_VIEWPORT, iViewport);

	imageSize = iViewport[2] * 3 * iViewport[3];				//rgb ���Դ�СΪ����ֱ���*3

	pBits = (GLbyte *)malloc(imageSize);

	//����ɫ��������ȡλ
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glPixelStorei(GL_PACK_ROW_LENGTH, 0);
	glPixelStorei(GL_PACK_SKIP_ROWS, 0);
	glPixelStorei(GL_PACK_SKIP_PIXELS, 0);

	//ץȡ��ǰ��ȡ���������ò�����
	//�л���ǰ̨���������ж����������ָ���ȡ������״̬
	glGetIntegerv(GL_READ_BUFFER, &lastBuffer);
	glReadBuffer(GL_FRONT);
	glReadPixels(0, 0, iViewport[2], iViewport[3], GL_BGR, GL_UNSIGNED_BYTE, pBits);
	glReadBuffer(lastBuffer);

	free(pBits);
	return 1;
}