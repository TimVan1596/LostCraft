#pragma once

const string craftnames[NUM_CRAFTS]={"��ͨ����","������","ʯ�ƾ���","�������","��ʴ����","ʥ����","��ʦ����","��������"};
const int availables[NUM_CRAFTS]={1,1,5,10,20,30,35,45};
const int mps[NUM_CRAFTS] = {0,5,10,20,40,60,80,100};
const int atks[NUM_CRAFTS] = {10,12,15,18,20,22,25,30};
const int coolings[NUM_CRAFTS] = {0,1,3,3,4,4,5,5};

class Craftsmanship
{
public:
	Craftsmanship(void);
	~Craftsmanship(void);

	string name;	// ����
	int consumption;// ������MP��ֵ
	int ATK;		// ������
	int cooling;	// ���ܹ涨��ȴʱ��
	int available;	// ��������Ӣ�۵ȼ�
	int action;		// ������ȴ�غ�
};

