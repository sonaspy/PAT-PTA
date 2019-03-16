// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)
#define MAXN 3000
#define ROOT 0
using namespace std;

void insert(int *&a, int data, int cur)
{
    if (a[cur] == 0)
        {
            a[cur] = data;
            return;
        }
    if (data < a[cur])
        insert(a, data, 2 * cur + 1);
    if (data > a[cur])
        insert(a, data, 2 * cur + 2);
}

bool isTheSame(int *a, int *b)
{
    for (int i = 0; i < MAXN; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, l, num;
    cin >> n;
    while (n != 0)
        {
            cin >> l;
            int *source = new int[MAXN];
            fill(source, source + MAXN, 0);
            for (int i = 0; i < n; i++)
                {
                    cin >> num;
                    insert(source, num, ROOT);
                }
            for (int i = 0; i < l; i++)
                {
                    int *dst = new int[MAXN];
                    for (int i = 0; i < n; i++)
                        {
                            cin >> num;
                            insert(dst, num, ROOT);
                        }
                    if (isTheSame(source, dst))
                        printf("Yes\n");
                    else
                        printf("No\n");
                }
            cin >> n;
        }
    return 0;
}