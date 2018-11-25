#include<iostream>
using namespace std;

template <class T>
void quickSort(T a[], int left, int right){
    // Sort a[left:right], a[right+1] >= a[left:right].
    if(left >= right)
        return;
    int leftCursor = left;
    int RightCurosr = right + 1;
    T pivot = a[left];
    while(true){
        while(a[++leftCursor] < pivot);
        while(a[--RightCurosr] > pivot);
        if(leftCursor >= RightCurosr)
            break;
        else
            swap(a[leftCursor],a[RightCurosr]);
    }
    swap(a[RightCurosr],a[left]);
    
    quickSort(a, left, RightCurosr-1);
    quickSort(a, RightCurosr+1, right);
}

template <class T>
void quickSort_extern(T a[], int n)
{ // Sort a[0 : n - 1] using the quick sort method.
    if (n <= 1)
        return;
    // move largest element to right end
    int max = indexOfMax(a, n);
    swap(a[n - 1], a[max]);
    quickSort(a, 0, n - 2);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
