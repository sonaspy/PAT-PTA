// author -  newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include <map>
#include <algorithm>
#include <stack>

#define test() freopen("in","r",stdin)
using namespace std;
class abc
{
  public:
    int d;
    char a, b, c;
    abc(char x, char y, char z, int s) : a(x), b(y), c(z), d(s) {}
};
void hanio(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    hanio(n - 1, a, c, b);
    hanio(1, a, b, c);
    hanio(n - 1, b, a, c);
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    abc temp('a', 'b', 'c', n);
    stack<abc> q;
    temp.d = n, temp.a = 'a', temp.b = 'b', temp.c = 'c';
    q.push(temp);
    while (!q.empty())
    {
        temp = q.top();
        q.pop();
        if (temp.d == 1)
            printf("%c -> %c\n", temp.a, temp.c);
        else
        {
            q.push(abc(temp.b, temp.a, temp.c, temp.d - 1));
            q.push(abc(temp.a, temp.b, temp.c, 1));
            q.push(abc(temp.a, temp.c, temp.b, temp.d - 1));
        }
    }
    //    cout<<endl;
    //    hanio(n,'a','b','c');
}