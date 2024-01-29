#include <iostream>

// 1) struct vs class

// struct는 기본 접근 지정자가 public이고 , class는 private이다.

// why? - > c++은 c언어에서 파생되어 발전했기 때문에, 호환성을 지키기 위함.

// -> struct는 데이터 묶음을 표현하는 용도
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도




// 2) static 변수, static 함수 (static = 정적 = 고정된)

class Marine
{

public:
	int _hp;
	int _attack;

};



class Marine
{

public:
	// 마린 클래스에 종속적
	int _hp;


	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void Test()
	{

		_hp = 100; // 종속적인 변수를 건들면 에러를 뱉어
		TakeDamage(10); // 함수도 마찬가지

		s_attack = 100; // 독립적인 스태틱 변수는 수정 가능.
	}


	static void SetAttack()
	{
		s_attack = 10;

	}



	// 특정마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static int s_attack; // 설계도만으로만 존재

};


// 정적 전역 객체
static int s_global = 1;


int Marine::s_attack = 0; // 마린 클래스의 종속
// 실제 메모리상에는 어디있을까?
// 완전 다른 공간에 있다.
// 초기화를 하면 .data영역
// 안하면 .bss 영역



void Marine::Test()
{

	_hp = 100;
}

struct TestStruct
{
	int _a;
	int _b;
};

class TestClass
{
	int _a;
	int _b;
};


int main()
{

	Marine m1;
	m1._hp = 40;
	m1._attack = 6;

	Marine m2;
	m2._hp = 40;
	m2._attack = 6;

	// 모든 마린들을 찾아서 공격력을 업그레이드??
	m1._attack = 7;
	m2._attack = 7;

	// 물론 hp는 각각 다른 값들을 가지고 있어야 해




	TestStruct ts;
	ts._a = 1;

	TestClass tc;
	tc._a = 1;
}





int main()
{

	int Marine::s_attack = 6;

	Marine m1;
	m1._hp = 40;
	m1.s_attack = 6;

	Marine m2;
	m2._hp = 40;
	m2.s_attack = 6;

	// 모든 마린들을 찾아서 공격력을 업그레이드??

	static int s_attack = 7;

	m1.s_attack = 7;
	m2.s_attack = 7;

	// 물론 hp는 각각 다른 값들을 가지고 있어야 해



	TakeDamage(); // 종속적인 함수
	m1.TakeDamage(2);

	Marine::SetAttack(7);

}



class Player
{

public:
	int _id;

};

int GenerateId()
{

	// 1씩 증가하는 id를 뱉자

	// 생명주기: 프로그램 시작 / 종료 (메모리에 항상 올라가 있음)
	// 가시범위:


	// 정적 지역 객체
	// 함수 내부에 선언했다고 해도 data영역!
	static int s_id = 1; // 초기화는 한번!




	// 비교를 위한

	int s_id = 1; // 이렇게 선언한다면, Generatid가 호출될때마다 스택영역에 쌓이는 s_id 겠지만


	return s_id++;
}

int main()
{

	

	static int id = 10;
	int a = id;

	GenerateId();
	GenerateId();
	GenerateId();




}






#include<iostream>

int i = 1;
int main()
{



}


///
// 외부 링크를 가지는 전역 변수
int i = 1;

// 내부 링크를 가지는 전역 변수 (다른 소스 파일에서 접근 불가)
static int j = 2;