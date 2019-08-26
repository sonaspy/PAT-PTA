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
    vector<int> danger_pair[100000];
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &t1, &t2);
        danger_pair[t1].push_back(t2), danger_pair[t2].push_back(t1);
    }
    while (k--)
    {
        int cnt, explotion = 0, onship[100000] = {0};
        scanf("%d", &cnt);
        vector<int> packages(cnt);
        for (int i = 0; i < cnt; i++)
        {
            scanf("%d", &packages[i]);
            onship[packages[i]] = 1;
        }
        for (auto node : packages)
            for (auto v : danger_pair[node])
                if (onship[v] == 1)
                {
                    explotion = 1;
                    break;
                }
        printf("%s\n", explotion ? "No" : "Yes");
    }
    return 0;
}