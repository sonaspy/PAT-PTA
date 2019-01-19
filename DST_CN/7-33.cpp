// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#define test() freopen("in","r",stdin)

using namespace std;
int n, m, s;
vector<int> MAP[1010],path;
int reached[1010], flag = 0, connect;

void dfs(int source)
{
    connect++;
    path.push_back(source);
    reached[source] = 1;
    for (int i = 0; i < MAP[source].size(); i++)
    {
        int next = MAP[source][i];
        int hasNext = 0;
        if (reached[next] == 0)
        {
            hasNext = 1;
            dfs(next);
        }
        if (hasNext == 1)
            path.push_back(source);
    }
    return;
}

void Output(){
    vector<int>::iterator it;
    it = path.begin();
    printf("%d", (*it));
    for (it += 1; it != path.end(); it++)
        printf(" %d", (*it));
}

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a].push_back(b);
        MAP[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        sort(MAP[i].begin(), MAP[i].end());
    
    dfs(s);
    if(connect == n){
       Output();
    }
    else{
        Output();
        cout << " "<< 0;
    }
    return 0;
}