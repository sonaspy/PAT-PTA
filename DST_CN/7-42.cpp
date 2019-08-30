// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;
int N, P;
struct hashnode
{
    int data;
    bool state = false;
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> N >> P;
    struct hashnode table[100000];
    int in_num, pos;
    for (int i = 0; i < N; i++)
        {
            scanf("%d", &in_num);
            for (int j = 0; j < P; j++)
                if (table[j].data == in_num)
                    {
                        printf(" %d", j);
                        goto next;
                    }
            pos = in_num % P;
            while (table[pos].state)
                pos = (pos + 1) % P;
            table[pos].data = in_num;
            table[pos].state = true;
            if (!i)
                printf("%d", pos);
            else
                printf(" %d", pos);
next:
            ;
        }
    return 0;
}