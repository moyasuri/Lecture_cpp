#include <iostream>
#include <vector>
using namespace std;

int main()
{


	// STL (Standard Template Library)
	// 프로그래밍 할 때 필요한 일련의 자료구조/ 알고리즘들을 템플릿으로 제공하는 라이브러리


	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)
	

	// 원리에 대해서 설명을 해라! 가 보통 면접질문
	// 
	// vector (동적 배열) ... -> C#에는 리스트가 있다.
	// - vector의 동작 원리 (size /capacity)
	// - 중간 삽입 /삭제
	// - 처음 / 끝 삽입/삭제
	// - 임의 접근

	// 배열
	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = { };

	// 플레이어 수를 예상할 수 없다면.. 배열의 크기 정의에 문제가 생긴다.
	// 만들어 지는 순간에 결정!

	//for (int i = 0; i < MAX_SIZE; i++)
	//	arr[i] = i;
	//for (int i = 0; i < MAX_SIZE; i++)
	//	cout << arr[i] << endl;



	// 이 동적배열은, 어떻게하여 유동적으로 되는가?

	// 1) (여유분을 두고) 메모리를 할당한다. 
	// 2) 여유분까지 꽉 찼으면, 메모리를 추가적으로 확보
	// 1-1) 여유분은 얼만큼이 적당한가?
	// 2-1) 증설은 얼마나 해야 하는가?
	// 3) 기존의 데이터는 어떻게 처리하는가?

	int arr3[100] = {};

	int* arr2 = new int[100]; // 이거가지고 모지라!하면은
	delete arr2;
	arr2 = new int[1000];


	vector<int> v;

	
	//v.resize(1000); // 미리 데이터 할당 >> 생성자로서 똑같은말은 vector<int> v(1000, 0);  0->초기값 설정
	// vector<int> v2= v 라면 v의 모든 속성이 v2한테 복사됨
	//cout << v.size()<<endl;
	//for (int i = 0; i < 1000; i++)
	//{
	//	cout << v[i] << endl;
	//}


	for (int i = 0; i < 1000; i++)
	{

		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}
	// capacity 는 1.5배씩 늘어. -> 컴파일러마다 달라, 
	// 케파가 다 찻다면 완전히 새로운 메모리에 원래있던 값들을 복사해, 원래있던 메모리 뒤쪽에 이미 어떤 값이 존재할 수도 있으니까
	// 복사비용이 좀 많이들겟네 , 근데 2배씩 메모리증설을하면 그렇게 또 복사비용이 매번 많이 들진않겠지?

	// 또한 미리 안다면
	// v.reserve(1000) -> 근데 이렇다고 해도 사이즈가 1000개 되는건아님!
	

	// 한번 늘어난 capacity는 줄어들지는 않아 -> cpp에서는 그럼
	// 언젠가 또 필요할수도잇다고 생각의 바탕에서




	const int size = v.size();
	for(int i = 0; i < size; i++)
	{
		cout << v[i] << endl;
	}

	

	// size (실제 사용 데이터 개수)
	// capacity (여유분을 포함한 용량 개수)
	// v.capacity();


	v.clear(); // 벡터의 모든 값을 날려버리겠다. // size는 0이되지만 , capcity는 여전히 남아있다.

	// capa도 줄이는법

	vector<int>().swap(v); // 앞에 임시벡터라서 이 줄이 실행되자마자 소멸됨
	cout << v.size() << " " << v.capacity() << endl;
	

	v.pop_back();
	v.back();
	v.front();



	return 0;
	
}