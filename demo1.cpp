// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

template <class T>
inline void HeapSort(T *a, int n)
{
    make_heap(a, a + n);
    for (int i = n; i > 1; --i)
        pop_heap(a, a + i);
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
static void mergeSort_(T *list, int first, int last)
{
    int len = 1, n = last - first + 1;
    while (len <= n)
    {
        for (int i = 0; i + len <= n; i += len * 2)
        {
            int low = i, mid = i + len - 1, high = i + 2 * len - 1;
            high = high > last ? last : high;
            __merge(list, low, mid, high);
        }
        len *= 2;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int b[100];
    generate(b, b + 100, []() { return rand() % 10; });
    mergeSort_<int>(b, 0, 99);
    copy(b, b + 100, ostream_iterator<int>(cout, "\n"));
    return 0;
}