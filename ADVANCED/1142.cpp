// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
unordered_set<int> MAP[211], st;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, a1, a2, k, p, tmp, tmp1;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a1, &a2);
        MAP[a1].insert(a2), MAP[a2].insert(a1);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        bool f1 = true, f2 = true, f3;
        st.clear();
        scanf("%d%d", &p, &tmp);
        st.insert(tmp);
        for (int j = 1; j < p; j++)
        {
            scanf("%d", &tmp1);
            st.insert(tmp1);
            if (!MAP[tmp].count(tmp1))
                f1 = false;
        }
        if (!f1)
            printf("Not a Clique\n");
        else
        {
            for (int j = 1; j <= n; j++)
            {
                if (!st.count(j))
                {
                    f3 = true;
                    for (auto v : st)
                    {
                        if (!MAP[j].count(v))
                        {
                            f3 = false;
                            break;
                        }
                    }
                    if (f3)
                    {
                        f2 = false;
                        break;
                    }
                }
            }
            !f2 ? printf("Not Maximal\n") : printf("Yes\n");
        }
    }
    return 0;
}