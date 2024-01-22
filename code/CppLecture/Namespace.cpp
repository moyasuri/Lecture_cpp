#include <iostream>

// C++���� Ŭ������ ���� ��� ������ ���� �� �ʱ�ȭ�� Ŭ���� �ܺο��� �̷������ �մϴ�.Ŭ���� ���ο��� ���� �ʱ�ȭ�ϴ� ���� ������ �ʽ��ϴ�.
namespace MyNamespace {

    class MyClass {
    public:
        static int myStaticVariable;
        void myFunction() {
            // Ŭ���� ���� �ٸ� ����� ����
            myMemberVariable = 5;
        }

    private:
        int myMemberVariable;
    };

    // ���� ��� ������ ����, �ٽ� static�̶�� �� �ʿ䰡 ����
    int MyClass::myStaticVariable = 0; // �ʱ�ȭ ���� ������ �� ����
}



int main() {
    MyNamespace::MyClass obj;
    obj.myFunction();
    
    MyNamespace::MyClass::myStaticVariable = 50;

    return 0;
}





