// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;
int N, root;
struct treeNode
{
    int K1, K2,
        Left, Right;
};
treeNode Tree[1001];
void Build()
{
    int k1, k2, i, l, r;
    cin >> N;
    int a[N];
    fill(a, a + N, 0);
    for (i = 0; i < N; i++)
    {
        scanf("%d%d%d%d", &Tree[i].K1, &Tree[i].K2, &l, &r);
        Tree[i].Left = l;
        Tree[i].Right = r;
        if (l != -1)
            a[l] = 1;
        if (r != -1)
            a[r] = 1;
    }
    for (i = 0; i < N && a[i]; i++)
        ;
    root = i;
}
int inorder[1001];
int c = 0;
void JudgeBST(int ROOT)
{
    if (ROOT != -1)
    {
        JudgeBST(Tree[ROOT].Left);
        inorder[c++] = Tree[ROOT].K1;
        JudgeBST(Tree[ROOT].Right);
    }
    else
        return;
}

bool JudgeHeap(int ROOT)
{
    bool f1, f2;
    if (Tree[ROOT].Left == -1 && Tree[ROOT].Right == -1)
        return true;
    if (Tree[ROOT].Left != -1)
    {
        if (Tree[Tree[ROOT].Left].K2 < Tree[ROOT].K2)
            return false;
        f1 = JudgeHeap(Tree[ROOT].Left);
    }
    if (Tree[ROOT].Right != -1)
    {
        if (Tree[Tree[ROOT].Right].K2 < Tree[ROOT].K2)
            return false;
        f2 = JudgeHeap(Tree[ROOT].Right);
    }
    return f2 && f1;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Build();
    JudgeBST(root);
    bool flag1, flag2, flag;
    int i = 0;
    while (inorder[i] <= inorder[i + 1] && i < N - 1)
        i++;
    if (i == N - 1 || N == 1)
        flag1 = true;
    else
        flag1 = false;
    flag2 = JudgeHeap(root);
    flag = flag1 && flag2;
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}