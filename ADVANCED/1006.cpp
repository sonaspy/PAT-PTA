// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;
struct Node
{
    string name;
    int enter, leave;
};
bool cmp(Node a, Node b)
{
    return a.enter < b.enter;
}
bool cmp1(Node a, Node b)
{
    return a.leave > b.leave;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, t1, t2, t3;
    vector<Node> en, le;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            Node tmp;
            tmp.name = s;
            scanf("%d:%d:%d", &t1, &t2, &t3);
            tmp.enter = t3 + t2 * 60 + t1 * 3600;
            scanf("%d:%d:%d", &t1, &t2, &t3);
            tmp.leave = t3 + t2 * 60 + t1 * 3600;
            en.push_back(tmp);
        }
    le = en;
    sort(en.begin(), en.end(), cmp);
    sort(le.begin(), le.end(), cmp1);
    cout << en.front().name << " " << le.front().name;
    return 0;
}