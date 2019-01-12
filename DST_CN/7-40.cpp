
// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>

#define test() freopen("in", "r", stdin)

using namespace std;
const int maxn = 233;

int n, m;

struct node
{
    int id;
    int au, al, p;
    double d1, d2;
} a[maxn], b[maxn], c[maxn], d[maxn];
bool cmp1(node a, node b)
{
    if (a.au == b.au)
        return a.id < b.id;
    return a.au > b.au;
}
bool cmp2(node a, node b)
{
    if (a.al == b.al)
        return a.id < b.id;
    return a.al > b.al;
}
bool cmp3(node a, node b)
{
    return a.d1 > b.d1;
}
bool cmp4(node a, node b)
{
    return a.d2 > b.d2;
}
int main(int argc, char const *argv[])
{
    /* code */
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        a[i].id = b[i].id = c[i].id = d[i].id = i;
        scanf("%d %d %d", &a[i].au, &a[i].al, &a[i].p);
        a[i].d1 = 1.0 * a[i].au / a[i].p, a[i].d2 = 1.0 * a[i].al / a[i].p;
        b[i].au = c[i].au = d[i].au = a[i].au;
        b[i].al = c[i].al = d[i].al = a[i].al;
        b[i].p = c[i].p = d[i].p = a[i].p;
        b[i].d1 = c[i].d1 = d[i].d1 = a[i].d1;
        b[i].d2 = c[i].d2 = d[i].d2 = a[i].d2;
    }
    sort(a, a + n, cmp1);
    sort(b, b + n, cmp2);
    sort(c, c + n, cmp3);
    sort(d, d + n, cmp4);

    for (int i = 0; i < m; ++i)
    {
        int dd;
        scanf("%d", &dd);
        if (i)
            printf(" ");
        int id = 1000, cc;
        for (int j = 0; j < n; ++j)
        {
            if (a[j].id == dd)
            {
                while (j > 0  && a[j].au == a[j - 1].au)
                    j--;
                if (j < id)
                {
                    id = j;
                    cc = 1;
                }
                break;
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (b[j].id == dd)
            {
                while (j > 0 && b[j].al == b[j - 1].al)
                    j--;
                if (j < id)
                {
                    id = j;
                    cc = 2;
                }
                break;
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (c[j].id == dd)
            {
                while (j > 0 && c[j].d1 == c[j - 1].d1)
                    j--;
                if (j < id)
                {
                    id = j;
                    cc = 3;
                }
                break;
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (d[j].id == dd)
            {
                while (j > 0 && d[j].d2 == d[j - 1].d2)
                    j--;
                if (j < id)
                {
                    id = j;
                    cc = 4;
                }
                break;
            }
        }
        printf("%d:%d", id + 1, cc);
    }
    return 0;
}