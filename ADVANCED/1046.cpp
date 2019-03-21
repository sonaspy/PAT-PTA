// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;
int map[100010];

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, sum = 0, m,c1,c2,res;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &map[i]);
        map[i] += map[i-1];
    } // map[i]  : i -> i+1 (km)  map[n] :n -> 1(km);
    cin >> m;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &c1, &c2);
        if(c2 < c1) swap(c1,c2);
        res = min(map[c2-1]-map[c1-1],map[n]-(map[c2-1]-map[c1-1]));
        cout << res <<endl;
    }
    return 0;
}