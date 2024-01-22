#include <iostream>
using namespace std;

// callback

class Item
{
public:


public:

	int _itemId = 0;
	int _rarity = 0;
	int _ownerId = 0;


};

class FindByOwnerId
{
public:
	bool operator()(const Item* item) // Item을 딱히 수정할 생각은 아님 const 붙이기
	{
		return (item->_ownerId == _ownerId);
	}

public:
	int _ownerId;

};

class FindByRarity
{
public:
	bool operator()(const Item* item) // Item을 딱히 수정할 생각은 아님 const 붙이기
	{
		return (item->_rarity >= _rarity);
	}

public:
	int _rarity; // 각기 다른 값을 가질 수 있음

};

// Item* FindItem(Item items[], int itemCount, bool(*func)(const Item*)) 지정된 시그니쳐 함수포인터밖에 쓰지를 못하는거야.


template<typename T>
// Item* FindItem(Item items[], int itemCount, FindByOwnerId selector)
Item* FindItem(Item items[], int itemCount, T selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		// Todo : 조건체크
		if(selector(item))
			return item;
	}

	return nullptr;
}

int main()
{

	// 함수 포인터 + 함수 객체 + 템플릿

	// 콜백 (Call back) : 다시 호출
	// ex) MoveTask -> 나중에 미뤄서, 다시 호출

	// 어떤 상황이 일어나면 -> 이 기능을 호출해줘
	// ex) UI 스킬 버튼을 누르면 -> 스킬을 쓰는 함수를 호출

	Item items[10];
	items[3]._ownerId = 100;
	items[8]._rarity = 2;
	FindByOwnerId functor1;
	functor1._ownerId = 100;
	
	FindByRarity functor2;
	functor2._rarity = 1;

	Item* item1 = FindItem(items, 10, functor1);
	Item* item2 = FindItem(items, 10, functor2);
	

	cout << item1->_itemId;



	return 0;
}
