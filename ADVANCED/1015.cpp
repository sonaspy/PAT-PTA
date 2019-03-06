// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define test() freopen("in","r",stdin)

using namespace std;

bool isPrime(int num){
    if(num == 1)return false;
    for(int i = 2; i <= sqrt(num);i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int num, radix;
    while(true){
        cin >> num >> radix;
        if(num < 0)return 0;
        if(!isPrime(num)){
            printf("No\n");
            continue;
        }
        int len = 0, arr[100];
        while(num){
            arr[len++] = num % radix;
            num /= radix;
        }
        for (int i = len - 1,c = 0; i > -1; i--,c++)
            num += arr[i] * pow(radix,c);
        printf("%s", isPrime(num) ? "Yes\n" : "No\n");
    }
    return 0;
}