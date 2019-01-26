// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct Node *ptrNode;
struct Node
{
    int id, level = 0;
    vector<ptrNode> childs;
};

int solve(int *&a, int root, unordered_map<int, ptrNode> &mp, int level)
{
    int maxLevel = 0, tmp;
    if (!mp.count(root))
    {
        a[level]++;
        return level;
    }
    for (auto iter : mp[root]->childs)
    {
        tmp = solve(a, iter->id, mp, level + 1);
        maxLevel = max(maxLevel, tmp);
    }
    return maxLevel;
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, m, parent, nums, child;
    cin >> n >> m;
    while (n != 0)
    {
        int *layer = new int[100];
        int level;
        unordered_map<int, ptrNode> mp;
        fill(layer, layer + 100, 0);
        if (n == 1)
        {
            cout << 1 << endl;
            goto end;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> parent >> nums;
            ptrNode tParent = new Node;
            tParent->id = parent;
            for (int j = 0; j < nums; j++)
            {
                ptrNode tChild = new Node;
                cin >> child;
                tChild->id = child;
                tParent->childs.push_back(tChild);
            }
            mp[parent] = tParent;
        }
        level = solve(layer, 1, mp, 0);
        for (int i = 0; i <= level; i++)
            cout << (i == 0 ? "" : " ") << layer[i];
        cout << endl;
    end:
        cin >> n >> m;
    }
    return 0;
}