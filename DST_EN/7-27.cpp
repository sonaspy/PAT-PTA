// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <unordered_map>
#include <string>
#define test() freopen("in", "r", stdin)
#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    unordered_map<string, string> mp;
    int n;
    string passwd,id;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cin >> c >> id >> passwd;
            if (c == 'L')
                {
                    if (!mp.count(id))
                        printf("ERROR: Account Not Exist\n");
                    else if (mp[id] != passwd)
                        printf("ERROR: Wrong Password\n");
                    else
                        printf("Log in Successful\n");
                }
            else
                {
                    if (mp.count(id))
                        printf("ERROR: Account Number Already Exists\n");
                    else
                        {
                            printf("Register Successful\n");
                            mp[id] = passwd;
                        }
                }
        }
    return 0;
}