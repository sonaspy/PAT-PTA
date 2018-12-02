// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int N;
    cin >> N;
    int a[100001];
    for(int i = 0; i < N; i++)
      scanf("%d",&a[i]);
    make_heap(a, a+N);
    sort_heap(a, a+N);
    printf("%d",a[0]);
    for(int i = 1; i < N; i++)
      printf(" %d",a[i]);
    return 0;
}