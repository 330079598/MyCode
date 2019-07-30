#include<iostream>
using namespace std;

int main(void)
{
    int a,b,c,d,sum;
    cin>>a>>b>>c>>d;
    int e = c - a;
    int f = d - b;
    if(f < 0)
       {
            f += 60;
            e --;
       }
    cout<<e<<" "<<f;
    return 0;
}
