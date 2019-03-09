// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>

#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int num, count = 0;
    cin >> num;
    while(num != 1)
        {
            if(num %2)
                num = (3*num+1)/2;
            else
                num /= 2;
            count += 1;
        }
    cout << count;
    return 0;
}