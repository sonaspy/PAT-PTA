// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <map>
#include <string>
#include <cmath>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    string award;
    bool checked = false;
};

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    map<int, Node> mp;
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        struct Node tmp;
        if (i == 1)
        {
            tmp.award = "Mystery Award";
            mp.insert(make_pair(num, tmp));
        }
        else if (isPrime(i))
        {
            tmp.award = "Minion";
            mp.insert(make_pair(num, tmp));
        }
        else
        {
            tmp.award = "Chocolate";
            mp.insert(make_pair(num, tmp));
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        if (mp.count(num) == 0)
            printf("%04d: Are you kidding?\n", num);
        else if (mp[num].checked == false)
        {
            mp[num].checked = true;
            printf("%04d: %s\n", num, mp[num].award.c_str());
        }
        else if (mp[num].checked == true)
            printf("%04d: Checked\n", num);
    }
    return 0;
}