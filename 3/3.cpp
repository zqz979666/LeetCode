#include <stdio.h>
#include <iostream>
//#include <vector>
#include <windows.h>
#include <cstring>

using namespace std;

int main()
{
    string str;
    string tmp;
    cout << "please enter the string:";
    cin >> str;
    int maxsize = 0;
    int n = 0;
    size_t pos;
    for(int i = 0 ;i < str.size() ; ++i)
    {
        pos = tmp.find(str[i]);
        if(pos == tmp.npos)//没有找到重复字符，则添加到tmp，长度加一
        {
            tmp.push_back(str[i]);
            ++n;
            maxsize = maxsize > n ? maxsize : n;
        }
        if(pos != tmp.npos)//找到重复字符，则放弃当前子串，改变i的值,清空tmp
        {
            i = i - n;//注意这里不要直接计算为i的下一个值，因为for循环体中还会再加一
            n = 0;
            if(i + maxsize >= str.size())//如果后面的子串长度不比maxsize大，则无需再检查
                break;
            tmp = "";//把tmp放在最后，方便保存
        }
    }
    cout << "maxsize: " << maxsize << endl;
    cout << "the longest substr: " << tmp << endl;
    system("pause");
    return 0;
}

