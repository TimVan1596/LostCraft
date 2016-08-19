#pragma once
#include "InhHero.h"
#include "InhMonster.h"
class Scenario
{
public:
	Scenario(void);
	~Scenario(void);

	InhHero myHero;			// Ӣ�۶���
	InhMonster myMonster;	// �������
	bool state;				// GO��GameOver����־
	int round;				// ��ǰ�غ�

	void initScenario();
	InhMonster choice();
	bool challenge();
	void showInfo(int, InhHero, InhMonster);
	void showInfo(string, InhHero, InhMonster);
};

