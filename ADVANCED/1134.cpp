// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> MAP[100000];
    unordered_set<int> edge;
    int n, m, k;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        MAP[a].push_back(i), MAP[b].push_back(i);
    }
    cin >> k;
    while (k--)
    {
        scanf("%d", &a);
        edge.clear();
        for (int i = 0; i < a; i++)
        {
            scanf("%d", &b);
            for (auto j : MAP[b])
                edge.insert(j);
        }
        printf("%s\n", (edge.size() == m ? "Yes" : "No"));
    }
    return 0;
}