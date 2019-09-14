// author - newguo@sonaspy.cn
// coding - utf_8

#define SIZE 20
#include <bits/stdc++.h>
#include "dsa.h"
#define test() freopen("in", "r", stdin)
using namespace newgraph;
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    dGraph dg;
    srand(time(NULL));
    int n, m, a1, a2, d;
    n = SIZE;
    vector<vector<int>> g(n, vector<int>(n, INF_VAL));
    //g[0][1] = 3, g[0][2] = 4, g[2][5] = 5, g[5][8] = 2, g[2][4] = 3, g[7][8] = 10, g[8][9] = 1, g[7][9] = 4, g[4][7] = 4, g[1][4] = 1, g[1][3] = 2, g[4][6] = 8, g[9][10] = 6, g[3][6] = 6, g[6][10] = 7;
    dg.rand_acyclic(n, 3, 11);
    //dg.init(g);

    vector<int> ord;
    dg.toporder(ord);
    //reverse(ord.begin(), ord.end());
    cout << "toporder : ";
    output_vec(ord);

    clock_t startTime, endTime;
    startTime = clock();

    cout << "acyclic " << dg.acyclic() << endl;
    dg.get_keyaction();

    //cout << dg.istoporder(ord) << endl;

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}