#include <stdio.h>
#include <iostream>
//#include <vector>
#include <windows.h>
#include <cstring>

using namespace std;

int main(){

    string s;
    cout << "input the string: ";
    cin >> s;

    int len = s.length();
    int head=0,tail=0;
    int maxsize = 0;
    bool flag = false;
    string result =  "";
    if(len >= 2 )//仅有长度大于等于2的字符串有回文子串
    {
        for(int i = 0 ; i<len-1 ; ++i)
        {
            if(len - i <= maxsize) break;
            head = tail = i;
            int n = 1;//子串长度
            while(tail < len-1)
            {
                tail++;
                n++;
                flag = true;
                if(s[tail] == s[head])//找到头尾相同的一个子串
                {
                    //n==2和n==3是必回文的
                    for(int j = 1;j <= n/2 - 1;++j)
                    {
                        if(s[head+j] != s[tail-j])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                else flag = false;
                if(flag && n > maxsize)
                {
                    maxsize = n;
                    result = s.substr(head,n);
                }
            }
        }
        if(maxsize == 0)
            cout << s.substr(0,1);
    }
    //else return s;

    else cout << "no";


    cout << result;

    system("pause");
    return 0;
}