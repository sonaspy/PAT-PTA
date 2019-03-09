// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a1, a2, a3, a4;
    char c;
    scanf("%c", &c);
    unordered_map<int, unordered_map<int, int>> mp;
    while (c != 'E')
    {
        if (cin.peek() > 'A')
        {
            scanf("%c\n", &c);
            continue;
        }
        if (c == 'I')
        {
            scanf("%d%d%d\n", &a1, &a2, &a3);
            mp[a1][a2] += a3;
        }
        if (c == 'Q')
        {
            scanf("%d%d%d%d\n", &a1, &a2, &a3, &a4);
            int count = 0;
            for (auto i : mp)
                for (auto j : i.second)
                    if (i.first >= a1 && i.first <= a2 && j.first >= a3 && j.first <= a4)
                        count += j.second;
            printf("%d\n", count);
        }
    }
    return 0;
}