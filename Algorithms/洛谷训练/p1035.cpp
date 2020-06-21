#include<iostream>
using namespace std;

int main(void)
{
    int n,i = 0;
    cin>>n;
    for(double s = 0;s <= n;++i, s+=1.0/i );
    cout<<i;
    return 0;
}
