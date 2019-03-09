// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<map>
#define test() freopen("in","r",stdin)

using namespace std;

map<long, string> Qdb;
int N;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    char c;
    long id;
    string s;
    cin >> N;
    for(int i = 0; i < N; i++)
        {
            cin >> c >> id >> s;
            switch(c)
                {
                case 'L':
                    if(!Qdb.count(id)) printf("ERROR: Not Exist\n");
                    else if(s != Qdb[id]) printf("ERROR: Wrong PW\n");
                    else printf("Login: OK\n");
                    break;
                case 'N':
                    if(Qdb.count(id)) printf("ERROR: Exist\n");
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