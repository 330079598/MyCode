求 aa 的 bb 次方对 pp 取模的值。

#### 输入格式

三个整数 a,b,pa,b,p ,在同一行用空格隔开。

#### 输出格式

输出一个整数，表示`a^b mod p`的值。

#### 数据范围

1≤a,b,p≤1091≤a,b,p≤109

#### 输入样例：

```
3 2 7
```

#### 输出样例：

```
2
```



- 首先我想到的是暴力枚举，但是时间超了，毫无疑问要找更好的算法，结果这题不就是快速幂的标准样例么（还是听xyc直播讲的，以前根本不知道是啥）。。。。

  - 想要用下面的算法，先证明一个公式：

  - $$  (a * b ) \% p = ((a \% p ) * ( b \% p) ) \% p $$ 

  - $$( a +b )\% p = (( a \% p ) + (b \% p) ) \% p $$

    - 证明：$$a * b \% p$$

    - $$a = c1 * p + yu1 $$; $$b = c2 * p + yu2;$$

      $$((a* b)) \% p = ((c1 * p + yu1 ) * (c2 * p+ yu2 ))\% p$$  展开即可！

  - **a = (long long)a * a % p; 这里是倍增，每次求 $a^{2^1}\%p$,$a^{2^2}\%p$,$a^{2^3}\%p$,…$a^{2^1}\%p$,$a^{2^2}\%p$,$a^{2^3}\%p$,… 值***;

  - **if (b & 1) res = (long long)res * a % p; 这里是求指数 b 的二进制表示，如果第 k 位是1，就乘上对应的 $a^{2^k}$***;

```c
#include<iostream>
using namespace std;

int main(void)
{
    long long a,b,p,sum = 1;
    cin>>a>>b>>p;
    sum = sum % p;
    while(b)
    {
        if(b&1)
            sum = (long long)sum * a % p;
        a = a * a % p;
        b >>= 1;
    }
    cout<<sum<<endl;
    return 0;
}
```





- yxc的代码，我就是抄的，哈哈

```c
#include <iostream>

using namespace std;

int main()
{
    int a, b, p;
    cin >> a >> b >> p;

    int res = 1 % p;
    while (b)
    {
        if (b & 1) res = (long long)res * a % p;//long long也可以写成 1ll 
        a = (long long)a * a % p;
        b >>= 1;
    }

    cout << res << endl;

    return 0;
}
```
