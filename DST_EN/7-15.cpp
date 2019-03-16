// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Student
{
    int id = 0, total = 0, score[6] = {-1, -1, -1, -1, -1, -1}, perfect_solved = 0;
};
inline bool cmp(Student a, Student b)
{
    if (a.total == b.total)
        {
            if (a.perfect_solved == b.perfect_solved)
                return a.id < b.id;
            return a.perfect_solved > b.perfect_solved;
        }
    return a.total > b.total;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, M, K, a1, a2, a3;
    cin >> N >> K >> M;
    vector<Student> container;
    int full_score[6], mp[10002][6], f[10002];
    for (int i = 1; i <= K; i++)
        cin >> full_score[i];
    memset(mp, -1, sizeof mp);
    for (int i = 0; i < M; i++)
        {
            cin >> a1 >> a2 >> a3;
            if (a3 > -1)
                f[a1] = 1;
            if (a3 == -1)
                a3 = 0;
            if (a3 > mp[a1][a2])
                mp[a1][a2] = a3;
        }
    for (int i = 1; i <= N; i++)
        {
            struct Student tmp;
            bool flag = false;
            if (!f[i])
                continue;
            tmp.id = i;
            for (int j = 1; j <= K; j++)
                tmp.score[j] = mp[i][j];
            for (int j = 1; j <= K; j++)
                {
                    if (tmp.score[j] != -1)
                        tmp.total += tmp.score[j];
                    if (tmp.score[j] == full_score[j])
                        tmp.perfect_solved++;
                }
            container.push_back(tmp);
        }
    sort(container.begin(), container.end(), cmp);
    for (int i = 0, rank = 1; i < container.size(); i++)
        {
            if (i != 0 && container[i - 1].total != container[i].total)
                rank = i + 1;
            printf("%d %05d %d", rank, container[i].id, container[i].total);
            for (int j = 1; j <= K; j++)
                if (container[i].score[j] != -1)
                    printf(" %d", container[i].score[j]);
                else
                    printf(" -");
            printf("\n");
        }
    return 0;
}