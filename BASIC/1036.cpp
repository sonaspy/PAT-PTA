// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include<string>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int n, row, cloumn;
    char c;
    cin >> n >> c;
    row = n, cloumn = int(row * 0.5 + 0.5);
    string s1, s2;
    for(int i = 0;i < row; i++) s1.push_back(c);
    s2.push_back(c);
    for (int i = 0; i < row-2; i++)
        s2.push_back(' ');
    s2.push_back(c);
    cout << s1 << endl;
    for (int i = 0; i < cloumn-2; i++)
        cout << s2 << endl;
    cout << s1 << endl;
    return 0;
}