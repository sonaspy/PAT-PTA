// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    int id;
    int score = 0;
} nodes[100001];
bool cmp(struct Node A, struct Node B)
{
    return A.score > B.score;
}
int main(int argc, char const *argv[])
{
    /* code */
    // test();
    int n, id, score;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &id, &score);
            nodes[id].id = id;
            nodes[id].score += score;
        }
    sort(nodes + 1, nodes + n + 1, cmp);
    cout << nodes[1].id << " " << nodes[1].score;
    return 0;
}