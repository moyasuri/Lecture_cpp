#include <iostream>
using namespace std;

// 함수 포인터 : 함수 포인터



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
	int _itemId; // 아이템을 구분하기 위한 ID
	int _rarity; // 희귀도
	int _ownerId; //소지자 ID

};

// 파라메터에 함수를 넣을 순 없을까?, 함수가 조건이 되면 좋을거같은데! 
// 밑에서 나온 selector는 그저 이름이야


// IsOwnerItem 의 함수 때문에  int 를 받는 시그니쳐를 만들어 볼까?
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


	// 아이템을 못찾았다!하면은 nullptr 반환
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

	// pointer[주소]  -> 주소 [int 값]
	int* pointer = &a;

	// 1) 포인터 *
	// 2) 변수 이름 pointer
	// 3) 데이터 타입
	
	typedef int DATA; // typedefinition int DATA , int형식의 또다른 이름을 DATA라고 하겠다.
	

	DATA* ptr = &a;
	*ptr = 40; // 값 수정 가능


	// 의문 사항이 생김.
	// 함수를 타입으로 만들어서, 포인터를 타고가면 함수가 있어요라는 정의를 내리고 싶어.

	// 함수의 시그니쳐
	// int(int a, int b); 

	// typedef int(int a, int b) FUNDATA; <= 일반적인 데이터타입 정할때는 이렇게인것처럼 보이지만, 함수는!
	typedef int(FUNC_TYPE)(int a, int b); // int 2개를 받고, int 1개를 return 하는 함수를 FUNC_TYPE이라고 부르기로 하자.
	typedef int(FUNC_TYPE2)(int a); // 변형

	// 괄호 안에 들어간 (FUNC_TYPE)은 함수의 시그니쳐를 정의하고 있는것이다!!!!


	// modern cpp(추후에 배울)에서는, 아래와 같이 표현함.
	using FUNC_TYPE3 = int(int a, int b);


	// typedef에 쓰인 a , b는 생략을 해도 ok, 우리는 signiture가 중요한 것!


	// 함수를 정의했으니, 함수포인터를 만들어보자.


	DATA result = Add(1, 2);
	cout << result << endl;

	// 1. 포인터 *
	// 2. 변수이름 fn
	// 3. 데이터 타입 함수 (인자는 int, int 반환은 int)
	
	
	FUNC_TYPE* fn;
	fn = Add;
	cout << fn(3, 4)<<endl;

	
	
	int result2 = (*fn)(1, 4); // 함수 포인터는 *(접근 연산자)가 붙어도 함수 주소를 가리킴.
	cout << result2 << endl;


	// 문법적으로 한단계를 더거치는 이유가 뭐지?
	// -> 만약에 시그니쳐가 매우 유사한 함수를 하나 더만들어보자.sub
	// 이때 함수 포인터로 기능을 구현했다면, 함수 포인터의 주소를 sub로 가리키는 것만으로도 모든 함수를 바꿀 수 있다.



	

	Item items[10] = {};
	items[3]._rarity = 2; //rare
	Item* rareItem = FindItem(items, 10, IsRareItem, 2); // 희귀도 찾기
	Item* OwnerItem = FindItem(items, 10, IsOwnerItem, 100); // 주인찾기


	cout << rareItem->_rarity;
	/*
	bool IsRareItem(Item * item)
	{
		return item->_rarity >= 2;

	}
	*/

	// 단점 1 정확하게 시그니쳐가 일치해야함!
	
	// 아래의 함수를 넣으려고하면 int ownerId가 추가적으로 필요해지면서 signiture가 달라지게 되어!
	/*
	bool IsOwnerItem(Item * item, int ownerId)
	{

		return item->_ownerId == ownerId;
	}

	*/


	// 단점 2 인자타입이 달라지게 된다면.. int double... 등등
	// 

	// 이를 해결하기 위해 나중에는 객체를 집어넣는다.


	return 0;


}