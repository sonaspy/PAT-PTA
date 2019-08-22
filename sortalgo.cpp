// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define SIZE 30000
using namespace std;

template <class T>
inline void HeapSort(T *a, T *b)
{
    int n = b - a;
    make_heap(a, a + n);
    for (int i = n; i > 1; --i)
        pop_heap(a, a + i);
}

template <class T>
void bubbleSort(T *a, T *b)
{ // Bubble largest element in a[0:n-1] to right.
    int n = b - a;
    for (int k = n - 1; k > 0; k--)
    {
        bool swapped = 0;
        for (int i = 0; i < k; i++)
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = 1;
            }
        if (!swapped)
            break;
    }
}
template <class T>
void selectionSort(T *a, T *b)
{ // Sort the n elements a[0:n-1].
    int n = b - a;
    for (int i = n; i > 1; i--)
    {
        int j = max_element(a, a + i) - a;
        swap(a[j], a[i - 1]);
    }
}

template <class T>
static void linear_insert(T *lo, T *hi)
{ // [lo, hi]
    T val = *hi;
    if (val > *(hi - 1))
        return;
    T *pos = val < *lo ? lo : upper_bound(lo, hi, val);
    copy_backward(pos, hi, hi + 1);
    *pos = val;
}
template <class T>
static void insertionSort(T *lo, T *hi)
{ // [lo, hi)
    if (lo != hi)
        for (T *i = lo + 1; i != hi; ++i)
            linear_insert(lo, i);
}

const int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
template <class T>
static void shellSort(T *a, T *b)
{
    int n = b - a;
    int i, j, c, step;
    for (c = 0; Sedgewick[c] >= n; ++c)
        ;

    for (step = Sedgewick[c]; step; step = Sedgewick[++c])
        for (i = step; i < n; ++i)
        {
            T t = a[i];
            for (j = i; step <= j && t < a[j - step]; j -= step)
                a *j = a[j - step];
            a *j = t;
        }
}

template <typename T>
static void __merge(T *list, int left, int mid, int right)
{
    // a temporary array to store merged result
    T merged[right - left + 1];
    int currIter = 0, leftIter = left, rightIter = mid + 1;

    while (leftIter <= mid && rightIter <= right)
        merged[currIter++] = list[leftIter] < list[rightIter] ? list[leftIter++] : list[rightIter++];

    while (leftIter <= mid)
        merged[currIter++] = list[leftIter++];

    while (rightIter <= right)
        merged[currIter++] = list[rightIter++];

    //copying the entire merged array back
    for (int i = 0; i < currIter; ++i)
        list[i + left] = merged[i];
}
//[start, end]
template <typename T>
static void mergeSort(T *list, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(list, start, mid);
        mergeSort(list, mid + 1, end);
        __merge(list, start, mid, end);
    }
}

template <typename T>
static void mergeSort_(T *list, T *b)
{
    int len = 1;
    int n = b - list;
    while (len <= n)
    {
        for (int i = 0; i + len <= n; i += len * 2)
        {
            int lo = i, mid = i + len - 1, hi = i + 2 * len - 1;
            hi = hi > n - 1 ? n - 1 : hi;
            __merge(list, lo, mid, hi);
        }
        len *= 2;
    }
}

#define CUTOFF 100
template <typename T>
static inline T __median3(T *left, T *right)
{
    T *cent = left + (right - left) / 2;
    if (*left > *cent)
        swap(*left, *cent);
    if (*left > *right)
        swap(*left, *right);
    if (*cent > *right)
        swap(*cent, *right);
    swap(*left, *cent);
    return *left;
}
//Partition routine for quicksort
template <typename T>
static T *__partition(T *start, T *end)
{
    T pivot = __median3(start, end);
    T *i = start + 1, *j = end;
    while (i <= j)
    {
        while (i <= end && *i <= pivot)
            ++i;
        while (j >= start && *j > pivot)
            --j;
        if (i < j)
            swap(*i, *j);
    }
    swap(*start, *j);
    return j;
}
//quickSort Routine
template <typename T>
static void quickSort(T *start, T *end)
{
    if (start < end)
    {
        T *pivot = __partition(start, end);
        quickSort(start, pivot - 1);
        quickSort(pivot + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int b[SIZE];
    generate(b, b + SIZE, []() { return rand() % SIZE; });
    clock_t startTime, endTime;

    startTime = clock();

    quickSort(b, b + SIZE);

    endTime = clock();

    cout << is_sorted(b, b + SIZE) << endl;
    cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}