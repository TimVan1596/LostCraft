// LostCraft.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "AdvScenario.h"


int _tmain(int argc, _TCHAR* argv[])
{
	AdvScenario s;
	((Hero *)s.rHero)->setName();
	s.state = true;
	while(s.state)
	{
		s.choice();
		s.round = 0;
		s.state = s.challenge();
	}
	PC;
	return 0;
}

