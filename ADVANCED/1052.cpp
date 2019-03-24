// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    int id, data, next, valid;
    bool operator<(const Node b) const { return data < b.data; }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, head, pre, data, next, i;
    cin >> n >> head;
    Node mp[100001];
    vector<Node> v;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &pre, &data, &next);
        mp[pre]={pre, data,next,1};
    }
    for (int walk = head; walk != -1; walk = mp[walk].next)
    {
        if(mp[walk].valid)
        v.push_back(mp[walk]);
        else break;
    }
    n = v.size();
    if (!n){cout << "0 -1";return 0;}
    sort(v.begin(), v.end());
    for (i = 0; i < n - 1; i++) v[i].next = v[i + 1].id;
    printf("%d %05d\n",n, v[0].id);
    for (i = 0; i < n - 1; i++) printf("%05d %d %05d\n", v[i].id, v[i].data, v[i].next);
    printf("%05d %d -1", v[i].id, v[i].data);
    return 0;
}