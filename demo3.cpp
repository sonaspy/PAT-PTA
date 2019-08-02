// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

inline void myreverse(int *head, int *tail)
{
    if (head != tail)
        for (; head < --tail; ++head)
            swap(*head, *tail);
}
int leftfun(int *a, int p, int n)
{
    myreverse(a, a + n);
    myreverse(a, a + n - p);
    myreverse(a + n - p, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 1;
}
int rightfun(int *a, int p, int n)
{
    myreverse(a, a + n);
    myreverse(a, a + p);
    myreverse(a + p, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 1;
}
int M_search(int *a, int *b, int n1, int n2)
{
    int lo1 = 0, lo2 = 0, hi1 = n1 - 1, hi2 = n2 - 1, m1, m2;
    while (lo1 != hi1 || lo2 != hi2)
    {
        m1 = (lo1 + hi1) / 2;
        m2 = (lo2 + hi2) / 2;
        if (a[m1] == b[m2])
            return a[m1];
        if (a[m1] < b[m2])
        {
            lo1 = (hi1 + lo1) % 2 == 0 ? m1 : m1 + 1;
            hi2 = m2;
        }
        else
        {
            hi1 = m1;
            lo2 = (hi2 + lo2) % 2 == 0 ? m2 : m2 + 1;
        }
    }
    return min(a[lo1], b[lo2]);
}

bool isParlin(string s)
{
    auto lo = s.begin(), hi = s.end();
    if (lo != hi)
        for (; lo < --hi; ++lo)
            if (*lo != *hi)
                return false;
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string ss = "121";
    cout << isParlin(ss);
    return 0;
}