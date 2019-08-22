// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
#include <stdio.h>

int bsearch(int array[], int n, int v)
{
    int left, right, middle;
    left = 0, right = n - 1;
    int num = 0;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        num++;
        if (array[middle] > v)
            right = middle - 1;
        else if (array[middle] < v)
            left = middle + 1;
        else
            return num;
    }
    return -1;
}
void funa(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
inline int GCD(int n1, int n2)
{
    while (n2)
    {
        int tmp = n1 % n2;
        n1 = n2;
        n2 = tmp;
    }
    return n1;
}

inline double f(double s) { return s * s * s - 4 * s * s + 3 * s - 6; }
inline double dichotomy(string s)
{
    double lo = -100, hi = 100, mid;
    while (f(lo) * f(hi) != 0)
    {
        mid = (lo + hi) / 2;
        if (f(lo) * f(mid) > 0)
            lo = mid;
        else
            hi = mid;
        if (abs(f(mid)) < 1e-4)
            break;
    }
    return mid;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    copy_backward(a, a + 9, a + 9);
    return 0;
}
