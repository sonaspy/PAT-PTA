// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
vector<int> v[10000];
int visit[10000], minLen, mintrans, src, dst;
unordered_map<int, int> mpLine;
vector<int> ansPath, tempPath;
inline int getTransferT(vector<int> &a)
{
    int len = -1, preLine = 0, curline;
    for (int i = 1; i < a.size(); i++)
    {
        curline = mpLine[a[i - 1] * 10000 + a[i]];
        if (curline != preLine)
            len++;
        preLine = curline;
    }
    return len;
}
void dfs(int node, int len)
{
    if (node == dst)
    {
        if (len < minLen || (len == minLen && getTransferT(tempPath) < mintrans))
        {
            minLen = len;
            mintrans = getTransferT(tempPath);
            ansPath = tempPath;
        }
        return;
    }
    for (auto i : v[node])
    {
        if (!visit[i])
        {
            tempPath.push_back(i);
            visit[i] = 1;
            dfs(i, len + 1);
            visit[i] = 0;
            tempPath.pop_back();
        }
    }
}
int main()
{
    //   test();
    int n, m, k, pre, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++)
        {
            scanf("%d", &temp);
            v[pre].push_back(temp), v[temp].push_back(pre);
            mpLine[pre * 10000 + temp] = mpLine[temp * 10000 + pre] = i + 1;
            pre = temp;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &src, &dst);
        minLen = 1 << 30, mintrans = 1 << 30;
        tempPath.clear(), tempPath.push_back(src);
        visit[src] = 1;
        dfs(src, 0);
        visit[src] = 0;
        printf("%d\n", minLen);
        int preLine = 0, precur = src, curline;
        for (int j = 1; j < ansPath.size(); j++)
        {
            curline = mpLine[ansPath[j - 1] * 10000 + ansPath[j]];
            if (curline != preLine)
            {
                if (preLine != 0)
                    printf("Take Line#%d from %04d to %04d.\n", preLine, precur, ansPath[j - 1]);
                preLine = curline;
                precur = ansPath[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, precur, dst);
    }
    return 0;
}//attention