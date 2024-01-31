#include <iostream>
using namespace std;

<<<<<<< HEAD
// Å¸ÀÔº¯È¯ Æ÷ÀÎÅÍ
=======
// íƒ€ìž…ë³€í™˜ í¬ì¸í„°
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
	// º¹»ç»ý¼ºÀÚ°¡ È£ÃâÀÌ µÈ´Ù.
	// ³¡³¯¶§ ¼Ò¸êÀÚ
=======
	// ë³µì‚¬ìƒì„±ìžê°€ í˜¸ì¶œì´ ëœë‹¤.
	// ëë‚ ë•Œ ì†Œë©¸ìž
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
		// Stack [ ÁÖ¼Ò(4(32) 8(64)¹ÙÀÌÆ® ] -> Heap ÁÖ¼Ò [type[4] dbid[4] dummy[4096]]
		Item* item2 = new Item(item);

		TestItem(item); // µ¥ÀÌÅÍ º¹»ç
=======
		// Stack [ ì£¼ì†Œ(4(32) 8(64)ë°”ì´íŠ¸ ] -> Heap ì£¼ì†Œ [type[4] dbid[4] dummy[4096]]
		Item* item2 = new Item(item);

		TestItem(item); // ë°ì´í„° ë³µì‚¬
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		TestItem(*item2);

		TestItemPtr(&item);
		TestItemPtr(item2);

		delete item2;

	}



<<<<<<< HEAD
	// ¹è¿­
	{

		cout << "----------------" << endl;
		// ¾ÆÀÌÅÛ 100°³, »ý¼ºÀÚ 100°³
=======
	// ë°°ì—´
	{

		cout << "----------------" << endl;
		// ì•„ì´í…œ 100ê°œ, ìƒì„±ìž 100ê°œ
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		Item item3[100] = {};


		cout << "----------------" << endl;
<<<<<<< HEAD
		// ¾ÆÀÌÅÛÀ» °¡¸®Å°´Â ¹Ù±¸´Ï°¡ 100°³, ½ÇÁ¦ ¾ÆÀÌÅÛÀº 1°³µµ ¾øÀ» ¼ö ÀÖÀ½.
=======
		// ì•„ì´í…œì„ ê°€ë¦¬í‚¤ëŠ” ë°”êµ¬ë‹ˆê°€ 100ê°œ, ì‹¤ì œ ì•„ì´í…œì€ 1ê°œë„ ì—†ì„ ìˆ˜ ìžˆìŒ.
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
	// ÀÌ µÚ´Â ¾ÆÀÌÅÛ 3ÀÌ ¼Ò¸ê.
=======
	// ì´ ë’¤ëŠ” ì•„ì´í…œ 3ì´ ì†Œë©¸.
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5




	return 0;


}