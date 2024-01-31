
#ifndef __MYFUNC_H__
#define __MYFUNC_H__
#include <iostream>
#define noah 30
using namespace std;


class myfunction
{
public:
	myfunction() : _hp(noah)
	{

	}

	int square(int);


public:
	int _hp;
};



int factorial(int);
#endif
