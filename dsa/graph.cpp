// author - newguo@sonaspy.cn
// coding - utf_8

#define SIZE 100
#include <bits/stdc++.h>
#include "graph.h"
#define test() freopen("in", "r", stdin)
using namespace newgraph;
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    udGraph udg;
    srand(time(NULL));
    vector<vector<int>> g(SIZE, vector<int>(SIZE, INF_VAL));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
            g[i][j] = g[j][i] = rand() % 4 ? INF_VAL : rand() % 100 + 1;
    }
    udg.init(g);

    clock_t startTime, endTime;
    startTime = clock();

    udg.makestp(1); // kru
    cout << udg.stpsum() << endl;

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    startTime = clock();

    udg.makestp(0);
    cout << udg.stpsum() << endl;

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}