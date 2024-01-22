#include <iostream>
using namespace std;


// ���ø� ����
// core library ���鶧 �ʿ��ϴ�.


class Knight
{


public:
	// ...

public:
	int _hp = 100;

};






// ���ø��� ������,

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

template<typename T> // �� T�� �� �ʿ�� ������, convention
// template<class T> // �̷��� Ŭ�����ε� ����� �����ϱ� ��.
void Print(T a)
{
	cout << a << endl;
}

// ������ �ܰ迡�� �� Ÿ���� �����ε� �Լ��� ����




// ���ø� Ư��ȭ, �� Knight�� ��쿡�� �Ʒ������� ������ �ɰ��̴�.

template<>
void Print(Knight a)
{

	cout << "Knight !!!!!!!!"<< endl;
	cout << a._hp << endl;

}


// �Ķ������ Ÿ���� 2���� ���

template<typename T1, typename T2>

void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}




// Add �Լ��� ������ 
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



// ������ �����ε� (�����Լ� ����)

ostream& operator<<(ostream& os, const Knight& k)
{

	os << k._hp;
	return os;
}



int main()
{
	// ���ø� : �Լ��� Ŭ������ ���� Ʋ
	// 1) �Լ� ���ø�
	// 2) Ŭ���� ���ø�
	
	
	
	// Print(int, const char*);  // �� ��, ���ø� ������ ����� �� ������?


	// �����Ϸ��� �Ͻ������� ������ֱ�
	Print(50);
	Print(50.0f);
	Print(50.0);
	Print("hello World");

	Print("Hello ", 100);

	// ��������� ������ֱ�
	Print<int>(50); // ������ int version�� ȣ���



	int result1 = Add(1, 2);
	float result2 = Add<float>(1.11f, 2.22f);



	Knight k1;
	Print(k1);

	

	return 0;
}