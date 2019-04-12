// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string buy, shop;
    cin >> shop >> buy;
    unordered_map<char, int> mp;
    for (auto i : buy)
        mp[i]++;
    for (auto i : shop)
    {
        if (mp.count(i))
        {
            if (mp[i] > 0)
                mp[i]--;
            if (mp[i] == 0)
                mp.erase(i);
        }
    }
    if (mp.empty())
        cout << "Yes " << shop.size() - buy.size();
    else{
        int sum = 0;
        for(auto i : mp)
            sum += i.second;
        cout << "No " << sum;
    }
    return 0;
}