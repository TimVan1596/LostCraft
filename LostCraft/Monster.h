#pragma once
class Hero;
class Monster
{
public:
	Monster(void);
	~Monster(void);

	string name;	// ����
	int level;		// ���𣺳�ʼֵΪ1��Ϊ0������ʧ��
	int HP;			// ����ֵ��Ϊ0�򱾾�ʧ��
	int ATK;		// ������

	void initMonster(int); 
	void attack(Hero&);
	bool isAlive();
};

