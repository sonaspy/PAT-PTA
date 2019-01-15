// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string a, da, b, db, p1, p2;
    int pa = 0, pb = 0, c1, c2;
    cin >> a >> da >> b >> db;
    c1 = count(a.begin(), a.end(), da[0]);
    c2 = count(b.begin(), b.end(), db[0]);
    while(c1--)p1.push_back(da[0]);
    while(c2--)p2.push_back(db[0]);
    stringstream oss1(p1), oss2(p2);
    oss1 >> pa;
    oss2 >> pb;
    cout << pa+pb;

    return 0;
}