// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;

vector<int> a, b;
struct node
{
    char data;
    node *lchild=nullptr, *rchild=nullptr;
    node(int d):data(d){}
};
void level(node *root, vector<int> &v)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *now = q.front();
        q.pop();
        v.push_back(now->data);
        if (now->lchild != NULL)
            q.push(now->lchild);
        if (now->rchild != NULL)
            q.push(now->rchild);
    }
}
void insert(node *&root, int x)
{
    if (root == NULL)
    {
        root = new node(x);
    }
    else if (x < root->data)
        insert(root->lchild, x);
    else
        insert(root->rchild, x);
}
int main()
{
    int n;
    string temp, str;
    while (cin >> n && n)
    {
        cin >> temp;
        node *t = NULL;
        a.clear();
        for (int i = 0; i < temp.size(); i++)
            insert(t, temp[i]);
        level(t, a);
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            node *s = NULL;
            b.clear();
            for (int i = 0; i < str.size(); i++)
                insert(s, str[i]);
            level(s, b);
            if (a == b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}