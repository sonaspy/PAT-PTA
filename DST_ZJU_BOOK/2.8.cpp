// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>

#define test() freopen("in","r",stdin)

using namespace std;
int tag[10];
int cnt[10];
int n;
void print(int d, int p)
{
    cnt[p] = d;
    for (int i = 1; i <= n; i++)
        if (!tag[i])
            {
                tag[i] = 1;
                print(i, p + 1);
                tag[i] = 0;
            }
    if (p == n - 1)
        {
            for (int i = 0; i < n; i++)
                printf("%d",cnt[i]);
            printf("\n");
        }
}
int main(int argc, char const *argv[])
{
    /* code */
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            tag[i] = 1;
            print(i, 0);
            tag[i] = 0;
        }
    return 0;
}