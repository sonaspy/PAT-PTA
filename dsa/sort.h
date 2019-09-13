// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;
#ifndef __NEW_SORT__
#define __NEW_SORT__
namespace newsort
{
template <typename T>
static void HeapSort(T *lo, T *hi)
{
    make_heap(lo, hi);
    for (int i = hi - lo; i > 1; --i)
        pop_heap(lo, lo + i);
}

template <typename T>
static void bubbleSort(T *lo, T *hi)
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

template <typename T>
static void double_bubbleSort(T *lo, T *hi)
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

template <typename T>
static void selectionSort(T *lo, T *hi)
{ // Sort the n elements a[0:n-1].

    T *i, *j;
    for (T *i = hi; i > lo + 1; i--)
    {
        j = max_element(lo, i);
        swap(*j, *(i - 1));
    }
}

template <class T>
T *_lower_bound(T *lo, T *hi, const T &val)
{ // binary search
    int len = hi - lo, half_len;
    T *mid;
    while (len > 0)
    {
        half_len = len >> 1;
        mid = lo + half_len;
        if (*mid < val) // (<=) upperbound
        {
            lo = mid + 1;
            len -= half_len + 1;
        }
        else
            len = half_len;
    }
    return lo;
}
template <class T>
T *_upper_bound(T *lo, T *hi, const T &val)
{ // binary search
    int len = hi - lo, half_len;
    T *mid;
    while (len > 0)
    {
        half_len = len >> 1;
        mid = lo + half_len;
        if (*mid <= val) // (<=) upperbound
        {
            lo = mid + 1;
            len -= half_len + 1;
        }
        else
            len = half_len;
    }
    return lo;
}
template <typename T>
static inline void linear_insert(T *lo, T *hi)
{ // [lo, hi]
    T val = *hi;
    if (val > *(hi - 1))
        return;
    T *pos = val < *lo ? lo : upper_bound(lo, hi, val);
    copy_backward(pos, hi, hi + 1);
    *pos = val;
}
template <typename T>
static void insertionSort(T *lo, T *hi)
{ // [lo, hi)
    if (lo != hi)
        for (T *i = lo + 1; i != hi; ++i)
            linear_insert(lo, i);
}

const int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
template <typename T>
static void shellSort(T *a, T *b)
{
    int n = b - a;
    int i, j, c, increment;
    for (c = 0; n <= Sedgewick[c]; ++c)
        ;

    for (increment = Sedgewick[c]; increment != 0; increment = Sedgewick[++c])
        for (i = increment; i < n; ++i)
        {
            T tmp = a[i];
            for (j = i; increment <= j && a[j - increment] > tmp; j -= increment)
                a[j] = a[j - increment];
            a[j] = tmp;
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

#define CUTOFF 50
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
    T *pre = lo, *post = hi;
    while (pre < post)
    {
        while (pre < post && pivot <= *post)
            post--;
        while (pre < post && *pre <= pivot)
            pre++;
        swap(*pre, *post);
    }
    *pre = pivot;
    return pre;
}
template <typename T>
static void quickSort(T *lo, T *hi)
{
    if (lo < hi)
    {
        T *p = __partition(lo, hi);
        quickSort(lo, p - 1);
        quickSort(p + 1, hi);
    }
}
template <typename T>
static T *findKthMin(T *lo, T *hi, int k)
{
    T *p = __partition(lo, hi);
    int cur = p - lo;
    if (cur == k)
        return p;
    else if (k < cur)
        return findKthMin(lo, p - 1, k);
    else
        return findKthMin(p + 1, hi, k - (cur + 1));
}

template <typename T>
static void partial_k_sort(T *lo, T *hi, int k)
{
    // k < size / 2  sort k max elem to bottom;
    T *walk = hi;
    if (k > hi - lo)
        return;
    make_heap(lo, hi);
    for (; hi - walk < k; walk--)
        pop_heap(lo, walk);
}
template <typename T>
static void partial_k_sort2(T *lo, T *hi, int k)
{
    // k > size / 2  sort k max elem to neck;
    T *walk = lo + k;
    if (k > hi - lo)
        return;
    make_heap(lo, lo + k, greater<int>());
    for (; walk < hi; ++walk)
    {
        if (*walk > *lo)
        {
            //swap(*walk, *lo);
            pop_heap(lo, lo + k, greater<int>());
            swap(*walk, *(lo + k - 1));
            push_heap(lo, lo + k, greater<int>());
        }
    }
}

template <typename T>
static void s_output(T *lo, T *hi)
{
    for (; lo < hi; ++lo)
        cout << *lo << " ";
    cout << endl;
}

/*

1:Build max heap , then call DeletMax for k times.  
O(N + KlogN)
2:Keep a min heap of k elements. Compare a new element with the root and, DeletMin and Insert the
new element (if the new one is larger.)
O(K + NlogK)
3:partition Average = O(N). Worst=O(N2).

*/

template <typename T>
static void tableSort(T *a, T *b)
{
    int n = b - a;
    vector<int> table(n);
    for (int i = 0; i < n; i++)
        table[i] = i;
    for (int i = 1; i < n; i++)
    {
        int tmp = table[i];
        int j;
        for (j = i; 1 <= j && a[tmp] < a[table[j - 1]]; j -= 1)
            table[j] = table[j - 1];
        table[j] = tmp;
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

// template <class Iter>
// void quickSort(Iter* left, Iter* right)
// {
//     if (left >= right)
//         return;
//     Iter *mid = left;
//     mid = partition(left + 1, right, bind2nd(less<int>(), *mid));
//     iter_swap(mid - 1, left);
//     quickSort(left, mid - 1);
//     quickSort(mid, right);
// }
}; // namespace newsort

#endif