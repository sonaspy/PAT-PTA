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
bool cmp0(Node a, Node b)
{
    return a.score[0] > b.score[0];
}
bool cmp1(Node a, Node b)
{
    return a.score[1] > b.score[1];
}
bool cmp2(Node a, Node b)
{
    return a.score[2] > b.score[2];
}
bool cmp3(Node a, Node b)
{
    return a.score[3] > b.score[3];
}
void solve(int id)
{
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
    test();
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
    sort(vec.begin(), vec.end(), cmp0), solve(0);
    sort(vec.begin(), vec.end(), cmp1), solve(1);
    sort(vec.begin(), vec.end(), cmp2), solve(2);
    sort(vec.begin(), vec.end(), cmp3), solve(3);
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