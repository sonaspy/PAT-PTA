// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>
#define test() freopen("in", "r", stdin)
#define SIZE 2000
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(INT_MIN), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
};
double myPow(double x, int n)
{
    long long N = n;
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }
    double ans = 1;
    double cur = x;
    for (long long i = N; i; i /= 2)
    {
        if ((i % 2) == 1)
            ans *= cur;
        cur *= cur;
    }
    return ans;
}

double polynomial(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i; --i)
        p = a[i - 1] + x * p;
    return p;
}

// find median in 2 array
template <class T>
T M_search(T *lo1, T *hi1, T *lo2, T *hi2)
{
    T *m1, *m2;
    while (lo1 < hi1 || lo2 < hi2)
    {
        m1 = lo1 + (hi1 - lo1) / 2;
        m2 = lo2 + (hi2 - lo2) / 2;
        if (*m1 == *m2)
            return *m1;
        if (*m1 < *m2)
        {
            lo1 = (hi1 - lo1) % 2 ? m1 + 1 : m1;
            hi2 = m2;
        }
        else
        {
            lo2 = (hi2 - lo2) % 2 ? m2 + 1 : m2;
            hi1 = m1;
        }
    }
    return min(*lo1, *lo2);
}

template <class T>
bool isparlindrome(T lo, T hi)
{
    if (lo < hi)
        for (; lo < --hi; ++lo)
            if (*lo != *hi)
                return false;
    return true;
}

template <class T>
bool reverse_(T lo, T hi)
{
    if (lo < hi)
        for (; lo < --hi; ++lo)
            swap(*lo, *hi);
}

template <class T>
bool list_move(T *lo, T *hi, int offset, bool left)
{
    if (lo < hi)
    {
        reverse(lo, hi);
        if (left)
        {
            reverse(lo, hi - offset);
            reverse(hi - offset, hi);
        }
        else
        {
            reverse(lo, lo + offset);
            reverse(lo + offset, hi);
        }
        return true;
    }
    return false;
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
T *bin_search(T *lo, T *hi, const T &val)
{
    T *mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (*mid < val)
            lo = mid + 1;
        else if (val < *mid)
            hi = mid - 1;
        else
            return mid;
    }
    return hi;
}

bool isMatch(vector<int> &push_seq, vector<int> &pop_seq, int capacity)
{
    int walk = 0;
    stack<int> s;
    for (int j = 0; j < push_seq.size(); j++)
    {
        s.push(push_seq[j]);
        if (s.size() > capacity)
            break;
        while (s.size() && s.top() == pop_seq[walk])
            s.pop(), walk++;
    }
    return walk == capacity;
}

static void _merge_list(ListNode *l1, ListNode *l2, ListNode *&l)
{ // 2 increasing order list merge to a new increasing order list. in-place (rear insert)
    ListNode *p = l1->next, *q = l2->next, *r;
    l = l1;
    l->next = nullptr;
    delete l2;
    r = l;
    while (p && q)
    {
        p->val <= q->val ? r->next = p, p = p->next : r->next = q, q = q->next;
        r = r->next;
    }
    r->next = p ? p : q;
}
#define HEAD_INSERT(L, walk) \
    walk->next = L->next;    \
    L->next = walk
static void _merge_list2(ListNode *l1, ListNode *l2, ListNode *&l)
{ // 2 increasing order list merge to a new decreasing order list. in-place (head insert)
    ListNode *p = l1->next, *q = l2->next, *h;
    l = l1;
    l->next = nullptr;
    delete l2;
    while (p && q)
    {
        p->val <= q->val ? h = p, p = p->next : h = q, q = q->next;
        HEAD_INSERT(l, h);
    }
    while (p)
    {
        h = p, p = p->next;
        HEAD_INSERT(l, h);
    }
    while (q)
    {
        h = q, q = q->next;
        HEAD_INSERT(l, h);
    }
}
void reverse_List(ListNode *L)
{
    ListNode *walk, *post;
    walk = L->next;
    L->next = NULL;
    while (walk)
    {
        post = walk->next;
        HEAD_INSERT(L, walk);
        walk = post;
    }
}

template <class T>
void unique_sorted_list(T *lo, T *hi)
{
    T *i = lo, *j = lo + 1;
    for (; j < hi; ++j)
        if (*i != *j)
            *(++i) = *j;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE] = {1, 3, 5, 7, 9, 11};
    int a[SIZE] = {2, 4, 6, 8, 10};
    clock_t startTime, endTime;
    //iota(b, b + SIZE, 0);
    startTime = clock();
    cout << M_search(b, b + 5, a, a + 4) << endl;
    endTime = clock();

    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}