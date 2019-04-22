# icebound的商店
时间限制: 1 Sec  内存限制: 64 MB

题目描述

icebound在得到神殿的宝藏之后，开了一家神秘的商店。你来到了商店，发现慷慨的icebound搞了T次促销活动。在每 次促销活动中，icebound都会想出一个他喜欢的数字，如果你买的商品的总价刚好等于icebound喜欢的数字，那么你就 可以免费得到这些商品。
icebound的商店里一共有15件商品，商品的价格和这家商店一样神秘，第一件商品的价格是1元，第二件商品的价格 是2元，设第n件商品的价格为wn元，则：wn = wn−1 + wn−2(3 ≤ n ≤ 15)。
如果在某次活动中icebound喜欢的数字是 4，那么共有 4 种购买方案：

1. 买4个 第一种商品  
2. 买4个 第一种商品 和1个 第二种商品  
3. 买2个 第二种商品  
4. 买1个 第一种商品 和1个 第三种商品  
请你算出共有多少种方案可以免费购物，方案数对1000000009(109+9)取模。

输入

第一行给出一个整数T，表示icebound搞了T次活动。
接下来的T行每行给出一个正整数 x，表示在这次活动中icebound喜欢的数字。
(1 ≤ T ≤ 3000, 1 ≤ x ≤ 3000)

输出

输出T行，每行输出一个正整数。
第i行的正整数表示在第i 次活动中免费购物的方案数，方案数对1000000009(109+9)取模。

样例输入

3
5
20
30
样例输出

6
134
- 题解:
  - dp动态规划类型,类似于完全背包....

```c++
#include<iostream>
#include<cstring>
using namespace std;

const int mod = 1e9+9;
const int N = 1e5+9;
int f[N],n,m;
int dp[N];

void init(){
	f[1]=1;
	f[2]=2;
	for(int i = 3;i <=15;i++)
		f[i]=f[i-1]+f[i-2];
} 

int main(void){
	init();
	int t;
	cin>>t;
	while(t--){
		cin>>m;
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i = 1;i <= 15;i ++){
			for(int j = f[i];j <= m;j++)
				dp[j]=(dp[j]%mod+dp[j-f[i]]%mod)%mod;
		}
		cout<<dp[m]<<endl;
	}
	
	return 0;
}
```

