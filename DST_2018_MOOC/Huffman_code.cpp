#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
    string dight;
    int weight;
    bool operator<(const node &a) const
    { //什么情况下优先输出后面那个，这个和sort的刚好相反
        if (weight == a.weight)
        {
            return dight.length() < a.dight.length();
        }
        return weight > a.weight;
    }
};
node h[100];
map<char, int> ha;
int main()
{
    int n;
    scanf("%d", &n);
    int i, num, sum;
    char cha;
    for (i = 0; i < n; i++)
    {
        cin >> cha;
        scanf("%d", &ha[cha]);
    }
    scanf("%d", &num);
    while (num--)
    {
        sum = 0;
        priority_queue<node> q;
        for (i = 0; i < n; i++)
        {
            cin >> cha >> h[i].dight;
            sum += ha[cha];
            h[i].weight = ha[cha];
            q.push(h[i]);
        }

        node cur, next;
        queue<node> qq;
        bool can;
        while (!q.empty())
        {
            cur = q.top();
            q.pop();
            can = false;
            while (!q.empty())
            {
                next = q.top();
                q.pop();
                if (cur.dight.length() == next.dight.length())
                {
                    if (cur.dight.substr(0, cur.dight.length() - 1) == next.dight.substr(0, next.dight.length() - 1) && cur.dight[cur.dight.length() - 1] != next.dight[next.dight.length() - 1])
                    {
                        can = true;
                        while (!qq.empty())
                        { //还原
                            q.push(qq.front());
                            qq.pop();
                        }
                        break;
                    }
                    else
                    {
                        qq.push(next);
                    }
                }
                else
                    break;
            }
            if (can)
            { //找到了
                cur.dight = cur.dight.substr(0, cur.dight.length() - 1);
                cur.weight += next.weight;
                if (q.empty())
                {
                    break;
                }
                q.push(cur);
            }
            else
            {
                break;
            }
        }
        if (can && cur.weight == sum && !cur.dight.length())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}