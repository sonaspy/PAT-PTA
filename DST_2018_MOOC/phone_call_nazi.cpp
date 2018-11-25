#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    unordered_map<string, int> myMap;
    myMap.reserve(n);
    char s[12];
    for (int i(0); i < 2 * n; ++i)
    {
        scanf("%s", s);
        ++myMap[s];
    }

    auto it = myMap.cbegin();
    int num = 1;               //人数
    string minStr = it->first; //最小号码
    int callCnt = it->second;  //呼叫次数
    for (++it; it != myMap.cend(); ++it)
    {
        if (it->second == callCnt)
        {
            ++num;
            if (it->first < minStr)
                minStr = it->first;
        }
        else if (it->second > callCnt)
        {
            num = 1;
            minStr = it->first;
            callCnt = it->second;
        }
    }

    cout << minStr << " " << callCnt;
    if (num > 1)
        cout << " " << num;

    return 0;
}