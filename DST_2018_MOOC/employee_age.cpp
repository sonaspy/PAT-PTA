#include<iostream>
#include<array>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    vector<int> working_years(51);
    int N, i, years;
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> years;
        working_years[years]++;
    }
    for(i = 0; i < 51; i++){
        if(working_years[i])
            cout << i << ":" << working_years[i] << endl;
    }

    return 0;
}