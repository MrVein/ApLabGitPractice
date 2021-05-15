//no problem. x[0] = 1 changes the least important byte of a; wich will result in an "modified a"
#include<stdio.h>
int main()
{
    int a;
    char *x;
    x = (char *)&a;
    a = 512;
    x[0] = 1;
    printf("%d\n", a);
    return 0;
}
