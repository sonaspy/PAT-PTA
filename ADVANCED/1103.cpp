// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int target, k, p, maxFacSum = -1, thisSum = 0, facSum = 0;
vector<int> potentials, res, tmpRes;
inline void init()
{
    int c = 1, n = 1;
    while (n <= target)
    {
        potentials.push_back(n);
        n = pow(++c, p);
    }
}
inline void dfs(int this_fac)
{
    if (tmpRes.size() == k)
    {
        if (thisSum == target && facSum > maxFacSum)
        {
            maxFacSum = facSum;
            res = tmpRes;
        }
        return;
    }
    for (; this_fac > -1; this_fac--)
    {
        if (thisSum + potentials[this_fac] <= target)
        {
            facSum += this_fac, tmpRes.push_back(this_fac + 1), thisSum += potentials[this_fac];
            dfs(this_fac);
            thisSum -= potentials[this_fac], tmpRes.pop_back(), facSum -= this_fac;
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> target >> k >> p;
    init();
    dfs(potentials.size() - 1);
    if (maxFacSum == -1)
        cout << "Impossible\n";
    else
    {
        cout << target;
        for (int i = 0; i < res.size(); i++)
        {
            if (i == 0)
                printf(" = ");
            else
                printf(" + ");
            printf("%d^%d", res[i], p);
        }
    }
    return 0;
}