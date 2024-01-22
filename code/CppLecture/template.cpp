#include <iostream>
using namespace std;


// 템플릿 기초
// core library 만들때 필요하다.


class Knight
{


public:
	// ...

public:
	int _hp = 100;

};






// 템플릿이 없을때,

//void Print(int a)
//{
//	cout << a << endl;
//}
//
//
//void Print(float a)
//{
//	cout << a << endl;
//}
//
//void Print(double a)
//{
//	cout << a << endl;
//}
//
//void Print(const char* a)
//{
//	cout << a << endl;
//}
//

template<typename T> // 꼭 T로 할 필요는 없으나, convention
// template<class T> // 이렇게 클래스로도 사용이 가능하긴 함.
void Print(T a)
{
	cout << a << endl;
}

// 컴파일 단계에서 각 타입의 오버로딩 함수가 생김




// 템플릿 특수화, 딱 Knight의 경우에만 아래버전을 따르게 될것이다.

template<>
void Print(Knight a)
{

	cout << "Knight !!!!!!!!"<< endl;
	cout << a._hp << endl;

}


// 파라메터의 타입이 2개인 경우

template<typename T1, typename T2>

void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}




// Add 함수를 만들어보자 
//int Add(int a, int b)
//{
//	return a + b;
//
//}
//
//float Add(float a, float b)
//{
//	return a + b;
//}



template<typename T>
T Add(T a, T b)
{
	return a + b;
}



// 연산자 오버로딩 (전역함수 버전)

ostream& operator<<(ostream& os, const Knight& k)
{

	os << k._hp;
	return os;
}



int main()
{
	// 템플릿 : 함수나 클래스를 찍어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿
	
	
	
	// Print(int, const char*);  // 이 때, 템플릿 문법을 사용할 수 없을까?


	// 컴파일러가 암시적으로 만들어주기
	Print(50);
	Print(50.0f);
	Print(50.0);
	Print("hello World");

	Print("Hello ", 100);

	// 명시적으로 만들어주기
	Print<int>(50); // 무조건 int version이 호출됨



	int result1 = Add(1, 2);
	float result2 = Add<float>(1.11f, 2.22f);



	Knight k1;
	Print(k1);

	

	return 0;
}