// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    int n, cnt = 0;
    char a[50], b[50];
    double number, sum = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a);
        sscanf(a, "%lf", &number);
        sprintf(b, "%.2f", number);
        if (strncmp(a, b, strlen(a)) != 0 || abs(number) > 1000)
        {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        }
        sum += number;
        cnt++;
    }
    if (cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else if (cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}