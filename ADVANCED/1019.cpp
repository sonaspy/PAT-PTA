// author -  newguo@sonaspy.cn
// coding - utf_8

#include<iostream>
#include<string>
#include<vector>
#define test() freopen("in","r",stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> numbers;
    int num, b;
    cin >> num >> b;
    while (num)
        {
            int tmp = num % b;
            num /= b;
            numbers.push_back(tmp);
        }
    bool f = true;
    for(int i = 0; i <= numbers.size()/2; i++)
        if(numbers[i] != numbers[numbers.size()-1 - i]) f = false;
    cout << (f? "Yes":"No") << endl;
    cout << numbers[numbers.size()-1];
    for(int i = numbers.size()-2; i >-1; i--)
        cout << " " << numbers[i];
    return 0;
}