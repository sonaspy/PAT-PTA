// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    string s1, s2, s22, s3;
    getline(cin, s1);
    getline(cin, s2);
    set<char> st;
    for (auto i : s1)
    {
        st.insert(towlower(i));
        st.insert(i);
    }
    if (st.count('+'))
    {
        for (auto i : s2)
            if (!isupper(i))
                s22.push_back(i);
        for (auto i : s22)
            if (!st.count(i))
                s3.push_back(i);
    }
    else
        for (auto i : s2)
            if (!st.count(i))
                s3.push_back(i);
    if(s3.size() == 0) cout << endl;
    else cout << s3;
    return 0;
}