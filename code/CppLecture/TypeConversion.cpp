#include <iostream>
using namespace std;

<<<<<<< HEAD
// Ÿ�Ժ�ȯ ������
=======
// 타입변환 포인터
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5

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

<<<<<<< HEAD
	// ��������ڰ� ȣ���� �ȴ�.
	// ������ �Ҹ���
=======
	// 복사생성자가 호출이 된다.
	// 끝날때 소멸자
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
}

void TestItemPtr(Item* item)
{

}

int main()
{

	{
		// Stack [type[4] dbid[4] dummy[4096] ]
		Item item;

<<<<<<< HEAD
		// Stack [ �ּ�(4(32) 8(64)����Ʈ ] -> Heap �ּ� [type[4] dbid[4] dummy[4096]]
		Item* item2 = new Item(item);

		TestItem(item); // ������ ����
=======
		// Stack [ 주소(4(32) 8(64)바이트 ] -> Heap 주소 [type[4] dbid[4] dummy[4096]]
		Item* item2 = new Item(item);

		TestItem(item); // 데이터 복사
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		TestItem(*item2);

		TestItemPtr(&item);
		TestItemPtr(item2);

		delete item2;

	}



<<<<<<< HEAD
	// �迭
	{

		cout << "----------------" << endl;
		// ������ 100��, ������ 100��
=======
	// 배열
	{

		cout << "----------------" << endl;
		// 아이템 100개, 생성자 100개
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		Item item3[100] = {};


		cout << "----------------" << endl;
<<<<<<< HEAD
		// �������� ����Ű�� �ٱ��ϰ� 100��, ���� �������� 1���� ���� �� ����.
=======
		// 아이템을 가리키는 바구니가 100개, 실제 아이템은 1개도 없을 수 있음.
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5

		Item* item4[100] = {};

		for (int i = 0; i < 100; i++)
			item4[i] = new Item();

		cout << "----------------" << endl;

		for (int i = 0; i < 100; i++)
			delete item4[i];

		cout << "----------------" << endl;
		
	}
<<<<<<< HEAD
	// �� �ڴ� ������ 3�� �Ҹ�.
=======
	// 이 뒤는 아이템 3이 소멸.
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5




	return 0;


}