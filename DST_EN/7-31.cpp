// author -  newguo@sonaspy.cn
// coding - utf_8
#include <cstdio>
#include <cstring>
#include <algorithm>
#define test() freopen("in", "r", stdin)
using namespace std;
const int maxn = 1e5 + 10;
struct Node
{
    int age, worth;
    char name[10];
} node[maxn];

bool cmp(Node a, Node b)
{
    if (a.worth != b.worth)
        return a.worth > b.worth;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return strcmp(a.name, b.name) < 0;
}

int main(int argc, char const *argv[])
{
    int n, m, k, amin, amax;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%s %d %d", node[i].name, &node[i].age, &node[i].worth);
    sort(node, node + n, cmp);
    for (int i = 1; i <= k; i++)
        {
            scanf("%d%d%d", &m, &amin, &amax);
            printf("Case #%d:\n", i);
            int cnt = 0;
            for (int j = 0; j < n; j++)
                {
                    if (node[j].age >= amin && node[j].age <= amax)
                        {
                            printf("%s %d %d\n", node[j].name, node[j].age, node[j].worth);
                            cnt++;
                        }
                    if (cnt == m)
                        break;
                }
            if (cnt == 0)
                printf("None\n");
        }
    return 0;
}
