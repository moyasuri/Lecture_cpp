#include<iostream>

using namespace std;


class Animal
{
public:
    Animal() {  }

    Animal(int value)
    {
        _age = value;
    }

    virtual void Speak() = 0; // ���� ���� �Լ� 1�� �̻� ���ԵǾ� �ִ� Ŭ������

protected:
    int _age;

};

class Dog : public Animal
{
public:
    Dog() : Animal(4)
    {

    }

    void Speak()
    {
        cout << "�۸�" << endl;
    }



};

class Cat : public Animal
{
public:
    Cat() : Animal(2)
    {

    }
    void Speak()
    {
        cout << "�ɳ�" << endl;
    }

};

void AnimalSpeak(Animal* animal)
{
    animal->Speak();
}

int main()
{

    Cat* mycat = new Cat();
    
    Animal* myanimal = new Cat();

    myanimal->Speak();
    AnimalSpeak(mycat);



}
