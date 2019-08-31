// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cmath>
#define test() freopen("in", "r", stdin)

/*
1.如果当前位数字为0，那么该位的1的个数由更高位的数字确定。比如3130，个位为1的个数为313 * 1 = 313
3.如果当前位数字为1，那么该位的1的个数不但由高位决定，还由低位数字决定。比如3130百位为1，那么百位数字1的个数为3 * 100 + 30 + 1 = 331
3.如果当前位数字大于1，那么该位数字1的个数为（高位数+ 1） * 位数单位。比如3130十位为3，那么十位数字1的个数为（31 + 1） * 10 = 330
*/
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, left, right, a = 1, now, sum = 0;
    cin >> n;
    string s = to_string(n);
    for (int i = 0, bits = s.size() - 1; i < s.size(); i++, bits--)
    {
        int now = s[i] - '0', high = (i != 0 ? stoi(s.substr(0, i)) : 0), low = (i != s.size() - 1 ? stoi(s.substr(i + 1, s.size() - i - 1)) : 0);
        if (!now)
            sum += high * pow(10, bits);
        else if (now == 1)
            sum += high * pow(10, bits) + low + 1;
        else
            sum += (high + 1) * pow(10, bits);
    }
    cout << sum;

    return 0;
}