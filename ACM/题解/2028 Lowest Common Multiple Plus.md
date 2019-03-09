# Lowest Common Multiple Plus

**Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)Total Submission(s): 84178    Accepted Submission(s): 35083**

Problem Description

求n个数的最小公倍数。

 

Input

输入包含多个测试实例，每个测试实例的开始是一个正整数n，然后是n个正整数。

 

Output

为每组测试数据输出它们的最小公倍数，每个测试实例的输出占一行。你可以假设最后的输出是一个32位的整数。

 

Sample Input

```
2 4 6
3 2 5 7
```

 

Sample Output

```
12
70
```

- 分析：先求出前两个数的最大公约数（可以使用辗转相除法），最小公倍数=两数之积/最大公约数，然后继续循环求下面的数的最小公约数

```c++
#include<iostream>
using namespace std;

int main(void)
{
	int i,k;
	int lcy[105],temp,k1,k2;
	while(cin>>k)
	{
		for(int j = 0;j < k;j++)
		{
			cin>>lcy[j];
		}
		for(i = 0;i < k-1;i++)
		{
			k1=lcy[i];
			k2=lcy[i+1];
			while(k1%k2 != 0)
			{
				temp = k1%k2;
				k1 = k2;
				k2 = temp;
			}
			lcy[i+1] = lcy[i]/k2*lcy[i+1];//这里要先除再乘，不然提交答案错误
		}
		cout<<lcy[i]<<endl; 
	}
	return  0;
}
```

