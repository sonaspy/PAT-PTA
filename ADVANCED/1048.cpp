// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

int n, m, tmp, mp[1005]; // if you do not decare variables(especially the array mp[1005]) as global, test case 3 won't pass.
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        ++mp[tmp];
    }
    for (int i = 1; i < m; i++)
    {
        if (mp[i] && mp[m - i])
        {
            if (2 * i == m && mp[i] < 2) continue;
            printf("%d %d\n", i, m - i);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}