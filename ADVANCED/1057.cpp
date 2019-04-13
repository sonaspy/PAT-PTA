// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define test() freopen("in", "r", stdin)
#define ISEVEN(x) ((x) % 2 == 0)
using namespace std;
int mid, n, key, l_size, r_size;
multiset<int> right_heap;              // nondecreasing order. storing large key.
multiset<int, greater<int>> left_heap; // nonincreasing order . storing small key.
void reBalance()
{
    l_size = left_heap.size(), r_size = right_heap.size();
    if (l_size < r_size)
    {
        left_heap.insert(*right_heap.begin());
        right_heap.erase(right_heap.begin());
    }
    else if (r_size + 1 < l_size)
    {
        right_heap.insert(*left_heap.begin());
        left_heap.erase(left_heap.begin());
    }
    mid = *left_heap.begin(); // small heap's 1st element will be the midValue all the time.
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
            if (key <= mid)
                left_heap.insert(key);
            else
                right_heap.insert(key);
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
                int top = Stack.back();
                printf("%d\n", top), Stack.pop_back();
                (top > mid) ? right_heap.erase(right_heap.find(top)) : left_heap.erase(left_heap.find(top));
                reBalance();
            }
        }
    }
    return 0;
} //attention