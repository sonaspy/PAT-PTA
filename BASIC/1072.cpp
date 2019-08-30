// author - sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, m, id, sum_stu = 0, sum_g = 0;
    unordered_set<int> st;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        {
            cin >> id;
            st.insert(id);
        }
    for (int i = 0; i < n; i++)
        {
            int num;
            string name;
            cin >> name;
            cin >> num;
            vector<int> v;
            for (int j = 0; j < num; j++)
                {
                    cin >> id;
                    if (st.count(id))
                        v.push_back(id);
                }
            if (v.size() > 0)
                {
                    sum_stu += 1;
                    sum_g += v.size();
                    cout << name << ":";
                    for (auto iter : v)
                        printf(" %04d", iter);
                    printf("\n");
                }
        }
    printf("%d %d", sum_stu, sum_g);
    return 0;
}