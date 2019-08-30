// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <cmath>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, I, J;
    cin >> n;
    int tree[n + 1];
    for (int i = 1; i < n + 1; i++)
        scanf("%d", &tree[i]);
    cin >> I >> J;
    for (int i = 1; i < n + 1; i++)
        {
            if (!tree[i] && i == I)
                {
                    printf("ERROR: T[%d] is NULL", I);
                    return 0;
                }
        }
    int l1 = log2(I), l2 = log2(J);
    if(l1 < l2)
        {
            while(l1 != l2)
                {
                    J /= 2;
                    l2--;
                }
        }
    else if(l1 > l2)
        {
            while (l1 != l2)
                {
                    I /= 2;
                    l1--;
                }
        }
    while(I != J)
        {
            I /= 2;
            J /= 2;
        }
    printf("%d %d", I, tree[I]);
    return 0;
}