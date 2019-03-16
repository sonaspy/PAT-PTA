// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s;
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
        {
            bool hasAlpha = false, hasDigit = false, tailuan = false;
            getline(cin, s);
            if (s.size() < 6)
                {
                    printf("Your password is tai duan le.\n");
                    continue;
                }
            else
                {
                    for (auto iter : s)
                        {
                            if (!isalpha(iter) && iter != '.' && !(iter >= '0' && iter <= '9'))
                                {
                                    cout << "Your password is tai luan le.\n";
                                    tailuan = true;
                                    break;
                                }
                            if (isalpha(iter))
                                hasAlpha = true;
                            else if (iter >= '0' && iter <= '9')
                                hasDigit = true;
                        }
                    if (!tailuan)
                        {
                            if (!hasDigit)
                                printf("Your password needs shu zi.\n");
                            else if (!hasAlpha)
                                printf("Your password needs zi mu.\n");
                            else
                                printf("Your password is wan mei.\n");
                        }
                }
        }
    return 0;
}