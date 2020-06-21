#include<iostream>
using namespace std;

int main(void)
{
    int a,b,max = 0,day = 0,s;
    for(int i = 1;i < 8;i++)
    {
        cin>>a>>b;
        s = a+b;
        if((s > 8) && (s > max))
        {
            max = s;
            day = i;
        }
    }
    cout<<day;
    return 0;
}
