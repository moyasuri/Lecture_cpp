#include <iostream>
using namespace std;

<<<<<<< HEAD
// Å¸ÀÔº¯È¯ Æ÷ÀÎÅÍ
=======
// íƒ€ì…ë³€í™˜ í¬ì¸í„°
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
	// º¹»ç»ı¼ºÀÚ°¡ È£ÃâÀÌ µÈ´Ù.
	// ³¡³¯¶§ ¼Ò¸êÀÚ
=======
	// ë³µì‚¬ìƒì„±ìê°€ í˜¸ì¶œì´ ëœë‹¤.
	// ëë‚ ë•Œ ì†Œë©¸ì
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
}

void TestItemPtr(Item* item)
{

}

int main()
{
<<<<<<< HEAD
	// ¿¬°ü¼ºÀÌ ¾ø´Â Å¬·¡½º »çÀÌÀÇ Æ÷ÀÎÅÍ º¯È¯ Å×½ºÆ®
	{

		// Stack [ÁÖ¼Ò] -> Heap [_hp(4)]
		Knight* knight = new Knight();

		// ¾Ï½ÃÀûÀ¸·Î No
		// ¸í½ÃÀûÀ¸·Î´Â OK

		// Stack [ÁÖ¼Ò] 
=======
	// ì—°ê´€ì„±ì´ ì—†ëŠ” í´ë˜ìŠ¤ ì‚¬ì´ì˜ í¬ì¸í„° ë³€í™˜ í…ŒìŠ¤íŠ¸
	{

		// Stack [ì£¼ì†Œ] -> Heap [_hp(4)]
		Knight* knight = new Knight();

		// ì•”ì‹œì ìœ¼ë¡œ No
		// ëª…ì‹œì ìœ¼ë¡œëŠ” OK

		// Stack [ì£¼ì†Œ] 
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		Item* item = (Item*)knight;
		item->_itemType = 2;
		
		/*
		item->_itemDbId = 1;
		
		delete knight; 
		*/
		
<<<<<<< HEAD
		// °æ¿ì¿¡ µû¶ó¼­ ÅÍÁöÁö ¾ÊÀ» ¼öµµ ÀÖ´Ù.
		// Å¸ÀÔº¯È¯ Ä³½ºÆÃ Àß¸øÇÏ¸é ¸ÁÇÑ´Ù. 
=======
		// ê²½ìš°ì— ë”°ë¼ì„œ í„°ì§€ì§€ ì•Šì„ ìˆ˜ë„ ìˆë‹¤.
		// íƒ€ì…ë³€í™˜ ìºìŠ¤íŒ… ì˜ëª»í•˜ë©´ ë§í•œë‹¤. 
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5

	}


<<<<<<< HEAD
	// ºÎ¸ğ -> ÀÚ½Ä º¯È¯ Å×½ºÆ®

	{

		// ItemÀº ¹«±â³Ä? ¹æ¾î±¸ÀÏ¼öµµÀÖ°í..
		
		Item* item = new Item();

		// Weapon& weapon = item; // ÀÛÀº ¸Ş¸ğ¸®¿¡¼­ Å«¸Ş¸ğ¸®¿¡ °¡´Â°Å¶ó¼­.. À§ÇèÇÏÀİ¾Æ


		// ±Ùµ¥ ÁÖÀåÀ» °­ÇÏ°Ô ÇÏ¸é.. ÄÄÆÄÀÏ·¯°¡ Åë°ú°¡´É
		Weapon* weapon = (Weapon*)item;
		
		// ¾û¶×ÇÑ ¸Ş¸ğ¸® °Çµå¸®±â // crash
=======
	// ë¶€ëª¨ -> ìì‹ ë³€í™˜ í…ŒìŠ¤íŠ¸

	{

		// Itemì€ ë¬´ê¸°ëƒ? ë°©ì–´êµ¬ì¼ìˆ˜ë„ìˆê³ ..
		
		Item* item = new Item();

		// Weapon& weapon = item; // ì‘ì€ ë©”ëª¨ë¦¬ì—ì„œ í°ë©”ëª¨ë¦¬ì— ê°€ëŠ”ê±°ë¼ì„œ.. ìœ„í—˜í•˜ì–ì•„


		// ê·¼ë° ì£¼ì¥ì„ ê°•í•˜ê²Œ í•˜ë©´.. ì»´íŒŒì¼ëŸ¬ê°€ í†µê³¼ê°€ëŠ¥
		Weapon* weapon = (Weapon*)item;
		
		// ì—‰ëš±í•œ ë©”ëª¨ë¦¬ ê±´ë“œë¦¬ê¸° // crash
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		/*weapon->_damage = 10;

		delete item;*/


	}


	{

<<<<<<< HEAD
		// ÀÚ½Ä¿¡¼­ ºÎ¸ğ°¡ µÇ´Â °æ¿ì
		Weapon* weapon = new Weapon();
		//Item* item = (Item*)weapon; // »ı·« °¡´É
		// ¾Ï½ÃÀûÀ¸·Îµµ µÈ´Ù.
=======
		// ìì‹ì—ì„œ ë¶€ëª¨ê°€ ë˜ëŠ” ê²½ìš°
		Weapon* weapon = new Weapon();
		//Item* item = (Item*)weapon; // ìƒëµ ê°€ëŠ¥
		// ì•”ì‹œì ìœ¼ë¡œë„ ëœë‹¤.
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		Item* item = weapon;

		delete weapon;

	}

<<<<<<< HEAD
	// ¸í½ÃÀûÀ¸·Î Å¸ÀÔ º¯È¯ÇÒ ¶§´Â Ç×»ó Á¶½ÉÇØ¾ßÇÑ´Ù.
	// ¾Ï½ÃÀûÀ¸·Î´Â Ç×»ó µÉ¶§´Â ¾ÈÀüÇÑ°¡?
	// -> Æò»ı ¸í½ÃÀûÀ¸·Î Å¸ÀÔº¯È¯Àº ¾È ÇÏ¸é µÇ´Â°Å ¾Æ´Ñ°¡?
=======
	// ëª…ì‹œì ìœ¼ë¡œ íƒ€ì… ë³€í™˜í•  ë•ŒëŠ” í•­ìƒ ì¡°ì‹¬í•´ì•¼í•œë‹¤.
	// ì•”ì‹œì ìœ¼ë¡œëŠ” í•­ìƒ ë ë•ŒëŠ” ì•ˆì „í•œê°€?
	// -> í‰ìƒ ëª…ì‹œì ìœ¼ë¡œ íƒ€ì…ë³€í™˜ì€ ì•ˆ í•˜ë©´ ë˜ëŠ”ê±° ì•„ë‹Œê°€?
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5


	Item* inventory[20] = {};


<<<<<<< HEAD
	// µÑ´Ù¸¦ Ä¿¹öÇÒ ¼ö ÀÖ´Â ¾ÆÀÌÅÛ Æ÷ÀÎÅÍ¸¦ ¸¸µé¾îÁÖ´Â°Ô ÁÁ´Ù´Â°ÅÁö.
=======
	// ë‘˜ë‹¤ë¥¼ ì»¤ë²„í•  ìˆ˜ ìˆëŠ” ì•„ì´í…œ í¬ì¸í„°ë¥¼ ë§Œë“¤ì–´ì£¼ëŠ”ê²Œ ì¢‹ë‹¤ëŠ”ê±°ì§€.
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
		if (item->_itemType == IT_WEAPON) // ArmorÀÇ »ı¼ºÀÚ¿¡ IT_WEAPONÀ» ³Ö¾î¼­ ¿Àµ¿ÀÛº¸¿©ÁÖÀÚ.
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
			// ¿Ô´Ù°¬´Ù!
=======
		if (item->_itemType == IT_WEAPON) // Armorì˜ ìƒì„±ìì— IT_WEAPONì„ ë„£ì–´ì„œ ì˜¤ë™ì‘ë³´ì—¬ì£¼ì.
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
			// ì™”ë‹¤ê°”ë‹¤!
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5
		}

	}

<<<<<<< HEAD
	// ----Áß¿ä-----
=======
	// ----ì¤‘ìš”-----
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5


	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i]; 
<<<<<<< HEAD
		// ÀÎº¥Åä¸®¸¦ itemÀÌ¶ó´Â Æ÷ÀÎÅÍ·Î °ü¸®ÇÏ´Âµ¥..¾È¿¡´Â ½ÇÁ¦ ¿©·¯°¡Áö°¡ÀÖÁö
=======
		// ì¸ë²¤í† ë¦¬ë¥¼ itemì´ë¼ëŠ” í¬ì¸í„°ë¡œ ê´€ë¦¬í•˜ëŠ”ë°..ì•ˆì—ëŠ” ì‹¤ì œ ì—¬ëŸ¬ê°€ì§€ê°€ìˆì§€
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5

		if (item == nullptr)
			continue;

		/*delete item;
<<<<<<< HEAD
		// ¸ğµÎ item ¼Ò¸êÀÚ¸¸ È£ÃâÀÌµÇÀİ¾Æ
		// ÀÌ·¯¸é¾ÈµÈ´Ù´Â°ÅÁö
=======
		// ëª¨ë‘ item ì†Œë©¸ìë§Œ í˜¸ì¶œì´ë˜ì–ì•„
		// ì´ëŸ¬ë©´ì•ˆëœë‹¤ëŠ”ê±°ì§€
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
		// ±×·¡¼­ ¼Ò¸êÀÚ¿¡ virtualÀ» ºÙ¿©Áà¾ß°ÚÁö?
=======
		// ê·¸ë˜ì„œ ì†Œë©¸ìì— virtualì„ ë¶™ì—¬ì¤˜ì•¼ê² ì§€?
>>>>>>> c52f8c6274a0e7e04d1ff4846597d8577e26ccb5


	}


	return 0;


}