#include<iostream>
using namespace std;

int main(void)
{
    char a[8],b[8];
    int sum1 = 1,sum2 = 1,i = 0;
    cin>>a>>b;
    while(a[i] != '\0')
    {
        sum1 *= (a[i]-'A'+1);
        i++;
    }
    i = 0;
    while(b[i] != '\0')
    {
        sum2 *= (b[i]-'A'+1);
        i++;
    }
    if(sum1 % 47 == sum2 % 47)
        cout<<"GO";
    else
        cout<<"STAY";
    return 0;
}
