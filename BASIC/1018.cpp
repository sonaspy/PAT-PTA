// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#define test() freopen("in", "r", stdin)

using namespace std;
int win = 0, loss = 0, ti = 0;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    map<char, int> mp[2];
    int n;
    char c1, c2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c1 >> c2;
        if (c1 == c2)
            ti++;
        else if (c1 == 'B' && c2 == 'C')
        {
            win++;
            mp[0]['B']++;
        }
        else if (c1 == 'B' && c2 == 'J')
        {
            loss++;
            mp[1]['J']++;
        }
        else if (c1 == 'J' && c2 == 'C')
        {
            loss++;
            mp[1]['J']++;
        }
        else if (c1 == 'J' && c2 == 'B')
        {
            win++;
            mp[0]['J']++;
        }
        else if (c1 == 'C' && c2 == 'B')
        {
            loss++;
            mp[1]['B']++;
        }
        else if (c1 == 'C' && c2 == 'J')
        {
            win++;
            mp[0]['C']++;
        }
    }
    int max1 = 0, max2 = 0;
    c1 = 'B', c2 = 'B';
    for (auto it : mp[0])
        if (it.second > max1)
        {
            max1 = it.second;
            c1 = it.first;
        }
    for (auto it : mp[1])
        if (it.second > max2)
        {
            max2 = it.second;
            c2 = it.first;
        }
    if (n > 1000)
        printf("%d %d %d\n%d %d %d\nJ B", win, ti, loss, loss, ti, win);
    else
        printf("%d %d %d\n%d %d %d\n%c %c", win, ti, loss, loss, ti, win, c1, c2);
    return 0;
}