// author -  newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>

#define test() freopen("in","r",stdin)

using namespace std;

int Height(char a[], char b[], int n)
{
  int i = -1;
  if (n == 0) return 0;
  while (b[++i] != a[0]);
  int x = Height(a + 1, b, i) + 1;                     
  int y = Height(a + i + 1, b + i + 1, n - i - 1) + 1; 
  return x > y ? x : y;
}

int main(int argc, char const *argv[])
{
    /* code */
    char a[101];
    char b[101];
    int n;
    cin >> n;
    cin >> a >> b;
    int cnt = Height(a, b, n);
    cout << cnt << endl;
    return 0;
}