// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int arr[10000];
inline bool isPrime(int num)
{
    if (num != 2 && num % 2 == 0)
        return false;
    int s = sqrt(num);
    for (int i = 3; i <= s; i += 2)
        if (num % i == 0)
            return false;
    return true;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    fill(arr, arr + 10000, -2);
    int n, k, tmp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        arr[tmp] = i;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &tmp);
        printf("%04d: ", tmp);
        if (arr[tmp] == -2)
            printf("Are you kidding?\n");
        else if (arr[tmp] == -1)
            printf("Checked\n");
        else
        {
            if (arr[tmp] == 1)
                printf("Mystery Award\n");
            else if (isPrime(arr[tmp]))
                printf("Minion\n");
            else
                printf("Chocolate\n");
            arr[tmp] = -1;
        }
    }
    return 0;
}