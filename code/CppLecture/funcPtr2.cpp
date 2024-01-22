#include <iostream>
using namespace std;

// ������ ���� : �Լ� ������

// typedef �� ���Ͽ�
// typedef int A -> ����(int)�� Ÿ���� ������(A)�� �ȴ�.

typedef int NUMBER;


// ��Ȯ���� ���� / ������ ������ �ƴϰ�!
// [���� ����]���� typedef�� �տ��� ���̴� ��

//int INTEGER;
//int* PINTER;
//int FUNC();
//int ARRAY[20];

// ������� int FUNC()�Լ��� ������ ���̶�� ������ �ϴ� �ſ��ٸ�, 
// typedef �� �տ� ���δٰ� �ϸ���, ������ FUNC �� � �Լ� Ÿ���� �ǹ��� ���̴�. -> ���ڴ� void, return �� int�̴�.


typedef int INTEGER;
typedef int* PINTER;
// typedef int FUNC();
typedef int ARRAY[20];


typedef int FUNC(int, int);
// int (*PFUNC)(int, int); 

// �����Լ� ������
typedef int (*PFUNC)(int, int); // ��ȯŸ���� ������ ��Ʈ����, �Լ����������� Ȯ������������ �ݵ�� ��ȣ�� ��������.




int Test(int a, int b )
{
	cout << "Test" << endl;
	return a+b;
}


// a-1)
// �츮�� ���漱���� �ϸ� �������
// int func(int, int);
// ���� �Լ��� ���ðŶ�� �̾߱��ϴ°���, ������ � �޸𸮰� �Ҵ�ǰų� �׷��� �ƴ϶�°���.


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

	// �����Լ� (static) ��ü�� �������� ����.
	static void HelloKnight()
	{
		// _hp = 20; ��ü�� �������� ������ ������ �� ����.
	}

	// ��� �Լ�
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;
};


// d) ��� �Լ� ������
typedef int (Knight::* PMEMFUNC)(int, int);



int main()
{

	// �Լ� ������
	// 1) ������           *
	// 2) ������ �̸�	   myfunc
	// 3) Ÿ��             �Լ�(���� ,��ȯ)


	int (*myfunc)(int, int); // �ѹ��� ����°� �ͼ���������.
	
	// ������ ����
	typedef int(FUNC_TYPE)(int, int);
	FUNC_TYPE* fn;
	fn =  &Test;
	cout << fn(3, 3) << endl;



	FUNC* fn2; // �����Ͱ� �ƴ� �Ϲ����·� ����� ���� ���� �������̴�. ���� ���ø� ���� a)


	// a) 
	// int a�� �����ϸ� ���������� �ν��Ͽ� ���ø޸𸮿� 4����Ʈ�� �Ҵ��� �ȴ�.
	int a;
	// �׷��� �Լ��� ���� �޸� �Ҵ簳���̾ƴ�, �ּҰ��� Ÿ�� ���� �� �Լ��� �����Ѵٴ� �����̾���Ѵ�.
	// �� �����ϰ� ����ϴ� �����Ͱ� �ִ°� �ƴϴ�, �����ؾ� �� �ڵ���� �ٸ� ���� ���ǵǾ� �ִ°ž�.
	// -> a-1)
	
	FUNC t; //�������� �����̾�. t�� ���� ������ �ִ°Ծƴ�!  �̷��� �����غ��� �ǹ̰������ϱ�..
	// t�� ���󰡸� ���� �ִٴ°���.
	// -> b)
	


	PFUNC fr; // PFUNC* fr �̶� �����ʴ� ������ ���ʿ� PFUNC ��ü�� �������̰ŵ�!
	fr = &Test;
	fr(1, 2);
	(*fr)(1, 2);

	// !! �� �������� [���� �Լ� / ���� �Լ�]�� ���� �� �ִ�. (ȣ�� �Ծ��� ������ �ֵ�)
	// -> c)
	// fn = &GetHp(); �Ұ���, ����Լ��� ����
	// fn = &Knight::GetHp(); �ȿ� �ִ� �Լ���°� ���� �����ָ� ���� ������?; �ȵǴ���!, ������ �ñ״��ĸ� ���絵 �ȵ�

	Test(1, 2); // ���ÿ� �ٷ�!
	
	Knight k1;
	k1.GetHp(1, 1); // �� ����Լ��� ȣ���ϴ°�, �� ��ü�� �ּҸ� �Ѱ��ִ� �Ծ���� �����ϰ� �ִ�.

	// �׷��ٸ� ����Լ��� �����ͷ� �Ѵٸ� ��� �ؾ��ϴ°�??
	// -> d)
	






	// myfunc = &Test; // & ���� ���� (C ����� ȣȯ�� �����̴�.)
	myfunc = Test; // �Լ��� �ּҰ��� ! �ִ°��̴�.

	
	myfunc(1,1);
	(*myfunc)(1,1);  // Ÿ�� ���� ��

	PMEMFUNC mfn;


	// mfn = Knight::GetHp; ��ǥ�ر���
	mfn = &Knight::GetHp;

	// k1.mfn ���� ����� �����... �����Ϸ� ���忡�� k1���� ����� �ǹ��ϴ°��� �˼������⶧���̾�.
	(k1.*mfn)(1, 1);


	Knight* k2 = new Knight();
	
	//((*k2).*mfn)(1, 1);
	// *.= ->  �� ��ü�����ϴϱ�
	(k2->*mfn)(1, 1);
	
	delete k2;


	return 0;


}