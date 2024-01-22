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
	bool operator()(const Item* item) // Item�� ���� ������ ������ �ƴ� const ���̱�
	{
		return (item->_ownerId == _ownerId);
	}

public:
	int _ownerId;

};

class FindByRarity
{
public:
	bool operator()(const Item* item) // Item�� ���� ������ ������ �ƴ� const ���̱�
	{
		return (item->_rarity >= _rarity);
	}

public:
	int _rarity; // ���� �ٸ� ���� ���� �� ����

};

// Item* FindItem(Item items[], int itemCount, bool(*func)(const Item*)) ������ �ñ״��� �Լ������͹ۿ� ������ ���ϴ°ž�.


template<typename T>
// Item* FindItem(Item items[], int itemCount, FindByOwnerId selector)
Item* FindItem(Item items[], int itemCount, T selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		// Todo : ����üũ
		if(selector(item))
			return item;
	}

	return nullptr;
}

int main()
{

	// �Լ� ������ + �Լ� ��ü + ���ø�

	// �ݹ� (Call back) : �ٽ� ȣ��
	// ex) MoveTask -> ���߿� �̷Ｍ, �ٽ� ȣ��

	// � ��Ȳ�� �Ͼ�� -> �� ����� ȣ������
	// ex) UI ��ų ��ư�� ������ -> ��ų�� ���� �Լ��� ȣ��

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
