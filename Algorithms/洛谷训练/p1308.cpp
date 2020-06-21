#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
    string a,b,c;
    int sum = 0;
    getline(cin,a);
    getline(cin,b);
    for(int i = 0;i < a.length();i++)
        a[i]=tolower(a[i]);
    for(int i = 0;i < b.length();i++)
        b[i]=tolower(b[i]);
    int pos=0;
    for(int i = 0;i < b.length();i ++)
    {
        for(int j = 0;j < a.length();j++)
        {
            if(b[i] != a[i])
                break;
            if(b[i-1] != ' ')
                break;
            if(j == a.length()-1)
            {
                sum ++;
                if(sum == 1)
                    pos = i;
            }
        }
    }
    if(sum == 0)
        cout<<"-1";
    else
        cout<<sum<<" "<<pos;
    return 0;
}
