// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>

#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, tmp, maxSum = -1, thisSum = 0, firstNum, tmpFirst, lastNum, StartCount = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d",&tmp);
        thisSum += tmp;
        if(!StartCount){
            tmpFirst = tmp;
            StartCount = 1;
        }
        if(thisSum > maxSum){
            maxSum = thisSum;
            firstNum = tmpFirst;
            lastNum = tmp;
        }
        if(thisSum < 0){
            StartCount = 0;
            thisSum = 0;
        }
    }
    if(maxSum < 0) cout << 0;
    else cout << maxSum;
    return 0;
}