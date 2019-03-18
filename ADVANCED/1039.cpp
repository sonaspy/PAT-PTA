// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
#define test() freopen("in","r",stdin)

using namespace std;
unordered_map<string, vector<int> > mp;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, k, course, num;
    string name;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        scanf("%d%d",&course, &num);
        for(int j = 0; j < num; j++){
            cin >> name;
            mp[name].push_back(course);
        }
    }
    for(auto i : mp) sort(mp[i.first].begin(), mp[i.first].end());
    for(int i = 0; i < n; i++){
        cin >> name;
        cout << name << " " << mp[name].size();
        for(auto j : mp[name])
            printf(" %d",j);
        printf("\n");
    }
    return 0;
}