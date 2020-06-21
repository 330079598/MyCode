#include<iostream>
using namespace std;

long long m[110];
int main(void)
{
    long long n,x=0;
    cin>>n;
    while(n != 0)
    {
        m[x]=n;
        cin>>n;
        x++;
    }
    for(int i = x-1;i >= 0;i--)
    {
        cout<<m[i]<<" ";
    }
    return 0;
}
