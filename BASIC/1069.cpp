// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <unordered_set>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int m = 0, n = 0, s = 0;
    string str[1001];
    unordered_set<string> st;
    cin >> m >> n >> s;
    for (int i = 1; i <= m; i++)
        cin >> str[i];
    if (s > m)
    {
        cout << "Keep going...";
        return 0;
    }
    else
        for (int i = s; i <= m;)
        {

            if (!st.count(str[i]))
            {
                cout << str[i] << endl;
                st.insert(str[i]);
                i += n;
            }
            else
                i++;
        }
    return 0;
}