// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <math.h>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int a[101], n, b[101], cur = 0, step;
    cin >> n;
    bool is_insert = true;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i < n; i++)
    {
        if (!is_sorted(b, b + i + 1))
        {
            cur = i - 1;
            break;
        }
    }
    for (int j = cur + 1; j < n; j++)
        if (a[j] != b[j])
            is_insert = false;
    cout << (is_insert ? "Insertion Sort" : "Merge Sort") << endl;
    if (is_insert)
        sort(b, b + cur + 2);
    else
    {
        for (step = 2; step < n / 2; step *= 2)
        {
            int i;
            for (i = 0; i < n - (n % step); i += step)
            {
                if (!is_sorted(b + i, b + i + step))
                    goto end;
            }
            if (!is_sorted(b + i, b + n))
                goto end;
        }
    end:
        if (step == pow(2, log2(n) - 1))
            sort(b, b + n);
        else
        {
            int i, num = n - (n % (step));
            for (i = 0; i < num; i += step)
                sort(b + i, b + i + step);
            if ((n % (step)) > step / 2)
                sort(b + num, b + n);
        }
    }
    cout << b[0];
    for (int i = 1; i < n; i++)
        printf(" %d", b[i]);

    return 0;
}