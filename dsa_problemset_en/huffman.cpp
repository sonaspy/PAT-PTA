// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
typedef struct HuffmanNode *hfmPtr;
unordered_map<char, int> mp;
enum __attr_side
{
    LEFT,
    RIGHT,
    ROOT
};

struct HuffmanTree
{
    hfmPtr __root = nullptr;
    int __total_cost = 0;
} Tree;

struct HuffmanNode
{
    char __char_c;
    int __value_weight;
    string __string_code;
    __attr_side side;
    hfmPtr __L_child = nullptr, __R_child = nullptr;
    HuffmanNode(int d, int f) : __char_c(d), __value_weight(f) {}
    HuffmanNode();
};
struct cmp
{
    bool operator()(const hfmPtr __tmp_a, const hfmPtr __tmp_b) const { return __tmp_a->__value_weight > __tmp_b->__value_weight; }
};
priority_queue<hfmPtr, vector<hfmPtr>, cmp> pq;

void hfm_generate(hfmPtr &root)
{
    if (!root)
        return;
    static string __tmp_code;
    switch (root->side)
    {
    case LEFT:
        __tmp_code.push_back('0');
        break;
    case RIGHT:
        __tmp_code.push_back('1');
    default:
        break;
    }
    if (!root->__L_child && !root->__R_child)
    {
        root->__string_code = __tmp_code;
        cout << root->__char_c << " ( " << mp[root->__char_c] << " ) "
             << " : " << __tmp_code << endl;
    }
    else
        Tree.__total_cost += root->__value_weight;
    hfm_generate(root->__L_child);
    hfm_generate(root->__R_child);
    __tmp_code.pop_back();
}

int main(int argc, char const *argv[])
{
    /* __string_code */
    //test();

    mp['a'] = 4, mp['u'] = 1, mp['x'] = 2, mp['z'] = 1;
    for (auto i : mp)
    {
        hfmPtr tmp = new HuffmanNode(i.first, i.second);
        pq.push(tmp);
    }
    hfmPtr root = nullptr;
    while (pq.size() > 1)
    {
        hfmPtr tmp1 = pq.top();
        pq.pop();
        hfmPtr tmp2 = pq.top();
        pq.pop();
        hfmPtr s = new HuffmanNode('\0', tmp1->__value_weight + tmp1->__value_weight);
        s->__L_child = tmp1;
        tmp1->side = LEFT;
        s->__R_child = tmp2;
        tmp2->side = RIGHT;
        root = s;
        pq.push(s);
    }
    cout << root->__value_weight << endl;
    root->side = ROOT;
    hfm_generate(root);
    cout << Tree.__total_cost;
    return 0;
}