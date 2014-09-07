#include "CGame.h"
#include "Banners.h"

#define LIVES 5
#define KEYS 0

CGame::CGame() {}

void CGame::newGame()
{
	for (int line = 13; line < 16; line++)
	{
		drawTextXY(70, line, "         ", 0);
	}

	int iItem = 1, nLast = 3;
	char symb;
	std::string name;

	drawTextXY(60, 12, "input your name: ", 30);
	std::cin >> name;

	drawTextXY(60, 14, "choice your class: ", 0);

	ShowMenu(iItem);
	while (true)
	{
		if (isWin == true)
			break;

		symb = _getch();

		// left
		if (symb == 75)
		{
			if (0 < iItem - 1)
				iItem = iItem - 1;
			else
				iItem = nLast;
			ShowMenu(iItem);
		}

		// right
		if (symb == 77)
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
				character = CCharacter("Archer", name, LIVES, KEYS);
				playGame();
				break;
			case 2:
				std::cin.ignore();
				character = CCharacter("Swordsmen", name, LIVES, KEYS);
				playGame();
				break;
			case 3:
				std::cin.ignore();
				character = CCharacter("Wizard", name, LIVES, KEYS);
				playGame();
				break;
			}
		}
	}
}

void CGame::ShowMenu(int iItem)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	drawTextXY(78, 14, "           ", 0);

	GetConsoleScreenBufferInfo(hConsole, &csbi);

	if (iItem == 1)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		drawTextXY(79, 14, "Archer!", 0);
		scrn.X = 41;
		scrn.Y = 17;
		SetConsoleCursorPosition(hConsole, scrn);
		choiceForm(42);
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
		choiceInfo("Archer", 12, 4, 40, 45);
	}
	else
	{
		scrn.X = 41;
		scrn.Y = 17;
		SetConsoleCursorPosition(hConsole, scrn);
		choiceForm(42);
		choiceInfo("Archer", 12, 4, 40, 45);
	}

	if (iItem == 2)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		drawTextXY(79, 14, "Swordsmen!", 0);
		scrn.X = 64;
		scrn.Y = 17;
		SetConsoleCursorPosition(hConsole, scrn);
		choiceForm(65);
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
		choiceInfo("Swordsmen", 15, 5, 60, 68);
	}
	else
	{
		scrn.X = 78;
		scrn.Y = 17;
		SetConsoleCursorPosition(hConsole, scrn);
		choiceForm(65);
		choiceInfo("Swordsmen", 15, 5, 60, 68);
	}

	if (iItem == 3)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		drawTextXY(79, 14, "Wizard!", 0);
		scrn.X = 87;
		scrn.Y = 17;
		SetConsoleCursorPosition(hConsole, scrn);
		choiceForm(88);
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
		choiceInfo("Wizard", 8, 10, 30, 91);
	}
	else
	{
		scrn.X = 87;
		scrn.Y = 17;
		SetConsoleCursorPosition(hConsole, scrn);
		choiceForm(88);
		choiceInfo("Wizard", 8, 10, 30, 91);
	}
}

void CGame::choiceForm(int xPos)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int Width = 8;
	int Height = 21;

	int yPos = 15;
	scrn.X = xPos;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	for (int i = 0; i < Width; i++)
	{
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		for (int j = 0; j < Height; j++)
		{
			// left corner
			if (i == 0 && j == 0)
			{
				std::cout << (char)457;
			}

			// upper line
			if (i == 0 && j < Height - 2)
			{
				std::cout << (char)461;
			}

			// right corner
			if (i == 0 && j == Height - 1)
			{
				std::cout << (char)443;
			}

			// left line
			if (i > 0 && i < Width - 1 && j == 0)
			{
				std::cout << (char)442;
			}

			//// TODO: rework using SetConsoleCursorPosition
			// see line 245
			//// right line
			//if (i > 0 && i < Width - 1 && j == Height - 1)
			//{
			//	std::cout << (char)442;
			//}

			// left corner
			if (i == Width - 1 && j == 0)
			{
				std::cout << (char)456;
			}

			// bottom line
			if (i == Width - 1 && j < Height - 2)
			{
				std::cout << (char)461;
			}

			// right corner
			if (i == Width - 1 && j == Height - 1)
			{
				std::cout << (char)444;
			}

		}
		std::cout << std::endl;
	}

	// right line
	yPos = 16;
	scrn.X = xPos + Height - 1;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	for (int i = 0; i < Width - 2; i++)
	{
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << (char)442;
	}
}

void CGame::choiceInfo(std::string className, int hp, int dmg, int dodge, int xPos)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int yPos = 18;
	scrn.X = xPos;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << className << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "HP: " << hp << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "DMG: " << dmg << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "DODGE: " << dodge << std::endl;
}

void CGame::drawPlayerInfoForm(int xPos)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int yPos = 12;
	scrn.X = xPos;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << (char)457 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)443 << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << (char)442 << "                   " << (char)442 << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << (char)442 << "                   " << (char)442 << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << (char)442 << "                   " << (char)442 << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << (char)442 << "                   " << (char)442 << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << (char)442 << "                   " << (char)442 << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << (char)442 << "                   " << (char)442 << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << (char)456 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)444 << std::endl;
}

void CGame::drawPlayerInfo(int xPos)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int yPos = 14;
	scrn.X = xPos;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "  " << character.getCharName() << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "Class: " << character.getCharClass() << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "Lives: " << character.getLives() << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "Keys: " << character.getKeys() << std::endl;
}

void CGame::playGame()
{
	char symb;

	character.drawCharacter();
	drawPlayerInfoForm(2);
	drawPlayerInfo(5);
	drawLabyrinth();

	while (character.getLives() > 0)
	{
		if (isWin == true)
			break;

		symb = _getch();
		switch (symb)
		{
		case 72:
			character.moveCharacter(Labyrinth, UP);
			break;
		case 75:
			character.moveCharacter(Labyrinth, LEFT);
			break;
		case 77:
			character.moveCharacter(Labyrinth, RIGHT);
			break;
		case 80:
			character.moveCharacter(Labyrinth, DOWN);
			break;
		}

		drawPlayerInfoForm(2);
		drawPlayerInfo(5);
		drawLabyrinth();
	}
	if (character.getLives() <= 0)
	{
		drawGameOverMessage();
	}

	if (isWin == true)
	{
		drawYouWinMessage();
	}
}

void CGame::rulesInfo()
{
	drawTextXY(50, 20, "You can move character only with arrow keys.", 50);
	drawTextXY(42, 21, "Fights take place in the automatic mode by pressing the space bar only;)", 50);
}

void CGame::aboutInfo()
{
	drawTextXY(50, 47, "Coursework of Andrew Shevchuk-Yuganets", 50);
	drawTextXY(50, 48, "Copyright (c) 2014 Mazillka. All rights reserved.", 50);
}
