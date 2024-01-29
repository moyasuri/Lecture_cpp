#include <iostream>

using namespace std;

#define OUT
struct StatInfo
{
	int hp = 10;
	int attack;
	int defence;
};

void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

// 값을 수정하지 않는다면,

// 값전달방식


// [매개변수][ret][지역변수(info)][매개변수(info)][ret][지역변수]
void PrintInfoByCopy(StatInfo info)
{
	cout << "-------------------------" << endl;
	cout << "hp :" << info.hp << endl;
	cout << "att :" << info.attack << endl;
	cout << "def :" << info.defence << endl;
	cout << "-------------------------" << endl;
}

// 주소전달방식

void PrintInfoByPtr(StatInfo* info)
{
	cout << "-------------------------" << endl;
	cout << "hp :" << info->hp << endl;
	cout << "att :" << info->attack << endl;
	cout << "def :" << info->defence << endl;
	cout << "-------------------------" << endl;

}

// StatInfo 구조체가 1000바이트짜리 대형구조체라면?
// - 값전달과, 주소전달이 차이가 많이난다.
// 값전달 statinfo 넘기면 1000바이트 복사
// 주소전달 StatInfo* 는 8바이트
// 참조전달 StatInfo 는 8바이트


// 3번째 옵션 참조전달 (cpp)에서 추가적으로 나온..


// 값 전달처럼 편리하게 사용하고!
// 주소 전달처럼 주소값을 이용함





// 참조 타입은 바구니의 2번째 이름(별칭)
// -> 참조하는 대상이없으면 안됨


// 참조전달방식
void PrintInfoByRef(StatInfo& info)
{
	cout << "-------------------------" << endl;
	cout << "hp :" << info.hp << endl;
	cout << "att :" << info.attack << endl;
	cout << "def :" << info.defence << endl;
	cout << "-------------------------" << endl;

}


int main()
{
	// number라는 identifier를 사용 -> 4바이트 정수형임
	
	int number = 1;
	int* pointer = &number;

	*pointer = 2;
	
	// 작동방식 : int number, 동작방식 : *int pointer
	int& reference = number;

	// cpp 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	// number라는 바구니에 reference라는 다른 이름을 지어줄께
	// 앞으로 reference 바구니에 뭘 꺼내거나 넣으면,
	// 실제 number 바구니(진퉁에다가) 그 값을 거내거나 넣으면 됨
	
	reference = 3;
	

	// 귀찮게 또 다른 이름을 왜 지을까?
	// 참조전달 때문이다.
	// -> 이 기호가 좀 맘에안들수있다는거지.



	StatInfo info;
	StatInfo* pointer2;
	pointer2 = &info;
	PrintInfoByPtr(pointer2);


	// StatInfo& reference2; // 어떠한 값이라도 참조를 하고 있어야 한다.
	// reference2 = info;
	
	// NULL , 0 , nullptr 설명
	StatInfo& reference2 = info;
	PrintInfoByRef(reference2);
	
	// 섞어서 사용하지는 않음!
	// ChangeInfo(OUT info);

	StatInfo mystat;
	
	PrintInfoByRef(*pointer2);
	// 뭐 혹은.. StatInfo& ref3 = *pointer2;
	// PrintInfoByRef(ref3);
	
	// 참조하던걸 포인터로 넘겨주기
	// StatInfo& myptr = &reference2;
	// PrintInfoByPtr(myptr);
	PrintInfoByPtr(&reference2);

}