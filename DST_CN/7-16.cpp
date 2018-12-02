// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<vector>
#include<algorithm>
#define test() freopen("in","r",stdin)

using namespace std;

struct numpair{
  int ex, coef;
  bool operator<(const numpair p2) const{
    return ex > p2.ex;
  }
};

vector<numpair> ex_coef;
vector<numpair> res;
numpair num;
void Build(){
  while(true){
    scanf("%d%d",&num.coef,&num.ex);
    if(!num.ex)break;
    ex_coef.push_back(num);
  }
}
void diff(){
  sort(ex_coef.begin(), ex_coef.end());
  for(int i = 0; i < ex_coef.size(); i++){
    num.ex = ex_coef[i].ex - 1;
    num.coef = ex_coef[i].ex * ex_coef[i].coef;
    res.push_back(num);
  }
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    Build();
    diff();
    if(!res.empty()){
      cout << res[0].coef << " " << res[0].ex;
    for(int i = 1; i < res.size(); i++){
      printf(" %d %d",res[i].coef,res[i].ex);
      }
    }
    else
      cout << 0 << " " << 0;
    
    return 0;
}