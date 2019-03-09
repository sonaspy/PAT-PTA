// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <set>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    cin >> n;
    set<int> v;
    for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            int sum = 0;
            for (auto iter : s)
                sum += iter - '0';
            v.insert(sum);
        }
    cout << v.size() << endl;
    int flag = 1;
    for (auto iter : v)
        {
            if (flag)
                {
                    cout << iter;
                    flag = 0;
                }
            else
                cout << " " << iter;
        }
    return 0;
}