// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string abc = "abcdefghijklmnopqrstuvwxyz", replace = "mnbvcxzasdfghjklpoiuytrewq", a = "rmij'u uamu xyj";
    for (auto &i : a)
    {
        if (isalpha(i))
            i = abc[find(replace.begin(), replace.end(), i) - replace.begin()];
    }
    cout << a;
    return 0;
}