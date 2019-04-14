# Max Num

**Time Limit: 1000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)Total Submission(s): 32729    Accepted Submission(s): 18619**

Problem Description

There are some students in a class, Can you help teacher find the highest student .

 

Input

There are some cases. The first line contains an integer t, indicate the cases; Each case have an integer n ( 1 ≤ n ≤ 100 ) , followed n students’ height.

 

Output

For each case output the highest height, the height to two decimal plases;

 

Sample Input

```
2
3 170.00 165.00 180.00
4 165.00 182.00 172.00 160.00
```

 

Sample Output

```
180.00
182.00
```



```c
#include<iostream>

using namespace std;

int main(void)
{
	int n;
	int k;
	double a,max;
	cin>>n;
	while(n--)
	{
		cin>>k;
		for(int i = 1;i <= k;i ++)
		{
			cin>>a;
			if(i == 1)
				max = a;
			else
			{
				if(a > max)
					max = a;
			}
		}
		printf("%.2f\n",max);
	}
	return 0;
}
```





- 数组

```c
#include<iostream>

using namespace std;

int main(void)
{
	int n;
	int k;
	double s[105],max;
	cin>>n;
	while(n--)
	{
		cin>>k;
		for(int i = 0;i < k;i ++){
			cin>>s[i];
		}
		max = s[0];
		for(int i = 1;i < k;i ++)
		{
			if(max < s[i])
				max= s[i];
		}
		printf("%.2f\n",max);
	}
	return 0;
}
```

