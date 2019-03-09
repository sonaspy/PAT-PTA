// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>

#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int useTime = 0, f = 0, n, req;
    cin >> n;
    for(int i = 0; i < n; i++)
        {
            cin >> req;
            if(req > f)useTime += (req - f) * 6;
            else useTime += (f-req) * 4;
            useTime  += 5;
            f = req;
        }
    cout << useTime;
    return 0;
}