// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int a[101], n, b[101], cur = 0, step;
    cin >> n;
    bool is_insert = true;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i < n; i++)
    {
        if (!is_sorted(b, b + i + 1))
        {
            cur = i;
            break;
        }
    }
    for (int j = cur; j < n; j++)
        if (a[j] != b[j])
            is_insert = false;
    cout << (is_insert ? "Insertion Sort" : "Heap Sort") << endl;
    if (is_insert)
        sort(b, b + cur + 1);
    else{
        for(int i = 1; i <n ; i++){
            if(b[i] > b[0]){
                cur = i-1;
                break;
            }
        }
        swap(b[0], b[cur]);
        make_heap(b, b+cur);
    }
    cout << b[0];
    for (int i = 1; i < n; i++)
        printf(" %d", b[i]);
    return 0;
}