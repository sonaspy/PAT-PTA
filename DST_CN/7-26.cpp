// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <queue>
#include <vector>

#define test() freopen("in", "r", stdin)

using namespace std;

struct process
{
    int PRI;
    char s[12];
    friend bool operator<(process p1, process p2)
    {
        return p1.PRI > p2.PRI;
    }
};

priority_queue<process> pro_Q;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int numOfCommands, i;
    process tmp;
    scanf("%d\n", &numOfCommands);
    for (int i = 0; i < numOfCommands; i++)
        {
            scanf("%s", tmp.s);
            if (tmp.s[0] == 'G')
                {
                    if (!pro_Q.empty())
                        {
                            tmp = pro_Q.top();
                            pro_Q.pop();
                            printf("%s\n", tmp.s);
                        }
                    else
                        printf("EMPTY QUEUE!\n");
                }
            else
                {
                    scanf("%s %d", tmp.s, &tmp.PRI);
                    pro_Q.push(tmp);
                }
        }
    return 0;
}