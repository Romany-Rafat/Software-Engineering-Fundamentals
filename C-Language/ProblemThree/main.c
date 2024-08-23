#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<windows.h>
#define null -32
#define higl 180
#define norm 15
void textattr(int i) /// coloring
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void gotoxy(int x,int y) /// display
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    int i=1,now=0;
    char c1,c2,arr[4][15]= {"=>Edit","=>Display","=>Delete","=>Exit"};
    do
    {
        for(int i=0; i<4; i++)
        {
            gotoxy(40,i+3);
            if(now==i)
            {
                textattr(200);
            }
            else
            {
                textattr(norm);
            }
            printf("%s\n",arr[i]);
        }
        textattr(norm);
        c1=getch();
        switch(c1)
        {
        case -32: /// arrow keys.
        {
            c2=getch();
            switch(c2)
            {
            case 72: /// up arrow key.
            {
                //  0
                //  1
                //  2
                //  3
                if(now==0)
                {
                    now=3;
                }
                else if(now>0)
                {
                    now--;
                }
                break;
            }
            case 80:
            {
                if(now==3)
                {
                    now=0;
                }
                else if(now <3)
                {
                    now++;
                }
                break;
            }
            }
            break;
        }
        case 13:
        {
            if(now==0)
            {
                printf("==>Edit.\n");
            }
            else if(now==1)
            {
                printf("==>Display.\n");
            }
            else if(now==2)
            {
                printf("==>Delete.\n");
            }
            else if(now==3)
            {
                printf("==>Exit.");
                i=0;
            }
        }
        break;
        }
    }
    while(i);
    return 0;
}
