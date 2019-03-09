// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, valid = 0, weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    string s;
    char Z_M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    vector<string> vs;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> s;
            int sum = 0, z  = 0;
            for (int j = 0; j < 17; j++)
                {
                    char c = s[j];
                    if (!(c >= '0' && c <= '9'))
                        goto problem;
                    else
                        sum += (c - '0') * weight[j];
                }
            z = sum % 11;
            if (s[17] == Z_M[z])
                {
                    valid++;
                    continue;
                }
problem:
            vs.push_back(s);
        }
    if (valid == n)
        printf("All passed");
    else
        for (auto i : vs)
            cout << i << endl;
    return 0;
}