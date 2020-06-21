# 2734 Quicksum

- 我真是废材，一到字符串的题就犯难.....…..
- Problem Description

```
A checksum is an algorithm that scans a packet of data and returns a single number. The idea is that if the packet is changed, the checksum will also change, so checksums are often used for detecting transmission errors, validating document contents, and in many other situations where it is necessary to detect undesirable changes in data.

For this problem, you will implement a checksum algorithm called Quicksum. A Quicksum packet allows only uppercase letters and spaces. It always begins and ends with an uppercase letter. Otherwise, spaces and letters can occur in any combination, including consecutive spaces.

A Quicksum is the sum of the products of each character's position in the packet times the character's value. A space has a value of zero, while letters have a value equal to their position in the alphabet. So, A=1, B=2, etc., through Z=26. Here are example Quicksum calculations for the packets "ACM" and "MID CENTRAL":

ACM: 1*1 + 2*3 + 3*13 = 46MID CENTRAL: 1*13 + 2*9 + 3*4 + 4*0 + 5*3 + 6*5 + 7*14 + 8*20 + 9*18 + 10*1 + 11*12 = 650
```

- Input

```
The input consists of one or more packets followed by a line containing only # that signals the end of the input. Each packet is on a line by itself, does not begin or end with a space, and contains from 1 to 255 characters.
```

- Output

```
For each packet, output its Quicksum on a separate line in the outpu
```

- Sample Input

```
ACM
MID CENTRAL
REGIONAL PROGRAMMING CONTEST
ACN
A C M
ABC
BBC
#
```

- Sample Output

```
46
650
4690
49
75
14
15
```

- 这题真没什么好说的，就是字符串的输入，转换成字母在单词表中的顺序*序号
- 自我反省：c/c++基础语法学的不到位，导致函数不清楚功能，所以才会无从下手。
- gets() ：读取一串字符串，以回车结束

```c++
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void)
{
    long long sum;
    char s[260];
    while(gets(s) && s[0] != '#')
    {
        sum = 0;
        for(int i = 0;s[i];i++)
        {
            if(s[i] != ' ')
                sum += (s[i] - 'A' + 1)*(i+1);
        }
        printf("%lld\n",sum);
    }
    return 0;
}

```