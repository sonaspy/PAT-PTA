// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <string>
#include <map>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s, r = "PATest";
    cin >> s;
    int count = 0;
    map<char, int> mp;
    for (auto i : s)
        if (i == 'P' || i == 'A' || i == 'T' || i == 'e' || i == 's' || i == 't')
            {
                count++;
                mp[i] += 1;
            }
    while (count)
        for (auto c : r)
            if (mp[c] != 0)
                {
                    count--;
                    mp[c]--;
                    cout << c;
                }
    return 0;
}