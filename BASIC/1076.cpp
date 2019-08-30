// author - sonaspy@outlook.com
// coding - utf_8

#include<iostream>
#include<string>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++)
        {
            string s;
            for(int j = 0; j < 4; j++)
                {
                    cin >> s;
                    if(s == "A-T")
                        printf("1");
                    else if(s == "B-T")
                        printf("2");
                    else if (s == "C-T")
                        printf("3");
                    else if (s == "D-T")
                        printf("4");
                }
        }
    return 0;
}