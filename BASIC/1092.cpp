// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Moonpie
{
    int total = 0;
    int id;
} pies[1001];

bool cmp(struct Moonpie a, struct Moonpie b)
{
    if (a.total == b.total)
        return a.id < b.id;
    return a.total > b.total;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, M, num;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        {
            for (int j = 1; j <= N; j++)
                {
                    pies[j].id = j;
                    scanf("%d", &num);
                    pies[j].total += num;
                }
        }
    sort(pies + 1, pies + N + 1, cmp);
    cout << pies[1].total << endl;
    cout << pies[1].id;
    for (int i = 2; i <= N; i++)
        if (pies[i].total == pies[1].total)
            cout << " " << pies[i].id;
    return 0;
}