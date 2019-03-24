// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<vector>
#include<stack>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++)
    {
        int pop_times = 0;
        stack<int> S;
        vector<int> pop_seq(n);
        for (int j = 0; j < n; j++) scanf("%d", &pop_seq[j]);
        for (int j = 1; j <= n; j++)
        {
            S.push(j);
            if (S.size() > m) break;
            while (S.size() && S.top() == pop_seq[pop_times])
            {
                S.pop();
                pop_times++;
            }
        }
        if (pop_times == n)
            printf("YES\n");
        else
            printf("NO\n");
    }//attention
    return 0;
}