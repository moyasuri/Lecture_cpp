#include <iostream>

using namespace std;



// 객체지향 3가지 
// 다형성, 은닉성(캡슐화) 상속성

class Player {

public:
	Player()
	{
		cout << "Player 기본 생성자 등장" << endl;

	}
	Player(int hp)
	{
		cout << "Player hp 생성자 등장" << endl;

		_hp = hp;
	}
	~Player()
	{ 
		cout << "Player 소멸자 등장" << endl;
	}

	void Move()
	{
		cout << "Player의 Move 호출" << endl;
	}
	void Attack()
	{
		cout << "Player의 Attack 호출" << endl;
	}
	void die()
	{
		cout << "Player의 Die 호출" << endl;
	}

public:

	int _hp;
	int _attack;
	int _defence;


};




class Knight : public Player
{

public:
	Knight()
	{
		cout << "Knight 생성자" << endl;
	}

	Knight(int stamina) : Player(100)
	{
		_stamina = stamina;
		cout << "Knight stamina 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "Knight 소멸자" << endl;
	}

	void Move() { cout << "Move 호출" << endl; }


public:
	int _stamina;

	

};

class Archer : public Player
{

public:
	Archer()
	{
		cout << "Archer 생성자" << endl;
	}

	~Archer()
	{
		cout << "Archer 소멸자" << endl;
	}

	void Move() { cout << "Move 호출" << endl; }


public:
	int _arrow;



};

class Mage : public Player
{

public:
	Mage()
	{
		cout << "Mage 생성자" << endl;
	}

	~Mage()
	{
		cout << "Mage 소멸자" << endl;
	}

	void Move() { cout << "Move 호출" << endl; }


public:
	int _mp;

};


int main() {

	

	Knight k1(40);
	k1._attack = 10;
	k1._defence = 20;

	k1._stamina = 40;
	cout << k1._hp;
	k1.Attack();
	k1.Player::Move();



	// f5 -> 콘솔창에 뜨는 문자열은?? -> 나이트에 생성자 


}