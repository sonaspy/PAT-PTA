// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <unordered_set>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, sum;
    unordered_set<int> st;
    cin >> n;
    for (; n > 0; n--)
    {
        sum = n / 2 + n / 3 + n / 5;
        st.insert(sum);
    }
    cout << st.size();

    return 0;
}