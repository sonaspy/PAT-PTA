// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    int n, m, c1, c2;
    cin >> n;
    vector<int> v;
    unordered_set<int> st;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &c1, &c2);
        mp[c1] = c2;
        mp[c2] = c1;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> c1;
        st.insert(c1);
    }
    for (auto i : st)
        if (!st.count(mp[i]))
            v.push_back(i);
            
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    if (v.size() != 0)
    {
        printf("%05d", v[0]);
        for (int i = 1; i < v.size(); i++)
            printf(" %05d", v[i]);
    }
    return 0;
}