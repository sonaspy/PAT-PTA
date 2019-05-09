// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>
#define NUMS 100000
#define test() freopen("in", "r", stdin)
typedef long long ll;
using namespace std;
unordered_set<string> explo;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, k, t1, t2;
    vector<int> mp[100000];
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &t1, &t2);
        mp[t1].push_back(t2), mp[t2].push_back(t1);
    }
    while (k--)
    {
        int cnt, flag = 0, a[100000] = {0};
        scanf("%d", &cnt);
        vector<int> v(cnt);
        for (int i = 0; i < cnt; i++)
        {
            scanf("%d", &v[i]);
            a[v[i]] = 1;
        }
        for (auto i : v)
            for (auto j : mp[i])
                if (a[j] == 1)
                {
                    flag = 1;
                    break;
                }
        printf("%s\n", flag ? "No" : "Yes");
    }
    return 0;
}//attention