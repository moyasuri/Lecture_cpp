#include <iostream>
using namespace std;

// 클래스 템플릿




// randombox가 지금은 int를 return하지만, float를 return한다면... 똑같은 클래스를 하나 더만들어줘야하는데
// 너무나 비효율적이다.
//class RandomBox
//{
//public:
//	int getRandomData()
//	{
//		int idx = rand() % 10;
//		return _data[idx];
//	}
//
//public:
//	int _data[10];
//
//};
//



// typename T를 붙이면 어떤 타입도 가능하다.
// 그런데 무조건 typename을 붙어야 하는 건 아니다.


// template<typename T>
// template<typename T,int SIZE = 10 > // int SIZE는 이제 랜덤이아니라, 사이즈를 직접 고르게 됨. (defualt값도 가능)
// template< > 안에 들어가는건 [골라줘야 하는 목록]이라고 볼 수 있음.
template<typename T, int SIZE>
class RandomBox
{
public:
	T getRandomData()
	{
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	T _data[SIZE];

};


// 템플릿 특수화
// 어떤 특수한 조건에서는 템플릿이 그 조건에맞게 생성이 되게하자.


template<int SIZE>
class RandomBox<double, SIZE> 
{
public:
	double getRandomData()
	{
		cout << "randombox double" << endl;
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	double _data[SIZE];

};


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));


	RandomBox<int, 10> rb1;
	for (int i = 0; i < 10 ; i++)
	{
		rb1._data[i] = i;
	}

	int value1 = rb1.getRandomData();
	cout << value1 << endl;

	RandomBox<float, 20> rb2;
	for (int i = 0; i < 20 ; i++)
	{
		rb2._data[i] = i+0.5f;
	}

	float value2 = rb2.getRandomData();
	cout << value2 << endl;



	// rb1 = rb2; // 성립이 안됨, 템플릿으로 만들어진 두 클래스는 완전히 다른 클래스이다. 
	// 들어간 인자가 완전히 일치한다면 가능하다.



	RandomBox<double, 20> rb3;
	for (int i = 0; i < 20; i++)
	{
		rb3._data[i] = i + 0.5;
	}

	float value3 = rb3.getRandomData();
	cout << value3 << endl;



	return 0;
}