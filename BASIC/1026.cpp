// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<cmath>
#include<string>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int c1,c2,t, h, m, s;
    double t1;
    cin >> c1 >> c2;
    t1 = (c2 - c1) / 100.0 + 0.5;
    t = int(t1);
    h = t / 3600;
    m = (t % 3600) / 60;
    s = ((t%3600) % 60);
    string s1,s2,s3;
    s1 = to_string(h);
    s2 = to_string(m);
    s3 = to_string(s);
    if(h < 10) s1 = '0' + s1;
    if(m < 10) s2 = '0' + s2;
    if(s < 10) s3 = '0' + s3;
    cout << s1  << ":" << s2<< ":" << s3;
    return 0;
}