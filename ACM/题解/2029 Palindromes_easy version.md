# Palindromes _easy version

**Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)Total Submission(s): 57885    Accepted Submission(s): 35067**

Problem Description

“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。请写一个程序判断读入的字符串是否是“回文”。

 

Input

输入包含多个测试实例，输入数据的第一行是一个正整数n,表示测试实例的个数，后面紧跟着是n个字符串。

 

Output

如果一个字符串是回文串，则输出"yes",否则输出"no".

 

Sample Input

```txt
4
level
abcde
noon
haha
```

 

Sample Output

```txt
yes
no
yes
no
```

- 直接代码：
- 方法一：

```c++
#include<iostream>
#include<string.h>
using namespace std;

int main(void) {
	int n;
	char s[100];
	cin>>n;
	getchar();
	while(n--) {
		gets(s);
		bool k = true;
		int i = 0;
		int j = strlen(s)-1;
		for(; i <= j; i++,j--) {
			if(s[i] != s[j]) 
			{
				k=false;
				break;
			}
		}
		if(k)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
```

- 方法二：

```c++
#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
	int k;
	char s[100];
	cin>>k;
	getchar();
	while(k--)
	{
		gets(s);
		bool b = true;
		int len = strlen(s);
		for(int i =0;i < len/2;i++)
		{
			if(s[i] != s[len-i-1])
			{
				b=false;
				break;
			}
		}
		if(b)
			printf("yes\n");
		else
			printf("no\n");
	 } 
	 return 0;
}
```

