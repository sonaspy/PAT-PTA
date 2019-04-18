// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
int num, k, p, maxFacsum = -1;
vector<int> fac_p, res, tmpRes;
inline void ini()
{
    int c = 1, tmp = 0;
    while (tmp <= num)
    {
        fac_p.push_back(tmp);
        tmp = pow(c, p);
        c++;
    }
}
inline void DFS(int factor)
{
    static int nowNum = 0, facSum = 0;
    if (tmpRes.size() == k)
    {
        if (nowNum == num && facSum > maxFacsum)
        {
            maxFacsum = facSum;
            res = tmpRes;
        }
        return;
    }
    for (; 0 < factor; factor--)
    {
        if (nowNum + fac_p[factor] <= num)
        {
            tmpRes.push_back(factor);
            nowNum += fac_p[factor];
            facSum += factor;
            DFS(factor);
            tmpRes.pop_back();
            nowNum -= fac_p[factor];
            facSum -= factor;
        }
    }
}//attention

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> num >> k >> p;
    ini();
    DFS(fac_p.size() - 1);
    if (maxFacsum == -1)
        cout << "Impossible";
    else
    {
        cout << num;
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