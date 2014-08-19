#pragma once

class CUnit
{
	int hp;
	int dmg;
	int dodge;
	char type;
	char status;
public:
	CUnit(int _hp, int _dmg, int _dodge, char _type, char _status) :hp(_hp), dmg(_dmg), dodge(_dodge), type(_type), status(_status) {}

	int getHp()
	{
		return hp;
	}
	
	int getDmg()
	{
		return dmg;
	}

	int getDodge()
	{
		return dodge;
	}

	char getType()
	{
		return type;
	}

	char getStatus()
	{
		return status;
	}

	void setHp(int _hp)
	{
		hp = _hp;
	}

	void setStatus(char _status)
	{
		status = _status;
	}
};