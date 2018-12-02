// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<set>
#include<vector>
#define test() freopen("in","r",stdin)

using namespace std;
const int MAXN = 101;
int N, M;
struct edge{
  int cost;
  union{
    int from;
    int to;
  };
  bool operator < (const  edge & e2) const{
    return cost >= e2.cost;
  }
};

set<edge> outDegree[MAXN];
set<edge>::iterator et;
vector<int> toplogic;
int v1, totalcost = 0;
set<int> isend, isstart;
void Build(){
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    isend.insert(i);isstart.insert(i);
  }
  edge e;
  for(int i = 0; i < M; i++){
    scanf("%d%d%d",&v1, &e.to, &e.cost);
    isstart.erase(e.to);
    isend.erase(v1);
    outDegree[v1].insert(e);
  }
}

void createPath(){
  int left = *(isstart.begin()), right = *(isend.begin());
  toplogic.push_back(left);
  while(left != right){
    et = outDegree[left].begin();
    totalcost += (*et).cost;
    left = (*et).to;
    toplogic.push_back(left);
  }
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    Build();
    createPath();
    cout << totalcost << endl;
    for(int i = 1; i < toplogic.size(); i++){
      cout << toplogic[i-1] <<  "->" << toplogic[i] << endl;
    }
    return 0;
}