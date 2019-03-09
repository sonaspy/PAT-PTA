// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

int coupon[1000001], merchandise[1000001], N, M;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &coupon[i]);
    cin >> M;
    for (int i = 0; i < M; i++)
        scanf("%d", &merchandise[i]);
    int sort_num = N < M ? M : N;
    sort(coupon, coupon + sort_num);
    sort(merchandise, merchandise + sort_num);
    int i = 0, j = 0, sum = 0;
    while (i < N && j < N)
    {
        if (coupon[i] < 0 && merchandise[j] < 0)
        {
            sum += coupon[i] * merchandise[j];
            i++, j++;
        }
        else
            break;
    }
    i = N - 1, j = N - 1;
    while (i > -1 && j > -1)
    {
        if (coupon[i] > 0 && merchandise[j] > 0)
        {
            sum += coupon[i] * merchandise[j];
            i--, j--;
        }
        else
            break;
    }
    cout << sum;
    return 0;
}