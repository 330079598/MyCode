#include<iostream>
using namespace std;

int main(void)
{
   int a,sum = 0;
   for(int i = 1;i <= 12;i++)
   {
       sum += 300;
       cin>>a;
       sum -= a;
       if(sum < 0)
       {
           cout<<"-"<<i;
           break;
       }
       int b = sum / 100;
       sum = sum - 100*b;
   }
   cout<<sum*1.2;
   return 0;
}
