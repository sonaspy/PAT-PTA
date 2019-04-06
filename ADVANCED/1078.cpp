// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int m, n, h_table[11111], tmp, prime[11111] = {0};
inline void Solve(int key)
{
    int n_pos;
    for (int st = 0; st < m; st++)
    {
        n_pos = (key + st * st) % m;
        if (h_table[n_pos] == -1)
        {
            h_table[n_pos] = key;
            cout << n_pos;
            return;
        }
    }
    cout << "-";
}

inline int next_prime(int num)
{
    if (prime[num] == 1) return num;
    for (int i = num + 1; i < 11111; i++)
        if (prime[i] == 1)
            return i;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    fill(h_table, h_table + 11111, -1);
    fill(prime + 2, prime + 11111, 1);
    for (int i = 2; i * i < 11111; i++)
        for (int j = 2; i * j < 11111; j++)
            prime[i * j] = 0;
    cin >> m >> n;
    m = next_prime(m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (i != 0) printf(" ");
        Solve(tmp);
    }
    return 0;
}