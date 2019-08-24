// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
#define SIZE 30000
using namespace std;

template <class T>
inline void HeapSort(T *lo, T *hi)
{
    make_heap(lo, hi);
    sort_heap(lo, hi);
    // for (int i = n; i > 1; --i)
    //     pop_heap(a, a + i);
}

template <class T>
void bubbleSort(T *lo, T *hi)
{ // Bubble largest element in a[0:n-1] to hi.
    T *i, *k;
    for (k = hi - 1; k > lo; k--)
    {
        bool swapped = 0;
        for (i = lo; i < k; i++)
            if (*i > *(i + 1))
            {
                swap(*i, *(i + 1));
                swapped = 1;
            }
        if (!swapped)
            break;
    }
}

template <class T>
void double_bubbleSort(T *lo, T *hi)
{ // Bubble largest element in a[0:n-1] to hi.
    bool flag = true;
    hi--;
    T *i;
    while (lo < hi && flag)
    {
        flag = false;
        for (i = lo; i < hi; ++i)
            if (*i > *(i + 1))
                swap(*i, *(i + 1)), flag = true;
        hi--;
        for (i = hi; i > lo; --i)
            if (*i < *(i - 1))
                swap(*i, *(i - 1)), flag = true;
        lo++;
    }
}

template <class T>
void selectionSort(T *lo, T *hi)
{ // Sort the n elements a[0:n-1].

    T *i, *j;
    for (T *i = hi; i > lo + 1; i--)
    {
        j = max_element(lo, i);
        swap(*j, *(i - 1));
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
                a[j] = a[j - step];
            a[j] = t;
        }
}

template <typename T>
static void __merge(T *lo, T *mid, T *hi)
{
    // a temporary array to store merged result
    T merged[hi - lo + 1], *i = lo, *j = mid + 1;
    int cur = 0;

    while (i <= mid && j <= hi)
        merged[cur++] = *i < *j ? *(i++) : *(j++);

    while (i <= mid)
        merged[cur++] = *(i++);

    while (j <= hi)
        merged[cur++] = *(j++);

    //copying the entire merged array back
    for (int i = 0; i < cur; ++i)
        *(lo++) = merged[i];
}
//[lo, hi]
template <typename T>
static void mergeSort(T *lo, T *hi)
{
    if (lo < hi)
    {
        T *mid = lo + (hi - lo) / 2;
        mergeSort(lo, mid);
        mergeSort(mid + 1, hi);
        __merge(lo, mid, hi);
    }
}

template <typename T>
static void mergeSort_(T *arr, T *b)
{
    int len = 1, n = b - arr;
    while (len <= n)
    {
        for (int i = 0; i + len <= n; i += len * 2)
        {
            int lo = i, mid = i + len - 1, hi = i + 2 * len - 1;
            hi = hi > n - 1 ? n - 1 : hi;
            __merge(arr + lo, arr + mid, arr + hi);
        }
        len *= 2;
    }
}

#define CUTOFF 100
template <typename T>
static inline T __median3(T *lo, T *hi)
{
    T *mid = lo + (hi - lo) / 2;
    if (*lo > *mid)
        swap(*lo, *mid);
    if (*lo > *hi)
        swap(*lo, *hi);
    if (*mid > *hi)
        swap(*mid, *hi);
    swap(*lo, *mid);
    return *lo;
}
//Partition routine for quicksort
template <typename T>
static T *__partition(T *lo, T *hi)
{
    T pivot = __median3(lo, hi);
    T *i = lo, *j = hi;
    while (i < j)
    {
        while (i < j && *j >= pivot)
            j--;
        *i = i < j ? *j : *i;
        while (i < j && *i <= pivot)
            i++;
        *j = i < j ? *i : *j;
    }
    *i = pivot;
    return i;
}
//quickSort Routine
template <typename T>
static void quickSort(T *lo, T *hi)
{
    if (lo < hi)
    {
        T *pivot = __partition(lo, hi);
        quickSort(lo, pivot - 1);
        quickSort(pivot + 1, hi);
    }
}

template <typename T>
static void tableSort(T *a, T *b)
{
    int n = b - a;
    vector<int> table(n);
    for (int i = 0; i < n; i++)
        table[i] = i;
    for (int i = 1; i < n; i++)
    {
        int t = table[i];
        int j;
        for (j = i; 1 <= j && a[t] < a[table[j - 1]]; j -= 1)
            table[j] = table[j - 1];
        table[j] = t;
    }
    for (int i = 0; i < n; i++)
    {
        T val = a[i];
        int j = i, last = i, next;
        for (; table[j] != j; j = next)
        {
            last = j;
            next = table[j];
            a[j] = a[table[j]];
            table[j] = j;
        }
        a[last] = val;
    }
}

int findKthMin(int *lo, int *hi, int k)
{
    int *p = __partition(lo, hi);
    int len = p - lo;
    if (len == k)
        return *p;
    else if (len > k)
        return findKthMin(lo, p - 1, k);
    else
        return findKthMin(p + 1, hi, k - len - 1);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, []() { return rand() % SIZE; });
    clock_t startTime, endTime;

    startTime = clock();

    cout << findKthMin(b, b + SIZE, 200) << endl;
    
    endTime = clock();

    cout << is_sorted(b, b + SIZE) << endl;
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}