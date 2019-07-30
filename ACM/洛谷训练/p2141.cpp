#include<iostream>
using namespace std;

int main(void)
{
    int m[110],d[110];
    int t,sum = 0;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        cin>>m[i];
        d[i] = m[i];
    }
    for(int i = 0;i < t;i++)
        for(int j = i + 1;j < t;j++)
            for(int k = 0;k < t;k++)
            {
                if(d[k] == m[i] + m[j])
                {
                    d[k] = -1;
                    sum ++;
                }
            }
    cout<<sum;
    return 0;
}
