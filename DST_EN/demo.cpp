// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <regex>
#include <string>
#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string str1 = "          sigalhu233";

    regex r("\\s{0,1}");
    if (regex_match(str1.begin(), str1.begin() + 3, r))
        cout << "字符串匹配成功！" << endl;
    else
        cout << "字符串匹配失败！" << endl;

    string str = "sigalhu233sigal233hu233";
    smatch sm;

    cout << "正则表达式：([a-z]+)2" << endl;
    for (auto it = str.cbegin(); regex_search(it, str.cend(), sm, regex("([a-z]+)2")); it = sm.suffix().first)
    {
        cout << "字符串：" << &*it << " 匹配成功！" << endl;
        cout << "匹配字符子串个数：" << sm.size() << endl;
        cout << "分别为：";
        for (auto aa : sm)
            cout << aa.str() << " ";
        cout << endl;
        cout << "字符串 " << sm.str() << " 前的字符串为：" << sm.prefix().str() << endl;
        cout << "字符串 " << sm.str() << " 后的字符串为：" << sm.suffix().str() << endl;
        cout << endl;
    }

    return 0;
}
