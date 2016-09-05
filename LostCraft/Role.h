#pragma once
class Role
{
public:
	Role(void);
	~Role(void);

	string name;
	int level;
	int HP;

	virtual void attack(Role&)=0;
	bool isAlive();
};

