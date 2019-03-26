// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>

#define test() freopen("in", "r", stdin)

using namespace std;

struct Person
{
    char name[9];
    int age, w;
    bool operator<(const Person b) const { return (w != b.w ? w > b.w : age != b.age ? age < b.age : strcmp(name, b.name) < 0); }
};

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, k, a1, a2, m, t_a;
    vector<Person> persons;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        Person tmp;
        scanf("%s %d %d", tmp.name, &tmp.age, &tmp.w);
        persons.push_back(tmp);
    }
    sort(persons.begin(), persons.end());
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d%d", &m, &a1, &a2);
        printf("Case #%d:\n",i);
        int j ,c;
        for(j = 0, c = 0; j < n && c < m;j++){
            t_a = persons[j].age;
            if(t_a <= a2 && t_a >= a1){
                printf("%s %d %d\n",persons[j].name, t_a, persons[j].w);
                c++;
            }
        }
        if(!c)printf("None\n");
    }
    return 0;
}