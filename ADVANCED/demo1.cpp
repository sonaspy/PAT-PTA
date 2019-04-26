// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;

int func()
{
    srand(time(NULL));
    return rand() % 100;
}

int main(int argc, char const *argv[])
{
    /* code */
    cout << func();
    
    return 0;
}