#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <ctime>

using namespace std;

enum Direction { LEFT, UP, RIGHT, DOWN };

bool isWin = FALSE;

// default number of lives
#define LIVES 1 // 5
// default number of keys
#define KEYS 0 //  0

///
COORD scrn;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;
///

BOOL ShowConsoleCursor(BOOL bShow)
{
	CONSOLE_CURSOR_INFO cci;

	if (hConsole == INVALID_HANDLE_VALUE)
		return TRUE;

	if (!GetConsoleCursorInfo(hConsole, &cci))
		return FALSE;

	cci.bVisible = bShow;

	if (!SetConsoleCursorInfo(hConsole, &cci))
		return FALSE;

	return TRUE;
}

void consoleConfig()
{
	SetConsoleTitle(L"TheRogueLike");

	// set font and font size
	CONSOLE_FONT_INFOEX ConsoleFont = {0};
	GetCurrentConsoleFontEx(hConsole, FALSE, &ConsoleFont);

	wcscpy(ConsoleFont.FaceName, L"Raster Fonts");
	// wcscpy(ConsoleFont.FaceName, L"Точечные шрифты");
	SetCurrentConsoleFontEx(hConsole, FALSE, &ConsoleFont);

	ConsoleFont = { sizeof(CONSOLE_FONT_INFOEX) };
	ConsoleFont.dwFontSize.X = 8;
	ConsoleFont.dwFontSize.Y = 9;
	SetCurrentConsoleFontEx(hConsole, FALSE, &ConsoleFont);

	// set console size and buffer
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	scrn = { 150, 50 };
	SMALL_RECT src = { 0, 0, scrn.X - 1, scrn.Y - 1 };

	SetConsoleScreenBufferSize(hConsole, scrn);
	SetConsoleWindowInfo(hConsole, TRUE, &src);

	// hide cursor
	ShowConsoleCursor(FALSE);

	// console position
	SetWindowPos(FindWindow(NULL, L"TheRogueLike"), HWND_TOPMOST, 30, 30, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
}

void drawTextXY(int xPos, int yPos, string txt, int pause)
{
	scrn.X = xPos; scrn.Y = yPos;

	SetConsoleCursorPosition(hConsole, scrn);
	for (int i = 0; (unsigned)i < txt.length(); i++)
	{
		Sleep(pause);
		cout << txt[i];
	}
}
