// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <set>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int tmp;
    set<int> table[2];
    vector<int> res;
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &tmp);
        while (tmp != -1)
        {
            table[i].insert(tmp);
            scanf("%d", &tmp);
        }
    }
    set<int>::iterator p0, p1;
    p0 = table[0].begin(), p1 = table[1].begin();
    while (p0 != table[0].end() && p1 != table[1].end())
    {
        if (*p0 == *p1)
            res.push_back(*p0);
        p0++, p1++;
    }
    if (!res.size())
        printf("NULL");
    else
    {   bool f  = true;
        for (auto iter : res)
        {
            if(f){
                f= false;
                printf("%d",iter);
            }
            else printf(" %d",iter);
        }
    }

    return 0;
}