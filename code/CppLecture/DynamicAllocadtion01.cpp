#include <iostream>

using namespace std;


class Monster
{


public:
	int _hp = 100;
	int _x = 1;
	int _y = 2;
};


int main()
{

	// 유저 영역 [메모장] [LOL] [곰플레이어] 
	// 각프로그램은 독립적
	// 
	// 각 프로그램이 메모리가 필요하게된다면 커널에게 요청을 하게 된다. 이때 운영체제에서 제공하는 API를 사용하게 됨.
	// 근데 필요할때마다 계속 요청하게 된다면 커널영역은 매우 귀찮게 될꺼야, 그래서 크게 메모리를 받아줄꺼야.
	// 
	// -----------------------
	// 
	// 커널 영역 (Windows 등의 핵심 코드)

	// C++에서는 기본적으로 CRT(C런타임 라이브러리)의 [힙 관리자]를 통해 힙 영역 사용
	// 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수 도 있음(MMORPG 서버 메모리 풀링)



	// Definitions of common types
#ifdef _WIN64
	typedef unsigned __int64 size_t;
	typedef __int64          ptrdiff_t;
	typedef __int64          intptr_t;
#else
	typedef unsigned int     size_t;
	typedef int              ptrdiff_t;
	typedef int              intptr_t;
#endif


	//typedef int myint;
	//myint a; // int 타입



	// malloc
	// - 할당할 메모리 크기를 건내준다.
	// - 메로리 할당 후 시작 주소를 가리키는 포인터를 반환해준다. (메모리가 부족한다면 NULL 값 반환)
	

	// void* 
	// 타고가면 void가 있다는이야기인가?? ->No
	// 타고가면 void 뭐가 있는지 모르겠으니까 너가 적당히 변환해서 사용해라.
	//void* pointer = malloc(1000);
	void* pointer = malloc(sizeof(Monster));

	// free
	// - malloc(calloc, realloc) 을 통해 할당된 영역을 해제
	// - 힙관리자가 할당/ 미할당 여부를 구분해서 관리

	Monster* m1 = (Monster*)pointer;


	m1->_hp = 2100000000;
	m1->_x = 1;
	m1->_y = 2;


	free(pointer);

	// heap overflow
	// - 유효한 힙 범위를 초과해서 사용하는 문제
	
	// free 하지않으면 메모리 누수
	// double free
	// free 한번 더하는것

	// use after free
	// free 한다음에 m1->_hp = 100; 이런식으로 쓰는것

	// free 다음 
	pointer = nullptr; // 로 써야함.
	m1 = nullptr;


	// malloc은 c와 c++ 동시에 사용할 수 있는 것
	// malloc /free는 함수이고 new와 delete는 연산자




	Monster* m2 = new Monster;

	delete m2;
	
	Monster* m3 = new Monster[5];

	delete[] m3;


	// new / delete는 생성타입이 클래스일 경우 생성자/ 소멸자를 호출해준다!!!





}