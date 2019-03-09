// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, M, num, a1, a2, tmp;
    scanf("%d%d", &N, &M);
    unordered_set<int> st[100000];
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &a1, &a2);
        st[a1].insert(a2);
        st[a2].insert(a1);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &num);
        unordered_set<int> st1;
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &tmp);
            st1.insert(tmp);
        }
        for (auto iter : st1)
            for (auto it1 : st[iter])
                if (st1.count(it1))
                {
                    cout << "No\n";
                    goto end;
                }
        cout << "Yes\n";
    end:;
    }
    return 0;
}