#include <iostream>

using namespace std;

// 객체 지향 -> 상속성, 은닉성, 다형성


// 함수는.. struct으로 묶어줄수가없다.
struct StatInfo
{
	int _hp;
	int _attack;
	int _defence;
};


// 메모리 보여주자.

// [ [ player]  -> 12바이트 ]
// [  Knight     + 4바이트    ]

// 생성자 소멸자

class Player
{
public:

	Player()
	{
		cout << " player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		cout << " player() hp 생성자 호출" << endl;
		_hp = hp;
	}

	~Player()
	{
		cout << "~player() 소멸자 호출" << endl;
	}

	void Move() { cout << "player의 Move 호출" << endl; }
	void Attack() { cout << "player의 attack 호출" << endl; }
	void die() { cout << "player의 die 호출" << endl; }


public:
	int _hp;
	int _attack;
	int _defence;
};


// 생성자와 소멸자는 물려주는게 아니다.

class Knight : public Player
{

public:

	Knight()
	{
		_stamina = 100;
		cout << " Knight() 기본 생성자 호출" << endl;
	}
	Knight() : Player(100)
	{
		_stamina = 100;
		cout << " Knight() 기본 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}
	void Move() { cout << " Knight의 Move 호출 " << endl; }

public:
	int _stamina;

};

class Mage : public Player
{

	int _mp;

};
class priest : public  Player
{


};

int main()
{
	Knight k;


	k._hp = 100;
	k._attack = 30;
	k._defence = 20;
	k._stamina = 10;

	k.Move();

	k.Player::Move();



}