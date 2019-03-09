// author -  newguo@sonaspy.cn 
// coding - utf_8 

#include <iostream>
#include <climits>

using namespace std;

int maxSubArray(int a[], int n){
  if(n < 1)
    return 0;
  int max = 0;
  int cur = 0;
  for(int i = 0; i < n; i++){
    cur += a[i];
    if(cur < 0)
      cur = 0;
    if(cur > max)
      max = cur;
  }
  return max;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n ;
    int a[n];
    for(int i = 0; i < n; i++)
      cin >> a[i];
    cout << maxSubArray(a,n);
    return 0;
}