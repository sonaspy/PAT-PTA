// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define test() freopen("in", "r", stdin)

using namespace std;
// attention
typedef struct Node *ptrNode;
struct Node
{
    int id, level = 0;
    vector<ptrNode> childs;
};
int solve(int *&leaf, int root, unordered_map<int, ptrNode> &mp, int level)
{
    int maxLevel = 0, tmp;
    if (!mp.count(root))
        {
            leaf[level]++;
            return level;
        }
    for (auto iter : mp[root]->childs)
        {
            tmp = solve(leaf, iter->id, mp, level+1);
            maxLevel = max(maxLevel, tmp);
        }
    return maxLevel;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, k, p, c, level;
    int *leaf = new int[100];
    unordered_map<int, ptrNode> mp;
    fill(leaf, leaf + 100, 0);
    cin >> n >> m;
    if (n == 1)
        {
            cout << 1;
            return 0;
        }
    for (int i = 0; i < m; i++)
        {
            cin >> p >> k;
            ptrNode tParent = new Node;
            tParent->id = p;
            for (int j = 0; j < k; j++)
                {
                    cin >> c;
                    ptrNode tChild = new Node;
                    tChild->id = c;
                    tParent->childs.push_back(tChild);
                }
            mp[p] = tParent;
        }
    level = solve(leaf, 1, mp, 0);
    for (int i = 0; i <= level; i++)
        cout << (i == 0 ? "" : " ") << leaf[i];
    return 0;
}