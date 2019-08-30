// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <time.h>
#include <string>
#include <unistd.h>
#define test() freopen("in", "r", stdin)

using namespace std;
string replace_all_distinct(string &str1, const string &old_value, const string &new_value)
{
    string str = str1;
    for (string::size_type pos(0); pos != string::npos; pos += new_value.length())
    {
        if ((pos = str.find(old_value, pos)) == string::npos)
            break;
        str.replace(pos, old_value.length(), new_value);
    }
    return str;
}


int main(int argc, char const *argv[])
{
    /* code */

    string s = "huojiandui";
    string news = replace_all_distinct(s,"huo","yytrt");
    cout << news;
    // double start = clock();
    // // Place your codes here...
    // long long count = 0;
    // for (long long i = 0; i < 4999999999; i++)
    //     count++;

    // double ends = clock();

    // cout << "post-self-increment Running Time : " << (double)(ends - start) / CLOCKS_PER_SEC << " s" << endl;

    // start = clock();
    // // Place your codes here...
    // count = 0;
    // for (long long i = 0; i < 4999999999; i++)
    //     ++count;

    // ends = clock();

    // cout << "pre-self-increment Running Time : " << (double)(ends - start) / CLOCKS_PER_SEC << " s" << endl;
    return 0;
}