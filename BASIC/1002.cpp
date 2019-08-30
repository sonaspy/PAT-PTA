// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <string>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s, res;
    cin >> s;
    int sum = 0, flag = 1;
    for (auto iter : s)
        sum += iter - 48;
    res = to_string(sum);
    for (auto iter : res)
        {
            switch (iter)
                {
                case '0':
                    if (flag)
                        {
                            flag = 0;
                            cout << "ling";
                        }
                    else
                        cout << " ling";
                    break;
                case '1':
                    if (flag)
                        {
                            flag = 0;
                            cout << "yi";
                        }
                    else
                        cout << " yi";
                    break;
                case '2':
                    if (flag)
                        {
                            flag = 0;
                            cout << "er";
                        }
                    else
                        cout << " er";
                    break;
                case '3':
                    if (flag)
                        {
                            flag = 0;
                            cout << "san";
                        }
                    else
                        cout << " san";
                    break;
                case '4':
                    if (flag)
                        {
                            flag = 0;
                            cout << "si";
                        }
                    else
                        cout << " si";
                    break;
                case '5':
                    if (flag)
                        {
                            flag = 0;
                            cout << "wu";
                        }
                    else
                        cout << " wu";
                    break;
                case '6':
                    if (flag)
                        {
                            flag = 0;
                            cout << "liu";
                        }
                    else
                        cout << " liu";
                    break;
                case '7':
                    if (flag)
                        {
                            flag = 0;
                            cout << "qi";
                        }
                    else
                        cout << " qi";
                    break;
                case '8':
                    if (flag)
                        {
                            flag = 0;
                            cout << "ba";
                        }
                    else
                        cout << " ba";
                    break;
                case '9':
                    if (flag)
                        {
                            flag = 0;
                            cout << "jiu";
                        }
                    else
                        cout << " jiu";
                    break;
                }
        }
    return 0;
}