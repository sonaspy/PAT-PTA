// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<string>
#include<vector>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n,shuffle[100];
    string C="SHCDJ";
    vector<string> origin(54), res(54);
    cin >> n;
    for(int i = 0;i < 54;i++){
        string tp;
        cin >> shuffle[i];
        --shuffle[i];
        tp.push_back(C[i/13]);
        tp += to_string(i%13+1);
        origin[i] = tp;
    }
    res = origin;
    for(int i = 0;i <n;i++){
        origin = res;
        for(int j = 0; j < 54; j++)
            res[shuffle[j]] = origin[j];
    }
    cout << res[0];
    for(int i = 1;i < 54;i++)
        cout << " " <<res[i];





    return 0;
}