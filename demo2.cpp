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
    std::list<int> mylist1, mylist2;
    std::list<int>::iterator it;

    // set some initial values:
    for (int i = 1; i <= 4; ++i)
        mylist1.push_back(i); // mylist1: 1 2 3 4

    for (int i = 1; i <= 10; ++i)
        mylist2.push_back(i * 10); // mylist2: 10 20 30

    it = mylist2.begin();
    ++it,++it; // points to 2

    mylist2.splice(mylist2.begin(), mylist2, it);

    for (it = mylist2.begin(); it != mylist2.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}
