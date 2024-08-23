#include<stdio.h>

static int r = 0;
int func();
int main()
{
    func(); func();
}

int func()
{

    r++;
    printf("%d",r);
    return 0;
}
