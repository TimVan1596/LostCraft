#include "StdAfx.h"
#include "InhMonster.h"


InhMonster::InhMonster(void)
{
}


InhMonster::InhMonster(int optional)
{
	string names[5] = {"�Ͷ�̹���","��˹�����","̩˹���","��ͷԳ��","������(BOSS)"};
	int levels[5] = {1,5,10,30,50};
	name = names[optional];
	level = levels[optional];
	HP = 100 * level;
	ATK = 20 * level;
}

InhMonster::~InhMonster(void)
{
}

void InhMonster::attack(InhHero &h)
{
	h.HP -= ATK;
}
