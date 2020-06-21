#include<iostream>
using namespace std;

int main(void)
{
    int a,b,sum = 0;
    cin>>a>>b;
    for(int i = 1;i <= a;i++)
    {
        int temp = i;
        while(temp != 0)
        {
            int c = temp % 10;
            temp = temp / 10;
            if(c == b)
                sum++;
        }
    }
    cout<<sum;
    return 0;
}
