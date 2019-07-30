#include<iostream>
using namespace std;


int main(void)
{
    string s;
    char p;
    int cnt = 0;
    cin>>s;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] >= '0' && s[i] <= '9')cnt++;
        else{
            p = s[i];
            break;
        }
    }
    int k = cnt - 1;
    while(s[k] == '0' && k > 0) k--;
    for(int i = k;i >= 0;i--)
    {
        cout<<s[i];
    }
    
    if(p == 0)
        return 0;
    else{
        if(p == '%')
        {
            cout<<p;
            return 0;
        }else
            cout<<p;
    }

    int z = s.size() - 1;
    while(s[cnt + 1] == '0'&& z > cnt + 1) cnt ++;
    if(p != '.')
    {
        while(s[z] == '0' && z > cnt + 1) z --;
    }

    for(int i = z;i > cnt;i --)
        cout<<s[i];
    

    return 0;
}
