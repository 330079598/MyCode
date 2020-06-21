#include<iostream>
using namespace std;

int main(void)
{
    long long m,n,sum = 0;
    cin>>m>>n;
    for(int i = 1;i <= n;i++)
    {
        if(m != 6 && m != 7) sum += 250;
        if(m == 7)
            m = 1;
       else
          m ++; 
    }
    cout<<sum;
    return 0;
}
