// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int a[] = {1,2,3,4,5};
    vector<int> v1(a+3,a+5),v2(a,a+5),v;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end() , back_inserter(v));
    for(auto i : v) cout << i << " ";
    return 0;
}