// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;
struct Node
{
    string name;
    int enter, leave;
    Node(string s, int e, int l) : name(s), enter(e), leave(l) {}
};
inline bool cmp(const Node a, const Node b) { return a.enter < b.enter; }
inline bool cmp1(const Node a, const Node b) { return a.leave > b.leave; }
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, t1, t2, t3, e, l;
    vector<Node> ls;
    string s1, s2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        scanf("%d:%d:%d", &t1, &t2, &t3);
        e = t3 + t2 * 60 + t1 * 3600;
        scanf("%d:%d:%d", &t1, &t2, &t3);
        l = t3 + t2 * 60 + t1 * 3600;
        ls.push_back(Node(s, e, l));
    }
    sort(ls.begin(), ls.end(), cmp), s1 = ls.front().name;
    sort(ls.begin(), ls.end(), cmp1), s2 = ls.front().name;
    cout << s1 << " " << s2;
    return 0;
}