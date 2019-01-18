// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int N;
    cin >> N;
    double a[N], sum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &a[i]);
        sum += (i + 1) * a[i] * (N - i);
    }
    printf("%.2lf", sum);
    return 0;
}