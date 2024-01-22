#include <iostream>

using namespace std;


int main()
{

	/*
	 const 포인터란 ?
	 const라는 키워드는 변수를 상수화 시킬때 사용하는 키워드입니다.
	 이렇게 상수화 된 변수는 이후 변경이 불가능하며 포인터 변수에 const 키워드를 붙여도 같은 동작을 합니다.
	 다만 const의 위치가 어디로 가느냐에 따라 의미가 다릅니다.

	int a = 100;

	// 1) const 자료형 변수명 = 초기값 
	const int* ptr = &a;
	// 가리키는 값은 변경 불가, ptr 값은 변경 가능

	// 2) 자료형 const 변수명 = 초기값 
	int const* ptr2 = &a;
	// 가리키는 값은 변경 가능, ptr 값은 변경 불가

	// 3) const 자료형 const 변수명 = 초기값 
	const int const* ptr3 = &a;
	*/


	// 동적할당

	int* arr = new int[10]; // 동적 배열 선언 및 할당

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 1; // 동적 배열 사용
	}

	delete[] arr;

	// 2차원 동적배열

	// 동적 배열 선언 & 할당
	int** arr2 = new int* [5];

	for (int i = 0; i < 5; i++) {
		arr2[i] = new int[20];
	}








}
