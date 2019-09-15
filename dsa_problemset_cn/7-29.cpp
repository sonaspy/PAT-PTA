// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include<queue>
#define test() freopen("in", "r", stdin)

using namespace std;
const int maxSegmentSize = 1e4;
priority_queue<int, vector<int>, greater<int> > Q;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, len, cost = 0, v1,v2;
    cin >> N;
    for(int i = 0; i < N; i++)
        {
            scanf("%d",&len);
            Q.push(len);
        }
    while(Q.size() != 1)
        {
            v1 = Q.top();
            Q.pop();
            v2 = Q.top();
            Q.pop();
            cost += (v1+v2);
            Q.push(v1+v2);
        }
    cout << cost;
    return 0;
}