# An easy problem

**Time Limit: 1000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)Total Submission(s): 34866    Accepted Submission(s): 22558**

Problem Description

we define f(A) = 1, f(a) = -1, f(B) = 2, f(b) = -2, ... f(Z) = 26, f(z) = -26;
Give you a letter x and a number y , you should output the result of y+f(x).

 

Input

On the first line, contains a number T.then T lines follow, each line is a case.each case contains a letter and a number.

 

Output

for each case, you should the result of y+f(x) on a line.

 

Sample Input

```
6
R 1
P 2
G 3
r 1
p 2
g 3
```

 

Sample Output

```
19
18
10
-17
-14
-4
```

- 这个确实简单，我竟然都会写

```c++
#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
	char c;
	int n,k,m,z;
	cin>>n;
	while(n--)
	{
		int sum=0;
		cin>>c>>k;
		if(islower(c))
			z=-(c-96);
		else
			z=(c-64);
		sum=z+k;
		cout<<sum<<endl;
	}
	return 0;
}
//实际代码还可以再精简一下
```

- 如果忘了islower()怎么办？？？

```c++
#include<iostream>
using namespace std;

int main()
{
    int num,y,x;
    char k;
    while(scanf("%d",&num)!=EOF)
    {
        while(num--)
        {
            scanf(" %c%d",&k,&y);
            if(k>='A'&&k<='Z')
                x=k-64;
            else
                x=-(k-96);
            printf("%d\n",x+y);

        }
    }
}
/*注意这种同时输入字符还有数字的题目，一些数字或者空格会被当做字符输入，
导致结果与预想的不一致，可以在%c的前面加上一个空格来过滤掉。*/
```

