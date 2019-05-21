// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;
struct Node
{
    int id;
    double score[4];
};
unordered_map<int, int[4]> mp;
vector<Node> vec;
inline bool cmp0(Node a, Node b) { return a.score[0] > b.score[0]; }
inline bool cmp1(Node a, Node b) { return a.score[1] > b.score[1]; }
inline bool cmp2(Node a, Node b) { return a.score[2] > b.score[2]; }
inline bool cmp3(Node a, Node b) { return a.score[3] > b.score[3]; }
typedef bool (*funcP)(Node a, Node b);
funcP cmp[4] = {cmp0, cmp1, cmp2, cmp3};
void solve(int id)
{
    sort(vec.begin(), vec.end(), cmp[id]);
    int rank = 1;
    mp[vec.front().id][id] = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i].score[id] != vec[i - 1].score[id])
            rank = i + 1;
        mp[vec[i].id][id] = rank;
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, id;
    char T[4] = {'A', 'C', 'M', 'E'};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        Node node;
        cin >> node.id >> node.score[1] >> node.score[2] >> node.score[3];
        node.score[0] = (node.score[1] + node.score[2] + node.score[3]) / 3;
        vec.push_back(node);
    }
    for (int i = 0; i < 4; i++)
        solve(i);
    for (int i = 0; i < m; i++)
    {
        cin >> id;
        if (!mp.count(id))
        {
            cout << "N/A" << endl;
            continue;
        }
        int k = 0, minRank = 99999999;
        for (int j = 0; j < 4; j++)
        {
            if (mp[id][j] < minRank)
            {
                minRank = mp[id][j];
                k = j;
            }
        }
        cout << mp[id][k] << " " << T[k] << endl;
    }
    return 0;
}