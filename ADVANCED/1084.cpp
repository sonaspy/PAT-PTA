// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s1, s2, s11, s22, res;
    cin >> s1 >> s2;
    unordered_set<char> st;
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    for (auto i : s1)
    {
        if (!st.count(i)) s11.push_back(i);
        st.insert(i);
    }
    st.clear();
    for (auto i : s2)
    {
        st.insert(i);
    }
    for (auto i : s11)
    {
        if (!st.count(i))
            res.push_back(i);
    }
    cout << res;
    return 0;
}