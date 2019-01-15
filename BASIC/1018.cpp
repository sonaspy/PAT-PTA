// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    int win = 0, loss = 0, tie = 0;
} player1, player2;

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
        {
            player1.tie++;
            player2.tie++;
        }
        else if (c1 == 'B' && c2 == 'C')
        {
            player1.win++;
            player2.loss++;
            mp[0]['B'] += 1;
        }
        else if (c1 == 'B' && c2 == 'J')
        {
            player1.loss++;
            player2.win++;
            mp[1]['J'] += 1;
        }
        else if (c1 == 'J' && c2 == 'C')
        {
            player2.win++;
            player1.loss++;
            mp[1]['J'] += 1;
        }
        else if (c1 == 'J' && c2 == 'B')
        {
            player1.win++;
            player2.loss++;
            mp[0]['J'] += 1;
        }
        else if (c1 == 'C' && c2 == 'B')
        {
            player2.win++;
            player1.loss++;
            mp[1]['B'] += 1;
        }
        else if (c1 == 'C' && c2 == 'J')
        {
            player1.win++;
            player2.loss++;
            mp[0]['C'] += 1;
        }
    }
    printf("%d %d %d\n", player1.win, player1.tie, player1.loss);
    printf("%d %d %d\n", player2.win, player2.tie, player2.loss);
    int max1 = 0, max2 = 0;
    c1 = 'B', c2 = 'B';
    for (auto it : mp[0])
    {
        if (it.second > max1)
        {
            max1 = it.second;
            c1 = it.first;
        }
    }
    for (auto it : mp[1])
    {
        if (it.second > max2)
        {
            max2 = it.second;
            c2 = it.first;
        }
    }
    cout << c1 <<  " "<<c2;

    return 0;
}