#include <iostream>


using namespace std;

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR =2,

};

class Item
{
public:
	Item()
	{

		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "ItemType()" << endl;
		_itemType = itemType;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&item)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item" << endl;

	}



public:
	int _itemType = 0;
	int _itemDbId = 0;
	char _dummy[4096] = {};
};

class Knight
{
public: 
	Knight()
	{

	}

	~Knight()
	{

	}



};

class Weapon : public Item
{
public:
	Weapon():Item(IT_WEAPON)
	{

	}

	virtual ~Weapon()
	{
		cout << "~Weapon()" << endl;

	}

public:
	int _damage = 3;
};

class Armor : public Item
{

public:
	Armor():Item(IT_ARMOR)
	{

	}

	~Armor()
	{
		cout << "~Armor()" << endl;
	}

public:
	int _defence = 0;
};

// visual studio에서 제공하는 컴파일러(코드영역 -> 어셈블리언어(기계어))
// 컴파일러는 한개다?
// O, X

int main()
{
	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{

		Knight* knight = new Knight();

		Item* item = (Item*)knight;


		//item->_itemDbId = 4; // 이러면 문제가 매우매우매우 심각해집니다.

		//delete item;

	}

	// 부모 -> 자식

	{

		Item* item = new Item();


		//weapon->_damage = 10;

		//delete weapon;

	}

	// 자식 -> 부모

	{
		Weapon* weapon = new Weapon();
		
		Item* item = weapon;

	}
	

	// 이점 
	// invetory -> armor, weapon
	Item* inventory[20] = {};

	// random의 기준이 뭐냐?
	// 컴퓨터 

	// seed (시간)
	srand((unsigned int)time(nullptr));

	for (int i = 0;i < 20;i++)
	{
		int randValue = rand() % 2;
		switch (randValue)
		{
			case 0:
				inventory[i] = new Weapon();
				break;
			case 1:
				inventory[i] = new Armor();
				break;

		}
	}

	for (int i = 0;i < 20;i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
		{
			continue;
		}
		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon damage : " << weapon->_damage << endl;

		}

	}

	

	

	for (int i = 0;i < 20;i++)
	{
		Item* item = inventory[i];

		delete item;
		
		//if (item->_itemType == IT_WEAPON)
		//{
		//	Weapon* weapon = (Weapon*)item;
		//	delete weapon;
		//}
		//else
		//{
		//		Armor* armor = (Armor*)item;
		//		delete armor;
		//}


	}



	return 0;


}


class Animal
{
	Animal(int value) 
	{

	}

	int _age;

};

class Dog
{


};

class Cat
{


};

void Speak()
{

}






