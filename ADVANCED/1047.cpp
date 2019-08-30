// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define test() freopen("in", "r", stdin)

using namespace std;

bool cmp(const char * a, const char* b){return strcmp(a,b) < 0;}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, tmp, num;
    cin >> n >> m;
    vector<char*> courses[m];
    for (int i = 0; i < n; i++)
    {
        char* name = new char[4];
        scanf("%s", name);
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &tmp);
            courses[tmp - 1].push_back(name);
        }
    }
    for (int i = 0; i < m; i++)
    {
        sort(courses[i].begin(), courses[i].end(),cmp);
        printf("%d %lu\n",i+1, courses[i].size());
        for(auto j : courses[i])printf("%s\n", j);
    }

    return 0;
}