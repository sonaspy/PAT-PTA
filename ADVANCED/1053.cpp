// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>

#define test() freopen("in", "r", stdin)
#define ROOT 0
using namespace std;
typedef struct Node *ptrN;
typedef vector<ptrN> Descendant;
typedef vector<int> Path;
struct Node
{
    int id, w_data;
    Descendant desc;
    Node(){};
    Node(int i, int d) : id(i), w_data(d) {}
};

int n, m, s, tmp;
ptrN *mMp = new ptrN[100];
vector<Path> paths;

void FindPath(int id)
{
    static Path path;
    static int w = 0;
    w += mMp[id]->w_data;
    path.push_back(mMp[id]->w_data);
    if (mMp[id]->desc.empty() && w == s)
    {
        paths.push_back(path);
        return;
    }
    for (auto j : mMp[id]->desc)
    {
        FindPath(j->id);
        w -= mMp[j->id]->w_data;
        path.pop_back();
    }
}

bool cmp(Path a, Path b)
{
    for (int i = 0; i < a.size() && i < b.size(); ++i)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return a.size() > b.size();
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        ptrN node = new Node(i, tmp);
        mMp[i] = node;
    }
    ptrN root = mMp[0];
    for (int i = 0; i < m; i++)
    {
        int p, num;
        scanf("%d%d", &p, &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &tmp);
            mMp[p]->desc.push_back(mMp[tmp]);
        }
    }
    FindPath(ROOT);
    sort(paths.begin(), paths.end(), cmp);
    for (auto i : paths)
    {
        for (int j = 0; j < i.size() - 1; ++j)
            printf("%d ", i[j]);
        printf("%d", i.back());
        printf("\n");
    }
    return 0;
}