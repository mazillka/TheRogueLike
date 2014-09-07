#include "CCharacter.h"

class CGame
{
	CCharacter character;

public:
	CGame();

	void newGame();

private:
	void ShowMenu(int iItem);

	void choiceForm(int xPos);

	void choiceInfo(std::string className, int hp, int dmg, int dodge, int xPos);

	void drawPlayerInfoForm(int xPos);

	void drawPlayerInfo(int xPos);

	void playGame();

public:
	void rulesInfo();

	void aboutInfo();

};