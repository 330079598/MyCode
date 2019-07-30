#include<iostream>
using namespace std;

int main(void)
{
    int w = 0;
    double n,sum = 0,s = 2;
    cin>>n;
    while(n > sum)
    {
        sum += s;
        s=s*0.98;
        w ++ ;
    }
    cout<<w;
    return 0;
}
