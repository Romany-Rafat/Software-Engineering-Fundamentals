#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#define null -32
#define higl 180
#define norm 15
using namespace std;

void textattr(int i) /// coloring
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void gotoxy(int x, int y) /// display
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Stack
{
private:
    int SZ, *STK, TOP;

public:
    Stack(int SZ)
    {
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

    ~Stack()
    {
        delete[] STK;
    }
};

int main()
{
    Stack s1(2);
    int now = 0;
    char c1, c2, arr[5][15] = {"=>PUSH", "=>POP", "=>PRINT", "=>IS-FULL", "=>IS-EMPTY"};

    do
    {
        for (int i = 0; i < 5; i++)
        {
            gotoxy(40, i + 3);
            if (now == i)
            {
                textattr(200);
            }
            else
            {
                textattr(norm);
            }
            printf("%s\n", arr[i]);
        }
        textattr(norm);
        c1 = getch(); // Use getch() to handle special keys
        system("cls");
        switch (c1)
        {
        case -32: // Arrow keys
        {
            c2 = getch(); // Get the actual arrow key code
            switch (c2)
            {
            case 72: // Up arrow key
                now = (now == 0) ? 4 : now - 1;
                break;
            case 80: // Down arrow key
                now = (now == 4) ? 0 : now + 1;
                break;
            }
            break;
        }
        case 13: // Enter key
        {
            int elem;
            if (now == 0)
            {
                printf("Enter data: ");
                scanf("%i", &elem);
                if (s1.push(elem))
                    printf("==> PUSHED.\n");
            }
            else if (now == 1)
            {
                if (s1.pop())
                    printf("==> POPPED.\n");
            }
            else if (now == 2)
            {
                printf("==> PRINT.\n");
                s1.print();
            }
            else if (now == 3)
            {
                printf("==> IS FULL: %s\n", s1.isFull() ? "true" : "false");
            }
            else if (now == 4)
            {
                printf("==> IS EMPTY: %s\n", s1.isEmpty() ? "true" : "false");
            }
            break;
        }
        }
    }
    while (true);   // Infinite loop, can be exited with Ctrl+C or other methods

    return 0;
}
