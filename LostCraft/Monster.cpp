#include "StdAfx.h"
#include "Monster.h"
#include "Hero.h"

Monster::Monster(void)
{
}


Monster::Monster(int optional)
{
	string names[5] = {"�Ͷ�̹���","��˹�����","̩˹���","��ͷԳ��","������(BOSS)"};
	int levels[5] = {1,5,10,30,50};
	name = names[optional];
	level = levels[optional];
	HP = 100 * level;
	ATK = 20 * level;
}

Monster::~Monster(void)
{
}

void Monster::attack(Role &r)
{
	r.HP -= ATK;
}
