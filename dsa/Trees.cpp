// author - newguo@sonaspy.cn
// coding - utf_8

#include "Trees.h"

#define SIZE 100
using namespace std;
using namespace newtree;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 500; });
    //iota(b, b + SIZE, 1);
    vector<int> a(b, b + SIZE), c = a, d;
    AVLTree<int> x;
    x.create(a);
    x.del_one(x.ROOT()->val);
    cout << x.is_balanced();

    return 0;
}