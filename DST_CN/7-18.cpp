// author -  newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<queue>
#define test() freopen("in","r",stdin)

using namespace std;

queue<int> QA, QB;
bool first = true;
int numOfClients, clientID, n;

void Enter(){
  cin >> numOfClients;
  while(numOfClients--){
    scanf("%d",&clientID);
    (clientID % 2) ? QA.push(clientID) : QB.push(clientID);
  }
}

void Departure(){
  while(QA.size() >= 2 && !QB.empty()){
    n = 2;
    while(n--){
      clientID = QA.front();QA.pop();
      if(first == true) {printf("%d",clientID); first = false;}
      else printf(" %d",clientID);
    }
    clientID = QB.front();QB.pop();
    printf(" %d",clientID);
  }
  if(QA.empty() && !QB.empty()){
    while(!QB.empty()){
      clientID = QB.front();
    QB.pop();
    if (first == true)
    {
      printf("%d", clientID);
      first = false;
    }
    else
      printf(" %d", clientID);
    }
  }
  if(!QA.empty() && QB.empty()){
    while(!QA.empty()){
      clientID = QA.front();
    QA.pop();
    if (first == true)
    {
      printf("%d", clientID);
      first = false;
    }
    else
      printf(" %d", clientID);
    }
  }
  if(QA.size() == 1 && !QB.empty()){
    clientID = QA.front();
    QA.pop();
    if (first == true)
    {
      printf("%d", clientID);
      first = false;
    }
    else
      printf(" %d", clientID);
    while (!QB.empty())
    {
      clientID = QB.front();
      QB.pop();
      printf(" %d", clientID);
    }
  }
}

int main(int argc, char const *argv[])
{
    /* code */
    test();Enter();Departure();
    return 0;
}