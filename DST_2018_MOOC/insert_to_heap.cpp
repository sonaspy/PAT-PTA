#include <iostream>
#include <algorithm>
using namespace std;

bool isHeapSort(int *init, int *arr, int n);
int getNextHeapSortIndex(int *arr, int n);
void heapSortOnce(int *arr, int index);

int main(void)
{
    int n;
    cin >> n;
    int *init = new int[n];
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> init[i];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    if (isHeapSort(init, arr, n))
    {
        cout << "Heap Sort" << endl;
        heapSortOnce(arr, getNextHeapSortIndex(arr, n));
    }
    else
        cout << "Insertion Sort" << endl;

    cout << arr[0];
    for (int i = 1; i < n; ++i)
        cout << " " << arr[i];

    delete[] init;
    delete[] arr;
    return 0;
}

/*
 * 1. 从前面找第一个反序的元素索引 -> 有序子列元素个数。
 * 2. 判断从该索引开始，是否与原始数列一致。若一致，是插入排序。
*/
bool isHeapSort(int *init, int *arr, int n)
{
    int len = 1; //记录插入排序中，有序子列的个数。
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            len = i + 1;
            break;
        }
    }

    for (int i = len; i < n; ++i)
        if (arr[i] != init[i])
            return true;

    sort(arr, arr + len + 1); //若是插入排序，直接在这里完成下一趟插入。
    return false;
}

//返回下一次进行堆排序操作的元素的下标。
int getNextHeapSortIndex(int *arr, int n)
{
    int heap = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > heap)
            return i - 1;
    }
    return n - 1; //最大堆，未排序。
}

void heapSortOnce(int *arr, int index)
{
    swap(arr[0], arr[index]);
    int size = index - 1;
    //下滤。
    int tmp = arr[0];
    int parent = 0;
    int child;
    for (; parent * 2 + 1 <= size; parent = child)
    {
        child = parent * 2 + 1;
        if (child < size && arr[child] < arr[child + 1])
            ++child;

        if (tmp > arr[child])
            break;
        else
            arr[parent] = arr[child];
    }
    arr[parent] = tmp;
}