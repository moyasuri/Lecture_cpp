#include <iostream>

using namespace std;


int main()
{

	int b = 3;

	const int* const a = &b;
	const int *c = &b;
	
	int x = 4;

	cout << *a;
	
	c = &x;



	


}
