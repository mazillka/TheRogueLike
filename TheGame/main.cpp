#include <ctime>
#include "Banners.h"
#include "CGame.h"

void ShowMenu(int iItem)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

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
		std::cout << ">" << "New Game" << std::endl;
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
	else
	{
		std::cout << " " << "New Game" << std::endl;
	}

	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	if (iItem == 2)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::cout << ">" << "Rules" << std::endl;
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
	else
	{
		std::cout << " " << "Rules" << std::endl;
	}

	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	if (iItem == 3)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::cout << ">" << "About" << std::endl;
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
	else
	{
		std::cout << " " << "About" << std::endl;
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
				std::cin.ignore();
				game.newGame();
				break;
			case 2:
				std::cin.ignore();
				game.rulesInfo();
				break;
			case 3:
				std::cin.ignore();
				game.aboutInfo();
				break;
			}
		}
	}
}
