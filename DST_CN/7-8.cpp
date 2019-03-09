// author -  newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>

using namespace std;

const int N = 105;
const int INF = 1 << 16;
int graph[N][N];

int main(int argc, char const *argv[])
{
    /* code */
    //freopen("in","r",stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <=n; j++){
        if(i == j)
          graph[i][j] = 0;
        else
          graph[i][j] = INF;
      }

      for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
      }

      for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
          for(int j = 1; j <= n; j++)
            if(graph[i][j] > graph[i][k] + graph[k][j])
              graph[i][j] = graph[i][k] + graph[k][j];

      int index = 0, max, min = INF;
      for(int i = 1; i <= n; i++){
        max = 0;
        for(int j = 1; j <= n; j++){
          if(max < graph[i][j])
            max = graph[i][j];
        }
        if(min > max){
           min = max;
          index = i;
        }
      }
      if(index == 0)
        cout << "0\n";
      else
        cout << index << " " << min << endl;
    return 0;
}