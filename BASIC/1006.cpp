// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string n, h, m, l;
    cin >> n;
    for (int i = n.size() - 1; i > -1; i--)
    {
        if (i == n.size() - 1)
        {
            for (int j = 1; j <= n[n.size() - 1] - 48; j++)
                l.push_back('0' + j);
        }
        else if (i == n.size() - 2)
        {
            for(int j = 0; j < n[n.size()-2] - 48; j++)
                m.push_back('S');
        }
        else if (i == n.size() - 3)
        {
            for (int j = 0; j < n[n.size() - 3] - 48; j++)
                h.push_back('B');
        }
    }
    cout << h+m+l;

    return 0;
}