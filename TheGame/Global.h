#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

enum Direction { LEFT, UP, RIGHT, DOWN };

bool isWin = FALSE;

// default number of lives
#define LIVES 1 // 5
// default number of keys
#define KEYS 0 //  0

void consoleConfig()
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	SetConsoleTitle(L"TheRogueLike");

	// set font and font size
	CONSOLE_FONT_INFOEX ConsoleFont = { 0 };
	GetCurrentConsoleFontEx(hConsole, FALSE, &ConsoleFont);

	wcscpy_s(ConsoleFont.FaceName, 13, L"Raster Fonts");
	SetCurrentConsoleFontEx(hConsole, FALSE, &ConsoleFont);

	ConsoleFont = { sizeof(CONSOLE_FONT_INFOEX) };
	ConsoleFont.dwFontSize.X = 8;
	ConsoleFont.dwFontSize.Y = 9;
	SetCurrentConsoleFontEx(hConsole, FALSE, &ConsoleFont);
	//end

	// set console size and buffer
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	scrn = { 150, 50 };
	SMALL_RECT src = { 0, 0, scrn.X - 1, scrn.Y - 1 };

	SetConsoleScreenBufferSize(hConsole, scrn);
	SetConsoleWindowInfo(hConsole, TRUE, &src);
	//end

	// hide cursor
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cci);
	//end

	// console position
	SetWindowPos(FindWindow(NULL, L"TheRogueLike"), HWND_TOPMOST, 30, 30, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
	//end
}

void drawTextXY(int xPos, int yPos, string txt, int pause)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xPos; scrn.Y = yPos;

	SetConsoleCursorPosition(hConsole, scrn);
	for (int i = 0; (unsigned)i < txt.length(); i++)
	{
		Sleep(pause);
		cout << txt[i];
	}
}
