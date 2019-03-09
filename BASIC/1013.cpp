// author -  newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<vector>
#include<math.h>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int a1,a2, x = 0;
    vector<int> prime,ans;
    cin >> a1 >> a2;
    for(int i = 2; i <= 200000; i++){
        bool isprime = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0) {isprime = false;break;}
        }
        if(isprime) prime.push_back(i);
    }
    for(int i = a1 - 1; i < a2; i++){
        x++;
        printf("%d%c", prime[i], (x % 10 == 0 || i == a2-1) ? '\n' : ' ');
    }
    return 0;
}