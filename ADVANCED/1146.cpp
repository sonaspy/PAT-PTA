// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int indegree[1001] = {0}, cnt = 0, resorder[1001] = {0}, n, m, k, a1, a2;
vector<int> MAP[1001], res;

inline bool Judge()
{
    vector<int> In(indegree, indegree + n + 1);
    for (int i = 0; i < n; i++)
    {
        int V = resorder[i];
        if (In[V])
            return false;
        for (auto w : MAP[V])
            In[w]--;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a1, &a2);
        MAP[a1].push_back(a2);
        indegree[a2]++;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &resorder[j]);
        if (!Judge())
        {
            if (cnt != 0)
                cout << " ";
            cout << i;
            cnt++;
        }
    }

    return 0;
}