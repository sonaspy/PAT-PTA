// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define WOLF -1
#define MAX_NUM 105
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, states[MAX_NUM];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> states[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            vector<int> assume(MAX_NUM, 1), liars;
            assume[i] = assume[j] = WOLF;
            for (int id = 1; id <= n; id++)
            {
                if (states[id] * assume[abs(states[id])] < 0)
                    liars.push_back(id);
            }
            if (liars.size() == 2 && assume[liars[0]] + assume[liars[1]] == 0)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}