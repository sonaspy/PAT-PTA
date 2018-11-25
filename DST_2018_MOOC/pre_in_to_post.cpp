#include <iostream>
#include <fstream>
#include <string>

struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    char elem;
};

void BinaryTreeFromOrderings(char *inorder, char *preorder, int length)
{
    if (length == 0)
    {
        //cout<<"invalid length";
        return;
    }
    TreeNode *node = new TreeNode; //Noice that [new] should be written out.
    node->elem = *preorder;
    int rootIndex = 0;
    for (; rootIndex < length; rootIndex++)
    {
        if (inorder[rootIndex] == *preorder)
            break;
    }
    //Left
    BinaryTreeFromOrderings(inorder, preorder + 1, rootIndex);
    //Right
    BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));
    //    *         cout << node->elem << endl;
    return;
}

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
     char pr[] = "GDAFEMHZ";
     char in[] = "ADEFGHMZ";

    BinaryTreeFromOrderings(in, pr, 8);

    printf("\n");
    return 0;
}
