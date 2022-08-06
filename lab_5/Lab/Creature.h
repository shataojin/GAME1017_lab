#pragma once

#include <iostream>
using namespace std;
class Creature
{
protected:
	int m_health;
	int m_attack;
private:
	int s_numberOfCreaturesCreated = 0;
	int s_numberOfCreaturesRightNow = 0;
public:
	Creature(int health, int attack);
	~Creature();
	virtual void TakeDamge(int damage);
	virtual void Fight(Creature* pOatherMage);
	virtual void Display();
	virtual bool IsDead();
	 static int GetNumberOfCreaturesCreated();
	 static int GetNumberOfCreaturesRightNow();
};