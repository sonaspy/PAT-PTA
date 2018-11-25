// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>


using namespace std;

int GetMergeLength(int *, int);
void MergeOnce(int *, int , int);
bool isMergeSort(int *, int *, int);

int main(int argc, char const *argv[])
{
    /* code */
   // freopen("input.a", "r", stdin);
    int n, i;
    cin >> n;
    int *init = new int [n];
    int *arr = new int[n];
    for(i = 0; i < n; i++)
        cin >> init[i];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    
    if(isMergeSort(init, arr, n)){
        cout << "Merge Sort" << endl;
        MergeOnce(arr, n, GetMergeLength(arr,n));
    }
    else   
        cout << "Insertion Sort" << endl;
    
    cout << arr[0];
    for(i = 1; i < n; i++)
        cout << " " << arr[i];
    delete [] arr;
    delete [] init;
    return 0;
}

int GetMergeLength(int *arr, int n){
    int len, i;
    for(len = 2; len <= n/2; len *= 2){
        for(i = 0; i <= n - 2*len; i += 2*len)
            if(!is_sorted(arr+i, arr+i+2*len))
                return len;
        if(!is_sorted(arr+i, arr+n))
            return len;
    }
    // return n;     //all elements is sorted. maybe error.
}

bool isMergeSort(int *init, int *arr, int n){
    int len = 1,i;
    for( i = 0; i < n - 1; i++){
        if(arr[i] > arr[i+1]){
            len = i + 1;
            break;
        }
    }
    for(int i = len; i < n; i++)
        if(arr[i] != init[i])
            return true;   // is merge.
    sort(arr, arr+len+1); // accomplished next sort for insert.
    return false;
}

void MergeOnce(int *arr, int n, int len){
    int i = 0;
    for(; i < n - 2*len; i += 2 * len)
        sort(arr + i , arr + i + 2 * len);
    sort(arr + i, arr + n);
}