// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <unordered_map>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s1, s2;
    unordered_map<char, int> sell, want;
    int f1 = 1, f2 = 1, remain = 0, lack = 0;
    cin >> s1 >> s2;
    for (auto i : s1)
        sell[i] += 1;
    for (auto i : s2)
        want[i] += 1;
    for (auto i : sell)
        {
            for (auto j : want)
                if (j.first == i.first)
                    {
                        sell[i.first] -= j.second;
                        want[j.first] = 0;
                    }
        }
    for (auto i : want)
        {
            if (i.second != 0)
                {
                    f1 = 0;
                    lack -= i.second;
                }
        }
    for (auto i : sell)
        {
            if (i.second < 0)
                {
                    f2 = 0;
                    lack += i.second;
                }
            else
                remain += i.second;
        }
    if (f1 && f2)
        printf("Yes %d", remain);
    else
        printf("No %d", -lack);
    return 0;
}