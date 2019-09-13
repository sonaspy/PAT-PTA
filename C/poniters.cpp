// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#define test() freopen("in", "r", stdin)

using namespace std;
inline int func(int i) { return 1; }
int (*pf)(int) = &func;
typedef int (*FUNCPointer)(int);
FUNCPointer pfarr1[3] = {pf, pf, pf};
int (*pfarr2[3])(int) = {pf, pf, pf};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int b[3] = {11, 22, 33}, c[3] = {44, 55, 66}, d[3] = {77, 88, 99};
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *a2[3] = {*a, *(a + 1), *(a + 2)};
    int *a3[3] = {b, c, d};
    int(*p2arr)[3];
    int **p;
    p2arr = a;
    a2[1] = b;


    return 0;
}