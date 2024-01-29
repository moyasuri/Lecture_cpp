// 객체란 사실 게임속에서 존재하는 모든 오브젝트 들.
// 예를 들면 플레이어, 몬스터, 게임 룸, 방 단위

// Knight를 설계해보자
// - 속성 (데이터) : hp, attack , y ,x
// - 기능 (동작) move attack die

# include <iostream>

using namespace std;

struct A
{
public:
	int hp;
	int attack;
	int posY;
	int posX;

};

 
class Knight
{

public:
	void Move(int y, int x);

	void Attack();


	// 클래스 함수 내부에서는 자체 설계도 내부의 변수에 접근할 수 있는 권한이
	// 있다.
	void Die()
	{
		hp = 0;

	}

public:

	int hp;
	int attack;
	int posY;
	int posX;

};

// 선언, 정의를 따로 써도 된다.
void Knight::Move(int y, int x)
{
	posY = y;
	posX = x;


	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}

void Move(Knight* k, int y, int x)
{
	k->posY = y;
	k->posX = x;
}

int main()
{

	Knight k1;
	k1.posX = 3;
	k1.posY = 3;
	k1.Move(3, 4);

	Move(&k1, 2, 2);

	return 0;



}