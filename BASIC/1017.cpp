// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<string>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string s, res;
    int d, r, meta, sh;
    cin >> s >> d;
    meta = s[0] - '0';
    for(int i = 0; i < s.size();)
        {
            sh = meta / d;
            res.push_back('0' + sh);
            r = meta % d;
            if(i == s.size() - 1) break;
            meta = r*10 + (s[++i] - '0');
        }
    int i = 0;
    while(res[i] == '0') i++;
    res = res.substr(i, res.size()-i);
    cout << res << " " << r;
    return 0;
}