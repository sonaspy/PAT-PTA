// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<char> S;
    string s, res, symbols;
    unordered_map<char, char> mp;
    mp[')'] = '(',mp['}'] = '{',mp[']'] = '[',mp['>'] = '<';
    while (getline(cin, s))
    {
        res += s;
        if (s == ".")
            break;
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == '(' || res[i] == '[' || res[i] == '{' || res[i] == ')' || res[i] == ']' || res[i] == '}')
            symbols.push_back(res[i]);
        else if (res[i] == '/' && res[i + 1] == '*')
            symbols.push_back('<'), i++;
        else if (res[i] == '*' && res[i + 1] == '/')
            symbols.push_back('>'), i++;
    }
    for (int i = 0; i < symbols.size(); i++)
    {
        if (symbols[i] == '(' || symbols[i] == '[' || symbols[i] == '{' || symbols[i] == '<')
            S.push_back(symbols[i]);
        else if (S.size() && mp[symbols[i]] == S.back())
            S.pop_back();
        else
        {
            cout << "NO" << endl;
            if (S.empty()) symbols[i] == '>' ? cout << "?-*/" : cout << "?-" << symbols[i];
            else S.back() == '<' ? cout << "/*-?" : cout << S.back() << "-?";
            return 0;
        }
    }
    if (S.empty())
        cout << "YES";
    else
    {
        cout << "NO" << endl;
        S.back() == '<' ? cout << "/*-?" : cout << S.back() << "-?";
    }
    return 0;
}