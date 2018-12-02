// author - newguo@sonaspy.cn 
// coding - utf_8 

#define test() freopen("in","r",stdin)
#include <iostream>
using namespace std;
#define MAX 100

/*
 * Small capacity of the stack as the queue stack, large capacity as the queue stack. 
 * If the queue entry stack is full and the queue exit stack is not empty, the queue is full.
 *  If the queue entry stack is full and the queue exit stack is empty, 
 * all the elements of the queue entry stack will be put into the queue exit stack. 
 * When the queue stack is empty, it is put into the queue stack. If the queue stack is empty,
 *  the queue is empty. If the queue stack is empty, 
 * all the elements of the queue stack will be put into the queue stack,
 * and the first element of the queue stack will be output.
 */

int main(int argc, char const *argv[])
{
    /* code */
  int s1[MAX], s2[MAX];
  int a1, a2, r1 = 0, r2 = 0, x;
  char ch;
  cin >> a1 >> a2;
  if (a1 > a2) swap(a1,a2);
  while (cin >> ch && ch != 'T')
  {
    if (ch == 'A')
    {
      cin >> x;
      if (r1 == a1 && r2)
        cout << "ERROR:Full" << endl;
      else if (r1 == a1)
      {
        while (r1)
          s2[++r2] = s1[r1--];
        s1[++r1] = x;
      }
      else
        s1[++r1] = x;
    }
    else
    {
      if (!r1 && !r2)
        cout << "ERROR:Empty" << endl;
      else
      {
        if (!r2)
        {
          while (r1)
            s2[++r2] = s1[r1--];
        }
        cout << s2[r2--] << endl;
      }
    }
  }
}