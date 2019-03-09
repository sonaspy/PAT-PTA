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
    string s1, s2, s3, s4,
           week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cin >> s1 >> s2 >> s3 >> s4;
    int len = s1.size() > s2.size() ? s2.size() : s1.size();
    bool find1 = false;
    for (int i = 0; i < len; i++)
        {
            if (!find1 && s1[i] >= 'A' && s1[i] <= 'G' && s2[i] >= 'A' && s2[i] <= 'G' && s1[i] == s2[i])
                {
                    find1 = true;
                    cout << week[s1[i] - 'A'] << " ";
                }
            else if (find1 && s1[i] == s2[i])
                {
                    if (s1[i] >= 'A' && s1[i] <= 'N')
                        {
                            cout << s1[i] - 'A' +10 << ":";
                            break;
                        }
                    if (s1[i] >= '0' && s1[i] <= '9')
                        {
                            cout << "0" <<s1[i] - '0' << ":";
                            break;
                        }
                }
        }
    len = s3.size() > s4.size() ? s3.size() : s4.size();
    for (int i = 0; i < len; i++)
        {
            if (s3[i] == s4[i] && isalpha(s3[i]))
                {
                    if(i <= 9)
                        {
                            cout << "0"<< i;
                            break;
                        }
                    else
                        {
                            cout << i;
                            break;
                        }
                }
        }
    return 0;
}