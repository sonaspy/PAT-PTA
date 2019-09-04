// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        this->columns = vector<bool>(n, false);           // if there is a queen in this column.
        this->main_diag = vector<bool>(2 * n - 1, false); // if there is a queen in this diag
        this->vice_diag = vector<bool>(2 * n - 1, false); // if there is a queen in this diag
        this->C = vector<int>(n, -1);                     // each row's queen put in which column
        vector<vector<string>> res;
        this->n = n;
        dfs(res, 0);
        return res;
    }

private:
    vector<bool> columns, main_diag, vice_diag;
    vector<int> C;
    int n;
    void dfs(vector<vector<string>> &res, int row)
    {
        if (row == n)
        {
            res.push_back(vector<string>());
            for (int i = 0; i < n; i++)
            {
                string s(n, '.');
                for (int j = 0; j < n; j++)
                    if (j == C[i])
                        s[j] = 'Q';
                res.back().push_back(s);
            }
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (!columns[j] && !main_diag[row - j + n - 1] && !vice_diag[row + j])
            {
                C[row] = j;
                columns[j] = main_diag[row - j + n - 1] = vice_diag[row + j] = true;
                dfs(res, row + 1);
                C[row] = -1;
                columns[j] = main_diag[row - j + n - 1] = vice_diag[row + j] = false;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    vector<vector<string>> ss = s.solveNQueens(6);
    for (auto vs : ss)
    {
        for (auto str : vs)
            cout << str << endl;
        cout << endl;
    }
    return 0;
}