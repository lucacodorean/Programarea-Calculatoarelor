/*
You can take a string as input in C using scanf(“%s”, s). But, it accepts string only until it finds the first space.
In order to take a line as input, you can use scanf("%[^\n]%*c", s); where  is defined as char s[MAX_LEN] where  is the maximum size of .
Here, [] is the scanset character. ^\n stands for taking input until a newline isn't encountered.
Then, with this %*c, it reads the newline character and here, the used * indicates that this newline character is discarded.

Note: The statement: scanf("%[^\n]%*c", s); will not work because the last statement will read a newline character, \n, from the previous line.
This can be handled in a variety of ways. One way is to use scanf("\n"); before the last statement.
 */

#include <stdio.h>
#define MAX_L 100

int main()
{
    char first; scanf("%c", &first);
    char second[MAX_L], third[MAX_L];

    scanf("%s\n", second);
    scanf("%[^\n]%*c", third);

    printf("%c", first);
    printf("\n%s", second);
    printf("\n%s", third);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}