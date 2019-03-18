// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>

#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int num[10001], n, tmp, input[100000];
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d",&tmp);
        input[i] = tmp, num[tmp]++; 
    }
    for(int i = 0; i < n; i++)
        if(num[input[i]] == 1){cout << input[i];return 0;}
    cout << "None";
    return 0;
}