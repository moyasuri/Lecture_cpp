#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;

static int i = 0;
void fn(int &a)
{
	static int i = 0;
	while (1)
	{
		this_thread::sleep_for(chrono::seconds(1));
		std::cout << a << endl;
		if (i != 5)
		{
			i++;

		}
		else
		{
			break;
		}

	}
	
}

void fn2(int& a)
{
	static int i = 0;
	while (1)
	{
		this_thread::sleep_for(chrono::seconds(1));
		std::cout << a << endl;
		if (i != 10)
		{
			i++;

		}
		else
		{
			break;
		}

	}

}
void threadCaller(std::thread& t)
{	
	int *num = new int(42);
	t = thread(fn, ref(*num));
	

}
void caller()
{
	int num = 50;
	fn2(num);

}
int main()
{
	std::thread t1;
	threadCaller(t1);
		
	caller();
	t1.join();
	cout << "abc";
}