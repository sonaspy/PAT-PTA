// author -sonaspy@outlook.com 
// coding - utf_8 

#include<iostream>
#include<deque>
#include<set>

#define test() freopen("in","r",stdin)

using namespace std;

struct Student{
    int id, v_grade, t_grade, total;
    Student(int i, int v, int t, int _t): id(i), v_grade(v), t_grade(t), total(_t){}
    bool  operator<(const Student b)const{return total != b.total? total > b.total : v_grade != b.v_grade? v_grade > b.v_grade :id < b.id;}
};
set<Student> students[4];
deque<Student> ans;
int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, l, h, id, vg, tg;
    cin >> n >> l >> h;
    for(int i = 0; i < n; ++i){
        scanf("%d%d%d", &id, &vg, &tg);
        Student s = Student(id,vg,tg, vg+tg);
        if(vg < l || tg < l)continue;
        else if(h <= vg && h <= tg)
            students[0].insert(s);
        else if(tg < h && h <= vg)
            students[1].insert(s);
        else if(tg <= vg && tg < h && vg < h)
            students[2].insert(s);
        else students[3].insert(s);
    }
    for(int i = 0;i < 4; i++)ans.insert(ans.end(), students[i].begin(), students[i].end());
    printf("%lu\n",ans.size());
    for(auto i: ans)printf("%08d %d %d\n",i.id,i.v_grade, i.t_grade);
    return 0;
}