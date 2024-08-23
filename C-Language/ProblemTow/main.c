#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    char ch[] = "Program is running ";
    char ch2;
    int i = 0;

    printf("%s", ch);

    while (1)
    {
        if (_kbhit())
        {
            ch2 = getch();
            if (ch2 == 27)
                break;
        }

        gotoxy(20, 0);
        for (i = 0; i < 3; i++)
        {
            printf(".");
            Sleep(300);
        }
        gotoxy(20, 0);
        printf("   ");
    }

    return 0;
}
