// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <stack>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int M, N, K;
    cin >> M >> N >> K;
    stack<int> S;
    int arr[10000];
    while (K--)
        {
            while (!S.empty())
                S.pop();
            for (int i = 0; i < N; i++)
                cin >> arr[i];
            int cur = 0;
            bool flag = true;
            for (int i = 0; i < N; i++)
                {
                    S.push(i + 1);
                    if (S.size() > M)
                        {
                            flag = false;
                            break;
                        }
                    while (!S.empty() && S.top() == arr[cur])
                        {
                            S.pop();
                            cur++;
                        }
                }
            if(S.empty() && flag)
                printf("YES\n");
            else printf("NO\n");
        }
    return 0;
}