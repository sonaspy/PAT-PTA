// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

typedef struct node *ptrNode;
struct node
{
    int data;
    ptrNode Left, Right;
    node()
    {
        data = 0;
        Left = NULL;
        Right = NULL;
    }
};

int seqNum[1002];

ptrNode Insert(ptrNode head, ptrNode tmp)
{
    if (!head)
        return tmp;
    if (tmp->data < head->data)
        head->Left = Insert(head->Left, tmp);
    else
        head->Right = Insert(head->Right, tmp);
    return head;
}

bool isTheTree = true;
int cursor = 0;

void preOrder(ptrNode t)
{
    if (t && isTheTree)
    {
        if (t->data != seqNum[cursor++])
            isTheTree = false;
        preOrder(t->Left);
        preOrder(t->Right);
    }
    else
        return;
}

void postOrder(ptrNode t)
{
    if (!t)
        return;
    else
    {
        postOrder(t->Left);
        postOrder(t->Right);
        if (isTheTree)
            isTheTree = false;
        else
            cout << " ";
        printf("%d", t->data);
    }
}

void makeImageTree(ptrNode t)
{
    if (!t)
        return;
    else
    {
        makeImageTree(t->Left);
        makeImageTree(t->Right);
        ptrNode tmp = t->Left;
        t->Left = t->Right;
        t->Right = tmp;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    int N, b;
    cin >> N;
    ptrNode head = NULL; // Build Tree.
    for (int i = 0; i < N; i++)
    {
        ptrNode tmp = new node;
        scanf("%d", &tmp->data);
        seqNum[i] = tmp->data;
        head = Insert(head, tmp);
    }
    // Judge
    preOrder(head);

    if (!isTheTree)
    {
        makeImageTree(head);
        isTheTree = true;
        cursor = 0;
        preOrder(head);
    }

    if (!isTheTree)
        cout << "NO";
    else
    {
        cout << "YES\n";
        postOrder(head);
    }
    return 0;
}