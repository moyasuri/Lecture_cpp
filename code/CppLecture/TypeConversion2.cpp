#include <iostream>
using namespace std;

<<<<<<< HEAD
// 타입변환 포인터
=======
// ����엯蹂��솚 �룷�씤�꽣
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
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

<<<<<<< HEAD
	// 복사생성자가 호출이 된다.
	// 끝날때 소멸자
=======
	// 蹂듭궗�깮�꽦�옄媛� �샇異쒖씠 �맂�떎.
	// �걹�궇�븣 �냼硫몄옄
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
}

void TestItemPtr(Item* item)
{

}

int main()
{
<<<<<<< HEAD
	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{

		// Stack [주소] -> Heap [_hp(4)]
		Knight* knight = new Knight();

		// 암시적으로 No
		// 명시적으로는 OK

		// Stack [주소] 
=======
	// �뿰愿��꽦�씠 �뾾�뒗 �겢�옒�뒪 �궗�씠�쓽 �룷�씤�꽣 蹂��솚 �뀒�뒪�듃
	{

		// Stack [二쇱냼] -> Heap [_hp(4)]
		Knight* knight = new Knight();

		// �븫�떆�쟻�쑝濡� No
		// 紐낆떆�쟻�쑝濡쒕뒗 OK

		// Stack [二쇱냼] 
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		Item* item = (Item*)knight;
		item->_itemType = 2;
		
		/*
		item->_itemDbId = 1;
		
		delete knight; 
		*/
		
<<<<<<< HEAD
		// 경우에 따라서 터지지 않을 수도 있다.
		// 타입변환 캐스팅 잘못하면 망한다. 
=======
		// 寃쎌슦�뿉 �뵲�씪�꽌 �꽣吏�吏� �븡�쓣 �닔�룄 �엳�떎.
		// ����엯蹂��솚 罹먯뒪�똿 �옒紐삵븯硫� 留앺븳�떎. 
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5

	}


<<<<<<< HEAD
	// 부모 -> 자식 변환 테스트

	{

		// Item은 무기냐? 방어구일수도있고..
		
		Item* item = new Item();

		// Weapon& weapon = item; // 작은 메모리에서 큰메모리에 가는거라서.. 위험하잖아


		// 근데 주장을 강하게 하면.. 컴파일러가 통과가능
		Weapon* weapon = (Weapon*)item;
		
		// 엉뚱한 메모리 건드리기 // crash
=======
	// 遺�紐� -> �옄�떇 蹂��솚 �뀒�뒪�듃

	{

		// Item��� 臾닿린�깘? 諛⑹뼱援ъ씪�닔�룄�엳怨�..
		
		Item* item = new Item();

		// Weapon& weapon = item; // �옉��� 硫붾え由ъ뿉�꽌 �겙硫붾え由ъ뿉 媛��뒗嫄곕씪�꽌.. �쐞�뿕�븯�옏�븘


		// 洹쇰뜲 二쇱옣�쓣 媛뺥븯寃� �븯硫�.. 而댄뙆�씪�윭媛� �넻怨쇨���뒫
		Weapon* weapon = (Weapon*)item;
		
		// �뿁�슧�븳 硫붾え由� 嫄대뱶由ш린 // crash
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		/*weapon->_damage = 10;

		delete item;*/


	}


	{

<<<<<<< HEAD
		// 자식에서 부모가 되는 경우
		Weapon* weapon = new Weapon();
		//Item* item = (Item*)weapon; // 생략 가능
		// 암시적으로도 된다.
=======
		// �옄�떇�뿉�꽌 遺�紐④�� �릺�뒗 寃쎌슦
		Weapon* weapon = new Weapon();
		//Item* item = (Item*)weapon; // �깮�왂 媛��뒫
		// �븫�떆�쟻�쑝濡쒕룄 �맂�떎.
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		Item* item = weapon;

		delete weapon;

	}

<<<<<<< HEAD
	// 명시적으로 타입 변환할 때는 항상 조심해야한다.
	// 암시적으로는 항상 될때는 안전한가?
	// -> 평생 명시적으로 타입변환은 안 하면 되는거 아닌가?
=======
	// 紐낆떆�쟻�쑝濡� ����엯 蹂��솚�븷 �븣�뒗 �빆�긽 議곗떖�빐�빞�븳�떎.
	// �븫�떆�쟻�쑝濡쒕뒗 �빆�긽 �맆�븣�뒗 �븞�쟾�븳媛�?
	// -> �룊�깮 紐낆떆�쟻�쑝濡� ����엯蹂��솚��� �븞 �븯硫� �릺�뒗嫄� �븘�땶媛�?
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5


	Item* inventory[20] = {};


<<<<<<< HEAD
	// 둘다를 커버할 수 있는 아이템 포인터를 만들어주는게 좋다는거지.
=======
	// �몮�떎瑜� 而ㅻ쾭�븷 �닔 �엳�뒗 �븘�씠�뀥 �룷�씤�꽣瑜� 留뚮뱾�뼱二쇰뒗寃� 醫뗫떎�뒗嫄곗��.
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5


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
<<<<<<< HEAD
		if (item->_itemType == IT_WEAPON) // Armor의 생성자에 IT_WEAPON을 넣어서 오동작보여주자.
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
			// 왔다갔다!
=======
		if (item->_itemType == IT_WEAPON) // Armor�쓽 �깮�꽦�옄�뿉 IT_WEAPON�쓣 �꽔�뼱�꽌 �삤�룞�옉蹂댁뿬二쇱옄.
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
			// �솕�떎媛붾떎!
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		}

	}

<<<<<<< HEAD
	// ----중요-----
=======
	// ----以묒슂-----
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5


	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i]; 
<<<<<<< HEAD
		// 인벤토리를 item이라는 포인터로 관리하는데..안에는 실제 여러가지가있지
=======
		// �씤踰ㅽ넗由щ�� item�씠�씪�뒗 �룷�씤�꽣濡� 愿�由ы븯�뒗�뜲..�븞�뿉�뒗 �떎�젣 �뿬�윭媛�吏�媛��엳吏�
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5

		if (item == nullptr)
			continue;

		/*delete item;
<<<<<<< HEAD
		// 모두 item 소멸자만 호출이되잖아
		// 이러면안된다는거지
=======
		// 紐⑤몢 item �냼硫몄옄留� �샇異쒖씠�릺�옏�븘
		// �씠�윭硫댁븞�맂�떎�뒗嫄곗��
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		
		
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

<<<<<<< HEAD
		// 그래서 소멸자에 virtual을 붙여줘야겠지?
=======
		// 洹몃옒�꽌 �냼硫몄옄�뿉 virtual�쓣 遺숈뿬以섏빞寃좎��?
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5


	}


	return 0;


}