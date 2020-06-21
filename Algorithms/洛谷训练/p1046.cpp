#include<iostream>
using namespace std;

int main(void)
{
    int m[15];
    for(int i = 0;i < 10;i ++)
    {
        cin>>m[i];
    }
    int n,sum = 0;
    cin>>n;
    n=n+30;
    for(int i = 0;i < 10;i++)
    {
        if(m[i] <= n)
            sum++;
    }
    cout<<sum;
    return 0;
}
