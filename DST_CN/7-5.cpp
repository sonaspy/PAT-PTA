// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    freopen("in","r",stdin);
    int N, M, idx,var, flag;
    cin >> N  >> M;
    vector<int> __minHeap(N);
    for(int i = 0; i < N; i++){
      cin >> __minHeap[i];
      make_heap(__minHeap.begin(),__minHeap.begin()+i+1,greater<int>());
    }
    while(M--){
      flag = 1;
      cin >> idx; idx--;
      while(true){
          if(flag){
            cout << __minHeap[idx];
            flag = 0;
        }
        else
          cout << " " << __minHeap[idx];
        if(idx == 0) break;
        idx = (idx-1)/2;
      }
      cout << endl;
    }
    return 0;
}