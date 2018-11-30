// author - newguo@sonaspy.cn 
// coding - utf_8 

#include <stdio.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
  int K;
  vector<int> vec;
  vector<int>::iterator left, right, mid;
  int temp = 0;
  bool flag = true;
  scanf("%d", &K);
  while (scanf("%d", &temp), temp >= 0)
    vec.push_back(temp);
  if (K > vec.size() || K < 1)
  {
    printf("NULL\n");
    return 0;
  }

  vector<int>::iterator N = vec.begin() + (vec.size() - K);

  left = vec.begin();
  right = vec.end() - 1;

  while (left <= right)
  {
    mid = left + (right - left) / 2;

    if (mid == N)
    {
      printf("%d\n", *mid);
      break;
    }
    if (mid > N)
      right = mid - 1;
    else if (mid < N)
      left = mid + 1;
  }

  return 0;
}