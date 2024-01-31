#include <iostream>
using namespace std;

// 타입변환 포인터
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

	// 복사생성자가 호출이 된다.
	// 끝날때 소멸자
}

void TestItemPtr(Item* item)
{

}

int main()
{
	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{

		// Stack [주소] -> Heap [_hp(4)]
		Knight* knight = new Knight();

		// 암시적으로 No
		// 명시적으로는 OK

		// Stack [주소] 
		Item* item = (Item*)knight;
		item->_itemType = 2;
		
		/*
		item->_itemDbId = 1;
		
		delete knight; 
		*/
		
		// 경우에 따라서 터지지 않을 수도 있다.
		// 타입변환 캐스팅 잘못하면 망한다. 

	}


	// 부모 -> 자식 변환 테스트

	{

		// Item은 무기냐? 방어구일수도있고..
		
		Item* item = new Item();

		// Weapon& weapon = item; // 작은 메모리에서 큰메모리에 가는거라서.. 위험하잖아


		// 근데 주장을 강하게 하면.. 컴파일러가 통과가능
		Weapon* weapon = (Weapon*)item;
		
		// 엉뚱한 메모리 건드리기 // crash
		/*weapon->_damage = 10;

		delete item;*/


	}


	{

		// 자식에서 부모가 되는 경우
		Weapon* weapon = new Weapon();
		//Item* item = (Item*)weapon; // 생략 가능
		// 암시적으로도 된다.
		Item* item = weapon;

		delete weapon;

	}

	// 명시적으로 타입 변환할 때는 항상 조심해야한다.
	// 암시적으로는 항상 될때는 안전한가?
	// -> 평생 명시적으로 타입변환은 안 하면 되는거 아닌가?


	Item* inventory[20] = {};


	// 둘다를 커버할 수 있는 아이템 포인터를 만들어주는게 좋다는거지.


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
		if (item->_itemType == IT_WEAPON) // Armor의 생성자에 IT_WEAPON을 넣어서 오동작보여주자.
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
			// 왔다갔다!
		}

	}

	// ----중요-----


	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i]; 
		// 인벤토리를 item이라는 포인터로 관리하는데..안에는 실제 여러가지가있지

		if (item == nullptr)
			continue;

		/*delete item;
		// 모두 item 소멸자만 호출이되잖아
		// 이러면안된다는거지
		
		
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

		// 그래서 소멸자에 virtual을 붙여줘야겠지?


	}


	return 0;


}