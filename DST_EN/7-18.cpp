// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, unordered_set<int>> mp;
    unordered_map<int, int> indegree;
    vector<int> ans;
    int n, num[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (int i = 0; i < n; i++)
        {
            if (num[i] < 0)
                continue;
            int remain = num[i] % n;
            if (remain == i)
                indegree[num[i]] = 0;
            else
                for (int j = remain; j != i; j = (j + 1) % n)
                    {
                        if (num[j] < 0)
                            continue;
                        mp[num[j]].insert(num[i]);
                        indegree[num[i]]++;
                    }
        }
    for (auto i : indegree)
        if (i.second == 0)
            pq.push(i.first);
    while (pq.size())
        {
            int v = pq.top();
            ans.push_back(v);
            pq.pop();
            for (auto i : mp[v])
                if (--indegree[i] == 0)
                    pq.push(i);
        }
    for (int i = 0; i < ans.size(); i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", ans[i]);
        }
    return 0;
}