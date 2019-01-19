// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<map>
#include<string>
#define test() freopen("in","r",stdin)

using namespace std;
map<string, int> Treemap;
map<string, int>::iterator it;

int N;

int main(int argc, char const *argv[])
{
    /* code */
  //test();
    scanf("%d\n",&N);
    for(int i = 0; i < N; i++){
      string treeName;
      getline(cin, treeName);
      if(Treemap.count(treeName))
        Treemap[treeName] += 1;
      else
        Treemap[treeName] = 1;
    }
    double percent;
    for(it = Treemap.begin(); it != Treemap.end(); it++){
      percent = (*it).second /(double) N * 100;
      printf("%s %.4lf%%\n",(*it).first.c_str(), percent);
    }
    return 0; 
}