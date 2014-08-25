#define _CRT_SECURE_NO_WARNINGS

#include "Global.h"
#include "Labyrinth.h"
#include "Banners.h"
#include "CGame.h"

void ShowMenu(int iItem)
{
	drawTextXY(42, 20, "                                                                        ", 0);
	drawTextXY(42, 21, "                                                                        ", 0);

	drawTextXY(50, 47, "                                                 ", 0);
	drawTextXY(50, 48, "                                                 ", 0);

	int yPos = 13;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	scrn.X = 70;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	if (iItem == 1)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << ">" << "New Game" << endl;
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
	else
	{
		cout << " " << "New Game" << endl;
	}

	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	if (iItem == 2)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << ">" << "Rules" << endl;
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
	else
	{
		cout << " " << "Rules" << endl;
	}

	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	if (iItem == 3)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << ">" << "About" << endl;
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
	else
	{
		cout << " " << "About" << endl;
	}
}

void main()
{
	consoleConfig();
	srand((unsigned int)time(NULL));

	CGame game = CGame();

	int iItem = 1, nLast = 3;
	char symb;

	drawGameName();
	ShowMenu(iItem);
	while (true)
	{
		if (isWin == true)
			break;

		symb = _getch();

		// up
		if (symb == 72)
		{
			if (0 < iItem - 1)
				iItem = iItem - 1;
			else
				iItem = nLast;
			ShowMenu(iItem);
		}

		// down
		if (symb == 80)
		{
			if (iItem < nLast)
				iItem = iItem + 1;
			else
				iItem = 1;
			ShowMenu(iItem);
		}

		// enter
		if (symb == 13)
		{
			keybd_event(VK_RETURN, 0, KEYEVENTF_EXTENDEDKEY, 0);
			ShowMenu(iItem);

			switch (iItem)
			{
			case 1:
				cin.ignore();
				game.newGame();
				break;
			case 2:
				cin.ignore();
				game.rulesInfo();
				break;
			case 3:
				cin.ignore();
				game.aboutInfo();
				break;
			}
		}
	}
}
