// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <string>
#define test() freopen("in", "r", stdin)
using namespace std;
int main()
{
    string c = "0123456789ABC";
    printf("#");
    for (int i = 0; i < 3; i++)
    {
        int num;
        scanf("%d", &num);
        printf("%c%c", c[num / 13], c[num % 13]);
    }
    return 0;
}