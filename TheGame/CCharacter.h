#include "CUnit.h"
#include "CArcher.h"
#include "CSwordsmen.h"
#include "CWizard.h"

class CCharacter
{
	COORD charPosition;
	string charClass;
	string charName;
	int lives;
	int keys;

	CUnit *player;
	CUnit *enemy;

public:
	CCharacter() {}

	CCharacter(string _charClass, string _charName, int _lives, int _keys)
	{
		// last door for test
		//charPosition.X = 23;
		//charPosition.Y = 72;

		charPosition.X = 1;
		charPosition.Y = 1;

		charClass = _charClass;

		charName = _charName;

		lives = _lives;

		keys = _keys;

		if (charClass == "Archer")
			player = new CArcher();
		if (charClass == "Swordsmen")
			player = new CSwordsmen();
		if (charClass == "Wizard")
			player = new CWizard();

	}

	string getCharClass()
	{
		return charClass;
	}

	string getCharName()
	{
		return charName;
	}

	int getLives()
	{
		return lives;
	}

	void setLives(int _lives)
	{
		lives += _lives;
	}

	int getKeys()
	{
		return keys;
	}

	void setKeys(int _keys)
	{
		keys += _keys;
	}

	void drawCharacter()
	{
		Labyrinth[charPosition.X][charPosition.Y] = 8;
 	}

private:
	void eraseCharacter()
	{
		Labyrinth[charPosition.X][charPosition.Y] = 0;
	}

	bool Door()
	{
		int dice = rand() % 10;
		int number, attempt = 0;
		clear();
		drawTextXY(1, 21, "You found locked door.", 50);
		if (keys > 0)
		{
			drawTextXY(1, 22, "And opened it with key.", 50);
			keys -= 1;
			return true;
		}
		else
		{
			drawTextXY(1, 22, "In order to pass you must\n pick up number combination \n from 0 to 9: \n\n", 50);

			while (attempt != 3)
			{
				cout << " " << attempt + 1 << " - chance" << endl;
				cout << " your number: ";
				cin >> number;

				if (number == dice)
				{
					drawTextXY(1, 31, "door opened.", 50);
					drawTextXY(1, 32, "now you can pass!", 50);
					return true;
				}
				attempt++;
			}
		}
		return false;
	}

	void Lives()
	{
		clear();
		int dice = rand() % 3;
		char buffer[2];
		_itoa(dice, buffer, 10);
		drawTextXY(1, 21, "you found " + (string)buffer + " lives", 50);
		setLives(dice);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Fight()
	{



		return false;
	}

	void reload(CUnit* unit)
	{
		if (unit->getType() == 'S')
			unit->setHp(15);
		if (unit->getType() == 'A')
			unit->setHp(12);
		if (unit->getType() == 'W')
			unit->setHp(8);
	}

	bool doAttack(CUnit* player, CUnit* enemy)
	{
		GetConsoleScreenBufferInfo(hConsole, &csbi);

		reload(player);
		reload(enemy);

		while (true)
		{
			showAll(player, enemy);

			if (enemy->getHp() <= 0)
			{
				return true;
			}
			if (player->getHp() <= 0)
			{
				return false;
			}

			// player
			scrn.X = 61;
			scrn.Y = 18;
			SetConsoleCursorPosition(hConsole, scrn);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			if (player->getType() == 'S')
				cout << "Swordsmen ";
			if (player->getType() == 'A')
				cout << "Archer ";
			if (player->getType() == 'W')
				cout << "Wizard ";
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);

			cout << "attacking ";

			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			if (enemy->getType() == 'S')
				cout << "Swordsmen ";
			if (enemy->getType() == 'A')
				cout << "Archer ";
			if (enemy->getType() == 'W')
				cout << "Wizard ";
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);

			_getch();

			if (isDodged(enemy->getDodge()) == false)
			{
				enemy->setHp((enemy->getHp()) - (player->getDmg()));
			}
			else
			{
				scrn.X = 70;
				scrn.Y = 19;
				SetConsoleCursorPosition(hConsole, scrn);
				cout << "Dodged!" << endl;
				_getch();
			}

			showAll(player, enemy);

			// enemy
			scrn.X = 61;
			scrn.Y = 18;
			SetConsoleCursorPosition(hConsole, scrn);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			if (enemy->getType() == 'S')
				cout << "Swordsmen ";
			if (enemy->getType() == 'A')
				cout << "Archer ";
			if (enemy->getType() == 'W')
				cout << "Wizard ";
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);

			cout << "attacking ";

			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			if (player->getType() == 'S')
				cout << "Swordsmen ";
			if (player->getType() == 'A')
				cout << "Archer ";
			if (player->getType() == 'W')
				cout << "Wizard ";
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);

			_getch();

			if (isDodged(player->getDodge()) == false)
			{
				player->setHp((player->getHp()) - (enemy->getDmg()));
			}
			else
			{
				scrn.X = 70;
				scrn.Y = 19;
				SetConsoleCursorPosition(hConsole, scrn);
				cout << "Dodged!" << endl;
				_getch();
			}
		}
		return false;
	}

	void Form(int xPos)
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
		cout << (char)442 << "                   " << (char)442 << endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << (char)456 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)444 << endl;
	}

	void Info(CUnit* unit, int xPos)
	{
		int yPos = 18;
		scrn.X = xPos;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		if (unit->getType() == 'S')
			cout << "Swordsmen" << endl;
		if (unit->getType() == 'A')
			cout << "Archer" << endl;
		if (unit->getType() == 'W')
			cout << "Wizard" << endl;

		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "HP: " << unit->getHp() << endl;
		if (unit->getHp() <= 0)
		{
			unit->setStatus('D');
			unit->setHp(0);
		}

		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "DMG: " << unit->getDmg() << endl;

		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "DODGE: " << unit->getDodge() << endl;

		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		if (unit->getStatus() == 'L')
			cout << "Live" << endl;
		else
			cout << "Dead" << endl;
	}

	void showAll(CUnit* player, CUnit* enemy)
	{
		system("cls");
		drawGameName();

		GetConsoleScreenBufferInfo(hConsole, &csbi);

		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Form(39);
		Info(player, 42);
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		Form(92);
		Info(enemy, 95);
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}

//
	bool isDodged(int dodge)
	{
		if ((rand() % 100) < dodge)
			return true;
		else
			return false;
	}
//
	bool Enemy()
	{
		switch (rand() % 3)
		{
		case 0:
			enemy = new CArcher();
			break;
		case 1:
			enemy = new CSwordsmen();
			break;
		case 2:
			enemy = new CWizard();
			break;
		}

		if (doAttack(player, enemy) == true)
		{
			return true;
		}
		else
		{
			return false;
		}

		return false;
	}

	void clear()
	{
		for (int line = 20; line != 33; line++)
		{
			drawTextXY(0, line, "                              ", 0); 
		}
	}

public:
	void moveCharacter(int Labyrinth[Width][Height], Direction dir)
	{
		eraseCharacter();
		switch (dir)
		{
		case UP:
			if (charPosition.X > 0 && Labyrinth[charPosition.X - 1][charPosition.Y] != 1)
			if (Labyrinth[charPosition.X - 1][charPosition.Y] == 2)
			{
				if (Door() == true)
				{
					charPosition.X--;
				}
				else
				{
					clear();
					drawTextXY(1, 21, "door closed!", 50);
				}
			}

			else if (Labyrinth[charPosition.X - 1][charPosition.Y] == 3)
			{
				Lives();
				charPosition.X--;
			}

			else if (Labyrinth[charPosition.X - 1][charPosition.Y] == 4)
			{
				if (Enemy() == true)
				{
					drawTextXY(1, 21, "you win!", 50);
					int dice = rand() % 2;
					if (dice > 0)
					{
						drawTextXY(1, 22, "and found 1 key \n at enemy's pockets.", 50);
						keys += 1;
					}
					else
					{
						drawTextXY(1, 22, "and nothing were found.", 50);
					}
					charPosition.X--;
				}
				else
				{
					clear();
					drawTextXY(1, 21, "you lose!", 50);
					drawTextXY(1, 22, "and lost 1 life", 50);
					lives -= 1;
				}
			}

			else
			{
				clear();
				charPosition.X--;
			}
			break;

		case LEFT:
			if (charPosition.Y > 0 && Labyrinth[charPosition.X][charPosition.Y - 1] != 1)
			if (Labyrinth[charPosition.X][charPosition.Y - 1] == 2)
			{
				if (Door() == true)
				{
					charPosition.Y--;
				}
				else
				{
					clear();
					drawTextXY(1, 21, "door closed!", 50);
				}
			}

			else if (Labyrinth[charPosition.X][charPosition.Y - 1] == 3)
			{
				Lives();
				charPosition.Y--;
			}

			else if (Labyrinth[charPosition.X][charPosition.Y - 1] == 4)
			{
				if (Enemy() == true)
				{
					drawTextXY(1, 21, "you win!", 50);
					int dice = rand() % 2;
					if (dice > 0)
					{
						drawTextXY(1, 22, "and found 1 key \n at enemy's pockets.", 50);
						keys += 1;
					}
					else
					{
						drawTextXY(1, 22, "and nothing were found.", 50);
					}
					charPosition.Y--;
				}
				else
				{
					clear();
					drawTextXY(1, 21, "you lose!", 50);
					drawTextXY(1, 22, "and lost 1 life", 50);
					lives -= 1;
				}
			}

			else
			{
				clear();
				charPosition.Y--;
			}
			break;

		case DOWN:
			if (charPosition.X < Width && Labyrinth[charPosition.X + 1][charPosition.Y] != 1)
			if (Labyrinth[charPosition.X + 1][charPosition.Y] == 2)
			{
				if (Door() == true)
				{
					charPosition.X++;
				}
				else
				{
					clear();
					drawTextXY(1, 21, "door closed!", 50);
				}
			}

			else if (Labyrinth[charPosition.X + 1][charPosition.Y] == 3)
			{
				Lives();
				charPosition.X++;
			}

			else if (Labyrinth[charPosition.X + 1][charPosition.Y] == 4)
			{
				if (Enemy() == true)
				{
					drawTextXY(1, 21, "you win!", 50);
					int dice = rand() % 2;
					if (dice > 0)
					{
						drawTextXY(1, 22, "and found 1 key \n at enemy's pockets.", 50);
						keys += 1;
					}
					else
					{
						drawTextXY(1, 22, "and nothing were found.", 50);
					}
					charPosition.X++;
				}
				else
				{
					clear();
					drawTextXY(1, 21, "you lose!", 50);
					drawTextXY(1, 22, "and lost 1 life", 50);
					lives -= 1;
				}
			}

			else
			{
				clear();
				charPosition.X++;
			}
			break;

		case RIGHT:
			if (charPosition.Y < Height && Labyrinth[charPosition.X][charPosition.Y + 1] != 1)
			if (Labyrinth[charPosition.X][charPosition.Y + 1] == 2)
			{
				if (Door() == true)
				{
					charPosition.Y++;
				}
				else
				{
					clear();
					drawTextXY(1, 21, "door closed!", 50);
				}
			}

			else if (Labyrinth[charPosition.X][charPosition.Y + 1] == 3)
			{
				Lives();
				charPosition.Y++;
			}

			else if (Labyrinth[charPosition.X][charPosition.Y + 1] == 4)
			{
				if (Enemy() == true)
				{
					drawTextXY(1, 21, "you win!", 50);
					int dice = rand() % 2;
					if (dice > 0)
					{
						drawTextXY(1, 22, "and found 1 key \n at enemy's pockets.", 50);
						keys += 1;
					}
					else
					{
						drawTextXY(1, 22, "and nothing were found.", 50);
					}
					charPosition.Y++;
				}
				else
				{
					clear();
					drawTextXY(1, 21, "you lose!", 50);
					drawTextXY(1, 22, "and lost 1 life", 50);
					lives -= 1;
				}
			}

			else if (charPosition.X == 23 && (charPosition.Y + 1) == 74)
			{
				isWin = true;
			}

			else
			{
				clear();
				charPosition.Y++;
			}
			break;
		}
		drawCharacter();
	}
};