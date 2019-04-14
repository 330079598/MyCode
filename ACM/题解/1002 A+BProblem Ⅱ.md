Problem Description

I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.

 

Input

The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.

 

Output

For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation. Output a blank line between two test cases.

 

Sample Input

```txt
2
1 2
112233445566778899 998877665544332211
```

 

Sample Output

```txt
Case 1:
1 + 2 = 3

Case 2:
112233445566778899 + 998877665544332211 = 1111111111111111110
```



```c++
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
    string a,b;
    int num,sum[1001];
    cin >> num;
    for(int z=0;z<num;z++)
    {
        cin>>a>>b;
        int m=0,n=0,temp=0,i,k;
        int sumLen=0;
        i=a.length();
        k=b.length();
        i=i-1;
        k=k-1;
        while(i>=0 && k>=0)
        {
            m=a[i]-'0';
            n=b[k]-'0';
            sum[sumLen++]=(temp+m+n)%10;
            temp=(temp+n+m)/10;   //处理进位问题
            i--;
            k--;
        }
        if(i>k)
        {
            while(i>=0)
            {
                m=a[i]-'0';
                sum[sumLen++]=(temp+m)%10;
                temp=(temp+m)/10;
                i--;
            }
        }
        if(k>i)
        {
            while(k>=0)
            {
                m=b[k]-'0';
                sum[sumLen++]=(temp+m)%10;
                temp=(temp+m)/10;
                k--;
            }
        }
        sum[sumLen]=temp;

        cout<<"Case "<<z+1<<":"<<endl;
        cout<<a<<" + "<<b<<" = ";
        if(sum[sumLen]!=0)
            cout<<sum[sumLen];
        for(--sumLen;sumLen>=0;sumLen--)
            cout<<sum[sumLen];

    cout<<endl;
     if(z<num-1)
        cout<<endl;
    }
    return 0;
}

```

- java可以用大数的方法写，简直是太方便了好么？？

```java 
import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int k = 1;
		while(N-->0) {
			BigDecimal a = sc.nextBigDecimal();
			BigDecimal b = sc.nextBigDecimal();
			System.out.println("Case "+(k++)+":");
			System.out.println(a+" + "+b+" = "+a.add(b));
			if(N>0) {
				System.out.println();
			}
		}
	}
}
```

