#include<iostream>
using namespace std;

int main(void)
{
    int n,sum = 0,max = 0,tem1 = 0,tem2 = 0;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>tem1;
        if(tem1 >= tem2)
        {
            sum ++;
        }else{
            max = (max > sum) ? max:sum;
            sum = 0;
        }
        tem2 = tem1;
    }
    cout<<max+1;
    return 0;
}
