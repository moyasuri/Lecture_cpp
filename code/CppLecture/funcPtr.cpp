#include <iostream>
using namespace std;

// �Լ� ������ : �Լ� ������



int Add(int a, int b)
{

	return a + b;


}

int Sub(int a, int b)
{
	return a - b;

}

class Item
{
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0)
	{

	}


public:
	int _itemId; // �������� �����ϱ� ���� ID
	int _rarity; // ��͵�
	int _ownerId; //������ ID

};

// �Ķ���Ϳ� �Լ��� ���� �� ������?, �Լ��� ������ �Ǹ� �����Ű�����! 
// �ؿ��� ���� selector�� ���� �̸��̾�


// IsOwnerItem �� �Լ� ������  int �� �޴� �ñ״��ĸ� ����� ����?
// typedef bool(ITEM_SELECTOR)(Item* item);
typedef bool(ITEM_SELECTOR)(Item* , int);

// Item* FindItem(Item items[], int itemCount, bool (*selector)(Item* item))



Item* FindItem(Item items[], int itemCount,  ITEM_SELECTOR* selector, int value)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (selector(item,value))
			return item;
		// ...
	}


	// �������� ��ã�Ҵ�!�ϸ��� nullptr ��ȯ
	return nullptr;
}

bool IsRareItem(Item* item, int value)
{
	return item->_rarity >= value;

}


bool IsOwnerItem(Item* item, int ownerId)
{

	return item->_ownerId == ownerId;
}

int main()
{
	int a = 10;

	// pointer[�ּ�]  -> �ּ� [int ��]
	int* pointer = &a;

	// 1) ������ *
	// 2) ���� �̸� pointer
	// 3) ������ Ÿ��
	
	typedef int DATA; // typedefinition int DATA , int������ �Ǵٸ� �̸��� DATA��� �ϰڴ�.
	

	DATA* ptr = &a;
	*ptr = 40; // �� ���� ����


	// �ǹ� ������ ����.
	// �Լ��� Ÿ������ ����, �����͸� Ÿ���� �Լ��� �־���� ���Ǹ� ������ �;�.

	// �Լ��� �ñ״���
	// int(int a, int b); 

	// typedef int(int a, int b) FUNDATA; <= �Ϲ����� ������Ÿ�� ���Ҷ��� �̷����ΰ�ó�� ��������, �Լ���!
	typedef int(FUNC_TYPE)(int a, int b); // int 2���� �ް�, int 1���� return �ϴ� �Լ��� FUNC_TYPE�̶�� �θ���� ����.
	typedef int(FUNC_TYPE2)(int a); // ����

	// ��ȣ �ȿ� �� (FUNC_TYPE)�� �Լ��� �ñ״��ĸ� �����ϰ� �ִ°��̴�!!!!


	// modern cpp(���Ŀ� ���)������, �Ʒ��� ���� ǥ����.
	using FUNC_TYPE3 = int(int a, int b);


	// typedef�� ���� a , b�� ������ �ص� ok, �츮�� signiture�� �߿��� ��!


	// �Լ��� ����������, �Լ������͸� ������.


	DATA result = Add(1, 2);
	cout << result << endl;

	// 1. ������ *
	// 2. �����̸� fn
	// 3. ������ Ÿ�� �Լ� (���ڴ� int, int ��ȯ�� int)
	
	
	FUNC_TYPE* fn;
	fn = Add;
	cout << fn(3, 4)<<endl;

	
	
	int result2 = (*fn)(1, 4); // �Լ� �����ʹ� *(���� ������)�� �پ �Լ� �ּҸ� ����Ŵ.
	cout << result2 << endl;


	// ���������� �Ѵܰ踦 ����ġ�� ������ ����?
	// -> ���࿡ �ñ״��İ� �ſ� ������ �Լ��� �ϳ� ��������.sub
	// �̶� �Լ� �����ͷ� ����� �����ߴٸ�, �Լ� �������� �ּҸ� sub�� ����Ű�� �͸����ε� ��� �Լ��� �ٲ� �� �ִ�.



	

	Item items[10] = {};
	items[3]._rarity = 2; //rare
	Item* rareItem = FindItem(items, 10, IsRareItem, 2); // ��͵� ã��
	Item* OwnerItem = FindItem(items, 10, IsOwnerItem, 100); // ����ã��


	cout << rareItem->_rarity;
	/*
	bool IsRareItem(Item * item)
	{
		return item->_rarity >= 2;

	}
	*/

	// ���� 1 ��Ȯ�ϰ� �ñ״��İ� ��ġ�ؾ���!
	
	// �Ʒ��� �Լ��� ���������ϸ� int ownerId�� �߰������� �ʿ������鼭 signiture�� �޶����� �Ǿ�!
	/*
	bool IsOwnerItem(Item * item, int ownerId)
	{

		return item->_ownerId == ownerId;
	}

	*/


	// ���� 2 ����Ÿ���� �޶����� �ȴٸ�.. int double... ���
	// 

	// �̸� �ذ��ϱ� ���� ���߿��� ��ü�� ����ִ´�.


	return 0;


}