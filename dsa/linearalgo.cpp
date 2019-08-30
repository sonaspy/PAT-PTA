// author -sonaspy@outlook.com
// coding - utf_8
#include <iostream>
#include <numeric>
#define test() freopen("in", "r", stdin)
#define SIZE 2000000
using namespace std;
double myPow(double x, int n)
{
    long long N = n;
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }
    double ans = 1;
    double cur = x;
    for (long long i = N; i; i /= 2)
    {
        if ((i % 2) == 1)
            ans *= cur;
        cur *= cur;
    }
    return ans;
}

double polynomial(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i; --i)
        p = a[i - 1] + x * p;
    return p;
}

// find median in 2 array
template <class T>
int M_search(T *a, T *b, int n1, int n2)
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

template <class T>
bool isparlindrome(T lo, T hi)
{
    if (lo != hi)
        for (; lo < --hi; ++lo)
            if (*lo != *hi)
                return false;
    return true;
}

template <class T>
bool reverse_(T lo, T hi)
{
    if (lo != hi)
        for (; lo < --hi; ++lo)
            swap(*lo, *hi);
}
template <class T>
T *_lower_bound(T *lo, T *hi, const T &val)
{ // binary search
    int len = hi - lo, half;
    T *mid;
    while (len > 0)
    {
        half = len >> 1;
        mid = lo + half;
        if (*mid < val) // (<=) upperbound
        {
            lo = mid + 1;
            len -= half + 1;
        }
        else len = half;
    }
    return lo;
}

template <class T>
T *bin_search(T *lo, T *hi, const T &val)
{
    T *mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (*mid < val)
            lo = mid + 1;
        else if (val < *mid)
            hi = mid - 1;
        else
            return mid;
    }
    return hi;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    clock_t startTime, endTime;
    iota(b, b + SIZE, 0);
    startTime = clock();
    for (int i = 0; i < 1000; i++)
        _lower_bound(b, b + SIZE, 2000);

    endTime = clock();

    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}