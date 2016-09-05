#include "StdAfx.h"
#include "Hero.h"
#include "Monster.h"

Hero::Hero(void)
{
	level = 1;
	HP = 2000;
	MP = 50;
	
	for (int i=0;i!=NUM_CRAFTS;i++)
	{
		crafts[i].name = craftnames[i];
		crafts[i].available = availables[i];
		crafts[i].consumption = mps[i];
		crafts[i].ATK = atks[i]*level;
		crafts[i].cooling = coolings[i];
		crafts[i].action = 0;
	}
}


Hero::~Hero(void)
{
}

void Hero::setName()
{
	cout << "������Ӣ�۵����֣�";
	cin >> name;
	cout << "Ӣ�ۣ�" << name << "��ʼ���ɹ���" << endl;
	PC;
}

void Hero::choice()
{
	cout << "��ѡ���ܣ�" << endl;
	for (int i=0;i!=NUM_CRAFTS;i++)
	{
		if (crafts[i].available<=level)
		{
			cout << i+1 << ":" << crafts[i].name << "��" << (crafts[i].action==0?"��":"��") << "��" << endl;
		}
	}
	do
	{
		int attack;
		cin >> attack;
		if (attack>0 && attack <=NUM_CRAFTS && crafts[attack-1].available<=level)
		{
			if (crafts[attack-1].action)
			{
				cout << "�ü���������ȴ�����Ժ�ʹ�ã�" << endl;
				cout << "������ѡ���ܣ�" << endl;
				continue;
			}
			if (MP-crafts[attack].consumption<0)
			{
				cout << "ħ��ֵ���㣬��ѡ��������ʽ������" << endl;
				cout << "������ѡ���ܣ�" << endl;
				continue;
			}
			iAttack = attack-1;
			return;
		}
		else
		{
			cout << "ѡ������" << endl;
			cout << "������ѡ���ܣ�" << endl;
			continue;
		}
	} while (true);
}

<<<<<<< HEAD
void Hero::attack(Monster &mon)
{
	mon.HP -= crafts[iAttack].ATK;
=======
void Hero::attack(Role &r)
{
	r.HP -= crafts[iAttack].ATK;
>>>>>>> polymorphism
	MP -= crafts[iAttack].consumption;
	crafts[iAttack].action = crafts[iAttack].cooling + 1;
}

void Hero::levelUp(int up)
{
	cout << "=======��ϲ������======" << endl;
	level += up;
	settlement(level);
	PC;
}

void Hero::levelDown()
{
	cout << "======�ɶ񣬽����ˣ�======" << endl;
	level--;
	settlement(level);
	PC;
}

void Hero::settlement(int level)
{
	HP = 2000 + (level-1)*500;
	MP = 50 + (level-1)*10;
	int atks[NUM_CRAFTS] = {10,12,15,18,20,22,25,30};
	for (int i=0;i!=NUM_CRAFTS;i++)
	{
		crafts[i].ATK = atks[i]*level;
		crafts[i].action = 0;
	}
}
