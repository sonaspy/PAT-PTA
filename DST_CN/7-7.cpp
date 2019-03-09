// author -  newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int reached[100001], coun;
set<int> ls[100001];
set<int>::iterator p;
int M, N, v1, v2;

void BFS(int idx){
  reached[idx] = 1;
  coun++;
  queue<int> Q;
  Q.push(idx);
  for(int depth = 0; depth < 6; depth++){
    vector<int> tmp;
    while(!Q.empty()){
      int itemp = Q.front();
      Q.pop();
      tmp.push_back(itemp);
    }
    for(int i = 0; i < tmp.size(); i++){
      int x = tmp[i];
      for(p = ls[x].begin(); p != ls[x].end(); p++)
        if(!reached[*p]){
          reached[*p] = 1;
          coun++;
          Q.push(*p);
        }
    }
  }
}

int main(int argc, char const *argv[])
{
    /* code */
    //freopen("in","r",stdin);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
      cin >> v1 >> v2;
      ls[v1].insert(v2);
      ls[v2].insert(v1);
    }
    for(int i = 1; i <= N; i++){
      coun = 0;
      memset(reached, 0, sizeof(reached));
      BFS(i);
      double ans = coun*1.0 / N;
      printf("%d: %.2f%%\n", i, ans * 100);
    }
}