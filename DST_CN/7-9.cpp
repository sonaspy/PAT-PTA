// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <stack>
#define test() freopen("in", "r", stdin)

using namespace std;
const int maxn = 501, INF = 1 << 16;
struct Edge
{
    int v2, c, d;
    Edge(int t, int cost, int dis) : v2(t), c(cost), d(dis) {}
};
vector<Edge> M[maxn];
stack<int> q;
int dist[maxn], cost[maxn], n, m, src, dst, v;

void Build()
{
    int v1, v2, d, c;
    cin >> n >> m >> src >> dst;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d%d", &v1, &v2, &d, &c); // faster than cin.
        M[v1].push_back(Edge(v2, c, d));
        M[v2].push_back(Edge(v1, c, d));
    }
    fill(dist, dist + n, INF);
    fill(cost, cost + n, INF);
}
void Dikjstra()
{
    dist[src] = cost[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        v = q.top(), q.pop();
        int v1 = v;
        for (auto sigleEdge : M[v1])
        {
            if ((dist[sigleEdge.v2] > dist[v1] + sigleEdge.d) ||
                (dist[sigleEdge.v2] == dist[v1] + sigleEdge.d && cost[sigleEdge.v2] > cost[v1] + sigleEdge.c))
            {
                dist[sigleEdge.v2] = dist[v1] + sigleEdge.d;
                cost[sigleEdge.v2] = cost[v1] + sigleEdge.c;
                q.push(sigleEdge.v2);
            }
        }
    }
    cout << dist[dst] << " " << cost[dst];
}
int main(int argc, char const *argv[])
{
    //test();
    Build();
    Dikjstra();
    return 0;
}

/*

#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;
struct node{
    int dst;
    int cost;
    node():dst(INF),cost(INF) {
    }
};
int N,M,S,D;
node mp[510][510];
node dis[510];
int vis[510];
void dij(int s,int e){
    dis[s].cost= dis[s].dst=0;
    int i,j, minc, v, minw;
    while(1){
        minw = minc=INF;
        v = -1;
        for(j=0;j<N;j++){
            if(vis[j]) continue;
            if(dis[j].dst<minw){
                v=j;
                minc=dis[j].cost;
                minw=dis[j].dst;
            }
            else if(dis[j].dst==minw && dis[j].cost<minc){
                    v=j;
                    minc=dis[j].cost;
            }
        }
        vis[v]=1;
        if(v== -1) break;
        for(j=0;j<N;j++){
            if(!vis[j] && mp[v][j].dst != INF){
            if(dis[j].dst>dis[v].dst+mp[v][j].dst){
                dis[j].dst=dis[v].dst+mp[v][j].dst;
                dis[j].cost=dis[v].cost+mp[v][j].cost;
            }
            else if(dis[j].dst==dis[v].dst+mp[v][j].dst && dis[j].cost > dis[v].cost+mp[v][j].cost)
                dis[j].cost=dis[v].cost+mp[v][j].cost;
        }
    }
    }
    cout<<dis[e].dst<<" "<<dis[e].cost<<endl;
}
int main(){
    int a,b,c,d;
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d%d",&N,&M,&S,&D);  //S是出发地 D是目的地  N是城市个数 M是公路条数
    for(int i=1;i<=M;i++){
        cin>>a>>b>>c>>d;
        mp[a][b].dst=  mp[b][a].dst=c;
        mp[a][b].cost= mp[b][a].cost=d;
    }
    dij(S,D);
 
    return 0;
}
*/