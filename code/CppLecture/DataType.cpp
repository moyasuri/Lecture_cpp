#include <iostream>
#include <climits>


using namespace std;
void line();


// CPU�� �޸𸮿� �����ϴ� �⺻ ������ 1����Ʈ �̹Ƿ� ���� ��κ��� �� ����ϴٴ� ����� ������ �д�.
// ������ ��,������ �ΰ��� ��츸 �ֱ� ������ 0��1 �� 1��Ʈ�����ε� ������ �� ������ ���� 8��Ʈ(1����Ʈ)�� ���� ������ CPU �� ���� 8��Ʈ �̱� �����̴�.
// 1����Ʈ�� 256��, 2����Ʈ�� 65000��, 4����Ʈ�� 42������� ���ڹ����� ǥ�������ϴ�.
// �� int ��� ��ȣ���� ������ �ڷ������� 0����  42���� ������ �ִ� 1���� ���� ������ �� �ִ�.

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