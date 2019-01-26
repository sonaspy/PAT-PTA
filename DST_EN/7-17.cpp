// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <cmath>
#include <string.h>
#define test() freopen("in", "r", stdin)

using namespace std;

inline bool isPrime(long long n)
{
    for (long long i = 2; i <= int(sqrt(n)); i++)
        if (n % i == 0)
            return false;
    return true;
}
inline int ReturnMaxPrime(int n){
    if(n <= 2) return 2;
    while(!isPrime(n))n++;
    return n;
}
int main(int argc, char const *argv[])
{
    /* code */
    test();
    int m, n, num, pos;
    cin >> m >> n;
    m = ReturnMaxPrime(m);
    bool table[m];
    memset(table, false, sizeof table);
    for (int i = 0; i < n; i++)
    {
        if(i > 0) printf(" ");
        scanf("%d", &num);
        int step = 0;
        do{
            pos = (num+step*step) % m;
            step++;
        }while(table[pos] && step < m);
        if(step == m)
            printf("-");
        else{
            table[pos] = true;
            printf("%d",pos);
        }
    }
    return 0;
}