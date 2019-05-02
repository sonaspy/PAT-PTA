// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int degree[555] = {0}, n, m, a1, a2, isconn = 1, oddnum = 0, vis[501] = {0}, v;
vector<int> MAP[555];
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a1, &a2);
        degree[a1]++, degree[a2]++, MAP[a1].push_back(a2), MAP[a2].push_back(a1);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d%c", degree[i], (i == n ? '\n' : ' '));
        oddnum += degree[i] % 2 == 1 ? 1 : 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i]){
            if(i > 1){
                isconn = 0;
                break;
            }
            queue<int> q;
            q.push(i);
            while(q.size()){
                v = q.front(), q.pop();
                vis[v] = 1;
                for(auto j : MAP[v])
                    if(!vis[j])
                        q.push(j);
            }
        }
    }
    if(isconn && oddnum == 0)cout << "Eulerian\n";
    else if (isconn && oddnum == 2) cout << "Semi-Eulerian\n";
    else cout << "Non-Eulerian\n";
    return 0;
}