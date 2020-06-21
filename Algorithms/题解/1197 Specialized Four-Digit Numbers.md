# 1197 Specialized Four-Digit Numbers

- Problem Description：

```txt
Find and list all four-digit numbers in decimal notation that have the property that the sum of its four digits equals the sum of its digits when represented in hexadecimal (base 16) notation and also equals the sum of its digits when represented in duodecimal (base 12) notation.

For example, the number 2991 has the sum of (decimal) digits 2+9+9+1 = 21. Since 2991 = 1*1728 + 8*144 + 9*12 + 3, its duodecimal representation is 1893(12), and these digits also sum up to 21. But in hexadecimal 2991 is BAF16, and 11+10+15 = 36, so 2991 should be rejected by your program.

The next number (2992), however, has digits that sum to 22 in all three representations (including BB016), so 2992 should be on the listed output. (We don't want decimal numbers with fewer than four digits - excluding leading zeroes - so that 2992 is the first correct answer.)
```

- Input:

```txt
There is no input for this problem.
```

- Output:

```txt
Your output is to be 2992 and all larger four-digit numbers that satisfy the requirements (in strictly increasing order), each on a separate line with no leading or trailing blanks, ending with a new-line character. There are to be no blank lines in the output. The first few lines of the output are shown below.
```

- Sample Input:

```txt
There is no input for this problem.
```

- Sample Output:

```txt
2992
2993
2994
2995
2996
2997
2998
2999
```

- 读懂题或许会清晰一点：大意是输出四位数，那种四个数字的十进制的和 和 十二进制的和 和 十六进制的和都相等的数字。

```c++
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void)
{
    int duo_sum = 0,hex_sum = 0,r,sum = 0;
    for(int i = 1000;i<10000;i++)
    {
        r = i;
        while(r != 0)//十六进制
        {
            hex_sum += r%16;
            r /= 16;
        }
        r = i;
        while(r != 0)//十二进制
        {
            duo_sum += r%12;
            r /= 12;
        }

        sum = i/1000+i%1000/100+i%1000%100/10+i%1000%100%10;//十进制
        if(sum == hex_sum && hex_sum == duo_sum)
            printf("%d\n",i);
        hex_sum = 0;
        duo_sum = 0;
        sum = 0;
    }

}
```

