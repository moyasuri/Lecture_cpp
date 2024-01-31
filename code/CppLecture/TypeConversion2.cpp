#include <iostream>
using namespace std;

// Ÿ�Ժ�ȯ ������
enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,

};



class Knight
{
public:
	Knight()
	{
		cout << "Knight" << endl;
	}

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
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&item)" << endl;
	}

	~Item()
	{
		cout << "~Item" << endl;
	}


public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {};

};


class Weapon : public Item
{
public:

	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}
	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

public:

	int _damage = 0;

};

class Armor : public Item
{
public:

	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}


	~Armor()
	{
		cout << "~Armor()" << endl;
	}
	
public:
	int _defence = 0;

};





void TestItem(Item item)
{

	// ��������ڰ� ȣ���� �ȴ�.
	// ������ �Ҹ���
}

void TestItemPtr(Item* item)
{

}

int main()
{
	// �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
	{

		// Stack [�ּ�] -> Heap [_hp(4)]
		Knight* knight = new Knight();

		// �Ͻ������� No
		// ��������δ� OK

		// Stack [�ּ�] 
		Item* item = (Item*)knight;
		item->_itemType = 2;
		
		/*
		item->_itemDbId = 1;
		
		delete knight; 
		*/
		
		// ��쿡 ���� ������ ���� ���� �ִ�.
		// Ÿ�Ժ�ȯ ĳ���� �߸��ϸ� ���Ѵ�. 

	}


	// �θ� -> �ڽ� ��ȯ �׽�Ʈ

	{

		// Item�� �����? ���ϼ����ְ�..
		
		Item* item = new Item();

		// Weapon& weapon = item; // ���� �޸𸮿��� ū�޸𸮿� ���°Ŷ�.. �������ݾ�


		// �ٵ� ������ ���ϰ� �ϸ�.. �����Ϸ��� �������
		Weapon* weapon = (Weapon*)item;
		
		// ������ �޸� �ǵ帮�� // crash
		/*weapon->_damage = 10;

		delete item;*/


	}


	{

		// �ڽĿ��� �θ� �Ǵ� ���
		Weapon* weapon = new Weapon();
		//Item* item = (Item*)weapon; // ���� ����
		// �Ͻ������ε� �ȴ�.
		Item* item = weapon;

		delete weapon;

	}

	// ��������� Ÿ�� ��ȯ�� ���� �׻� �����ؾ��Ѵ�.
	// �Ͻ������δ� �׻� �ɶ��� �����Ѱ�?
	// -> ��� ��������� Ÿ�Ժ�ȯ�� �� �ϸ� �Ǵ°� �ƴѰ�?


	Item* inventory[20] = {};


	// �Ѵٸ� Ŀ���� �� �ִ� ������ �����͸� ������ִ°� ���ٴ°���.


	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2; //0~1;
		
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

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;
		if (item->_itemType == IT_WEAPON) // Armor�� �����ڿ� IT_WEAPON�� �־ �����ۺ�������.
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
			// �Դٰ���!
		}

	}

	// ----�߿�-----


	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i]; 
		// �κ��丮�� item�̶�� �����ͷ� �����ϴµ�..�ȿ��� ���� ��������������

		if (item == nullptr)
			continue;

		/*delete item;
		// ��� item �Ҹ��ڸ� ȣ���̵��ݾ�
		// �̷���ȵȴٴ°���
		
		
		*/
		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			delete weapon;
		}
		else
		{
			Armor* armor = (Armor*)item;
			delete armor;
		}

		// �׷��� �Ҹ��ڿ� virtual�� �ٿ���߰���?


	}


	return 0;


}