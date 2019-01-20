// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include<sstream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    unordered_set<char> st;
    st.insert('e');
    cout << st.count('q');
    cout << st.count('q');

    return 0;
}
