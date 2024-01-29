// ploy + morph(신체, 몸의 어근)



#include <iostream>
using namespace std;


// 다형성 = 겉은 똑같은데, 기능이 다르게 작동한다.
// - 오버로딩(Overloading) = 함수 중복 정의 - 함수 이름의 재사용
// - 오버라이딩(Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의


// 바인딩(Binding) = 묶는다.  함수를 호출하면 뭐라 묶어야 될지 결정하는거지
// - 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// - 동적 바인딩(Dynammic Biding) : 실행 시점에 결정

// 일반 함수는 정적 바인딩을 사용. ->a)
// 동적 바인딩을 원한다면? -> 가상 함수( virtual function)


// 실제 객체가 어떤 타입인지 어떻게 알아서 가상함수를 호출해준걸까?
// - 가상 함수테이블 (vftable) 가상함수 테이블


// vftable [] 32bit - > 4바이트  64bit - > 8바이트
// vftable은 생성자를 호출할때 만들어진다.



// 순수 가상 함수 : 구현은 없고.. '인터페이스' 만 전달하는 함수.

class Player
{
public:
	void Move() { cout << "Move Player !" << endl; }
	// void Move() { } 에러
	//void Move(int a) { cout << "Move Player !(int)" << endl; } // 오버로딩
	virtual void VMove() { cout << "Move Player !" << endl; }


	// 사실은. Player가 입장하는경우는 없잖아? 궁수건 기사건 선택해서 입장하는거란말이지.
	
	// 순수 가상함수 선언
	// 구현부가없으며 자식들이 알아서 써먹으란이야기임
	// 또한 순수 가상 함수가 1개 이상 포함되면 바로 추상 클래스로 간주한다.
	// -직접적으로 객체를 만들 수 없게 됨.
	virtual void VAttack() = 0;



public:
	int _hp;
};

class Knight : public Player
{
public:
	void Move() { cout << "Move Knight !" << endl; }
	
	// 가상 함수는 재정의를 하더라도 가상 함수다. // 즉 아래에서 virtual을 안써준다고 하더라도 virtual이 붙은거랑 다름없다.
	virtual void VMove() { cout << "Move Knight !" << endl; }
	// 굉장히 놀랍게도 Player함수에 넣었는데 Knight의 VMove가 시행이 된다.

	virtual void VAttack()
	{

	}

public:
	int _stamina;

};

class Mage : public Player
{
public:
	void Move() { cout << "Move Mage !" << endl; }
};


// a) 원본이 나이트 였다 하더라도, 그냥 나는 함수 그대로를 실행하는거야 , 가상함수를 대입한 후 달라지는거지.


// [  [Player]  ]
// [   Knight   ]
void MovePlayer(Player* player)
{
	player->VMove();

	

}


// 최상위 클래스로 관리가 가능한거야 그래서 필요없어, 아래와 같이쓴다면 객체지향의 관점에서 벗어나
//void MoveKnight (Knight* knight)
//{
//	knight->Move();
//}


int main()
{
	// Player p; // 순수가상함수만들기전에 예시로 보여줬던것.
	//p.Move();
	//p.Move(1);
	// MovePlayer(&p); // 플레이어는 플레이어다? -> yes 플레이어를 넘겨준거다.
	//MoveKnight(&p); // 플레이어는 기사다? 항상 맞다는 보장이 없지. 궁수 일 수도있고..

	Knight k;
	//MoveKnight(&k);
	MovePlayer(&k);

	//k.Move();


}