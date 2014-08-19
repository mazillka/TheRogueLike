#include "CUnit.h"

class CWizard :public CUnit
{
public:
	CWizard() :CUnit(8, 10, 30, 'W', 'L'){}
};