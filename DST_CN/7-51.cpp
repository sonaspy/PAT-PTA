// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <set>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    multiset<int> list;
    int tmp, seq = 2;
    while (seq--)
    {
        scanf("%d", &tmp);
        while (tmp != -1)
        {
            list.insert(tmp);
            scanf("%d", &tmp);
        }
    }
    if (!list.size())
        printf("NULL");
    else
    {
        bool flag = true;
        for (auto iter : list)
        {
            if (flag)
            {
                flag = false;
                printf("%d", iter);
            }
            else
                printf(" %d", iter);
        }
    }

    return 0;
}