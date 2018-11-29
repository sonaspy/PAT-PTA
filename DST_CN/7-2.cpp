// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<map>
#include<algorithm>

using namespace std;
typedef map<int,int,greater<int> > MAP;

MAP readInfo(){
    int N, ceof, ex;MAP m;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ceof >> ex;
        m.insert(make_pair(ex,ceof));
    }
    return m;
}
void outPut(MAP m){
    if(m.empty()){
        cout << "0 0";
        cout << endl;
        return;
    }
    MAP::iterator p;
    int flag = 1;
    for(p = m.begin(); p !=m.end(); p++){
        if(flag) cout << p->second << " " << p->first, flag = 0;
        else
            cout << " " << p->second << " " << p->first;
    }
    cout << endl;
}

MAP Multiply(MAP p1, MAP p2){
    MAP m;
    if(p1.empty() || p2.empty())return m;
    MAP::iterator pt1, pt2;
    int coef, ex;
    for(pt1 = p1.begin(); pt1 != p1.end(); pt1++)
        for(pt2 = p2.begin(); pt2 != p2.end(); pt2++){
            coef = (pt1->second) * (pt2->second);
            ex = pt1->first + pt2->first;
            if(m.count(ex)) m[ex] += coef;
            else m.insert(make_pair(ex,coef));
        }
    return m;
}

MAP Add(MAP p1, MAP p2)
{   MAP m;
    if(p1.empty() && p2.empty()) return m;
    if(p1.empty() || p2.empty()){ m = (p1.empty())?p2:p1; return m ;}
    MAP::iterator pt1= p1.begin(), pt2= p2.begin();
    while(pt1 != p1.end() && pt2 != p2.end()){
        if(pt1->first > pt2->first){
            m.insert(*pt1);pt1++;
        }
        else if(pt1->first < pt2->first){
            m.insert(*pt2);pt2++;
        }
        else{
            if(pt1->second + pt2->second)
                m.insert(make_pair(pt1->first, pt1->second+pt2->second));
            pt1++;pt2++;
        }
    }
    if(pt1 != p1.end())
        while(pt1 != p1.end()){
            m.insert(*pt1);
            pt1++;
        }
    if (pt2 != p2.end())
        while (pt2 != p2.end())
        {
            m.insert(*pt2);
            pt2++;
        }
    return m;
}
int main(int argc, char const *argv[])
{
    /* code */
    freopen("in","r",stdin);
    MAP poly1, poly2, mp;
    poly1 = readInfo();
    poly2 = readInfo();
    mp = Multiply(poly1,poly2);
    outPut(mp);
    mp.clear();
    mp = Add(poly1,poly2);
    outPut(mp);
    return 0;
}