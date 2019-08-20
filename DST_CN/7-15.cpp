// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    char c;
    long id, N;
    unordered_map<long, string> Qdb;
    string s;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> c >> id >> s;
        switch (c)
        {
        case 'L':
            if (!Qdb.count(id))
                printf("ERROR: Not Exist\n");
            else if (s != Qdb[id])
                printf("ERROR: Wrong PW\n");
            else
                printf("Login: OK\n");
            break;
        case 'N':
            if (Qdb.count(id))
                printf("ERROR: Exist\n");
            else
            {
                Qdb[id] = s;
                printf("New: OK\n");
            }
            break;
        }
    }
    return 0;
}