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
    dg.random_init(SIZE, 20, 10);
    vector<int> ord;
    dg.in_toporder(ord);
    output_vec(ord);
    reverse(ord.begin(), ord.end());
    clock_t startTime, endTime;
    startTime = clock();
    cout << dg.acyclic() << endl;
    cout << dg.istoporder(ord) << endl;

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;

    return 0;
}