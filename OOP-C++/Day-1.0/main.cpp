#include <iostream>

using namespace std;

void swapByValue(int a, int b);
void swapByPointer(int* a, int* b);
void swapByReference(int& a, int& b);

int main()
{
    int a, b;
    cout << "Enter A : ";
    cin >> a;
    cout << "Enter B : ";
    cin >> b;
    cout << "A before swap is : " << a << " B before swap is : " << b << endl<< endl;

    swapByValue(a, b);
    cout << "A in main : " << a << ", B : " << b << endl<< endl;

    swapByPointer(&a, &b);
    cout << "A in main function after swap by value after swap by Pointer is : " << a << ", B  : " << b << endl<< endl;

    swapByReference(a, b);
    cout << "A in main function after swap by value after swap by reference is : " << a << ", B : " << b << endl<< endl;

    return 0;
}

void swapByValue(int a, int b)
{
    int temp;
    if (a <= 0 || b <= 0)
    {
        temp = a;
        a = b;
        b = temp;
    }
    else
    {
        a *= b;
        b = a / b;
        a = a / b;
    }
    cout << "In function swapByValue: A = " << a << ", B = " << b << endl;
}

void swapByPointer(int* a, int* b)
{
    int temp;
    if (*a <= 0 || *b <= 0)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    else
    {
        *a *= *b;
        *b = *a / *b;
        *a = *a / *b;
    }
    cout << "In function swapByPointer: A = " << *a << ", B = " << *b << endl;
}

void swapByReference(int& a, int& b)
{
    int temp;
    if (a <= 0 || b <= 0)
    {
        temp = a;
        a = b;
        b = temp;
    }
    else
    {
        a *= b;
        b = a / b;
        a = a / b;
    }
    cout << "In function swapByReference: A = " << a << ", B = " << b << endl;
}
