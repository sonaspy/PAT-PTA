// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <unordered_map>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    string id;
    int center;
} node;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, test;
    cin >> n;
    unordered_map<int, Node> mp;
    for (int i = 0; i < n; i++)
        {
            cin >> node.id >> test >> node.center;
            mp[test] = node;
        }
    cin >> m;
    for (int i = 0; i < m; i++)
        {
            cin >> test;
            cout << mp[test].id << " " << mp[test].center << endl;
        }
    return 0;
}