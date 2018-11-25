#include "string"
#include "iostream"
#include "map"
using namespace std;
map<string, string> Q;

int main()
{
    // freopen("1.txt","r",stdin);
    int m;
    cin >> m;
    string a3, a2;
    char a1;
    while (m--)
    {
        cin >> a1 >> a2 >> a3;
        if (a1 == 'N')
        {
            if (Q.find(a2) == Q.end())
            {
                Q[a2] = a3;
                cout << "New: OK" << endl;
            }
            else
            {
                cout << "ERROR: Exist" << endl;
            }
        }
        if (a1 == 'L')
        {
            if (Q.find(a2) == Q.end())
            {
                cout << "ERROR: Not Exist" << endl;
            }
            else
            {
                map<string, string>::iterator it;
                it = Q.find(a2);
                if (it->second == a3)
                {
                    cout << "Login: OK" << endl;
                }
                else
                {
                    cout << "ERROR: Wrong PW" << endl;
                }
            }
        }
    }

    return 0;
}