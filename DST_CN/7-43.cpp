// author - sonaspy@outlook.com
// coding - utf_8
#include <iostream>
#include <algorithm>
#include <string>
#include <map>


#define test() freopen("in","r",stdin)

using namespace std;
const int MAXN = 100000;
int N, P;
string s; // t;
map<string, int> str_pos;
bool vis[MAXN] = {false};

int main(int argc, char const *argv[])
{
    //test();
    scanf("%d %d", &N, &P);
    for (int i = 0; i < N; ++i)
        {
            cin >> s;
            int len = s.size();
            int pos = 0;
            if (len == 1)
                pos += (s[0] - 'A');
            else if (len == 2)
                pos = 32 * (s[0] - 'A') + (s[1] - 'A');
            else
                for (int j = 3; j >= 1; --j)
                    {
                        int index = len - j;
                        pos = pos * 32 + s[index] - 'A';
                    }
            pos %= P;
            if (str_pos[s] == 0 && vis[pos])
                {
                    for (int t = 1; t < MAXN; ++t)
                        {
                            if (!vis[(pos + t * t) % P])
                                {
                                    pos = (pos + t * t) % P;
                                    vis[pos] = true;
                                    str_pos[s] = pos;
                                    break;
                                }
                            else if (!vis[(pos - t * t + P) % P])
                                {
                                    pos = (pos - t * t + P) % P;
                                    vis[pos] = true;
                                    str_pos[s] = pos;
                                    break;
                                }
                        }
                }
            else
                {
                    pos %= P;
                    str_pos[s] = pos;
                    vis[pos] = true;
                }
            if(i == 0)cout << pos;
            else cout << " " << pos;
        }
    return 0;
}
