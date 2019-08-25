// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    string s;
    int birth;
    node(string s, int b) : s(s), birth(b) {}
    bool operator<(const node &b) const { return birth < b.birth; }
};
int main(int argc, char const *argv[])
{
    /* code */
    test();
    unordered_set<string> st;
    vector<node> vs;
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        st.insert(s);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (st.count(s))
            vs.push_back(node(s, stoi(s.substr(6, 8))));
    }
    sort(vs.begin(), vs.end());
    cout << vs.size() << endl;
    if (vs.size())
        cout << vs.front().s;
    return 0;
}