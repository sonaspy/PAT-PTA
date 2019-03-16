// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int T, K;
    cin >> T >> K;
    for (int i = 0; i < K; i++)
        {
            int n1, b, t, n2;
            cin >> n1 >> b >> t >> n2;
            if (t > T)
                printf("Not enough tokens. Total = %d.\n", T);
            else if ((n1 < n2 && b) || (n1 > n2 && !b))
                {
                    T += t;
                    printf("Win %d! Total = %d.\n", t, T);
                }
            else if ((n1 < n2 && !b) || (n1 > n2 && b))
                {
                    T -= t;
                    printf("Lose %d. Total = %d.\n", t, T);
                    if (T == 0)
                        {
                            printf("Game Over.\n");
                            break;
                        }
                }
        }
    return 0;
}