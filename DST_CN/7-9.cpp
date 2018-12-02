// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<vector>
#include<stack>
#define test() freopen("in","r",stdin)

using namespace std;
const int maxn = 501, INF = 1 << 16;
struct Edge
{
  int v2, c, d;
  Edge(int t, int cost, int dis) : v2(t), c(cost), d(dis) {}
};
vector<Edge> M[maxn];
stack<int> STACK;
int dist[maxn], cost[maxn], n, m, src, dst;

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
  for (int i = 0; i < n; i++)
  {
    dist[i] = INF;
    cost[i] = INF;
  }
}
void Dikjstra()
{
  dist[src] = 0;
  cost[src] = 0;
  STACK.push(src);
  while (!STACK.empty())
  {
    int tmp = STACK.top();
    STACK.pop();
    int v1 = tmp;
    for (int i = 0; i < M[v1].size(); i++)
    {
      Edge sigleEdge = M[v1][i]; 
      if ((dist[sigleEdge.v2] > dist[v1] + sigleEdge.d) ||
       (dist[sigleEdge.v2] == dist[v1] + sigleEdge.d && cost[sigleEdge.v2] > cost[v1] + sigleEdge.c))
      {
        dist[sigleEdge.v2] = dist[v1] + sigleEdge.d;
        cost[sigleEdge.v2] = cost[v1] + sigleEdge.c;
        STACK.push(sigleEdge.v2);
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