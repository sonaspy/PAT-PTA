// author - newguo@sonaspy.cn
// coding - utf_8

#include "dsa.h"

#define SIZE 63
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
    AVLTree<int> ax;
    ax.build(a);
    ax.invert();
    ax.printTree();
    return 0;
}