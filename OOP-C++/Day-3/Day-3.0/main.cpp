#include <iostream>
using namespace std;
class Stack
{
private:
    int SZ, *STK, TOP;
    static int obj;

public:
    static int countNUmberOfObjects()
    {
        return obj;
    }

    Stack(int SZ)
    {
        obj++;
        this->SZ = SZ;
        STK = new int[SZ];
        TOP = 0;
    }

    bool push(int elem)
    {
        if (isFull())
        {
            cout << "Stack is full\n";
            return false;
        }
        else
        {
            STK[TOP] = elem;
            TOP++;
            return true;
        }
    }

    bool pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return false;
        }
        else
        {
            cout << STK[TOP - 1] << endl;
            TOP--;
            return true;
        }
    }

    void print()
    {
        if (!isEmpty())
        {
            cout << "Your Stack Elements : \n";
            for (int i = 0; i < TOP; i++)
            {
                cout << STK[i] << endl;
            }
        }
        else
        {
            cout << "Stack is empty\n";
        }
    }

    bool isFull()
    {
        return (TOP == SZ);
    }

    bool isEmpty()
    {
        return (TOP == 0);
    }

    int peak()
    {
        if (isEmpty())
            return -1;
        else
            return STK[TOP - 1];
    }

    ~Stack()
    {
        delete[] STK;
    }
};
int Stack::obj = 0;
int main()
{
    Stack s1(3);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();
    cout << s1.peak() << endl;
    Stack s2(2);
    cout << "number of Objects from Stack class is : " << Stack::countNUmberOfObjects() << endl;
    return 0;
}
