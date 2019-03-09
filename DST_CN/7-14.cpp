// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<map>
#define test() freopen("in","r",stdin)

using namespace std;

map<long, int> mp;
map<long, int>::iterator it;
multimap<int, long, greater<int> > mp_;
multimap<int, long, greater<int> >::iterator p;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N;
    long  c1, c2;
    cin >> N;
    for(int i = 0; i < N; i++)
        {
            scanf("%ld%ld",&c1,&c2);
            if(!mp.count(c1))
                mp.insert(make_pair(c1,1));
            else
                mp[c1] += 1;
            if(!mp.count(c2))
                mp.insert(make_pair(c2,1));
            else
                mp[c2] += 1;
        }
    for(it = mp.begin(); it != mp.end(); it++)
        mp_.insert(make_pair((*it).second, (*it).first));
    p = mp_.begin();
    int n = mp_.count((*p).first);
    if( n > 1)
        {
            cout << (*p).second << " " << (*p).first << " " << n;
        }
    else
        cout << (*p).second << " " << (*p).first;
    return 0;
}