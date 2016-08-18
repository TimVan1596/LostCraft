#include "StdAfx.h"
#include "Hero.h"

Hero::Hero(void)
{
}


Hero::~Hero(void)
{
}

void Hero::initHero()
{
	cout << "������Ӣ�۵����֣�";
	cin >> name;
	level = 1;
	HP = 2000;
	MP = 50;
	string craftnames[NUM_CRAFTS] = {"��ͨ����","������","ʯ�ƾ���","�������","��ʴ����","ʥ����","��ʦ����","��������"};
	int availables[NUM_CRAFTS] = {1,1,5,10,20,30,35,45};
	int mps[NUM_CRAFTS] = {0,5,10,20,40,60,80,100};
	int atks[NUM_CRAFTS] = {10,12,15,18,20,22,25,30};
	int coolings[NUM_CRAFTS] = {0,1,3,3,4,4,5,5};
	for (int i=0;i!=NUM_CRAFTS;i++)
	{
		crafts[i].name = craftnames[i];
		crafts[i].available = availables[i];
		crafts[i].consumption = mps[i];
		crafts[i].ATK = atks[i]*level;
		crafts[i].cooling = coolings[i];
		crafts[i].action = 0;
	}
	cout << "Ӣ�ۣ�" << name << "��ʼ���ɹ���" << endl;
	PC;
}

int Hero::choice()
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
			return attack-1;
		}
		else
		{
			cout << "ѡ������" << endl;
			cout << "������ѡ���ܣ�" << endl;
			continue;
		}
	} while (true);
}

void Hero::attack(int index, Monster &mon)
{
	//cout << "��ѡ���ܣ�" << endl;
	//int attack;
	//bool retry = false;
	//do
	//{
	//	int numCraft=0;
	//	do
	//	{
	//		for (int i=0;i!=NUM_CRAFTS;i++)
	//		{
	//			if (crafts[i].available<=level)
	//			{
	//				cout << i+1 << ":" << crafts[i].name << endl;
	//				numCraft++;
	//			}
	//		}
	//		cin >> attack;
	//		attack--;
	//	} while (attack<0||attack>=numCraft);
	//	if (crafts[attack].action)
	//	{
	//		cout << "�ü���������ȴ�����Ժ�ʹ�ã�" << endl;
	//		retry = true;
	//	}
	//	if (MP-crafts[attack].consumption<0)
	//	{
	//		cout << "ħ��ֵ���㣬��ѡ��������ʽ������" << endl;
	//		retry = true;
	//	}
	//}while(retry);
	mon.HP -= crafts[index].ATK;
	MP -= crafts[index].consumption;
	crafts[index].action = crafts[index].cooling + 1;
}

bool Hero::isAlive()
{
	return HP>0;
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