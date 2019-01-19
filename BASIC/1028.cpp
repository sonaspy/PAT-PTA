// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    int n, YMD, count = 0, oldest = 99999999, youngest = 0;
    string name, ymd, old, young;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> ymd;
        ymd.erase(remove(ymd.begin(), ymd.end(), '/'), ymd.end());
        YMD = atoi(ymd.c_str()); // stoi()  also feasible
        if (20140906 - YMD > 2000000 || YMD > 20140906)
            continue;
        count++;
        if (YMD < oldest)
        {
            oldest = YMD;
            old = name;
        }
        if (YMD > youngest)
        {
            youngest = YMD;
            young = name;
        }
    }
    if (count == 0)
        cout << 0;
    else
        cout << count << " " << old << " " << young;

    return 0;
}