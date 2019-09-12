// author - newguo@sonaspy.cn
// coding - utf_8
#include <bits/stdc++.h>
#include "sort.h"

#define SIZE 100
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace newsort;

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % SIZE; });
    clock_t startTime, endTime;
    startTime = clock();

    quickSort(b, b + SIZE);

    endTime = clock();

    cout << is_sorted(b, b + SIZE) << endl;
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}