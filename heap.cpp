// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Heap
{
    // data[1....n] data[0] = INT_MAX
public:
    vector<int> data;
    int size;
    Heap()
    {
        data.push_back(INT_MAX);
        data.resize(101);
        generate(data.begin() + 1, data.end(), []() { return rand() % 100; });
        size = data.size() - 1;
    }
    void push(int val)
    {
        data.push_back(val);
        size = data.size() - 1;
        int i = size;
        for (; data[i / 2] < val; i /= 2)
            data[i] = data[i / 2];
        data[i] = val;
    }
    void percDown(int pos)
    {
        int val = data[pos], up = pos, down = 2 * pos;
        for (; down <= size; up = down, down *= 2)
        {
            if (down < size && data[down] < data[down + 1])
                ++down;
            if (data[down] <= val)
                break;
            data[up] = data[down];
        }
        data[up] = val;
    }
    void pop()
    {
        if (size == 1)
            return;
        data[1] = data.back();
        data.pop_back();
        size = data.size() - 1;
        percDown(1);
    }
    void buildHeap()
    {
        int i;
        for (i = size / 2; i; --i)
            percDown(i);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}