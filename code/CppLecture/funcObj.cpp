#include <iostream>
using namespace std;


// 오늘의 주제 : 함수 객체

void HelloWorld()
{
	cout << "Hello World" << endl;


}


class Knight
{
public:
	void AddHp(int addHp)
	{
		_hp += addHp;
	}

private:
	int _hp = 100; // a) 나이트의 상태 값
};


class Functor
{
public:
	/*void operator+()
	{

	}*/
	
	/* 다른거에서 가져온 예시
	OperatorTest operator+(OperatorTest& ref)
	{
		return OperatorTest(this->_num + ref._num);
	}

	*/
	void operator()()
	{
		cout << "Functor Test" << endl;
		cout << "_value= "<< _value << endl;
	}
	bool operator()(int num)
	{
		cout << "Functor Test" << endl;
		_value += num;
		cout << _value << endl;

		return true;
	}


private:
	int _value = 0;


};

class MoveTask
{

public:
	void operator()()
	{
		cout << "해당 좌표로 플레이어 이동" << endl;
	}

public:
	int _playerId;
	int _posX;
	int _posY;
};


int main()
{
	// 함수 객체 (Functor) : 함수처럼 동작하는 객체
	// 사용 이유: 함수 포인터의 단점을 보완하기위해
	// 완전히 같은 시그니쳐만 사용 가능했었다.

	// 함수 포인터 선언
	void (*pfunc)(void);
	
	// 동작은 넘겨줄 때 유용하다.
	pfunc = &HelloWorld;
	(*pfunc)();

	// 함수 포인터 다점
	// 1) 시그니쳐가 안 맞으면 사용할 수 없다.
	// 2) 상태를 가질 수 없다. 상태 = 함수에 저장 되는 값 -> a)
	



	// 함수 처럼 동작하는 객체
	// () 연산자 오버로딩 
	HelloWorld();


	Functor functor;
	
	cout << "------" << endl;
	functor();
	bool ret = functor(3);
	
	// STL을 공부하게 되면 자주쓰게 될 것.

	// MMO에서 함수 객체를 사용하는 예시
	// client(game을 그려줌) <-> server (game의 judge)
	// server : client 가 보내준 네트워크 패킷을 받아서 처리
	// ex) client -> 나를 (5,0) 좌표로 이동 시켜줘 
	// 동시다발적으로 명령을 호출하면, 서버는 부담이되니, 일단 요청을 객체로 만들어 두고
	// 순서대로 명령을 처리한다.


	// 일단 만들어주고
	MoveTask task;
	task._playerId = 100;
	task._posX = 5;
	task._posY = 0;

	// 나중에 여유 될 때 일감을 실행한다.
	task();

	

	
		
	return 0;
}