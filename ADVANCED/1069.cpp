// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s,s1;
    int sub = INT_MAX;
    cin >> s;
    while(sub != 0 && sub != 6174){
        while(s.size() < 4)s += '0';
        s1 = s;
        sort(s.begin(),s.end(), greater<char>());
        sort(s1.begin(), s1.end());
        sub = stoi(s) - stoi(s1);
        printf("%s - %s = %04d\n", s.c_str(), s1.c_str(),sub);
        s = to_string(sub);
    }
    return 0;
}