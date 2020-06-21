给定一张 n 个点的带权无向图，点从 0~n-1 标号，求起点 0 到终点 n-1 的最短Hamilton路径。 Hamilton路径的定义是从 0 到 n-1 不重不漏地经过每个点恰好一次。

#### 输入格式

第一行输入整数n。

接下来n行每行n个整数，其中第ii行第jj个整数表示点ii到jj的距离（记为a[i,j]）。

对于任意的x,y,z，数据保证 a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]>=a[x,z]。

#### 输出格式

输出一个整数，表示最短Hamilton路径的长度。

#### 数据范围

1≤n≤20
0≤a[i,j]≤10^7

#### 输入样例：

```
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0
```

#### 输出样例：

```
18
```

- 题解:

记录当前最优解,就是考虑当前的状态.

状态转移方程:

```c++
f[i][j] = min(f[i][j],f[i-(1<<j)][h] + weight[h][j])
 //或者这里也可以用异或操作
 f[i][j] = min(f[i][j],f[i^(1<<j)][h] + weight[h][j])
```

- 源码:

```c++
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 20, M = 1 << 20;
int dp[M][N],weight[N][N];
int n;

int main(void){
    cin>>n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n ;j++)
            cin>>weight[i][j];
    /**
	memset是按照字节填充,即8位一填充，所以所填充的数要属于[0-255],
	按此逻辑填充每个字节均为0x3f=63=00111111,所以每个数都被填充成0x3f3f3f3f=1,061,109,567 
	如果填充成255，那么数字就会变成-1,如果填充成127,那么inf+inf就会变成负数，因此填充63=0x3f
    */
    memset(dp,0x3f,sizeof dp);
    
    dp[1][0]=0;//第一个的状态为1,并且是从0开始,所以是[1][0]
    for(int i = 0;i < 1<<n;i++)
        for(int j = 0;j < n;j++)
            if(i >> j & 1){
                for(int h = 0;h < n;h++)
                    if(i - (1 << j) >> h & 1)//i-(1<<j)是除去j的集合i
                        //dp[i][j]的最短路径(再次重点：此时是以j为最终节点)应该是从其所有子集中，所有其他节点到达j点的最小值
                        //例如 i = 01011 j = 3 表示dp[i][j]已经遍历过了0、1、3号节点,并且以3为终点
                        //那么dp[11][3]=dp[3][0]和dp[3][1]和INF中的最小值
                        dp[i][j] = min(dp[i][j],dp[i-(1<<j)][h]+weight[h][j]);//状态转移方程.
            }
    	//输出已经遍历所有的城市,并且终点在n-1的最短路.
        cout<<dp[(1<<n) - 1][n-1]<<endl;
        return 0;
}
```

