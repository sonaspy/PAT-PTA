// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;
struct Node{
    string user, pwd;
    bool isMod;
};
vector<Node> usrList;
unordered_map<char,char> mp;
int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n;
    cin >> n;
    mp['1'] = '@', mp['0'] = '%', mp['l'] = 'L', mp['O'] = 'o';
    for (int i = 0; i < n; i++)
    {
        string s, s1;
        cin >> s >> s1;
        usrList.push_back({s,s1,false});
    }
    int isMod = 0;
    for (int i = 0; i < usrList.size();i++)
    {
        for (int j = 0; j <usrList[i].pwd.size(); j++)
        {
            if (mp.count(usrList[i].pwd[j]))
            {
                usrList[i].isMod = true;
                usrList[i].pwd[j] = mp[usrList[i].pwd[j]];
            }
        }
        if(usrList[i].isMod) isMod++;
    }
    if(isMod){
    cout << isMod << endl;
        for(auto i : usrList)
            if(i.isMod)
                printf("%s %s\n",i.user.c_str(),i.pwd.c_str());
    }
    else cout << "There "<< (n > 1?"are ":"is ")<< n << " account" << (n > 1? "s":"") << " and no account is modified";
    return 0;
}