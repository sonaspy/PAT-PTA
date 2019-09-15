// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, b;
    cin >> n >> b;
    b %= n;
    vector<int> v1(n), v2;
    for (int i = 0; i < n; i++)
        scanf("%d", &v1[i]);
    v2.insert(v2.end(), v1.begin() + b, v1.end());
    v2.insert(v2.end(), v1.begin(), v1.begin() + b);
    cout << v2[0];
    for(int i = 1; i < n; i++)
        printf(" %d",v2[i]);
    return 0;
}