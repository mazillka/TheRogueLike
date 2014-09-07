#include <windows.h>
#include <iostream>

static enum Direction { LEFT, UP, RIGHT, DOWN };

extern bool isWin;

const int Width = 25;
const int Height = 75;

extern int Labyrinth[Width][Height];

void consoleConfig();
void drawTextXY(int xPos, int yPos, std::string txt, int pause);
void drawLabyrinth();