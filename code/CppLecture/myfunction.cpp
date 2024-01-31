#include "myfunction.h"



int factorial(int var)
{
	if (var <= 1)
		return 1;
	return var * factorial(var - 1);
}



int myfunction::square(int number)
{
	cout << number;
	return number * number;
} 