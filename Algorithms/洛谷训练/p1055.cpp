#include<iostream>
using namespace std;

int main(void)
{
    char a[13];
    int sum = 0,m = 1;
    cin>>a;
    for(int i = 0;i <= 10;i++)
    {
        if(a[i] == '-')
            continue;
        sum += (m++)*(a[i]-'0');
    }
    int k = a[12]-'0';
    if(sum % 11 <= 9)
    {
        if(sum % 11 == k)
        {
            cout<<"Right";
        }else{
            for(int i = 0;i < 12;i++)
                cout<<a[i];
            if((sum % 11) == 10)
                cout<<"X";
            else
                cout<<sum%11;
        }
    }else
    {
        if(a[12] == 'X' && sum %11 == 10)
            cout<<"Right";
        else{
            for(int i = 0;i < 12;i++)
                cout<<a[i];
            cout<<"X";
        }
    }
    return 0;
}
