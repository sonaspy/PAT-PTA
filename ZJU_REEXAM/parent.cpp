// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
typedef struct Node *ptrn;
struct Node
{
    ptrn father = nullptr, mother = nullptr, child = nullptr;
    int level;
};
vector<ptrn> tree(256);
int n, m, root;

inline void Level()
{
    int l = 0;
    queue<ptrn> q, next_q;
    q.push(tree[root]);
    while (q.size())
    {
        while (q.size())
        {
            ptrn v = q.front();
            v->level = l;
            q.pop();
            if (v->father)
                next_q.push(v->father);
            if (v->mother)
                next_q.push(v->mother);
        }
        swap(q, next_q);
        l++;
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s;
    cin >> n >> m;
    for (int i = 0; i < 256; i++)
        tree[i] = new Node;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s[1] != '-')
        {
            tree[s[0]]->father = tree[s[1]];
            tree[s[1]]->child = tree[s[0]];
        }
        if (s[2] != '-')
        {
            tree[s[0]]->mother = tree[s[2]];
            tree[s[2]]->child = tree[s[0]];
        }
    }
    for (int i = 0; i < 256; i++)
    {
        if ((tree[i]->father || tree[i]->mother) && !tree[i]->child)
        {
            root = i;
            break;
        }
    }
    Level();

    for (int i = 0; i < m; i++)
    {
        cin >> s;
        ptrn v1 = tree[s[0]], v2 = tree[s[1]], hi, lo;
        if (v1->level < v2->level)
            hi = v1, lo = v2;
        else
            hi = v2, lo = v1;
        while (lo && lo->level != hi->level)
            lo = lo->child;
        if (lo != hi)
            cout << '-' << endl;
        else
        {
            int dis = v1->level - v2->level;
            if (dis > 0)
            {
                if (dis == 1)
                    cout << "parent\n";
                else if (dis == 2)
                    cout << "grandparent\n";
                else
                {
                    while (dis > 2)
                    {
                        cout << "great-";
                        dis--;
                    }
                    cout << "grandparent" << endl;
                }
            }
            else
            {
                if (dis == -1)
                    cout << "child\n";
                else if (dis == -2)
                    cout << "grandchild\n";
                else
                {
                    string s = "grandchild";
                    while (dis < -2)
                    {
                        cout << "great-";
                        dis++;
                    }
                    cout << "grandchild" << endl;
                }
            }
        }
    }
    return 0;
}