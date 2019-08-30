// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <string>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> numbers;
    int num, b, n;
    bool f;
    cin >> num >> b;
    while (num)
    {
        int tmp = num % b;
        num /= b;
        numbers.push_back(tmp);
    }
    f = true, n = numbers.size();
    for (int i = 0; i < n / 2; i++)
        if (numbers[i] != numbers[n - 1 - i])
            f = false;
    cout << (f ? "Yes" : "No") << endl;
    cout << numbers.back();
    for (int i = n - 2; i > -1; i--)
        cout << " " << numbers[i];
    return 0;
}