#include <iostream>

// C++에서 클래스의 정적 멤버 변수를 선언 및 초기화는 클래스 외부에서 이루어져야 합니다.클래스 내부에서 직접 초기화하는 것은 허용되지 않습니다.
namespace MyNamespace {

    class MyClass {
    public:
        static int myStaticVariable;
        void myFunction() {
            // 클래스 내의 다른 멤버에 접근
            myMemberVariable = 5;
        }

    private:
        int myMemberVariable;
    };

    // 정적 멤버 변수의 정의, 다시 static이라고 쓸 필요가 없음
    int MyClass::myStaticVariable = 0; // 초기화 값을 지정할 수 있음
}



int main() {
    MyNamespace::MyClass obj;
    obj.myFunction();
    
    MyNamespace::MyClass::myStaticVariable = 50;

    return 0;
}





