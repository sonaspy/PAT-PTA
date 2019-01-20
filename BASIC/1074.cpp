// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int a[21];
    vector<int> res;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n1 = s1.size();
    reverse(s2.begin(), s2.end());
    reverse(s3.begin(), s3.end());
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == '0')
            a[n1 - i - 1] = 10;
        else
            a[n1 - i - 1] = s1[i] - '0';
    }
    int carry = 0, i;
    for (i = 0; i < s2.size() && i < s3.size(); i++)
    {
        int sum = 0;
        int n2 = s2[i] - '0', n3 = s3[i] - '0';
        sum = (n2 + n3 + carry) % a[i];
        carry = (n2 + n3 + carry) / a[i];
        res.push_back(sum);
    }
    if (s2.size() != s3.size())
    {
        if (i == s2.size())
            for (; i < s3.size(); i++)
            {
                int sum = 0, num = s3[i] - '0';
                sum = (num + carry) % a[i];
                carry = (num + carry) / a[i];
                res.push_back(sum);
            }
        else
            for (; i < s2.size(); i++)
            {
                int sum = 0, num = s2[i] - '0';
                sum = (num + carry) % a[i];
                carry = (num + carry) / a[i];
                res.push_back(sum);
            }
    }
    reverse(res.begin(), res.end());
    for(i = 0; i < res.size() && res[i] == 0;i++);
    for (; i < res.size() ; i++)
        cout << res[i];

    return 0;
}