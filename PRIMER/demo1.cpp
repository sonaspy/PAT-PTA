// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<queue>
#include<numeric>

#define test() freopen("in","r",stdin)

using namespace std;
struct Node{
    int i;
    bool operator < (const Node b)const{return i < b.i;}
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<Node*> nodes(2);
    nodes[0] = new Node;
    nodes[1] = new Node;
    nodes[0]->i = 1;
    nodes[1]->i = 100;
    nodes.erase(max_element(nodes.begin(),nodes.end()));
    cout << nodes.front()->i;
    return 0;
}