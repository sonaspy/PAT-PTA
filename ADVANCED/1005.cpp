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
    int sum;
    string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"},
           s, res, ans;
    cin >> s;
    for (auto i : s)
        sum += i - '0';
    res = to_string(sum);
    for (auto i : res)
    {
        int j = i - '0';
        ans += nums[j];
        ans.push_back(' ');
    }
    ans.pop_back();
    cout << ans;
    return 0;
}