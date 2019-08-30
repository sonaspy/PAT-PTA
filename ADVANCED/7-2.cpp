// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    string s;
    int birth;
    node(string s, int b) : s(s), birth(b) {}
};
bool cmp(const node *a, const node *b) { return a->birth < b->birth; }
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    unordered_map<string, node *> alumni;
    vector<node *> vs, ordi;
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        alumni[s] = new node(s, stoi(s.substr(6, 8)));
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (alumni.count(s))
            vs.push_back(alumni[s]);
        else
            ordi.push_back(new node(s, stoi(s.substr(6, 8))));
    }
    sort(vs.begin(), vs.end(), cmp);
    cout << vs.size() << endl;
    if (vs.size())
        cout << vs.front()->s;
    else
    {
        sort(ordi.begin(), ordi.end(), cmp);
        cout << ordi.front->s;
    }
    return 0;
}