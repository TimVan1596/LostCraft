#pragma once
#include "scenario.h"
class AdvScenario :
	public Scenario
{
public:
	AdvScenario(void);
	~AdvScenario(void);

	Role *rHero;			// Ӣ�۶���
	Role *rMonster;			// �������

	void choice();
	bool challenge();
	void showInfo();
	void showInfo(string);
};

