// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
typedef int ElementType;
using namespace std;
#define MAXN 10
#include<stdio.h>

ElementType Median(ElementType A[], int N);


    int main(int argc, char const *argv[])
{
    /* code */
    freopen("input.a","r",stdin);
    ElementType A[MAXN];
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
      scanf("%d", &A[i]);
    printf("%d\n", Median(A, N));
    return 0;
}

ElementType Median(ElementType A[], int N)
{
  int i, j;
  int t = 0;
  for (i = N - 1; i > 0; i--)
  {
    for (j = 0; j < i; j++)
    {
      if (A[j] > A[j + 1])
      {
        t = A[j];
        A[j] = A[j + 1];
        A[j + 1] = t;
      }
    }
  }
  return A[N / 2];
}