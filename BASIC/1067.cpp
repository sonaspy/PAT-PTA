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
    string correct, trypwd;
    int n, count = 1;
    cin >> correct >> n;
    getchar();
    while (getline(cin, trypwd), trypwd != "#")
        {
            if (trypwd == correct)
                {
                    printf("Welcome in\n");
                    break;
                }
            else
                printf("Wrong password: %s\n", trypwd.c_str());
            if (count == n)
                {
                    printf("Account locked\n");
                    break;
                }
            count++;
        }
    return 0;
}