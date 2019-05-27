// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;
#define test() freopen("in", "r", stdin)
int tmp, n, colorn, strip[10001], colorRank[201];
static int length = 0, maxlen = 0;
void DFS(int start, int curRank)
{
    for (int i = start; i < n; i++)
    {
        int rank = colorRank[strip[i]];
        if (curRank <= rank)
        {
            length++;
            DFS(i + 1, rank);
        }
    }
    if (length > maxlen)
        maxlen = length;
    length--;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> colorn >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        colorRank[tmp] = i + 1;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &strip[i]);
    DFS(0, 1);
    cout << maxlen;
    return 0;
}