#pragma once
#include "Craftsmanship.h"
#include "Monster.h"
class Hero
{
public:
	Hero(void);
	~Hero(void);

	string name;						// ����
	int level;							// ���𣺳�ʼֵΪ1��Ϊ0������ʧ��
	int HP;								// ����ֵ��Ϊ0�򱾾�ʧ��
	int MP;								// ħ��ֵ��Ϊ0����ʹ��ħ������
	Craftsmanship crafts[NUM_CRAFTS];	// �����б�

	void initHero();
	int choice();
	void attack(int, Monster&);
	bool isAlive();
	void levelUp(int);
	void levelDown();
private:
	void settlement(int level);
};

