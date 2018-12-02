// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<set>
#include<queue>

using namespace std;

queue<int> Q;
set<int> graph[10];
int N, E, v1, v2;

void ReadInput(){
  cin >> N >> E;
    while(E--){
      cin >> v1;
      cin >> v2;
      graph[v1].insert(v2);
      graph[v2].insert(v1);
    }
}

int visit[11] = {0};
void DFS(int i){
  visit[i] = 1;
  set<int>::iterator p;
  cout << " " << i;
  for(p = graph[i].begin(); p != graph[i].end(); p++)
      if(!visit[*p]) DFS(*p);
}

int reached[11]= {0};
void BFS(int i){
  int v, j;
  reached[i] = 1;
  Q.push(i);
  while(!Q.empty()){
    v = Q.front();
    Q.pop();
    cout << " " << v;
    for(j = 0; j < N; j++)
      if(!reached[j] && graph[v].count(j)){
        reached[j] = 1;
        Q.push(j);
      }
  }
}

int main(int argc, char const *argv[])
{
    /* code */
    freopen("in","r",stdin);
    ReadInput();
    for(int i = 0; i < N; i++)
      if(!visit[i]){
        cout << "{" ;
        DFS(i);
        cout << " }\n";
      }   
    for(int i = 0; i < N; i++)
      if(!reached[i]){
        cout << "{";
        BFS(i);
        cout << " }\n";
      }
    return 0;
}