// author -  newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int n, a[100001];
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d",a[0]);
    for(int i = 1; i < n; i++)
        printf(" %d",a[i]);
    return 0;
}