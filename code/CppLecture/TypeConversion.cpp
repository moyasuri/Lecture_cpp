#include <iostream>
using namespace std;

// Ÿ�Ժ�ȯ ������

class Item
{
public:
	Item()
	{

		cout << "Item()" << endl;
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

	{
		// Stack [type[4] dbid[4] dummy[4096] ]
		Item item;

		// Stack [ �ּ�(4(32) 8(64)����Ʈ ] -> Heap �ּ� [type[4] dbid[4] dummy[4096]]
		Item* item2 = new Item(item);

		TestItem(item); // ������ ����
		TestItem(*item2);

		TestItemPtr(&item);
		TestItemPtr(item2);

		delete item2;

	}



	// �迭
	{

		cout << "----------------" << endl;
		// ������ 100��, ������ 100��
		Item item3[100] = {};


		cout << "----------------" << endl;
		// �������� ����Ű�� �ٱ��ϰ� 100��, ���� �������� 1���� ���� �� ����.

		Item* item4[100] = {};

		for (int i = 0; i < 100; i++)
			item4[i] = new Item();

		cout << "----------------" << endl;

		for (int i = 0; i < 100; i++)
			delete item4[i];

		cout << "----------------" << endl;
		
	}
	// �� �ڴ� ������ 3�� �Ҹ�.




	return 0;


}