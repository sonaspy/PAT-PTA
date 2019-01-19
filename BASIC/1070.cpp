// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, len;
    cin >> n;
    vector<double> st;
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &len);
        st.push_back(len);
    }
    sort(st.begin(), st.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            sum += st[i] * (double)pow(2, -i);
        else
            sum += st[i] * (double)pow(2, -i - 1);
    }
    cout << int(sum);
    return 0;
}