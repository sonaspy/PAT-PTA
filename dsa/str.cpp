// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int str_cmp(const char *str1, const char *str2)
{
    //not! while(*str1++==*str2++)
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            break;
        str1++, str2++;
    }
    return *str1 - *str2;
}
// s(len) -> n  ,  p(len) -> m
// O(mn)
bool str_if_match(string s, string p)
{
    for (auto i = s.begin(); i < s.end() - p.size() + 1; i++)
    {
        auto j = p.begin();
        for (auto walk = i; j < p.end(); walk++, j++)
            if (*j != *walk)
                break;
        if (j == p.end())
            return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}