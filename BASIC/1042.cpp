// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s;
    map<char, int> mp;
    int max = 0;
    char c;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (auto i : s)
        if (isalpha(i))
            mp[i] += 1;
    for (auto i : mp)
        if (i.second > max)
        {
            max = i.second;
            c = i.first;
        }
    cout << c << " " << max;

    return 0;
}