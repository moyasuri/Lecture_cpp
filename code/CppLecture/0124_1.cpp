#include<iostream>

#include <vector>

#include <iostream>
using namespace std;

#include <algorithm>
int main()
{

    std::vector<int> myVector = { 10, 20, 30, 20, 40, 10, 50 };
    //{ 10, 20, 30, 40, 50, 10, 20 }

    // 중복 요소 제거
    std::sort(myVector.begin(), myVector.end());

    for (int i : myVector)
    {
        std::cout << i;
    }


    std::vector<int>::iterator myIter = std::unique(myVector.begin(), myVector.end());


    for (int s : myIter) {

    }




}


