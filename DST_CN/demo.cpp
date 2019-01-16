// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include<sstream>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int  n, YMD, count = 0, oldest = 99999999, youngest = 0;
    string year, mon, day,name, ymd, old, young;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> ymd;
        ymd.erase(remove(ymd.begin(),ymd.end(),'/'), ymd.end());
        stringstream oss(ymd);
        oss >> YMD;
    }
    return 0;
}
