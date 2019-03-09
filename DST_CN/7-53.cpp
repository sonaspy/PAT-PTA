// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, s = 2, tmp;
    vector<int> v;
    cin >> N;
    for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < N; i++)
                {
                    scanf("%d", &tmp);
                    v.push_back(tmp);
                }
        }
    sort(v.begin(), v.end());
    printf("%d",v[(2*N - 1)/2]);
    return 0;
}