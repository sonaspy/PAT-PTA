// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>
#include <set>

#define test() freopen("in", "r", stdin)
#define ISEVEN(x) ((x) % 2 == 0)
using namespace std;
int mid, n, key, l_S, l_L;
multiset<int> _heap_L;               // nondecreasing order. storing large key.
multiset<int, greater<int>> _heap_S; // nonincreasing order . storing small key.
void reBalance()
{
    l_S = _heap_S.size(), l_L = _heap_L.size();
    if (l_S < l_L)
    {
        _heap_S.insert(*_heap_L.begin());
        _heap_L.erase(_heap_L.begin());
    }
    else if (l_L + 1 < l_S)
    {
        _heap_L.insert(*_heap_S.begin());
        _heap_S.erase(_heap_S.begin());
    }
    mid = *_heap_S.begin();// small heap's 1st element will be the midValue all the time.
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    char op[15];
    stack<int> Stack;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", op);
        if (op[1] == 'u')
        {
            scanf("%d", &key);
            Stack.push(key);
            if (key <= mid)
                _heap_S.insert(key);
            else
                _heap_L.insert(key);
            reBalance();
        }
        else if (op[1] == 'e')
        {
            if (Stack.empty())
                printf("Invalid\n");
            else
                printf("%d\n", mid);
        }
        else
        {
            if (Stack.empty())
                printf("Invalid\n");
            else
            {
                int top = Stack.top();
                printf("%d\n", top), Stack.pop();
                (top > mid)? _heap_L.erase(_heap_L.find(top)) : _heap_S.erase(_heap_S.find(top));
                reBalance();
            }
        }
    }
    return 0;
}