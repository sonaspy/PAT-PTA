// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
unordered_map<char, int> mp;
unordered_map<char, bool> isstuck;
unordered_set<char> st;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    string s, res, stuck;
    cin >> n >> s;
    for (auto i : s)
        mp[i]++;
    for (int i = 0; i < s.size(); i++)
    {
        int k = 1, c = i;
        while (i < s.size() - 1 && s[i] == s[i + 1])
            k++, i++;
        if (k % n != 0)
            isstuck[s[c]] = false;
        else if (!isstuck.count(s[c]) && k % n == 0)
            isstuck[s[c]] = true;
    }
    for (auto i : s)
    {
        if (isstuck[i] == true && !st.count(i))
        {
            stuck.push_back(i);
            st.insert(i);
        }
    }
    cout << stuck << endl;
    for (int i = 0; i < s.size(); i++)
    {
        int k = 1, c = i;
        if (isstuck[s[i]] == true)
            while (i < s.size() - 1 && s[i] == s[i + 1])
            {
                i++, k++;
                if (k % n == 0)
                    cout << s[c];
            }
        else
            cout << s[c];
    }
    return 0;
}