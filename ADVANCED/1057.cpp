// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
using namespace std;
int mid, n, key, top;
multiset<int> right_heap;
multiset<int, greater<int>> left_heap;
void adjust_balance()
{ // (decreasing)left[0.......n] [n+1..........2*n]right(increasing)
    if (left_heap.size() < right_heap.size())
    { // legitimate status example: left[5] right[5]  / left[6] right[5]  illegitimate: left[4] right[5] / left[7] right[5]
        left_heap.insert(*right_heap.begin());
        right_heap.erase(right_heap.begin());
    }
    else if (right_heap.size() + 1 < left_heap.size())
    {
        right_heap.insert(*left_heap.begin());
        left_heap.erase(left_heap.begin());
    }
    mid = *left_heap.begin(); // left_heap's physical 1st position element will be the midValue all the time. (i.e logic left[0....n]'s n-th position)
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    char op[15];
    vector<int> Stack;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", op);
        if (op[1] == 'u')
        {
            scanf("%d", &key);
            Stack.push_back(key);
            (key <= mid) ? left_heap.insert(key) : right_heap.insert(key);
            adjust_balance();
        }
        else if (op[1] == 'e')
            Stack.empty() ? printf("Invalid\n") : printf("%d\n", mid);
        else
        {
            if (Stack.empty())
                printf("Invalid\n");
            else
            {
                top = Stack.back();
                printf("%d\n", top), Stack.pop_back();
                mid < top ? right_heap.erase(right_heap.find(top)) : left_heap.erase(left_heap.find(top));
                adjust_balance();
            }
        }
    }
    return 0;
}