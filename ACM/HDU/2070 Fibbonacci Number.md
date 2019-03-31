# Fibbonacci Number

**Time Limit: 1000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)Total Submission(s): 34498    Accepted Submission(s): 15543**

Problem Description

Your objective for this question is to develop a program which will generate a fibbonacci number. The fibbonacci function is defined as such:

f(0) = 0
f(1) = 1
f(n) = f(n-1) + f(n-2)

Your program should be able to handle values of n in the range 0 to 50.

 

Input

Each test case consists of one integer n in a single line where 0≤n≤50. The input is terminated by -1.

 

Output

Print out the answer in a single line for each test case.

 

Sample Input

```
3
4
5
-1
```

 

Sample Output

```
2
3
5
```
HintNote: 
you can use 64bit integer: __int64


- 对哇，我可以用__int64哇！！！

```c
#include<iostream>

using namespace std;

int main(void)
{
	int n;
	__int64 num[100]={0,1};
	for(int i = 2;i < 51;i++)
		num[i]=num[i-1]+num[i-2];
	while(cin>>n,n != -1)
	{
		cout<<num[n]<<endl;
	}
	return 0;
}
```

