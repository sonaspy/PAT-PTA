// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    char a[1000];
};
void fun(node s[10])
{
    cout << &s->a << endl;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    node n1[10];
    //n1.a = new char[10];
    cout << &n1->a << endl;
    fun(n1);
    return 0;
}