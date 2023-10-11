#include <graphics.h>
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#define pi 3.14

DWORD WINAPI draw1(LPVOID)
{
	for (int i = 0; i < 180; i++)
	{
		putpixel(50 + i, 50, WHITE);
		Sleep(30);
	}
	for (int i = 0; i < 180; i++)
	{
		putpixel(50 + 180, 50 + i, WHITE);
		Sleep(30);
	}
	for (int i = 0; i < 180; i++)
	{
		putpixel(50 + 180 - i, 50 + 180, WHITE);
		Sleep(30);
	}
	for (int i = 0; i < 180; i++)
	{
		putpixel(50, 50 + 180 - i, WHITE);
		Sleep(30);
	}
	return 0;
}

DWORD WINAPI draw2(LPVOID)
{
	for (int i = 0; i < 720; i++)
	{
		putpixel(350 + 100 * cos(-pi / 2 + (double)((i * pi) / 360)), 140 + 100 * sin(-pi / 2 + (double)((i * pi) / 360)), WHITE);
		Sleep(30);
	}
	return 0;
}
int main()
{
	initgraph(900, 700);
	HANDLE hThread[2];
	DWORD threadID;
	hThread[0] = CreateThread(NULL, 0, draw1, 0, 0, &threadID);
	hThread[1] = CreateThread(NULL, 0, draw2, 0, 0, &threadID);
	getchar();
	closegraph();
	return 0;
}
