# 1170 Balloon Comes!

- Problem Description：

```
The contest starts now! How excited it is to see balloons floating around. You, one of the best programmers in HDU, can get a very beautiful balloon if only you have solved the very very very... easy problem.
Give you an operator (+,-,*, / --denoting addition, subtraction, multiplication, division respectively) and two positive integers, your task is to output the result. 
Is it very easy? 
Come on, guy! PLMM will send you a beautiful Balloon right now!
Good Luck!
```

- Input:

```
Input contains multiple test cases. The first line of the input is a single integer T (0<T<1000) which is the number of test cases. T test cases follow. Each test case contains a char C (+,-,*, /) and two integers A and B(0<A,B<10000).Of course, we all know that A and B are operands and C is an operator. 
```

- Sample Input:

```
Input contains multiple test cases. The first line of the input is a single integer T (0<T<1000) which is the number of test cases. T test cases follow. Each test case contains a char C (+,-,*, /) and two integers A and B(0<A,B<10000).Of course, we all know that A and B are operands and C is an operator. 
```

- Output:

```
For each case, print the operation result. The result should be rounded to 2 decimal places If and only if it is not an integer.
```

- Sample Input

```
4
+ 1 2
- 1 2
* 1 2
/ 1 2
```

- Sample Output

```
3
-1
2
0.50
```

- 唯独需要注意一点： 除法是需要判断的，如果要有小数，是需要输出2位小数的

```c
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void)
{
    int n,a,b;
    float sum=0;
    char c;
    cin>>n;
    while(n--)
    {
        cin>>c>>a>>b;

        if(c == '+')
            cout<<a+b<<endl;
        else if(c == '-')
            cout<<a-b<<endl;
        else if(c == '*')
            cout<<a*b<<endl;
        else if(c == '/')
        {
            sum = (float)a/b;
            if(a%b == 0)
                printf("%d\n",a/b);
            else
                printf("%.2f\n",sum);
        }
    }
    return 0;
}

```