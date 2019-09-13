// author - newguo@sonaspy.cn
// coding - utf_8
#include "dsa.h"

#define SIZE 10
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace newsort;

int main(int argc, char const *argv[])
{
    /* code */
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 20; });
    clock_t startTime, endTime;
    startTime = clock();

    partial_k_sort2(b, b + SIZE, 6);
    s_output(b, b + SIZE);

    endTime = clock();
    //cout << is_sorted(b, b + SIZE) << endl;
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}