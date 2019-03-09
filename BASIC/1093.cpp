// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <unordered_set>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    unordered_set<char> st;
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    for (auto i : s1)
        if (!st.count(i))
            {
                st.insert(i);
                s3.push_back(i);
            }
    for (auto i : s2)
        if (!st.count(i))
            {
                st.insert(i);
                s3.push_back(i);
            }
    cout << s3;
    return 0;
}