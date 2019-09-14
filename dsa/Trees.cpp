// author - newguo@sonaspy.cn
// coding - utf_8

#include "dsa.h"

#define SIZE 100000
using namespace std;
using namespace newtree;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    //generate(b, b + SIZE, [&]() { return rand() % 100; });
    iota(b, b + SIZE, 1);
    vector<int> a(b, b + SIZE), c = a, d;
    clock_t startTime, endTime;
    startTime = clock();

    while (getchar() != '0')
    {
        AVLTree<int> ax;
        ax.build(a);
        cout << ax.size() << endl;
        //ax.printTree();
    }

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}