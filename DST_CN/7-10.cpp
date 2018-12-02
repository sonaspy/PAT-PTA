// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<map>
#define test() freopen("in","r",stdin)

using namespace std;
int N, M, totalCost;
struct Edge{
  int v1, v2, cost;
};
const int MAXN = 1001;
int unionset[MAXN];
multimap<int, Edge> mp;
multimap<int, Edge>::iterator it;
void Build(){
  cin >> N >> M;
  Edge e;
  fill(unionset,unionset+MAXN,-1);
  for(int i = 0; i < M; i++){
    scanf("%d%d%d",&e.v1,&e.v2,&e.cost);
    mp.insert(make_pair(e.cost, e));
  }
}
int Find(int ele){
  int root = ele;
  while(unionset[root] != -1)
    root = unionset[root];
  return root;
}
void Unite(int roota, int rootb){
  unionset[rootb] = roota;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Build();
    Edge E;
    Edge STP[M];
    int k = 0;
    for(it = mp.begin(); it != mp.end() && k < N-1 && M > 0; it++){
      E = (*it).second;
      M--;
      int a = Find(E.v1);
      int b = Find(E.v2);
      if(a!=b){
        k++;
        Unite(a, b);
        totalCost += E.cost;
      }
    }
    if(k != N - 1) cout << "-1";
    else cout << totalCost;
    return 0;
}