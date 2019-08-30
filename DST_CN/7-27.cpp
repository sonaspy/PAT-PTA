// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;
const int MAXN = 102;

int main(int argc, char const *argv[])
{
    vector<string> name(MAXN);
    map<string, string> _parent;
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();
    while (n--)
        {
            string __name;
            getline(cin, __name);
            int cnt = count(__name.begin(), __name.end(), ' ');
            int general = cnt / 2;
            if (cnt == 0)
                {
                    _parent[__name] = "NULL";
                    name[general] = __name;
                }
            else
                {
                    __name = __name.substr(cnt);
                    _parent[__name] = name[general - 1];
                    name[general] = __name;
                }
        }
    while (m--)
        {
            string a, b, c, d;
            cin >> a >> b >> b >> c >> b >> d;
            switch (c[0])
                {
                case 'p':
                    swap(a, d);
                case 'c':
                    if (_parent[a] == d)
                        printf("True\n");
                    else
                        printf("False\n");
                    break;
                case 's':
                    if (_parent[a] == _parent[d])
                        printf("True\n");
                    else
                        printf("False\n");
                    break;
                case 'a':
                    swap(a, d);
                case 'd':
                    while (_parent[a] != d && _parent[a] != "NULL")
                        a = _parent[a];
                    if (_parent[a] == "NULL")
                        printf("False\n");
                    else
                        printf("True\n");
                }
        }
    return 0;
}
