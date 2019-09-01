// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int strcmp(const char *str1, const char *str2)
{
    //not! while(*str1++==*str2++)
    while (*str1 == *str2)
    {
        assert((str1 != NULL) && (str2 != NULL));
        if (*str1 == '\0')
            return 0;
        str1++, str2++;
    }
    return *str1 - *str2;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    
    return 0;
}