#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 포인터

// typedef 에 대하여
// typedef int A -> 왼쪽(int)의 타입이 오른쪽(A)가 된다.

typedef int NUMBER;


// 정확히는 왼쪽 / 오른쪽 기준이 아니고!
// [선언 문법]에서 typedef을 앞에다 붙이는 쪽

//int INTEGER;
//int* PINTER;
//int FUNC();
//int ARRAY[20];

// 예를들어 int FUNC()함수가 등장할 것이라고 선언을 하는 거였다면, 
// typedef 를 앞에 붙인다고 하면은, 이제는 FUNC 가 어떤 함수 타입을 의미할 것이다. -> 인자는 void, return 은 int이다.


typedef int INTEGER;
typedef int* PINTER;
// typedef int FUNC();
typedef int ARRAY[20];


typedef int FUNC(int, int);
// int (*PFUNC)(int, int); 

// 정적함수 포인터
typedef int (*PFUNC)(int, int); // 반환타입이 포인터 인트인지, 함수포인터인지 확실하지않으니 반드시 괄호로 감싸주자.




int Test(int a, int b )
{
	cout << "Test" << endl;
	return a+b;
}


// a-1)
// 우리가 전방선언을 하면 예를들어
// int func(int, int);
// 저런 함수가 나올거라고 이야기하는거지, 실제로 어떤 메모리가 할당되거나 그런건 아니라는거지.


// b)
int t(int a, int b)
{
	cout << "t" << endl;
	return a + b;
}



// c)
class Knight
{
public:

	// 정적함수 (static) 객체랑 연관성이 없다.
	static void HelloKnight()
	{
		// _hp = 20; 객체에 의존적인 정보를 수정할 수 없다.
	}

	// 멤버 함수
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;
};


// d) 멤버 함수 포인터
typedef int (Knight::* PMEMFUNC)(int, int);



int main()
{

	// 함수 포인터
	// 1) 포인터           *
	// 2) 변수의 이름	   myfunc
	// 3) 타입             함수(인자 ,반환)


	int (*myfunc)(int, int); // 한번에 만드는게 익숙해져야함.
	
	// 나눠서 쓰기
	typedef int(FUNC_TYPE)(int, int);
	FUNC_TYPE* fn;
	fn =  &Test;
	cout << fn(3, 3) << endl;



	FUNC* fn2; // 포인터가 아닌 일반형태로 사용할 일은 거의 없을것이다. 밑의 예시를 보자 a)


	// a) 
	// int a를 선언하면 지역변수로 인식하여 스택메모리에 4바이트가 할당이 된다.
	int a;
	// 그러나 함수는 스택 메모리 할당개념이아닌, 주소값을 타고 들어가면 그 함수가 존재한다는 개념이어야한다.
	// 즉 저장하고 사용하는 데이터가 있는게 아니다, 실행해야 될 코드들이 다른 곳에 정의되어 있는거야.
	// -> a-1)
	
	FUNC t; //어디까지나 선언이야. t가 무얼 가지고 있는게아님!  이렇게 선언해봐야 의미가없으니까..
	// t를 따라가면 무언가 있다는거지.
	// -> b)
	


	PFUNC fr; // PFUNC* fr 이라 하지않는 이유는 애초에 PFUNC 자체가 포인터이거든!
	fr = &Test;
	fr(1, 2);
	(*fr)(1, 2);

	// !! 위 문법으로 [전역 함수 / 정적 함수]만 담을 수 있다. (호출 규약이 동인할 애들)
	// -> c)
	// fn = &GetHp(); 불가능, 멤버함수만 가능
	// fn = &Knight::GetHp(); 안에 있는 함수라는걸 인지 시켜주면 되지 않을까?; 안되더라!, 심지어 시그니쳐를 맞춰도 안됨

	Test(1, 2); // 스택에 바로!
	
	Knight k1;
	k1.GetHp(1, 1); // 즉 멤버함수를 호출하는건, 그 객체의 주소를 넘겨주는 규약까지 포함하고 있다.

	// 그렇다면 멤버함수를 포인터로 한다면 어떻게 해야하는가??
	// -> d)
	






	// myfunc = &Test; // & 생략 가능 (C 언어의 호환성 때문이다.)
	myfunc = Test; // 함수의 주소값을 ! 넣는것이다.

	
	myfunc(1,1);
	(*myfunc)(1,1);  // 타고 가도 돼

	PMEMFUNC mfn;


	// mfn = Knight::GetHp; 비표준구문
	mfn = &Knight::GetHp;

	// k1.mfn 별을 안찍고 만들면... 컴파일러 입장에서 k1안의 멤버를 의미하는건지 알수가없기때문이야.
	(k1.*mfn)(1, 1);


	Knight* k2 = new Knight();
	
	//((*k2).*mfn)(1, 1);
	// *.= ->  로 대체가능하니까
	(k2->*mfn)(1, 1);
	
	delete k2;


	return 0;


}