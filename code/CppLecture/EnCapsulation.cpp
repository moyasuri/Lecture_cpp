#include <iostream>
using namespace std;


// 은닉성(data hiding) = 캡슐화(Encapsulation)


// 1. 정말 위험하고 건드리면 안되는 이유
// 2. 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들
// - 페달
// - 엔진
// - 문
// - 각종 전기선

// 운전자 입장

// - 핸들 페달 문
// - 엔진 각종 전기선, 트랜스미션, 그러나 존재는 해야 함.


// public (공개) protected(보호받는) private(사적인)


// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하진 않음
// - public : << 정말 이거밖에 안씀. (public -> public , protected -> protected)
// - protected : (public - > protected, protected -> protected)
// - private : (public -> private, protected -> private)

// 근데 알아야되는 이유는.. 기본적으로 private가 들어가니까 우린 public을 붙여줘야해서 그래

class Car
{

public: // (멤버) 접근 지정자(제한자)
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}

	void TurnKey()
	{
		// ...
		RunEngine();
	}


//private:
protected:
	void DisassembleCar() {}
	void RunEngine() {}
	void ConnectCircuit() {}



public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 각종 전기선

};


class SuperCar : public Car // 상속 접근 지정자, 위와는 조금 다르다.
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}

};



// 캡슐화 : 연관된 데이터와 함수를 논리적으로 묶어놓은 것.
class Berserker
{

public:

	int GetHp() { return _hp; }
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp < 50)
			SetBerserkerMode();

	}
	// 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동 (강해짐)


//public:
private:

	void SetBerserkerMode()
	{
		cout << "매우 강해짐!" << endl;
	}
	int _hp = 100;
};

int main()
{


	Car car;
	SuperCar mycar;

	mycar.PushRemoteController();


	Berserker b;
	//b._hp =20;
	
	// hp 를 건드릴때, 버서커 모드를 발동하는지 확인해야하는데 그런걸 체크하지 않았어!.
	
	/*if (b._hp < 50)
	{
		b.SetBerserkerMode(); // 버서커 모드도 아무때나 호출하는게 아니야.
	}*/





	return 0;
}