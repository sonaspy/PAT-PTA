// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <vector>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    // test();
    int n1, n2;
    vector<int> res;
    while (cin >> n1 >> n2)
        {
            if (n2 != 0)
                {
                    res.push_back(n1 * n2);
                    res.push_back(n2 - 1);
                }
        }
    if (!res.size())
        printf("0 0");
    else
        {
            bool f = true;
            for (auto iter : res)
                {
                    if (f)
                        {
                            printf("%d", iter);
                            f = false;
                        }
                    else
                        printf(" %d", iter);
                }
        }
    return 0;
}