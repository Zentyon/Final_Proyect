#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messagebox
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	string aviso = "Floppa la pelicula";
	int msgboxID = MessageBox(
        NULL,
        aviso.c_str(),
        "AVISO IMPORTANTE",
        MB_ICONASTERISK
    );
	return 0;
}