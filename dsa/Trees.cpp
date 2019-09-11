// author - newguo@sonaspy.cn
// coding - utf_8

#include "Trees.h"

#define SIZE 1000
using namespace std;
using namespace newtree;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 200; });
    vector<int> a(b, b + SIZE), c = a, d;
    sort(c.begin(), c.end());
    BST<int> as;
    as.build_pi(a, c);
    return 0;
}