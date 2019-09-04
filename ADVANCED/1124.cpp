// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int m, n, supposed;
    cin >> m >> n >> supposed;
    string str;
    unordered_map<string, int> already;
    bool flag = false;
    for (int i = 1; i <= m; i++)
    {
        cin >> str;
        if (already.count(str))
            supposed++;
        if (i == supposed && !already.count(str))
        {
            already[str] = 1;
            cout << str << endl;
            flag = 1;
            supposed += n;
        }
    }
    if (!flag)
        cout << "Keep going...\n";
    return 0;
}