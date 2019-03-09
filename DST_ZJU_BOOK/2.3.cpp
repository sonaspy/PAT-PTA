// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<list>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    list<int> lis;
    int a, n, carry = 0, sum, num;
    cin >> a >> n;
    n++;
    if(n == 1)
        {
            cout << 0;
            return 0;
        }
    while(n-- > 1)
        {
            sum = n * a + carry;
            num = sum % 10;
            carry = sum / 10;
            lis.push_front(num);
        }
    if(carry > 0)lis.push_front(carry);
    for(auto i : lis)
        cout << i;
    return 0;
}