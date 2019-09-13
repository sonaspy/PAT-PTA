// author - newguo@sonaspy.cn
// coding - utf_8

#include "Trees.h"

#define SIZE 5
using namespace std;
using namespace newtree;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    //srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 1000; });
    //iota(b, b + SIZE, 1);
    vector<int> a(b, b + SIZE), c = a, d;
    splayTree<int> ax;
    ax.build(a);
    ax.printTree();
    ax.search(73);
    ax.printTree();
    return 0;
}