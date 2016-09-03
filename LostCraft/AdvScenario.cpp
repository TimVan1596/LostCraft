#include "StdAfx.h"
#include "AdvScenario.h"


AdvScenario::AdvScenario(void)
{
	rHero = new Hero();
	rMonster = nullptr;
}


AdvScenario::~AdvScenario(void)
{
	delete rHero;
	delete rMonster;
}

void AdvScenario::choice()
{
	int optional;
	do
	{
		CLS;
		cout <<right << "��ѡ����Ҫ��ս�Ĺ��ޣ�" << endl;
		cout << setfill('-') << setw(30) << "" << endl;
		cout << "| 1:" << setfill(' ') << setw(26) << "�Ͷ�̹��֡�lv1��|" << endl;
		cout << "| 2:" << setw(26) << "��˹����֡�lv5��|" << endl;
		cout << "| 3:" << setw(26) << "̩˹��֡�lv10��|" << endl;
		cout << "| 4:" << setw(26) << "��ͷԳ�֡�lv30��|" << endl;
		cout << "| 5:" << setw(26) << "������(BOSS)��lv50��|" << endl;
		cout << setfill('-') << setw(30) << "" << endl;
		cin >> optional;
	} while (optional<1 || optional>5);
	if (rMonster!=nullptr)
	{
		delete rMonster;
	}
	rMonster = new Monster(optional-1);
	return;
}

bool AdvScenario::challenge()
{
	while(true)
	{
		showInfo();
		((Hero *)rHero)->choice();
		rHero->attack(*rMonster);
		showInfo(rHero->name);
		if(rMonster->isAlive())
		{
			rMonster->attack(*rHero);
			showInfo(rMonster->name);
			if (!rHero->isAlive())
			{
				((Hero *)rHero)->levelDown();
				if (rHero->level<=0)
				{
					cout << endl << "======��Ϸʧ�ܣ�======" << endl;
					return false;
				}
				return true;
			}
			else
			{
				round++;
				for (int i=0;i!=NUM_CRAFTS;i++)
				{
					((Hero *)rHero)->crafts[i].action = ((Hero *)rHero)->crafts[i].action <= 0 ? 0 : ((Hero *)rHero)->crafts[i].action - 1;
				}
				PC;
				continue;
			}
		}
		else
		{
			if (rMonster->level == 50)
			{
				cout << endl << "======��ϲͨ�أ�======" << endl;
				return false;
			}
			((Hero *)rHero)->levelUp(rMonster->level);
			return true;
		}
	}
}

void AdvScenario::showInfo()
{
	cout << left << setfill('-') << setw(39) << "" << endl;				// ����ȹ���40������ַ�
	cout << "|" << setfill(' ') << "��"  << setw(3) << round << "��" <<setw(30) << "" << "|" << endl;
	cout << setfill('-') << setw(39) << "" << endl;
	cout << "|" << setfill(' ') << setw(6) << "Ӣ�ۣ�" << setw(12) << rHero->name << "|" << setw(6) << "���ޣ�" << setw(12) << rMonster->name << "|" << endl;
	cout << "|" << setw(6) << "����" << setw(12) << rHero->level << "|" << setw(6) << "����" << setw(12) << rMonster->level << "|" << endl;
	cout << "|" << setw(6) << "HP��" << setw(12) << rHero->HP << "|" << setw(6) << "HP��" << setw(12) << rMonster->HP << "|" << endl;
	cout << "|" << setw(6) << "MP��" << setw(12) << ((Hero *)rHero)->MP << "|" << setw(18) << "" << "|" << endl;
	cout << setfill('-') << setw(39) << "" << endl;
}

void AdvScenario::showInfo(string name)
{
	cout << left << setfill('-') << setw(39) << "" << endl;				// ����ȹ���40������ַ�
	cout << "|" << setfill(' ') << setw(12) << name << "������" << setw(19) << "" << "|" << endl;
	cout << setfill('-') << setw(39) << "" << endl;
	cout << "|" << setfill(' ') << setw(6) << "Ӣ�ۣ�" << setw(12) << rHero->name << "|" << setw(6) << "���ޣ�" << setw(12) << rMonster->name << "|" << endl;
	cout << "|" << setw(6) << "����" << setw(12) << rHero->level << "|" << setw(6) << "����" << setw(12) << rMonster->level << "|" << endl;
	cout << "|" << setw(6) << "HP��" << setw(12) << rHero->HP << "|" << setw(6) << "HP��" << setw(12) << rMonster->HP << "|" << endl;
	cout << "|" << setw(6) << "MP��" << setw(12) << ((Hero *)rHero)->MP << "|" << setw(18) << "" << "|" << endl;
	cout << setfill('-') << setw(39) << "" << endl;
}
