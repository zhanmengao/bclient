#include <Windows.h>
#include <tchar.h>
#include<vector>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(NULL, TEXT("helloWin32"), TEXT("My MessageBox"), 0);
	Sleep(2000);
	MessageBox(NULL, TEXT("helloWin32"), TEXT("My MessageBox"), 0);
	return 0;
}