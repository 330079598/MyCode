#### 题目描述：

Give n non-negative integers, please find the least non-negative integer that doesn’t occur in the n numbers.

#### 输入：

The first line is an integer T, representing the number of test cases.

For each test case:

The first line of each test case is an integer n.

The second line of each test case are $n$ non-negative integers $a_i$.

$$T \leq 10$$

$$n\leq \times 10^5$$

$$ 0\leq a_i < 2^{31}​$$

#### 输出：

or each test case, output a line with the answer.

样例输入

```
2
4
4 0 1 3
2
1 1
```

样例输出

```
2
0
```

- 这个题和和我前两天看的题差不多,都需要排序,所以可以用到C++的stl啦,然后在输出这列数中没有出现的最小非负数.



- 手动去重

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int s[200005];


int main(void){
	int n;
	cin>>n;
	while(n--){
		int z = 0,flag = 0;
		int k;
		cin>>k;
		int s1[k];
		for(int i = 0;i < k;i++)
			cin>>s1[i];
			
		sort(s1,s1+k);
		
		//去重 
		s[z++] = s1[0];
		for(int i = 1;i < k;i++)
		{
			if(s1[i] != s1[i-1])
				s[z++]=s1[i];
		}
		
		for(int i = 0;i < z;i++){
			if(s[i] != i)
			{
				printf("%d\n",i);
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("%d\n",s[k-1]+1);
		
	}	
	return 0;
} 
```





- STL去重

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
	int n;
	cin>>n;
	while(n--){
		int z = 0,flag = 0;
		int k;
		cin>>k;
		int s[k];
		for(int i = 0;i < k;i++)
			cin>>s[i];
			
		sort(s,s+k);
		
		int a = unique(s,s+k) - s;
		
		for(int i = 0;i < a;i++){
			if(s[i] != i)
			{
				printf("%d\n",i);
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("%d\n",s[k-1]+1);
		
	}	
	return 0;
} 
```

