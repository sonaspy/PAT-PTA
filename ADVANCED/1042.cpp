// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("input", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, shuffle_seq[100];
    string C = "SHCDJ";
    vector<string> input(54), output(54);
    cin >> n;
    for (int i = 0; i < 54; i++)
    {
        string s;
        cin >> shuffle_seq[i];
        shuffle_seq[i]--;
        s.push_back(C[i / 13]);
        s += to_string(i % 13 + 1);
        output[i] = s;
    }
    while (n--)
    {
        input = output;
        for (int j = 0; j < 54; j++)
            output[shuffle_seq[j]] = input[j];
    }
    cout << output[0];
    for (int i = 1; i < 54; i++)
        cout << " " << output[i];
    return 0;
}