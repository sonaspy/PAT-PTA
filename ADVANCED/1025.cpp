// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    string id;
    int score, rank = 1, l_rank = 1, l_id;
    bool operator<(const Node b) const { return score > b.score; }
};
bool cmp(Node a, Node b) {return (a.rank == b.rank) ? a.id < b.id : a.rank < b.rank;}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m;
    cin >> n;
    vector<Node> list;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        vector<Node> list_tmp(m);
        for (int j = 0; j < m; j++)
        {
            list_tmp[j].l_id = i+1;
            cin >> list_tmp[j].id >> list_tmp[j].score;
        }
        sort(list_tmp.begin(),list_tmp.end());
        int rank = 1;
        for (int i = 1; i < list_tmp.size(); i++)
            list_tmp[i].l_rank = (list_tmp[i].score != list_tmp[i - 1].score) ? rank = i + 1 : rank;
        list.insert(list.end(),list_tmp.begin(),list_tmp.end());
    }
    sort(list.begin(),list.end());
    int rank = 1;
    for (int i = 1; i < list.size(); i++)
        list[i].rank = (list[i].score != list[i - 1].score) ? rank = i+1: rank;
    sort(list.begin(),list.end(),cmp);
    cout << list.size() << endl;
    for(auto i : list){printf("%s %d %d %d\n",i.id.c_str(), i.rank, i.l_id, i.l_rank);}
    return 0;
}