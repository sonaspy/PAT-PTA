// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;



int main(int argc, char const *argv[])
{
  /* code */
  int a[] = {1,2,3,4,5,6,7,8,9};
  vector<int> vi(a,a+8);
  for(int i = 6 ; i >= 0; i /= 2)
    cout << a[i];

  return 0;

}
