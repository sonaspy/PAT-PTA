// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;
vector<int> res;
typedef struct Node *nodePtr;
struct Node
{
    nodePtr left = NULL, right = NULL;
    int id;
};

void Post(nodePtr root){
    if(root->left) Post(root->left);
    if(root->right) Post(root->right);
    res.push_back(root->id);
}
int main(int argc, char const *argv[])
{
    /* code */
    test();
    string lastop = "Push", curop;
    int id, n, root, lastele;
    cin >> n;
    stack<nodePtr> S;
    vector<nodePtr> vec(50);
    nodePtr lastNode = new Node;
    for (int i = 0; i < 2 * n; i++, lastop = curop)
    {
        nodePtr tmp = new Node;
        cin >> curop;
        if (curop == "Push")
            cin >> id;
        else if (curop == "Pop")
        {

            lastNode = S.top();
            S.pop();
            vec[lastNode->id] = lastNode;
        }
        if (curop == "Push" && lastop == "Pop")
        {
            tmp->id = id;
            S.push(tmp);
            vec[lastNode->id]->right = tmp;
            lastNode = tmp;
        }
        else if (curop == "Push" && lastop == "Push")
        {
            tmp->id = id;
            S.push(tmp);
            if (i == 0)
                root = id;
            else
                lastNode->left = tmp;
            lastNode = tmp;
        }
    }
    Post(vec[root]);
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