#include <iostream>

using namespace std;

int main()
{

	int a = 5;  // 이진 표현: 0101
	int b = 3;  // 이진 표현: 0011
	int result = a & b;  // 비트 AND 연산
	// 결과: 0001 (10진수로 1)


	int a = 5;  // 이진 표현: 0101
	int b = 3;  // 이진 표현: 0011
	int result = a | b;  // 비트 OR 연산
	// 결과: 0111 (10진수로 7)


	/*
	비트 XOR 연산자 (^): 이 연산자는 
	두 개의 정수를 비트 단위로 XOR (exclusive OR) 연산합니다. 
	두 비트가 서로 다르면 결과 비트가 1이 됩니다. 예시:
	*/

	int a = 5;  // 이진 표현: 0101
	int b = 3;  // 이진 표현: 0011
	int result = a ^ b;  // 비트 XOR 연산
	// 결과: 0110 (10진수로 6)


	int a = 5;  // 이진 표현: 0101
	int result = ~a;  // 비트 NOT 연산
	// 결과: 1010 (10진수로 -6)


	int x = 8;   // 이진 표현: 1000
	int leftShifted = x << 2;  // 왼쪽 시프트 연산 (x * 2^2)
	// 결과: 32 (10진수)

	int y = 16;  // 이진 표현: 10000
	int rightShifted = y >> 2;  // 오른쪽 시프트 연산 (y / 2^2)
	// 결과: 4 (10진수)



}