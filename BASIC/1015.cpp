// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Student
{
    /* data */
    int id,
        de, cai, total;
} s;

bool cmp(struct Student A, struct Student B)
{
    if (A.total == B.total)
    {
        if (A.de != B.de)
            return A.de > B.de;
        return A.id < B.id;
    }
    return A.total > B.total;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, l, h, num;
    cin >> n >> l >> h;
    vector<Student> records, v1, v2, v3, v4;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &s.id, &s.de, &s.cai);
        s.total = s.cai + s.de;
        if (s.cai >= l && s.de >= l)
        {
            if (s.de >= h && s.cai >= h)
                v1.push_back(s);
            else if (s.de >= h && s.cai < h)
                v2.push_back(s);
            else if (s.de < h && s.cai < h && s.de >= s.cai)
                v3.push_back(s);
            else
                v4.push_back(s);
        }
    }
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    sort(v3.begin(), v3.end(), cmp);
    sort(v4.begin(), v4.end(), cmp);

    records.insert(records.end(), v1.begin(), v1.end());
    records.insert(records.end(), v2.begin(), v2.end());
    records.insert(records.end(), v3.begin(), v3.end());
    records.insert(records.end(), v4.begin(), v4.end());
    cout << records.size() << endl;
    for (auto s : records)
        printf("%d %d %d\n", s.id, s.de, s.cai);

    return 0;
}