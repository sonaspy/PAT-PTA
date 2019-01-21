// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;

void solve(int num)
{
    string s = to_string(num), s1;
    int i;
    for (i = 1; i <= 10; i++)
    {
        int sum = num * num * i;
        s1 = to_string(sum);
        s1 = s1.substr(s1.size() - s.size(), s.size());
        if (s1 == s)
        {
            cout << i << " " << sum << endl;
            break;
        }
    }
    if (i == 11)
        cout << "No\n";
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        solve(num);
    }
    return 0;
}