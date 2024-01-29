#include <iostream>
#include "myfunction.h"

using namespace std;

class Marine
{

public:
	Marine() : _hp(40)
	{
	
	}



	static void staticFunction(int value)
	{

		_attack = value;
	}


public:
	int _hp;
	int _id;
	static int _attack; // 설계도 상으로 존재

};

int Marine::_attack = 0;


int myfunction()
{
	// 가시범위 
	static int i = 0;
	
	int j = 0;
	i++;

	return i;

}

// 정적 전역변수

// 내부
static int abc;


int main()
{



	Marine m1;
	Marine m2;
	Marine m3;
	Marine m4;
	Marine m5;
	Marine m6;
	Marine m7;

	
	m1._hp = 14;
	m2._hp = 26;
	m3._hp = 32;

	Marine::staticFunction(30);
	myfunction();
	
	myfunction();

	abc = 4;
	// engineering bay 공격력을 업그레이드 했어요.



	

}

