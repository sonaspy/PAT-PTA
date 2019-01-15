// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <map>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int n, p = 0, t = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        map<char, int> m;
        for (int j = 0; j < s.size(); j++)
        {
            m[s[j]]++;
            if (s[j] == 'P')
                p = j;
            if (s[j] == 'T')
                t = j;
        }
        int preA = p, midA = t - p - 1, postA = s.size() - t - 1;
        if (m['P'] == 1 && m['A'] != 0 && m['T'] == 1 && m.size() == 3 &&midA != 0 &&preA *midA == postA)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}