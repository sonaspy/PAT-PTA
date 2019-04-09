// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
void my_function_1(int fruit[2][3][5]) { ; }
void my_function_2(int fruit[][3][5]) { ; }
void my_function_3(int (*fruit)[3][5]) { ; }

int main(int argc, char const *argv[])
{
    /* code */
    char s[16] = "12313";
    char *mp[5];
    mp[0] = new char[16];
    mp[0] = s;

    int *inta[10];
    inta[0] = new int[1];
    inta[1] = new int[20];
    cout << sizeof inta[0] << endl;
    cout << sizeof *(*(inta+1)+1) << endl;

    int apricot[2][3][5];
    my_function_1(apricot);
    my_function_2(apricot);
    my_function_3(apricot);
    int(*p)[3][5] = apricot;
    my_function_1(p);
    my_function_2(p);

    my_function_3(p);
    int(*q)[2][3][5] = &apricot;
    my_function_1(*q);
    my_function_2(*q);
    my_function_3(*q);
    return 0;
}