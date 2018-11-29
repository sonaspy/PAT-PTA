// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>

#define OK 1
#define ERROR 0
#define MaxTree 10
#define Null -1 
using namespace std;    
typedef char ElementType;
typedef struct TreeNode
{
  ElementType data;
  int left;
  int right;
} Tree;
Tree T1[MaxTree], T2[MaxTree];

int BulidTree(Tree T[])
{
  int N, check[MaxTree], root = Null; 
  char cl, cr;                       
  cin >> N;
  if (N)
  {
    for (int i = 0; i < N; i++)
      check[i] = 0;
    for (int i = 0; i < N; i++)
    {
      cin >> T[i].data >> cl >> cr;
      if (cl != '-')
      {
        T[i].left = cl - '0';
        check[T[i].left] = 1; 
      }
      else
        T[i].left = Null;
      if (cr != '-')
      {
        T[i].right = cr - '0';
        check[T[i].right] = 1; 
      }
      else
        T[i].right = Null;
    }
    for (int i = 0; i < N; i++) 
      if (!check[i])
      {
        root = i;
        break;
      }
  }
  return root;
}
int Isomprphic(int root1, int root2)
{
  if((root1 == Null) && (root2 == Null))
    return  OK;
  if (((root1 == Null) && (root2 != Null)) || ((root2 == Null) && (root1 != Null)))
    return ERROR;
  if( T1[root1].data != T2[root2].data)
    return ERROR;
  if ((T1[root1].left == Null) && (T2[root2].left == Null))
    return Isomprphic(T1[root1].right, T2[root2].right);
  if ((T1[root1].left != Null) && (T2[root2].left != Null )&&
        (T1[T1[root1].left].data == T2[T2[root2].left].data))
      return (Isomprphic(T1[root1].left, T2[root2].left) && Isomprphic(T1[root1].right, T2[root2].right));
  else
      return(Isomprphic(T1[root1].left, T2[root2].right) && Isomprphic(T1[root1].right, T2[root2].left));   
}
int main()
{
  int root1, root2;
  root1 = BulidTree(T1);
  root2 = BulidTree(T2);
  if (Isomprphic(root1, root2))
  cout << "Yes";
  else
  cout << "No";
  return 0;
}