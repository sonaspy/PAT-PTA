// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

string codes[100];
priority_queue<int, vector<int>, greater<int>> pq;
unordered_map<char, int> freq;
int n;
int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, m, total_w = 0;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> freq[c];
        pq.push(freq[c]);
    }
    cin >> m;
    while (pq.size() > 1)
    {
        int tp = pq.top();
        pq.pop();
        tp += pq.top();
        pq.pop();
        pq.push(tp);
        total_w += tp;
    }
    while (m--)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> c >> codes[i];
            sum += freq[c] * codes[i].size();
        }
        bool ambiguous = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (i == j)
                    continue;
                else if (codes[i] == codes[j].substr(0, codes[i].length()))
                    ambiguous = true;
        }
        (sum == total_w && !ambiguous) ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}