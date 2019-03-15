#include <stdio.h>

void swapv(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapp(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{

    int x = -1, y = 3;

    swapv(x, y);
    printf("x=%d,y=%d;\n ", x, y);

    swapp(x, y);
    printf("x=%d,y=%d\n", x, y);

    return 0;
}