// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>

#define test() freopen("in","r",stdin)

using namespace std;

struct unionFindNode
{
  int parent; 
  bool root;  
  unionFindNode()
  {
    parent = 1;
    root = true;
  }
};

class fastUnionFind
{
public:
  fastUnionFind(int numberOfElements)
  { // Initialize numberOfElements trees, 1 element per set/class/tree.
    node = new unionFindNode[numberOfElements + 1];
  }

  void unite(int rootA, int rootB)
  { 
    if (node[rootA].parent < node[rootB].parent)
    { // rootA becomes subtree of rootB
      node[rootB].parent += node[rootA].parent;
      node[rootA].root = false;
      node[rootA].parent = rootB;
    }
    else
    { 
      node[rootA].parent += node[rootB].parent;
      node[rootB].root = false;
      node[rootB].parent = rootA;
    }
  }
  unionFindNode *node;
};


int main(int argc, char const *argv[])
{
    /* code */
    test();
    fastUnionFind uf(30001);
    int totalStudents, clubs, stuOfclubs, fis, next;
    cin >> totalStudents >> clubs;
    for(int i = 0; i < clubs; i++){
        scanf("%d",&stuOfclubs);
        scanf("%d",&fis);
        for(int j = 0; j < stuOfclubs-1; j++){
          scanf("%d",&next);
          uf.unite(fis, next);
        }
    }
    int maxnum = 1;
    for(int i = 1; i <= 30001; i++){
      if (uf.node[i].parent > maxnum && uf.node[i].root == true)
        maxnum = uf.node[i].parent;
    }
    cout << maxnum;

    return 0;
}