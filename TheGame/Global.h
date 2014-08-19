#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <ctime>

using namespace std;

enum Direction { LEFT, UP, RIGHT, DOWN };
const int Width = 25;
const int Height = 75;

bool isWin = false;

// default number of lives
#define LIVES 1 // 5
// default number of keys
#define KEYS 1 //  1

///
COORD scrn;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;
///

BOOL ShowConsoleCursor(BOOL bShow)
{
	CONSOLE_CURSOR_INFO cci;

	if (hConsole == INVALID_HANDLE_VALUE)
		return true;

	if (!GetConsoleCursorInfo(hConsole, &cci))
		return false;

	cci.bVisible = bShow;

	if (!SetConsoleCursorInfo(hConsole, &cci))
		return false;

	return true;
}

void consoleConfig()
{
	SetConsoleTitle(L"TheRogueLike");

	// set font and font size
	CONSOLE_FONT_INFOEX ConsoleFont = { sizeof(CONSOLE_FONT_INFOEX) };
	GetCurrentConsoleFontEx(hConsole, false, &ConsoleFont);

	wcscpy(ConsoleFont.FaceName, L"Raster Fonts");
	// wcscpy(ConsoleFont.FaceName, L"Точечные шрифты");
	SetCurrentConsoleFontEx(hConsole, false, &ConsoleFont);

	ConsoleFont = { sizeof(CONSOLE_FONT_INFOEX) };
	ConsoleFont.dwFontSize.X = 8;
	ConsoleFont.dwFontSize.Y = 9;
	SetCurrentConsoleFontEx(hConsole, false, &ConsoleFont);

	// set console size and buffer
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	COORD size = { 150, 50 };
	SMALL_RECT src = { 0, 0, size.X - 1, size.Y - 1 };

	SetConsoleScreenBufferSize(hConsole, size);
	SetConsoleWindowInfo(hConsole, true, &src);

	// hide cursor
	ShowConsoleCursor(FALSE);
}

void drawGameName()
{
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int yPos = 3;

	scrn.X = 40;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	cout << "  _______ _          _____                         _      _ _ " << endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	cout << " |__   __| |        |  __ \\                       | |    (_) | " << endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	cout << "    | |  | |__   ___| |__) | ___   __ _ _   _  ___| |     _| | _____ " << endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	cout << "    | |  | '_ \\ / _ \\  _   // _ \\ / _` | | | |/ _ \\ |    | | |/ / _ \\ " << endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	cout << "    | |  | | | |  __/ |  \\ \\ (_) | (_| | |_| |  __/ |____| |   <  __/ " << endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	cout << "    |_|  |_| |_|\\___|_|   \\_\\___/ \\__, |\\__,_|\\___|______|_|_|\\_\\___| " << endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	cout << "                                  __/ | " << endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	cout << "                                 |___/ " << endl;
	SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	cout << endl;
}

void drawWin()
{
	system("cls");
	while (true)
	{
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		int yPos = 20;
		scrn.X = 50;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << " __     __          __          ___       _  " << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << " \\ \\   / /          \\ \\        / (_)     | | " << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "  \\ \\_/ /__  _   _   \\ \\  /\\  / / _ _ __ | | " << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "   \\   / _ \\| | | |   \\ \\/  \\/ / | | '_ \\| | " << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "    | | (_) | |_| |    \\  /\\  /  | | | | |_| " << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "    |_|\\___/ \\__,_|     \\/  \\/   |_|_| |_(_) " << endl;
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
		cout << endl;
	}
}

void drawGameOver()
{
	system("cls");
	while (true)
	{
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

		int yPos = 20;
		scrn.X = 40;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "   _____          __  __ ______    ______      ________ _____  _  " << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\| | " << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << " | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | | " << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << " | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /| | " << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << " | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\|_| " << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_(_) " << endl;
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
		cout << endl;
	}
}

int Labyrinth[Width][Height] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },
	{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 3, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 3, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, },
	{ 1, 4, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, },
	{ 1, 3, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 4, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, },
	{ 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, },
	{ 1, 0, 1, 0, 2, 0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, },
	{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, },
	{ 1, 0, 1, 0, 1, 0, 1, 3, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, },
	{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, },
	{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, }
};

void drawLabyrinth()
{
	int yPos = 12;
	for (int i = 0; i < Width; i++)
	{
		GetConsoleScreenBufferInfo(hConsole, &csbi);

		scrn.X = 38;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);

		for (int j = 0; j < Height; j++)
		{
			if (Labyrinth[i][j] == 1)
			{
				// wall's
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << (char)432;
				SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			}
			if (Labyrinth[i][j] == 0)
			{
				// route
				cout << " ";
			}
			if (Labyrinth[i][j] == 2)
			{
				// door's
				cout << (char)432;
			}
			if (Labyrinth[i][j] == 3)
			{
				// heal's
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << (char)3;
				SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			}
			if (Labyrinth[i][j] == 4)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "X";
				SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			}

			if (Labyrinth[i][j] == 8)
			{
				// character
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "*";
				SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			}
		}
		cout << endl;
	}
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
	cout << endl;
}
