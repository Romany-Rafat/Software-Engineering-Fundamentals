#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int age;
    string breed;
    string barkMethod;

public:
    Animal(string name = "Animal", int age = 0) : name(name), age(age) {}

    void showDetails()
    {
        cout << "Name of Animal: " << name << endl;
        cout << "Age of Animal: " << age << " years" << endl;
        cout << "Breed: " << breed << endl;
        cout << "Bark Method: " << barkMethod << endl;
    }

     void setBreed() {cout<<"base"<<endl;}
     void setBarkMethod() {
        cout<<"base"<<endl;
     }
};

class Dog : public Animal
{
public:
    Dog(string breed, string barkMethod, int age, string name) : Animal(name, age)
    {
        this->breed = breed;
        this->barkMethod = barkMethod;
    }

    void setBreed()
    {
        cout << "Breed of Dog: " << breed << endl;
    }

    void setBarkMethod()
    {
        cout << "Bark Method for Dog: " << barkMethod << endl;
    }
};

int main()
{
    ///Dog(string breed, string barkMethod, int age, string name) : Animal(name, age)
    Animal* ptr=new Dog("A","B",12,"Dog");
    ptr->setBreed();
    return 0;
}
