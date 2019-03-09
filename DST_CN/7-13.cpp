// author -  newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<map>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int N, age;
    map<int, int> mp;
    map<int ,int>::iterator it;
    cin >> N;
    while(N--){
      scanf("%d",&age);
      if(!mp.count(age)) mp[age] = 1;
      else mp[age] += 1;
    }
    for(it = mp.begin(); it != mp.end();it++){
      printf("%d:%d\n",(*it).first, (*it).second);
    }
    return 0;
}