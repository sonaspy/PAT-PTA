// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    unordered_map<int, int> mp;
    int n, score, flag = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            scanf("%d", &score);
            mp[score] += 1;
        }
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            scanf("%d", &score);
            if (flag)
                {
                    printf("%d", mp[score]);
                    flag = 0;
                }
            else
                printf(" %d", mp[score]);
        }
    return 0;
}