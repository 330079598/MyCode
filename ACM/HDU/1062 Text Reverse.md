# 1062 Text Reverse

- Problem Description

```txt
Ignatius likes to write words in reverse way. Given a single line of text which is written by Ignatius, you should reverse all the words and then output them.
```

- Input

```
The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
Each test case contains a single line with several words. There will be at most 1000 characters in a line.
```

- Output

```
For each test case, you should output the text which is processed.
```

- Sample Input

```
3
olleh !dlrow
m'I morf .udh
I ekil .mca
```

- Sample Output

```
hello world!
I'm from hdu.
I like acm.
```

- Hint

```
Remember to use getchar() to read '\n' after the interger T, then you may use gets() to read a line and process it.
```

- 我的理解：如果想用string的话，可能就要用到getline()这个方法，getline()遇到换行符就借书读取操作并返回结果，哪怕是你什么也不输入直接输入换行也是如此。所以要想用getline()这个方法就是在一开始输入的时候使用getchar()将换行符读取了，方式结果得到一个空的string。
- getline()使用：getline(cin,str)   把输入的东西存入str中

方法一：

```c++
g++:如果使用c++的话，编译错误，找不到getline()....
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(void)
{
    int t,len,count = 0;
    string str;
    while(cin>>t)
    {
    getchar();//防止空字符串

    for(int i = 0;i < t; i++)
    {
        getline(cin,str);
        len = str.size();
        str[len] =' ';
        for(int j = 0;j <= len;j++)
        {
            if(str[j] != ' ')
                count++;
            else
            {
                for(int k = j-1;k >= j-count;k--)
                {
                    cout<<str[k];
                }
                if(j != len)
                    cout<<" ";
                count = 0;
            }
        }
        cout<<endl;
    }
    }
    return 0;
}   
还是有点看不懂。。。。
```





方法二：

```c++
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main(void)
{
    char word[1005];
    int n;
    scanf("%d",&n);
    while(scanf("%s",word) != EOF)
    {
        for(int i = strlen(word)-1;i>=0;i--)
        {
            putchar(word[i]);
        }
        char c;
        while(c=getchar(),c == ' ' || c == '\t' || c == '\n')
            putchar(c);
        ungetc(c,stdin);
    }
    return 0;
}

```