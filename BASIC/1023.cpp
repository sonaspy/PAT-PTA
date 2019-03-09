// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    map<int, int> mp;
    int num;
    for (int i = 0; i < 10; i++)
        {
            cin >> num;
            if (num)
                mp[i] += num;
        }
    for (auto iter : mp)
        {
            if (iter.first != 0)
                {
                    cout << iter.first;
                    mp[iter.first]--;
                    break;
                }
        }
    for (auto iter : mp)
        {
            for (int i = 0; i < iter.second; i++)
                cout << iter.first;
        }
    return 0;
}