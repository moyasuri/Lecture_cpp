#include <iostream>
#include <iomanip> // input output manipulation ,  조작 
#include <vector>
#include <algorithm>
#include <list>
#include <sstream>





using namespace std;

namespace  seoul {
	std::string local_num;
	std::string landmark;
	int price(int a) {
		return a * 2;
	}
}

namespace  busan {
	std::string local_num;
	std::string landmark;
}

using namespace busan;

// 포인터 왜 배워야함??
// c언어의 가장 큰 특징은? -> 메모리에 접근이 가능하다. 

//

void swap(int* c, int* d) // call by address
{
	int temp;
	temp = *c;
	*c = *d;
	*d = temp;

}

void printInfo(const int* a, const int* b)
{

	std::cout << "abc";
	
}





int main()
{

	// -> A 기사가 공격하는걸 만들고있어요. attack
	// 
	// -> B 궁수가 공격하는 함수를 만들어야지 attack




	seoul::local_num = "02";
	seoul::landmark = "남산타워";
	
	local_num = "051";
	landmark = "광안대교";

	std::cout << landmark << std::endl;
	std::cout << seoul::landmark << std::endl;
	std::cout << seoul::price(3000) << std::endl;
}


