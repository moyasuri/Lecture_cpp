#include <iostream>

using namespace std;



struct Position {
	int x = 0;
	int y = 0;
};

// call by value value를 파라메터로 복사(값 복사)
// call by address 주소를 파라메터로 복사(주소 복사)
// call by reference call by address 랑 정확히 똑같다. 어디서? 로우레벨에서(어셈블리단계에서)

struct Student {
	
	
	string name;
	int phonenumber;
	string schoolname;
	string major;
	int studentnumber;
	string region;
	double height;
	double weight;

};

using namespace std;

void printStudenfInfobyvalue(Student stu)
{
	cout << stu.name << " " << stu.major << " " << stu.height;
}


void printStudenfInfobyaddress(const Student* stu)
{
	cout << stu->name << " " << stu->major << " " << stu->height;
}


void printStudentInfobyreference(Student& stu)
{
	cout << stu.name << " " << stu.major << " " << stu.height;
}

int main()
{



	//printStudenfInfobyvalue(noah);
	//printStudenfInfobyaddress(&noah);

	int a = 3;
	int& i = a;

	// a의 다른이름을 내가 i 로 설정하겠다.
	Student noah;
	Student& stu = noah;
	


	Student* mystu;
	mystu = &noah;

	noah.name = "noah";
	noah.major = "mechanical engineering";
	noah.height = 200.0;
	printStudentInfobyreference(stu);

	cout << noah.name << "and" << stu.name;

	// 쓰이는 문법은 일반 변수랑 똑같으나, 안에서 일어나는 일은, 포인터랑 똑같다.

		
	Student* mystu = nullptr;

}


