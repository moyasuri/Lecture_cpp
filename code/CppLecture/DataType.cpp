#include <iostream>
#include <climits>


using namespace std;
void line();


// CPU가 메모리에 접근하는 기본 단위가 1바이트 이므로 거의 대부분의 언어가 비슷하다는 사실을 염두해 둔다.
// 불형은 참,거짓의 두가지 경우만 있기 때문에 0과1 즉 1비트만으로도 가능할 것 같은데 굳이 8비트(1바이트)를 쓰는 이유는 CPU 의 손이 8비트 이기 때문이다.
// 1바이트는 256개, 2바이트는 65000개, 4바이트는 42억까지의 숫자범위를 표현가능하다.
// 즉 int 라는 부호없는 정수형 자료형에는 0부터  42억의 범위에 있는 1개의 값을 저장할 수 있다.

int main()
{
    cout << "Basic data type C++" << endl;
    line();
    cout << "bool size  : " << sizeof(bool) << " byte\n";


    cout << "char size        : " << sizeof(char) << " byte\n";
    cout << "wchar_t size  : " << sizeof(wchar_t) << " byte\n";
    cout << "short size       : " << sizeof(short) << " byte\n";
    cout << "int size           : " << sizeof(int) << " byte\n";
    cout << "long size        : " << sizeof(long) << " byte\n";


    cout << "float size      : " << sizeof(float) << " byte\n";
    cout << "double size  : " << sizeof(double) << " byte\n";
    cout << "long double size  : " << sizeof(long double) << " byte\n";


    return 0;
}
void line() {
    cout << "=======================" << endl;
}