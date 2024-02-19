#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;
void fn(int &a)
{
	static int i = 0;
	while (1)
	{
		this_thread::sleep_for(chrono::seconds(1));
		std::cout << a << endl;
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
	fn(num);

}
int main()
{
	std::thread t1;
	threadCaller(t1);
		
	caller();
	t1.join();
	cout << "abc";
}