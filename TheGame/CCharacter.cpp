#include "CCharacter.h"
#include "Banners.h"

CCharacter::CCharacter() {}

CCharacter::CCharacter(std::string _charClass, std::string _charName, int _lives, int _keys)
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

std::string CCharacter::getCharClass()
{
	return charClass;
}

std::string CCharacter::getCharName()
{
	return charName;
}

int CCharacter::getLives()
{
	return lives;
}

void CCharacter::setLives(int _lives)
{
	lives += _lives;
}

int CCharacter::getKeys()
{
	return keys;
}

void CCharacter::setKeys(int _keys)
{
	keys += _keys;
}

void CCharacter::drawCharacter()
{
	Labyrinth[charPosition.X][charPosition.Y] = 8;
}

void CCharacter::eraseCharacter()
{
	Labyrinth[charPosition.X][charPosition.Y] = 0;
}

bool CCharacter::Door()
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
			std::cout << " " << attempt + 1 << " - chance" << std::endl;
			std::cout << " your number: ";
			std::cin >> number;

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

void CCharacter::Lives()
{
	clear();
	int dice = rand() % 3;
	char buffer[2];
	_itoa_s(dice, buffer, 2, 10);
	drawTextXY(1, 21, "you found " + (std::string)buffer + " lives", 50);
	setLives(dice);
}

bool CCharacter::Fight()
{



	return false;
}

void CCharacter::reload(CUnit* unit)
{
	if (unit->getType() == 'S')
		unit->setHp(15);
	if (unit->getType() == 'A')
		unit->setHp(12);
	if (unit->getType() == 'W')
		unit->setHp(8);
}

bool CCharacter::doAttack(CUnit* player, CUnit* enemy)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

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
			std::cout << "Swordsmen ";
		if (player->getType() == 'A')
			std::cout << "Archer ";
		if (player->getType() == 'W')
			std::cout << "Wizard ";
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);

		std::cout << "attacking ";

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		if (enemy->getType() == 'S')
			std::cout << "Swordsmen ";
		if (enemy->getType() == 'A')
			std::cout << "Archer ";
		if (enemy->getType() == 'W')
			std::cout << "Wizard ";
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
			std::cout << "Dodged!" << std::endl;
			_getch();
		}

		showAll(player, enemy);

		// enemy
		scrn.X = 61;
		scrn.Y = 18;
		SetConsoleCursorPosition(hConsole, scrn);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		if (enemy->getType() == 'S')
			std::cout << "Swordsmen ";
		if (enemy->getType() == 'A')
			std::cout << "Archer ";
		if (enemy->getType() == 'W')
			std::cout << "Wizard ";
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);

		std::cout << "attacking ";

		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		if (player->getType() == 'S')
			std::cout << "Swordsmen ";
		if (player->getType() == 'A')
			std::cout << "Archer ";
		if (player->getType() == 'W')
			std::cout << "Wizard ";
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
			std::cout << "Dodged!" << std::endl;
			_getch();
		}
	}
	return false;
}

void CCharacter::Form(int xPos)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int yPos = 16;
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
	std::cout << (char)442 << "                   " << (char)442 << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << (char)456 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)461 << (char)444 << std::endl;
}

void CCharacter::Info(CUnit* unit, int xPos)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int yPos = 18;
	scrn.X = xPos;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	if (unit->getType() == 'S')
		std::cout << "Swordsmen" << std::endl;
	if (unit->getType() == 'A')
		std::cout << "Archer" << std::endl;
	if (unit->getType() == 'W')
		std::cout << "Wizard" << std::endl;

	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "HP: " << unit->getHp() << std::endl;
	if (unit->getHp() <= 0)
	{
		unit->setStatus('D');
		unit->setHp(0);
	}

	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "DMG: " << unit->getDmg() << std::endl;

	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "DODGE: " << unit->getDodge() << std::endl;

	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	if (unit->getStatus() == 'L')
		std::cout << "Live" << std::endl;
	else
		std::cout << "Dead" << std::endl;
}

void CCharacter::showAll(CUnit* player, CUnit* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

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
bool CCharacter::isDodged(int dodge)
{
	if ((rand() % 100) < dodge)
		return true;
	else
		return false;
}
//
bool CCharacter::Enemy()
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

void CCharacter::clear()
{
	for (int line = 20; line != 33; line++)
	{
		drawTextXY(0, line, "                              ", 0);
	}
}

void CCharacter::moveCharacter(int Labyrinth[Width][Height], Direction dir)
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
