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

    virtual void Speak() = 0; // 순수 가상 함수 1개 이상 포함되어 있는 클래스를

protected:
    int _age;

};

class Dog: public Animal
{
public:
    Dog() : Animal(4)
    {

    }

    void Speak()
    {
        cout << "멍멍" << endl;
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
        cout << "냥냥" << endl;
    }

};

void AnimalSpeak(Animal* animal)
{
    animal -> Speak();
}

int main()
{
    
    Cat* mycat = new Cat();

    AnimalSpeak(mycat);




}