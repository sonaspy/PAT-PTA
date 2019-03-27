// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>
#include <set>
#define test() freopen("in", "r", stdin)

using namespace std;
struct Node
{
    int i;
    bool operator<(const Node b) const { return i < b.i; }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    multiset<int> st;
    for (int i = 1; i < 10; i++)
        st.insert(10);
    cout << st.size();
    st.erase(10);
    cout << st.size();
    return 0;
}