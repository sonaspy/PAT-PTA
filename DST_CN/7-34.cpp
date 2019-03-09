// author -  newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<vector>
#include<queue>
#define test() freopen("in","r",stdin)

using namespace std;

vector<int> post[110];
int indegree[110];
bool istoplogic(int , vector<int> *, int *);

int main(int argc, char const *argv[])
{
    /* code */
    int n, i, j, k, pre;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        indegree[i] = k;
        for (j = 0; j < k; j++)
        {
            scanf("%d", &pre);
            post[pre].push_back(i);
        }
    }
   if(istoplogic(n, post, indegree))
    cout << 1;
    else cout << 0;
 return 0;
}

bool istoplogic(int n, vector<int> *post, int *indegree){
queue<int> Q;
int cnt = 0;
for (int i = 1; i <= n; i++)
    if (!indegree[i])
        Q.push(i);
while (!Q.empty())
{
    int tmp = Q.front();
    Q.pop();
    cnt++;
    for (int i = 0; i < post[tmp].size(); i++)
    {
        int next = post[tmp][i];
        if (!(--indegree[next]))
            Q.push(next);
    }
}
if (cnt == n)
    return true;
else
   return false;
}
