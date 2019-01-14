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
    //test();
    int tmp;
    vector<int> table[3];
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &tmp);
        while (tmp != -1)
        {
            table[i].push_back(tmp);
            scanf("%d", &tmp);
        }
    }
    vector<int>::iterator p0, p1;
    p0 = table[0].begin(), p1 = table[1].begin();
    while (p0 != table[0].end() && p1 != table[1].end())
    {
        if (*p0 == *p1){
            table[2].push_back(*p0);
            p0++;p1++;
        }
        else if(*p0 < *p1) p0++;
        else p1++;
    }
    if (!table[2].size())
        printf("NULL");
    else
    {   bool f  = true;
        for (auto iter : table[2])
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