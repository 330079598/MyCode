#include<iostream>
using namespace std;

int main(void)
{
    int T;
    cin>>T;
    int a,b;
    int min = 100000000;
    int sum = 0;
    for(int i = 0;i < 3;i++)
    {
        cin>>a>>b;
        if(T % a == 0)
        {
            sum = b * (T/a);
        }else{
            sum = b*(T / a + 1);
        }
        if( min >  sum || sum == 0)
            min = sum;
    }
    cout<< min;
    return 0;
}
