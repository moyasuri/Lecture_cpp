
# include <iostream>

using namespace std;

struct A
{
public:
	int mhp;
	int attack;
	int posY;
	int posX;

};


// 클래스에 소속된 함수들을 멤버 함수라고한다
// 이중에서 특별한 함수 2종이 있는데, 바로 시작과 끝을 알리는 함수들
// - 시작(탄생) -> 생성자 (여러개 존재 가능)
// - 끝(소멸) -> 소멸자 (오직 1개만)



// 암시적 생성자(implicit)
// 생성자를 명시적으로 만들지 않으면, 아무 인자도 받지 않는 기본생성자와 복사 생성자가 컴파일러에 의해 자동으로 만들어짐.
// 그러나 우리가 명시적(explicit)으로 아무 생성자를 하나를 만들면,
// 자동으로 만들어지던 기본 생성자는 더 이상 만들어지지 않음. // 그냥 실행하면 빌드 에러남.



class Knight 
{
public:
	// [1] 기본 생성자( 인자가 없음) // 객체화와 동시에 호출되는 함수 반환하는 타입이없다!!
	Knight()
	{
		cout << "Knight 기본 생성자 호출" << endl;
	}


	// [3] 복사 생성자 -> 자기 자신의 참조 타입을 인자로 받는다는 특징이 있음
	Knight(const Knight& knight)
	{
		cout << "Knight 복사 생성자 호출" << endl;
		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}


	// [2]기본생성자, 복사 생성자가 아니면 그냥 기타생성자라고 한다.

	// [2-1] 이 중에서 인자를 1개만 받는 기타 생성자를 타입 변환 생성자라고 한다.
	// 이 아이를 반드시 명시적 용도로만 사용하기 위해서는 explicit을 붙여줘야한다.
	explicit Knight(int hp)
	{

		cout << "생성자 Knight(hp) 호출" << endl;
		_hp = hp;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	Knight(int hp, int attack, int posX, int posY) 
	{

		_hp = hp;
		_attack = attack;
		_posX = posX;
		_posY = posY;
	}


	// 소멸자

	~Knight()
	{
		cout << "Knight() 기본 생성자 호출" << endl;

	}

public:
	void Move(int y, int x);

	void Attack();


	// 클래스 함수 내부에서는 자체 설계도 내부의 변수에 접근할 수 있는 권한이
	// 있다.
	void Die()
	{
		_hp = 0;

	}

public:

	int _hp;
	int _attack;
	int _posY;
	int _posX;

};

// 선언, 정의를 따로 써도 된다.
void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;


	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

void Move(Knight* k, int y, int x)
{
	k->_posY = y;
	k->_posX = x;
}


void HelloKnight(Knight k)
{
	cout << "hello" << endl;
}

int main()
{

	Knight k1; // 여기가 생성자
	k1._hp = 100;
	k1._posX = 3;
	k1._posY = 3;


	Knight k2(k1);

	cout << "k3\n";
	Knight k3 = k1; // 생성을 함과 동시에 합치기

	// 근데 아래는 달라.
	cout << "k4\n";
	Knight k4; // 우선 k4의 기본 생성자로 생성
	k4 = k1; // 복사.

	Knight k5(10, 10, 10, 10);



	k1.Move(3, 4);
	Move(&k1, 2, 2);
	






	// 암시적 형변환 -> 컴파일러가 알아서
	int num = 1;
	// float f = num; 암시적
	float f = (float)num; // 명시적

	Knight k6;
	// k6 = 1;// ?? 이게 가능한 이유는  암시적으로
	k6 = (Knight)1;// 명시적으로

	HelloKnight((Knight)4); // 이 경우 4를 넣어준 숫자때문에 Knight 이 만들어지면서 타입변환생성자가 넘어간다.

	return 0;



}