// author -  newguo@sonaspy.cn 
// coding - utf_8
#include <iostream>
using namespace std;
struct TreeNode{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(){data = 0; left = right = NULL;}
};
struct Tree{
  TreeNode* root;
  int cnt, travel[15];
  void initial(){
    root = new TreeNode;
    cnt = 0;
  }
  void insert(int info){
    TreeNode *walk = root, *prewalk;
    while(walk){
      prewalk = walk;
      if(info < walk->data)
        walk = walk->left;
      else
        walk = walk->right;
    }
    walk = new TreeNode;
    walk->data = info;
    if(info < prewalk->data)
    prewalk->left = walk;
    else  prewalk->right = walk;
  }
  void pathOutput(TreeNode * t){
    if(!t)return;
    travel[cnt++] = t->data;
    pathOutput(t->left);
    pathOutput(t->right);
  }
}tmp, tree; 

int main(int argc, char const *argv[])
{
    /* code */
    //freopen("in","r",stdin);
    int N, L, var;
    cin >> N;
    while(N){
      cin >> L;
      tree.initial();
      for(int i = 0; i < N; i++){
        cin >> var;
        tree.insert(var);
      }
      tree.pathOutput(tree.root);
      while(L--){
        tmp.initial();
        for(int i = 0; i < N; i++){
          cin >> var;
          tmp.insert(var);
        }
        tmp.pathOutput(tmp.root);
        bool flag = true;
        for(int j = 0; j < N; j++){
          if(tree.travel[j] != tmp.travel[j]) {flag = false; break;}
        }
        if(flag)  cout << "Yes\n";
        else  cout << "No\n";
      }
      cin >> N;
    }
    return 0;
}