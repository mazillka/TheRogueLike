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

void drawYouWinMessage()
{
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
		
		scrn.Y = yPos++;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "\tPress ESCAPE to close the Game:)" << endl;
		
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
}

void drawGameOverMessage()
{
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
		
		scrn.Y = yPos++;
		scrn.Y = yPos++;
		SetConsoleCursorPosition(hConsole, scrn);
		cout << "\t\tPress ESCAPE to close the Game:)" << endl;

		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
}
