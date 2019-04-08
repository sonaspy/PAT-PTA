// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
char b[] = {'a', 'b', 'c', 'd'};
void func1(char a[])
{
    printf("%p %p %p\n", &a, (&(a[0])), (&(a[1])));
}
void func2(char *a)
{
    printf("%p %p %p %p\n", &a, (&(a[0])), (&(a[1])), (a+1));
}
char ga[] = "abcdefghijklm";
void my_array_func(char ca[10])
{
    printf(" addr of array param = %p \n", &ca);
    printf(" addr (ca[0]) = %p \n", &(ca[0]));
    printf(" addr (ca[1]) = %p \n", &(ca[1]));
    printf(" ++ca = %p \n\n", ++ca);
}
void my_pointer_func(char *pa)
{
    printf(" addr of ptr param = %p \n", &pa);
    printf(" addr (pa[0]) = %p \n", &(pa[0]));
    printf(" addr (pa[1]) = %p \n", &(pa[1]));
    printf(" ++pa = %p \n", ++pa);
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    printf(" addr of global array = %p \n", &ga);
    printf(" addr (ga[0]) = %p \n", &(ga[0]));
    printf(" addr (ga[1]) = %p \n\n", &(ga[1]));
    my_array_func(ga);
    my_pointer_func(ga);
    return 0;
}