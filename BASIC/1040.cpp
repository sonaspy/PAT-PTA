// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    int i = 0;
    cin >> a;
    long numT = 0, numAT = 0, numPAT = 0;
    for (i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] == 'T')
            numT++;
        else if (a[i] == 'A')
            numAT = (numAT + numT) % 1000000007;
        else
            numPAT = (numPAT + numAT) % 1000000007;
    }
    cout << numPAT;
    return 0;
}
