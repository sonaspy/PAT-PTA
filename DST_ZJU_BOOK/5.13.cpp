// author -  newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;

struct Node
{
    string word;
    int times = 0;
    bool operator<(const struct Node b) const
    {
        if (times == b.times)
            return word < b.word;
        return times > b.times;
    }
};
void resolve(unordered_map<string, int> &mp, string &s)
{
    for (int i = 0; i < s.size(); i++)
        {
            string word;
            while ((isdigit(s[i]) || isalpha(s[i]) || s[i] == '_') && i < s.size())
                word.push_back(tolower(s[i++]));
            if (word.size())
                {
                    if(word.size()> 15)
                        word = word.substr(0,15);
                    mp[word]++;
                }
        }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    unordered_map<string, int> mp;
    vector<Node> list;
    string s;
    getline(cin, s);
    while (true)
        {
            resolve(mp, s);
            if (s.back() == '#')
                break;
            getline(cin, s);
        }
    for (auto i : mp)
        {
            Node tmp;
            tmp.word = i.first, tmp.times = i.second;
            list.push_back(tmp);
        }
    sort(list.begin(), list.end());
    int num = list.size()/10;
    cout << list.size() << endl;
    for(int i = 0; i < num; i++)
        cout << list[i].times << ":" << list[i].word << endl;
    return 0;
}