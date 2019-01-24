// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    int weight;
    string s;
} nodes[70];
priority_queue<int, vector<int>, greater<int>> pq;
unordered_map<char, int> mp;
int n;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, wpl = 0;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        cin >> mp[c];
        pq.push(mp[c]);
    }
    cin >> m;
    while (true)
    {
        int tp = pq.top();
        pq.pop();
        if (pq.empty())
            break;
        tp += pq.top();
        pq.pop();
        pq.push(tp);
        wpl += tp;
    }
    while (m--)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            cin >> nodes[i].s;
            sum += mp[c] * nodes[i].s.size();
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            string pre = nodes[i].s;
            for (int j = 0; j < n; j++)
                if (i != j && pre == nodes[j].s.substr(0, pre.length()))
                    flag = false;
        }
        if (sum == wpl && flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}