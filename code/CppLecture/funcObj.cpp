#include <iostream>
using namespace std;


// ������ ���� : �Լ� ��ü

void HelloWorld()
{
	cout << "Hello World" << endl;


}


class Knight
{
public:
	void AddHp(int addHp)
	{
		_hp += addHp;
	}

private:
	int _hp = 100; // a) ����Ʈ�� ���� ��
};


class Functor
{
public:
	/*void operator+()
	{

	}*/
	
	/* �ٸ��ſ��� ������ ����
	OperatorTest operator+(OperatorTest& ref)
	{
		return OperatorTest(this->_num + ref._num);
	}

	*/
	void operator()()
	{
		cout << "Functor Test" << endl;
		cout << "_value= "<< _value << endl;
	}
	bool operator()(int num)
	{
		cout << "Functor Test" << endl;
		_value += num;
		cout << _value << endl;

		return true;
	}


private:
	int _value = 0;


};

class MoveTask
{

public:
	void operator()()
	{
		cout << "�ش� ��ǥ�� �÷��̾� �̵�" << endl;
	}

public:
	int _playerId;
	int _posX;
	int _posY;
};


int main()
{
	// �Լ� ��ü (Functor) : �Լ�ó�� �����ϴ� ��ü
	// ��� ����: �Լ� �������� ������ �����ϱ�����
	// ������ ���� �ñ״��ĸ� ��� �����߾���.

	// �Լ� ������ ����
	void (*pfunc)(void);
	
	// ������ �Ѱ��� �� �����ϴ�.
	pfunc = &HelloWorld;
	(*pfunc)();

	// �Լ� ������ ����
	// 1) �ñ״��İ� �� ������ ����� �� ����.
	// 2) ���¸� ���� �� ����. ���� = �Լ��� ���� �Ǵ� �� -> a)
	



	// �Լ� ó�� �����ϴ� ��ü
	// () ������ �����ε� 
	HelloWorld();


	Functor functor;
	
	cout << "------" << endl;
	functor();
	bool ret = functor(3);
	
	// STL�� �����ϰ� �Ǹ� ���־��� �� ��.

	// MMO���� �Լ� ��ü�� ����ϴ� ����
	// client(game�� �׷���) <-> server (game�� judge)
	// server : client �� ������ ��Ʈ��ũ ��Ŷ�� �޾Ƽ� ó��
	// ex) client -> ���� (5,0) ��ǥ�� �̵� ������ 
	// ���ôٹ������� ����� ȣ���ϸ�, ������ �δ��̵Ǵ�, �ϴ� ��û�� ��ü�� ����� �ΰ�
	// ������� ����� ó���Ѵ�.


	// �ϴ� ������ְ�
	MoveTask task;
	task._playerId = 100;
	task._posX = 5;
	task._posY = 0;

	// ���߿� ���� �� �� �ϰ��� �����Ѵ�.
	task();

	

	
		
	return 0;
}