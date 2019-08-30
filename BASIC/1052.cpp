// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;

int convert(string s, string a[])
{
    int k = 0;
    for (auto i : s)
        {
            if (i != '[' && i != ' ' && i != ']')
                a[k] += i;
            if (i == ']')
                k++;
        }
    return k;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s[3], hand[11], eye[11], mouth[11];
    getline(cin, s[0]);
    getline(cin, s[1]);
    getline(cin, s[2]);
    int l1 = convert(s[0], hand);
    int l2 = convert(s[1], eye);
    int l3 = convert(s[2], mouth);
    int N;
    cin >> N;
    int num[N][5];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 5; j++)
            cin >> num[i][j];
    for (int i = 0; i < N; i++)
        {
            int a1 = num[i][0], a2 = num[i][1], a3 = num[i][2], a4 = num[i][3], a5 = num[i][4];
            if (a1 <= l1 && a2 <= l2 && a3 <= l3 && a4 <= l2 && a5 <= l1 && a1 > 0 && a2 > 0 && a3 > 0 && a4 > 0 && a5 > 0)
                cout << hand[a1 - 1] << "(" << eye[a2 - 1] << mouth[a3 - 1] << eye[a4 - 1] << ")" << hand[a5 - 1] << endl;
            else
                cout << "Are you kidding me? @\\/@" << endl;
        }
    return 0;
}