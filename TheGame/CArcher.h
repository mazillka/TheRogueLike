#include "CUnit.h"

class CArcher :public CUnit
{
public:
	CArcher() :CUnit(12, 4, 40, 'A', 'L') {}
};