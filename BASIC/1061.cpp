// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int s_n, q_n;
    cin >> s_n >> q_n;
    int point[q_n], ans[q_n];
    for (int i = 0; i < q_n; i++)
        cin >> point[i];
    for (int i = 0; i < q_n; i++)
        cin >> ans[i];
    for (int i = 0; i < s_n; i++)
        {
            int sum = 0, my_ans;
            for (int j = 0; j < q_n; j++)
                {
                    cin >> my_ans;
                    if (my_ans == ans[j])
                        sum += point[j];
                }
            cout << sum << endl;
        }
    return 0;
}