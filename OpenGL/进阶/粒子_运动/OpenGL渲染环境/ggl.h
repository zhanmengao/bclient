#pragma once

#include <windows.h>
#include "glew.h"
#include <GL/GL.h>
#include <GL/GLU.h>
#include <gl/glext.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <tchar.h>
#include <functional>
#include "Glm/glm.hpp"
#include "Glm/ext.hpp"

using namespace std;
using namespace glm;

#define WINDOW_WIDTH	800							//为窗口宽度定义的宏，以方便在此处修改窗口宽度
#define WINDOW_HEIGHT	600							//为窗口高度定义的宏，以方便在此处修改窗口高度
#define WINDOW_TITLE	L"梦幻西游"	//为窗口标题定义的宏

#define INVALID (-1)
#define _INVALID_ID_ (0)
#define _INVALID_LOCATION_ (-1)

#define ASSERT_PTR_BOOL(p) if(p==nullptr){return 0;}

#define ASSERT_INT_BOOL(i) if(i==_INVALID_ID_){return 0;}

#define ASSERT_INT_VOID(i) if(i==_INVALID_ID_){return ;}

#define ARRLEN(arr) sizeof(arr)/sizeof(arr[0])


#define BEGIN 	VBO_NAME.Begin();{SHADER_NAME.Begin();{SHADER_NAME.Bind(glm::value_ptr(MODELMATRIX_NAME), glm::value_ptr(VIEWMATRIX_NAME), glm::value_ptr(PROJECTIONMATRIX_NAME));
#define END 		}SHADER_NAME.End();}VBO_NAME.End();
#define DRAW  { glDrawArrays(GL_TRIANGLES,0,VBO_NAME.GetLenth());}

#define DRAW_MODEL BEGIN DRAW END

#define VBO_NAME m_VertexBuf
#define SHADER_NAME m_Shader
#define MODELMATRIX_NAME m_ModelMatrix
#define VIEWMATRIX_NAME viewMatrix
#define PROJECTIONMATRIX_NAME ProjectionMatrix

#define SHADER_ROOT "ShaderSource/up/"