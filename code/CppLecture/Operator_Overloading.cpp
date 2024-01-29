#include <iostream>

using namespace std;


class Position
{

public:
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;
		return pos;
	}

	bool operator==(const Position& arg)
	{
		return ( _x== arg._x && _y == arg._y);
	}
	
	Position& operator =(int arg)
	{
		
		_x = arg;
		_y = arg;
		return *this;
	}

	// [복사 생성자] [복사 대입 연산자] 특별대우의 이유는 객체가 복사 되길 원하는 특징.
	// 단순히 인트 등의 데이터타입의 형식이면 전혀 문제가 없으나 안에 클래스형식의 데이터를 가지고 있다면 
	// 세세하게 지정해줘야함.
	Position& operator =(const Position& arg)
	{

		_x = arg._x;
		_y = arg._y;
		return *this;
	}

	Position& operator++()
	{
		_x++;
		_y++;
		return *this;

	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;

	}




public:
	int _x;
	int _y;

};


Position operator+(int a, const Position& b)
{
	Position ret;
	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
	
}

// 왼쪽이 기준인지 오른쪽이 기준인지 모르니까 불가.
//void operator =(Position& a, int b)
//{
//	a._x = b;
//	a._y = b;
//}


int main()
{

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2; 
	pos.operator+(pos2);

	
	// Position pos4 = (pos = 1); // void를 반환하기때문에 불가


	pos2 = pos;

	Position pos4;
	pos4 = pos++;
	++(++pos);


	return 0;
}