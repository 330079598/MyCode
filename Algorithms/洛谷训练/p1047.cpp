#include<iostream>
#include<cstring>
using namespace std;

int map[10010];

int main(void)
{
    int sum = 0,m,n;
    cin>>m>>n;
    memset(map,0,sizeof(map));

    for(int i = 0;i <= m;i++)
    {
        map[i] = 1;
    }
    
    for(int i = 0;i < n;i++)
    {
        int head,tail;
        cin>>head>>tail;
        for(int j = head;j <= tail;j++)
            map[j] = 0;
    }

    for(int i = 0;i <= m;i++)
        if(map[i] == 1)
            sum++;

    cout<<sum<<endl;
    return 0;
}
