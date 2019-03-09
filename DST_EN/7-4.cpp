// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct Node *nodePtr;
struct Node
{
    nodePtr left = NULL, right = NULL;
    int l = -1, r = -1, id;
};

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, a1, a2, root;
    cin >> n;
    string s1, s2;
    vector<nodePtr> vec;
    vector<int> res;
    int isroot[n];
    for (int i = 0; i < n; i++)
        isroot[i] = 1;
    for (int i = 0; i < n; i++)
        {
            cin >> s1 >> s2;
            nodePtr tmp = new Node;
            tmp->id = i;
            if (s1 != "-")
                {
                    a1 = stoi(s1);
                    tmp->l = a1;
                    isroot[a1] = 0;
                }
            if (s2 != "-")
                {
                    a2 = stoi(s2);
                    tmp->r = a2;
                    isroot[a2] = 0;
                }
            vec.push_back(tmp);
        }
    for (int i = 0; i < n; i++)
        if (isroot[i] == 1)
            {
                root = i;
                break;
            }
    for (auto i : vec)
        {
            if (i->l != -1)
                i->left = vec[i->l];
            if (i->r != -1)
                i->right = vec[i->r];
        }
    queue<nodePtr> Q;
    Q.push(vec[root]);
    while (!Q.empty())
        {
            nodePtr tmp = new Node;
            tmp = Q.front();
            Q.pop();
            if (!tmp->left && !tmp->right)
                res.push_back(tmp->id);
            if (tmp->left)
                Q.push(tmp->left);
            if (tmp->right)
                Q.push(tmp->right);
        }
    int flag = 1;
    for (auto i : res)
        {
            if (flag)
                {
                    cout << i;
                    flag = 0;
                }
            else
                cout << " " << i;
        }
    return 0;
}