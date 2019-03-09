// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include<string>
#include<algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a, b, c, d, sh, r;
    cin >> a >> b >> d;
    c = a + b;
    string s;
    sh = c / d;
    r = c % d;
    while (sh || r)
    {   
        s.push_back(r+'0');
        r = sh % d;
        sh /= d;
    }
    reverse(s.begin(),s.end());
    if (!c)
        cout << 0;
    else
        cout << s;
    return 0;
}