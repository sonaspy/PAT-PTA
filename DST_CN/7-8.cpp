// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int INF = INT_MAX;
int mp[N][N];

int main(int argc, char const *argv[])
{
    /* code */
    //freopen("in","r",stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                mp[i][j] = 0;
            else
                mp[i][j] = INF;
        }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a][b] = mp[b][a] = c;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (mp[i][j] > mp[i][k] + mp[k][j] && mp[i][k] != INF && mp[k][j] != INF)
                    mp[i][j] = mp[i][k] + mp[k][j];

    int index = 0, val, min = INF;
    for (int i = 1; i <= n; i++)
    {
        val = *max_element(mp[i] + 1, mp[i] + 1 + n);
        if (min > val)
        {
            min = val;
            index = i;
        }
    }
    if (index == 0)
        cout << "0\n";
    else
        cout << index << " " << min << endl;
    return 0;
}