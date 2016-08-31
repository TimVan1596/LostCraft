#pragma once
#include "Hero.h"
#include "Monster.h"
class Scenario
{
public:
	Scenario(void);
	~Scenario(void);

	Hero myHero;			// Ӣ�۶���
	Monster myMonster;		// �������
	bool state;				// GO��GameOver����־
	int round;				// ��ǰ�غ�

	Monster choice();
	bool challenge();
	void showInfo(int, Hero, Monster);
	void showInfo(string, Hero, Monster);
};

