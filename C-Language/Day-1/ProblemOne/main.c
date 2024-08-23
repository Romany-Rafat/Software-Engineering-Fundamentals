#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int main()
{
    char ch, ch2;
    while (1)
    {
        printf("Press any key:\n");
        ch = getch();
        if (ch == -32 || ch == 0)    /// Extended key.
        {
            ch2 = getch();
            printf("Extended key detected. First code: %i, Second code: %i\n", ch, ch2);
        }
        else
        {
            printf("Regular key: %i\n", ch);
        }
    }
    return 0;
}
