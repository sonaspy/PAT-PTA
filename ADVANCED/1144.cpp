// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, num;
    unordered_set<int> st;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        st.insert(num);
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!st.count(i))
        {
            cout << i;
            exit(0);
        }
    }
    return 0;
}