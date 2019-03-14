// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s;
    cin >> s;
    int n = s.size(), x = 0, y = 3, mindis = 1 << 30, _x, _y;
    for (;y < n;y++)
    {
        if ((n + 2 - y) % 2 == 0)
            x = (n + 2 - y) / 2;
        else continue;
        if (x <= y && y - x < mindis)
        {
            mindis = y - x;
            _x = x, _y = y;
        }
    }
    for(int i = 0; i < _x -1;i++){
        cout << s[i];
        for(int j = 0; j < _y-2;j++)cout << " ";
        cout << s[s.size()-1-i];
        cout << endl;
    }
    cout << s.substr(_x-1,_y);

    return 0;
}