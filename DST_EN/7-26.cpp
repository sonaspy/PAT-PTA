// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a1, a2, a3, a4;
    char c;
    scanf("%c", &c);
    map<int, map<int, int>> mp;
    while (c != 'E')
    {
        if (isalpha(cin.peek()))
        {
            scanf("%c\n", &c);
            continue;
        }
        else if (c == 'I')
        {
            scanf("%d%d%d\n", &a1, &a2, &a3);
            mp[a1][a2] += a3;
        }
        else if (c == 'Q')
        {
            scanf("%d%d%d%d\n", &a1, &a2, &a3, &a4);
            int count = 0;
            for (auto i : mp)
            {
                if (i.first < a1)
                    continue;
                else if (i.first > a2)
                    break;
                for (auto j : i.second)
                {
                    if (j.first < a3)
                        continue;
                    else if (j.first > a4)
                        break;
                    count += j.second;
                }
            }
            printf("%d\n", count);
        }
    }
    return 0;
}