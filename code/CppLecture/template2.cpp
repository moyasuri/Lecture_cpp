#include <iostream>
using namespace std;

// Ŭ���� ���ø�




// randombox�� ������ int�� return������, float�� return�Ѵٸ�... �Ȱ��� Ŭ������ �ϳ� �����������ϴµ�
// �ʹ��� ��ȿ�����̴�.
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



// typename T�� ���̸� � Ÿ�Ե� �����ϴ�.
// �׷��� ������ typename�� �پ�� �ϴ� �� �ƴϴ�.


// template<typename T>
// template<typename T,int SIZE = 10 > // int SIZE�� ���� �����̾ƴ϶�, ����� ���� ���� ��. (defualt���� ����)
// template< > �ȿ� ���°� [������ �ϴ� ���]�̶�� �� �� ����.
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


// ���ø� Ư��ȭ
// � Ư���� ���ǿ����� ���ø��� �� ���ǿ��°� ������ �ǰ�����.


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



	// rb1 = rb2; // ������ �ȵ�, ���ø����� ������� �� Ŭ������ ������ �ٸ� Ŭ�����̴�. 
	// �� ���ڰ� ������ ��ġ�Ѵٸ� �����ϴ�.



	RandomBox<double, 20> rb3;
	for (int i = 0; i < 20; i++)
	{
		rb3._data[i] = i + 0.5;
	}

	float value3 = rb3.getRandomData();
	cout << value3 << endl;



	return 0;
}