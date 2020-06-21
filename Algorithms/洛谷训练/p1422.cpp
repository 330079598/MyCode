#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    double sum = 0;
    int a;
    cin>>a;
    if(a <= 150){
       sum = a * 0.4463;
    }else if(151 <= a && a <= 400){
        sum += 150*0.4463;
        sum += (a-150) * 0.4663;
    }else{
        sum += 150*0.4463;
        sum += (400 - 150) * 0.4663;
        sum += (a - 400) * 0.5663;
    }
    printf("%.1f",sum);
    return 0;
}
