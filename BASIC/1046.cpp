// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>

#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    int n, jhan,jhua,yhan,yhua, cnt1 = 0,cnt2 = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> jhan >> jhua >> yhan >> yhua;
        if ((jhua == jhan + yhan && yhua == yhan + jhan) || (jhua != jhan + yhan && yhua != yhan + jhan))
            continue;
        else if (jhua == jhan + yhan && yhua != yhan + jhan)
            cnt2++;
        else if (jhua != jhan + yhan && yhua == yhan + jhan)
            cnt1++;
    }
    cout << cnt1 << " " << cnt2;
    return 0;
}