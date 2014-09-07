#include "CUnit.h"
#include "CArcher.h"
#include "CSwordsmen.h"
#include "CWizard.h"

#include "Functions.h"

#include <conio.h>
#include <string>

class CCharacter
{
	COORD charPosition;
	std::string charClass;
	std::string charName;
	int lives;
	int keys;

	CUnit *player;
	CUnit *enemy;

public:
	CCharacter();

	CCharacter(std::string _charClass, std::string _charName, int _lives, int _keys);

	std::string getCharClass();

	std::string getCharName();

	int getLives();

	void setLives(int _lives);

	int getKeys();

	void setKeys(int _keys);

	void drawCharacter();

private:
	void eraseCharacter();

	bool Door();

	void Lives();

	bool Fight();

	void reload(CUnit* unit);

	bool doAttack(CUnit* player, CUnit* enemy);

	void Form(int xPos);

	void Info(CUnit* unit, int xPos);

	void showAll(CUnit* player, CUnit* enemy);

	bool isDodged(int dodge);

	bool Enemy();

	void clear();

public:
	void moveCharacter(int Labyrinth[25][75], Direction dir);

};