// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cstring>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    char jinzhi[21], s1[21], s2[21];
    int ans[21];
    int flag = 0;
    scanf("%s %s %s", jinzhi, s1, s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = strlen(jinzhi);
    reverse(s1, s1 + len1);
    reverse(s2, s2 + len2);
    reverse(jinzhi, jinzhi + len);
    for (int i = len1; i < len; i++)
        s1[i] = '0';
    for (int i = len2; i < len; i++)
        s2[i] = '0';
    int carry = 0;
    for (int i = 0; i < len; i++)
        {
            int mod = jinzhi[i] - '0';
            if (jinzhi[i] == '0')
                mod = 10;
            ans[i] = ((s1[i] - '0') + (s2[i] - '0') + carry) % mod;
            carry = ((s1[i] - '0') + (s2[i] - '0') + carry) / mod;
        }
    if (carry != 0)
        {
            printf("%d", carry);
            for (int i = len - 1; i >= 0; i--)
                {
                    flag = 1;
                    printf("%d", ans[i]);
                }
        }
    else
        {
            for (int i = len - 1; i >= 0; i--)
                {
                    if (ans[i] != 0 || flag == 1)
                        {
                            flag = 1;
                            printf("%d", ans[i]);
                        }
                }
        }
    if (flag == 0)
        printf("0");
    return 0;
}