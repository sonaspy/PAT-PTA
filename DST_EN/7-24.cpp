#include<iostream>
#include<algorithm>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int bags[101];
    bool selected[10001][101];
    int coins[10001],n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        {
            cin >> coins[i];
        }
    sort(coins + 1, coins + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
                {
                    if (j - coins[i] >= 0 && bags[j - coins[i]] + coins[i] >= bags[j])
                        {
                            selected[i][j] = true;
                            bags[j] = bags[j - coins[i]] + coins[i];
                        }
                }
        }
    if (bags[m] != m)
        {
            cout << "No Solution" << endl;
            return 0;
        }
    int j = m, i = n;
    while (1)
        {
            if (selected[i][j] == true)
                {
                    cout << coins[i];
                    j -= coins[i];
                    if (j != 0)
                        cout << " ";
                }
            i--;
            if (j == 0 || i == 0)
                break;
        }
    cout << endl;
    return 0;
}