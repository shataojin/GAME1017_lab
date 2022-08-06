#pragma once
#include"Creature.h"
#include <iostream>
using namespace std;

class Mage:public Creature
{
private:
	int m_numebrOfSpells;

public:
	Mage(int health, int attack, int spells);
	~Mage();
	virtual void CastSpell(Creature* pOatherMage);
	virtual void Display();
};