// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <stack>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        string s;
        cin >> s;
        stack<int> S;
        bool legal = true;
        for (auto i : s)
        {
            if(i == 'S'){
                S.push(1);
                if(S.size() > m){
                    legal = false;
                    break;
                }
            }
            else{
                if(S.empty()){
                    legal = false;
                    break;
                }
                S.pop();
            }
        }
        if(!legal) cout <<"NO" << endl;
        else{
            if(S.empty()) cout << "YES" <<endl;
            else cout << "NO" <<endl;
        }
    }
    return 0;
}