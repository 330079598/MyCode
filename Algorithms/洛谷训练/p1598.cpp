#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int maxn = 0,m[26];
int main(void)
{
    string s;

    for(int i = 0;i < 4;i ++)
    {
        getline(cin,s);
        int n = s.length();
        for(int j = 0;j < n;j ++)
        {
            if(s[j] >= 'A' && s[j] <= 'Z')
                m[s[j] - 'A'] ++;
        }
    }

    for(int i = 0;i < 26;i++)
    {
        maxn = max(maxn,m[i]);
    }
    for(int i = maxn;i > 0;i --)
    {
        for(int j = 0;j < 26;j ++)
            if(m[j] >= i)
                cout<<"* ";
            else
                cout<<"  ";
        cout<<endl;
    }
    for(int i = 0;i < 26;i ++)
        cout<<(char)(i+'A')<<" ";

    return 0;
}

