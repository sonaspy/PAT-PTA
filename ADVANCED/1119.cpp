// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

vector<int> in, pre(50), post(50);
bool isUni = true;
void solve(int prel, int prer, int postl, int postr)
{
    if (prel == prer)
    {
        in.push_back(pre[prel]);
        return;
    }
    if (pre[prel] == post[postr])
    {
        int i = prel + 1;
        while (i < prer + 1 && pre[i] != post[postr - 1])
            i++;
        if (i - prel > 1)
            solve(prel + 1, i - 1, postl, postl + (i - prel - 1) - 1);
        else
            isUni = false;
        in.push_back(post[postr]);
        solve(i, prer, postl + (i - prel - 1), postr - 1);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    solve(0, n - 1, 0, n - 1);
    printf("%s\n%d", isUni == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
    return 0;
} //attention