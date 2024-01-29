#include <iostream>

using namespace std;



// 객체지향 3가지 
// 다형성, 은닉성(캡슐화), 상속성

// 1. 정말위험하고 건드리면 안되는것들
// 2. 다른 경로로 접근하고 싶을 때, 
// get , set

// 엔진
// 조향장치
// 문
// 의자
// 핸들
// 전기선

// 깜빡이
// 클락션
// 와이퍼
// 엔진시동
// 
// 
// 엔진분해
// 전기선연결

// 정비사 -> 엔진을 분해해야? 고장났는지 안고장났는지 알꺼란말이죠.


class Car
{
public:
	Car()
	{

	}
	Car(int a, int b)
	{

	}




public:
	void MoveHandle() {}
	void pushpedal() {}
	void opendoor() {}
	
	void turnkey() 
	{
		// 보안도 뚫어야되고
		// 전기선이 접지도 잘되야되고..

		runEngine();
	}
	
protected:
	void disassemble() {}
	void runEngine() {}
	void connectcircuit() {}

public:
	// 핸들
	// 페달
	// 문
	// 엔진
	// 

};

class Supercar : public Car
{
public:
	void RemoteKey()
	{
		runEngine();
	}

};



class Berserker
{
public:

	int GetHp() { return _hp; }
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp < 50)
		{
			SetBerserkerMode();
		}

	}


private:
	void SetBerserkerMode()
	{
		cout << "공격력 무지 쌔집니다." << endl;
	}

	int _hp;

};



int main()
{

	Car mycar;

	Berserker olaf;


	

}