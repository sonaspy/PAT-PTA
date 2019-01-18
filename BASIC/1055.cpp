// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
    string name;
    int height;
};
int cmp(struct node a, struct node b)
{
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}
int main()
{
    int n, k, cloumns;
    cin >> n >> k;
    vector<node> stu(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].name;
        cin >> stu[i].height;
    }
    sort(stu.begin(), stu.end(), cmp);
    for (int row = k, stu_cur = 0; row > 0; row--)
    {
        if (row == k)
            cloumns = n / k + n % k;
        else
            cloumns = n / k;
        vector<string> ans(cloumns);
        ans[cloumns / 2] = stu[stu_cur].name;
        int j = cloumns / 2 - 1;
        for (int i = stu_cur + 1; i < stu_cur + cloumns; i = i + 2)
            ans[j--] = stu[i].name;
        j = cloumns / 2 + 1;
        for (int i = stu_cur + 2; i < stu_cur + cloumns; i = i + 2)
            ans[j++] = stu[i].name;
        cout << ans[0];
        for (int i = 1; i < cloumns; i++)
            cout << " " << ans[i];
        cout << endl;
        stu_cur += cloumns;
    }
    return 0;
}
