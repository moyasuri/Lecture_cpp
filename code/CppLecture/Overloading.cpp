#include <iostream>

int func1(int num1) {
    return num1 * num1;
}

int func1(int num1, int num2) {
    return num1 + num2;
}

int main() {
    //int result = func1(1); // 명시적으로 첫 번째 함수 호출
    //std::cout << "Result: " << result << std::endl;


    


    int a = func1(3,2);
    int b = func1(4);



    return 0;
}
