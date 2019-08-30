// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

bool isMatch(vector<int> &push_seq, vector<int> &pop_seq, int capacity)
{
    int walk = 0;
    stack<int> s;
    for (int j = 0; j < push_seq.size(); j++)
    {
        s.push(push_seq[j]);
        if (s.size() > capacity)
            return false;
        while (s.size() && s.top() == pop_seq[walk])
            s.pop(), walk++;
    }
    return walk == push_seq.size();
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int capacity, n, k;
    scanf("%d %d %d", &capacity, &n, &k);
    vector<int> pop_seq(n), push_seq(n);
    iota(push_seq.begin(), push_seq.end(), 1);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &pop_seq[j]);
        isMatch(push_seq, pop_seq, capacity) ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}