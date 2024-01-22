#include <iostream>

using namespace std;


int main()
{

	// const 포인터란 ?
	// const라는 키워드는 변수를 상수화 시킬때 사용하는 키워드입니다.
	// 이렇게 상수화 된 변수는 이후 변경이 불가능하며 포인터 변수에 const 키워드를 붙여도 같은 동작을 합니다.
	// 다만 const의 위치가 어디로 가느냐에 따라 의미가 다릅니다.


	//int a = 100;

	////1) const 자료형 변수명 = 초기값 
	//const int* ptr = &a;

	////2) 자료형 const 변수명 = 초기값 
	//int const* ptr2 = &a;

	////3) const 자료형 const 변수명 = 초기값 
	//const int const* ptr3 = &a;



	//// 상수 포인터(const pointer)
	//int a = 100;
	//int b = 200;

	////non const 포인터
	//int* ptr = &a;
	//ptr = &b; //주소 변경 가능
	//*ptr = 300; //값 변경 가능

	////상수 포인터(const pointer)
	//int* const ptr2 = &a;
	//// ptr2 = &b; //포인터가 상수이므로 변경 불가능
	//*ptr2 = 300; //값은 변경 가능



	//int* const ptr = &a;

	//// 일반적으로 상수 포인터라고 하면 위와 같이 사용한다고 보시면 됩니다.
	//// const의 우측에 포인터 변수의 값이 위치합니다.
	//// 즉 포인터 변수를 const하겠다는 뜻이며 선언과 동시에 초기화를 해주셔야 합니다.
	//// 이 경우 초기에 저장된 포인터 변수의 값은 변경이 불가능합니다.



	//// -------------------------------//
	//// 상수에 대한 포인터(Pointer to Const)
	//int a = 100;
	//int b = 200;

	////non const 포인터
	//int* ptr = &a;
	//ptr = &b; //주소 변경 가능
	//*ptr = 300; //값 변경 가능

	////상수에 대한 포인터
	//const int* ptr2 = &a;
	//ptr2 = &b; //포인터가 상수가 아니므로 변경 가능
	////*ptr2 = 300; //가리키는 값이 상수이므로 변경 불가능
	//const int* ptr = &a;

	//// const 키워드가 가장 좌측에 위치하면 이는 int* ptr 을 상수화 하겠다는 뜻이 됩니다.
	//// 즉* ptr이 상수가 되는것이지요.이렇게 된다면* ptr이 가리키는 값이 상수가 되어 값을 변경할 수 없게 됩니다.
	
	
	// -------------------------------//
	// 상수에 대한 상수 포인터(Const Pointer to Const)

	int a = 100;
	int b = 200;

	//non const 포인터
	int* ptr = &a;
	ptr = &b; //주소 변경 가능
	*ptr = 300; //값 변경 가능

	//상수에 대한 상수 포인터
	const int* const ptr2 = &a;
	//ptr2 = &b; //포인터가 상수이므로 변경 불가능
	//*ptr2 = 300; //가리키는 값이 상수이므로 변경 불가능


}
