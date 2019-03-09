// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> a, b;
    int n, m, flag = 1, tmp;
    cin >> n >> m;
    m %= n;
    for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            a.push_back(tmp);
        }
    b.resize(a.size());
    copy(a.begin() + a.size() - m, a.end(), b.begin());
    copy(a.begin(), a.begin() + a.size() - m, b.begin() + m);
    for (auto iter : b)
        {
            if (flag)
                {
                    flag = 0;
                    printf("%d", iter);
                }
            else
                printf(" %d", iter);
        }
    return 0;
}