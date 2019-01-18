// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <set>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    set<int> st;
    int n, tmp, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                tmp = a[i] * 10 + a[j];
                st.insert(tmp);
            }
        }
    }
    for (auto iter : st)
        sum += iter;
    cout << sum;
    return 0;
}