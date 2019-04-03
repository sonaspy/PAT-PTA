// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int *a = new int[10];
    int b[10];
    char s[] = "saaa";
    s[1]  = '*';
    cout << s[1] << endl;
    cout << a <<endl;
    cout << a + 1 << endl;
    cout << a + 2 << endl << endl;
    cout << &a <<endl;
    cout << &a + 1 << endl;
    cout << &a + 2 << endl;
    cout << &a + 3 << endl << endl;
    cout << b<<endl ;
    cout << b+1;
    return 0;
}