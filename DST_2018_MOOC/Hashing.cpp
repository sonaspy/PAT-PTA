#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <array>
using namespace std;

int NextPrime(int N)
{
    int i, p;
    if (N == 1)
        return 2;
    p = (N % 2) ? N + 2 : N + 1;
    while (true)
    {
        for (i = (int)sqrt(p); i > 2; i--)
            if (!(p % i))
                break;
        if (i == 2)
            break;
        else
            p += 2;
    }
    return p;
}

int IsPrime(int N)
{
    int i, p;
    if (N == 1)
        return false;
    else
    {
        for (i = 2; i <= (int)sqrt(N); i++)
        {
            if (!(N % i))
                return false;
        }
        return true;
    }
}

array<int, 10005> HashTable = {0};

int main(int argc, char const *argv[])
{
    /* code */
    int size, N, M, key, pos, delay, pervious, i;
    cin >> M >> N;
    if (IsPrime(M))
        size = M;
    else
        size = NextPrime(M);
    for (i = 0; i < N; i++)
    {
        cin >> key;
        pos = key % size;
        delay = 0;
        pervious = pos;
        while (delay < size)
        {
            if (HashTable[pos] == 0)
            {
                HashTable[pos] = key;
                cout << pos;
                break;
            }
            else
            {
                delay++;
                pos = (pervious + delay * delay) % size;
            }
        }
        if (delay == size)
            cout << "-";
        if (i != N - 1)
            cout << " ";
    }
    return 0;
}
