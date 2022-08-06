#include <iostream>

using namespace std;


int main()
{
	srand((unsigned)time(nullptr));

	Creature* creatureArray[2];
	creatureArray[0] = new Creature(100, 5);
	creatureArray[1] = new Mage(100, 7, 8);

	cout << "Created: " << Creature::GetNumberOfCreaturesCreated() << endl;
	cout << "Right Now: " << Creature::GetNumberOfCreaturesRightNow() << endl;

	for (int i = 0; i < 2; i++)
	{
		creatureArray[i]->Display();
	}

	while (true)
	{
		creatureArray[0]->Fight(creatureArray[1]);

		cout << "Creature Attack: " << endl;
		for (int i = 0; i < 2; i++)
		{
			creatureArray[i]->Display();
		}

		if (creatureArray[1]->IsDead())
		{
			cout << "Mage is DEAD!!!" << endl;
			break;
		}

		Mage* pMage = dynamic_cast<Mage*>(creatureArray[1]);
		if (pMage)
		{
			bool ShouldFight = rand() % 2 == 0;
			if (ShouldFight)
			{
				pMage->Fight(creatureArray[0]);
			}
			else
			{
				pMage->CastSpell(creatureArray[0]);
			}

			cout << "Mage Attack: " << endl;

			for (int i = 0; i < 2; i++)
			{
				creatureArray[i]->Display();
			}

			if (creatureArray[0]->IsDead())
			{
				cout << "Creature is DEAD!!!" << endl;
				break;
			}

		}
	}

	delete creatureArray[0];
	creatureArray[0] = nullptr;
	delete creatureArray[1];
	creatureArray[1] = nullptr;

	cout << "Created: " << Creature::GetNumberOfCreaturesCreated() << endl;
	cout << "Right Now: " << Creature::GetNumberOfCreaturesRightNow() << endl;

	return 0;
}


