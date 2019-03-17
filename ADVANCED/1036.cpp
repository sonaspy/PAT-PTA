// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<string>
#define test() freopen("in","r",stdin)
#define INF 99999999
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n, grade, f_grade = -1, m_grade = INF;
    char gender;
    cin >> n;
    string name, id, f_name, m_name, f_id, m_id;
    for(int i = 0; i < n; i++){
        cin >> name >> gender >> id >> grade;
        if(gender == 'F'){
            if(grade > f_grade){
                f_grade = grade;
                f_id = id;
                f_name = name;
            }
        }else{
            if(grade < m_grade){
                m_grade = grade;
                m_name = name;
                m_id = id;
            }
        }
    }
    if(f_grade == -1)cout << "Absent\n";
    else cout << f_name << " " << f_id << endl;
    if(m_grade == INF) cout << "Absent\n";
    else cout << m_name << " " << m_id << endl;
    if(f_grade == -1 || m_grade == INF) cout << "NA";
    else cout << f_grade - m_grade;
    return 0;
}