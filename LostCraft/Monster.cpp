#include "StdAfx.h"
#include "Monster.h"
#include "Hero.h"

Monster::Monster(void)
{
}


Monster::~Monster(void)
{
}

void Monster::initMonster(int optional)
{
	string names[5] = {"�Ͷ�̹���","��˹�����","̩˹���","��ͷԳ��","������(BOSS)"};
	int levels[5] = {1,5,10,30,50};
	name = names[optional];
	level = levels[optional];
	HP = 100 * level;
	ATK = 20 * level;
}

void Monster::attack(Hero &h)
{
	h.HP -= ATK;
}

bool Monster::isAlive()
{
	return HP>0;
}
