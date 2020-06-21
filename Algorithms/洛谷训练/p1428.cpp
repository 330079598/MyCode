#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
    int t,m[110],sum[110];
    cin>>t;
    memset(sum,0,sizeof(sum));
    for(int i = 0;i < t;i++)
    {
        cin>>m[i];
    }
    for(int i = 0;i < t;i++)
    {
        for(int j = i;j >= 0;j --)
        {
            if(m[i] > m[j])
            {
                sum[i]++;
            }
        }
    }
    for(int i = 0;i < t;i++)
        cout<<sum[i]<<" ";
    return 0;
}
