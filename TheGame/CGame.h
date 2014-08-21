#include "CCharacter.h"

class CGame
{
	CCharacter character;
public:
	CGame() {}

	void newGame()
	{
		for (int line = 13; line < 16; line++)
		{
			drawTextXY(70, line, "         ", 0);
		}

		int iItem = 1, nLast = 3;
		char symb;
		string name;

		drawTextXY(60, 12, "input your name: ", 30);
		cin >> name;

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
					cin.ignore();
					character = CCharacter("Archer", name, LIVES, KEYS);
					playGame();
					break;
				case 2:
					cin.ignore();
					character = CCharacter("Swordsmen", name, LIVES, KEYS);
					playGame();
					break;
				case 3:
					cin.ignore();
					character = CCharacter("Wizard", name, LIVES, KEYS);
					playGame();
					break;
				}
			}
		}
	}

private:
	void ShowMenu(int iItem)
	{
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

	void choiceForm(int xPos)
	{
		int yPos = 16;
		scrn.X = xPos;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)457 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)443 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)456 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)444 << endl;
	}

	void choiceInfo(string className, int hp, int dmg, int dodge, int xPos)
	{
		int yPos = 18;
		scrn.X = xPos;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << className << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "HP: " << hp << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "DMG: " << dmg << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "DODGE: " << dodge << endl;
	}

	void drawPlayerInfoForm(int xPos)
	{
		int yPos = 12;
		scrn.X = xPos;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)457 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)443 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)456 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)444 << endl;
	}

	void drawPlayerInfo(int xPos)
	{
		int yPos = 14;
		scrn.X = xPos;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "  " << character.getCharName() << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "Class: " << character.getCharClass() << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "Lives: " << character.getLives() << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "Keys: " << character.getKeys() << endl;
	}

	void playGame()
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

public:
	void rulesInfo()
	{
		drawTextXY(50, 20, "You can move character only with arrow keys.", 50);
		drawTextXY(42, 21, "Fights take place in the automatic mode by pressing the space bar only;)", 50);
	}

	void aboutInfo()
	{
		drawTextXY(50, 47, "Coursework of Andrew Shevchuk-Yuganets", 50);
		drawTextXY(50, 48, "Copyright (c) 2014 Mazillka. All rights reserved.", 50);
	}
};