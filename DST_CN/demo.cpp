// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
typedef map<int, int, greater<int> > MAP;


int main(int argc, char const *argv[])
{
  /* code */
  MAP::iterator pt1, pt2;
  MAP p1, p2, m;
  for(int i = 0; i < 10; i++){
    p1[i] = i;
    p2[i] = i;
  }
  for(pt1 = p1.begin(); pt1 != p1.end(); pt1++)
      m.insert(*pt1);
  for(pt1 = m.begin(); pt1 != m.end(); pt1++)
    cout << (*pt1).first;

  return 0;
}
