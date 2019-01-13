// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int N, M;
const int MAXN = 10005;
vector<int> MAP[MAXN];
int union_set[MAXN];

int trace_root(int c)
{
    if (union_set[c] == -1)
        return c;
    else
        return union_set[c] = trace_root(union_set[c]);
}

void union_connect(int c1, int c2)
{
    int r1 = trace_root(c1);
    int r2 = trace_root(c2);
    if (r1 != r2)
        union_set[r2] = r1;
}

int main(int argc, char const *argv[])
{
    /* code */
    // test();
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        MAP[i].clear();
        union_set[i] = -1;
    }
    int a1, a2;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &a1, &a2);
        union_connect(a1, a2);
        MAP[a1].push_back(a2);
        MAP[a2].push_back(a1);
    }
    int root_num = 0, odd_num = 0;
    for (int i = 1; i <= N; i++)
    {
        if (MAP[i].size() % 2)
            odd_num++;
        if (trace_root(i) == i)
            root_num++;
    }
    if (odd_num == 0 && root_num == 1)
        cout << 1;
    else
        cout << 0;

    return 0;
}