#include <iostream>
using namespace std;
int mp[1287][129][61], visit[1287][129][61] = {0};
int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
int M, N, L, T;
int cnt;
void dfs(int i, int j, int k)
{
    for (int t = 0; t < 6; t++)
    {
        int next_i = i + dir[t][0];
        int next_j = j + dir[t][1];
        int next_k = k + dir[t][2];
        if (next_i > -1 && next_i < M && next_j > -1 && next_j < N && next_k > -1 && next_k < L &&
            !visit[next_i][next_j][next_k] && mp[next_i][next_j][next_k])
        {
            visit[next_i][next_j][next_k] = true;
            cnt++;
            dfs(next_i, next_j, next_k);
        }
    }
}
int main(void)
{
    cin >> M >> N >> L >> T;
    for (int k = 0; k < L; k++)
    {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> mp[i][j][k];
    }
    int ans = 0;
    for (int k = 0; k < L; k++)
    {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (!visit[i][j][k] && mp[i][j][k])
                {
                    visit[i][j][k] = true;
                    cnt = 1;
                    dfs(i, j, k);
                    if (cnt >= T)
                        ans += cnt;
                }
    }
    cout << ans << endl;
    return 0;
}