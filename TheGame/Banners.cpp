#include "Banners.h"
#include <Windows.h>
#include <iostream>

void drawGameName()
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	int yPos = 3;
	scrn.X = 40;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "  _______ _          _____                         _      _ _ " << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << " |__   __| |        |  __ \\                       | |    (_) | " << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "    | |  | |__   ___| |__) | ___   __ _ _   _  ___| |     _| | _____ " << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "    | |  | '_ \\ / _ \\  _   // _ \\ / _` | | | |/ _ \\ |    | | |/ / _ \\ " << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "    | |  | | | |  __/ |  \\ \\ (_) | (_| | |_| |  __/ |____| |   <  __/ " << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "    |_|  |_| |_|\\___|_|   \\_\\___/ \\__, |\\__,_|\\___|______|_|_|\\_\\___| " << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "                                  __/ | " << std::endl;
	scrn.Y = yPos++;
	SetConsoleCursorPosition(hConsole, scrn);
	std::cout << "                                 |___/ " << std::endl;
	SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	std::cout << std::endl;
}

void drawYouWinMessage()
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	system("cls");
	while (TRUE)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			PostMessage(FindWindow(NULL, L"TheRogueLike"), WM_CLOSE, 0, 0);
		}

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		int yPos = 20;
		scrn.X = 50;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << " __     __          __          ___       _  " << std::endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << " \\ \\   / /          \\ \\        / (_)     | | " << std::endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << "  \\ \\_/ /__  _   _   \\ \\  /\\  / / _ _ __ | | " << std::endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << "   \\   / _ \\| | | |   \\ \\/  \\/ / | | '_ \\| | " << std::endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << "    | | (_) | |_| |    \\  /\\  /  | | | | |_| " << std::endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << "    |_|\\___/ \\__,_|     \\/  \\/   |_|_| |_(_) " << std::endl;

		scrn.Y = yPos++;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << "\tPress ESCAPE to close the Game:)" << std::endl;

		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
}

void drawGameOverMessage()
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	system("cls");
	while (TRUE)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			PostMessage(FindWindow(NULL, L"TheRogueLike"), WM_CLOSE, 0, 0);
		}

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

		int yPos = 20;
		scrn.X = 40;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << "   _____          __  __ ______    ______      ________ _____  _  " << std::endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << "  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\| | " << std::endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << " | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | | " << std::endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << " | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /| | " << std::endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << " | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\|_| " << std::endl;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << "  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_(_) " << std::endl;

		scrn.Y = yPos++;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		std::cout << "\t\tPress ESCAPE to close the Game:)" << std::endl;

		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
}
