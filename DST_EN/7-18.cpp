// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, vector<int>> post;
    unordered_map<int, int> indegree;
    vector<int> ans;
    int n, hashmp[1000], v, suppose;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", hashmp + i);
    for (int i = 0; i < n; i++)
    {
        if (hashmp[i] >= 0)
        {
            suppose = hashmp[i] % n;
            if (suppose == i)
                indegree[hashmp[i]] = 0;
            else
                for (int j = suppose; j != i; j = (j + 1) % n)
                {
                    post[hashmp[j]].push_back(hashmp[i]);
                    indegree[hashmp[i]]++;
                }
        }
    }
    for (auto i : indegree)
        if (!i.second)
            pq.push(i.first);
    while (pq.size())
    {
        v = pq.top(), pq.pop();
        ans.push_back(v);
        for (auto i : post[v])
            if (--indegree[i] == 0)
                pq.push(i);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i)
            printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}