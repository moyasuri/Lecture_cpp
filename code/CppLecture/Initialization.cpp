#include <iostream>
using namespace std;

// 초기화리스트

// stack memory 예시를 보여주자..


class Player
{

public:
	Player() { }
	Player(int id) { }


};


// is-A (Knight Is-A Player?)   yes -> 상속관계
// Has-A (Knight Has-A Inventory?) yes -> 포함관계

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl; _size = size; }

	~Inventory() { cout << "-Inventory()" << endl; }


public:
	int _size;

};


class Knight : public Player
{
public:

	Knight() : _hpRef(_hp), _hpConst(10)
	{ cout << "Knight" << endl; } // 가지고 있는 클래스가 먼저 호출이 된다.
	Knight(int value, int value2) : Player(1),_mp(value), _stamina(value2),_inventory(20),_hpRef(_hp), _hpConst(100)// 초기화 리스트

		/*
			선처리 영역
			_inventory = Inventory()
			위와 같은일이 일어나지 않기 위해 초기화 리스트에서 해야함
		*/

	{

		cout << "Knight(int value, int value2)" << endl;
		_hp = 100; // 생성자 내에서
		

		// _hpRef = _hp; // 이게 참조에서 안된다는거 알고 있지?
		// _hpConst= 100;


		// _inventory = Inventory(20);
	}



	~Knight()
	{
		cout << "~Knight" << endl;
	}

public:
	int _hp = 100; // C++11 문법
	int _mp = 30;
	int _stamina = 20;
	Inventory _inventory; // 엄밀히 이야기하면 Player가 가지고 있는게 좋겟지만 일단 기사가 가지고 있다고 생각
	// 또한 기사가 생성될때 인벤토리도 만들어짐
	// 나이트가 소멸이 될때 인벤토리도 소멸이되겠지
	

	int& _hpRef;
	const int _hpConst;


};



int main(){

	Knight k(10,20); // stack memory
	cout << k._hp << endl;

	return 0;
}
extern myvariable;
