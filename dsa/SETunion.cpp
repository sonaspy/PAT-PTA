// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class set_union
{
    vector<int> arr(1000, -1);
    inline int find_root(int id)
    {
        return arr[id] == -1 ? id : arr[id] = find_root(arr[id]);
    }
    inline void Union__(int a, int b)
    {
        int ra = find_root(a), rb = find_root(b);
        if (ra != rb)
            arr[rb] = ra;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}