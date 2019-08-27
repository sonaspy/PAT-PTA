// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

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

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    clock_t startTime, endTime;
    startTime = clock();
    vector<int> a(10), b(10);
    iota(a.begin(), a.end(), 1);
    iota(b.begin() , b.end(), 1);
    
    endTime = clock();

    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}