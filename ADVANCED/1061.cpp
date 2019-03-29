// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    string weekday[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"}, s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int cnt1 = 0, cnt2 = 0, si = min(s1.size(), s2.size());
    char first, second, mm, hh;
    for (int i = 0; i < si; i++)
    {
        if (!cnt1 && s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
        {
            cnt1 = 1;
            first = s1[i];
        }
        else if (!cnt2 && cnt1 && s1[i] == s2[i] && ((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N')))
        {
            cnt2 = 1;
            second = s1[i];
        }
    }
    cout << weekday[first-'A'];
    si = min(s3.size(),s4.size());
    hh = (isalpha(second) ? second-'A'+10: second - '0');
    printf(" %02d",hh);
    for(int i = 0; i < si; i++){
        if(s3[i] == s4[i] && isalpha(s3[i])){
            mm = i;
            break;
        }
    }   
    printf(":%02d",mm);
    return 0;
}