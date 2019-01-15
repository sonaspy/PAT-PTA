// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <set>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n, tmp, flag = 1;
    set<int, greater<int> > a, b;
    cin >> n;
    for (int i = 0; i < n; i++){
        scanf("%d", &tmp);
        a.insert(tmp);
        b.insert(tmp);
    }
    for (auto iter: a)
    {
        int num = iter ;
        while (num != 1)
        {
            if (num % 2)
                num = (3 * num + 1) / 2;
            else
                num /= 2;
            if(a.count(num)) b.erase(num);
        }
    }
    for(auto iter : b){
        if(flag) {printf("%d",iter); flag = 0;}
        else printf(" %d",iter);
    }


    return 0;
}