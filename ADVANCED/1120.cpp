// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, tmp;
    cin >> n;
    string num;
    set<int> friend_num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        tmp = 0;
        for (auto j : num)
            tmp += j - '0';
        friend_num.insert(tmp);
    }
    cout << friend_num.size() << endl;
    n = 0;
    for(auto i : friend_num){
        if(n != 0){
            cout << " ";
        }else n = 1;
        cout << i;
    }
    return 0;
}