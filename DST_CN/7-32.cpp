// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<vector>
#include<algorithm>
#define test() freopen("in","r",stdin)

using namespace std;

int N, M;

vector<int> mp[1001];
int reached[1001];

void DFS(int v){
    reached[v] = 1;
    int u;
    vector<int>::iterator it;
    for(it = mp[v].begin(); it != mp[v].end(); it++)
        if(!reached[(*it)])
            DFS((*it));
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    cin >> N >> M;
    int v1, v2;
    bool isOra1 = true, isOra2 = true;
    for(int i = 0; i < M; i++){
        scanf("%d%d",&v1,&v2);
        mp[v1].push_back(v2);
        mp[v2].push_back(v1);
    }
    for(int i = 1; i <= N; i++){
        if(mp[i].size() % 2){
            isOra1 = false;
            break;
        }
    }
    DFS(1);
    for(int i = 1; i <= N; i++)
        if(!reached[i])
            isOra2 = false;
    cout << isOra1 && isOra2;

    return 0;
}