// author - sonaspy@outlook.com
// coding - utf_8

#include<iostream>

#define test() freopen("in","r",stdin)

using namespace std;

int students[30001];

int getRoot(int member)
{
    if(students[member] < 0) return member;
    return getRoot(students[member]);
}

void init(int n)
{
    int i;
    for (i = 1; i <= n; i++)
        students[i] = -1;
}

void Union(int r1, int r2)
{
    r1 = getRoot(r1);
    r2 = getRoot(r2);
    if(r1 == r2) return;
    if(students[r1] <= students[r2])
        {
            students[r1] += students[r2];
            students[r2] = r1;
        }
    else
        {
            students[r2] += students[r1];
            students[r1] = r2;
        }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, i, j, k, stu, root1, root2;
    scanf("%d %d", &n, &m);
    init(n);
    for (i = 0; i < m; i++)
        {
            scanf("%d %d", &k, &root1);
            for (j = 1; j < k; j++)
                {
                    scanf("%d", &root2);
                    Union(root1, root2);
                }
        }
    int max = -1;
    for (i = 1; i <= n; i++)
        {
            if ( students[i] < max)
                {
                    max = students[i];
                }
        }
    printf("%d", -max);
    return 0;
}