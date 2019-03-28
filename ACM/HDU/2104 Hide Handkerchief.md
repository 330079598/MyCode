# 2104 Hide Handkerchief(质数)

- Problem Description:

```
The Children’s Day has passed for some days .Has you remembered something happened at your childhood? I remembered I often played a game called hide handkerchief with my friends.
Now I introduce the game to you. Suppose there are N people played the game ,who sit on the ground forming a circle ,everyone owns a box behind them .Also there is a beautiful handkerchief hid in a box which is one of the boxes .
Then Haha(a friend of mine) is called to find the handkerchief. But he has a strange habit. Each time he will search the next box which is separated by M-1 boxes from the current box. For example, there are three boxes named A,B,C, and now Haha is at place of A. now he decide the M if equal to 2, so he will search A first, then he will search the C box, for C is separated by 2-1 = 1 box B from the current box A . Then he will search the box B ,then he will search the box A.
So after three times he establishes that he can find the beautiful handkerchief. Now I will give you N and M, can you tell me that Haha is able to find the handkerchief or not. If he can, you should tell me "YES", else tell me "POOR Haha".

```

- Input:

```
There will be several test cases; each case input contains two integers N and M, which satisfy the relationship: 1<=M<=100000000 and 3<=N<=100000000. When N=-1 and M=-1 means the end of input case, and you should not process the data.
```

- Output:

```
For each input case, you should only the result that Haha can find the handkerchief or not.
```

- Sample Output:

```
YES
```

- 我英语太渣了，虽然能看懂大概是什么意思，就是不理解。。。。
- 有N个人玩丢手绢的游戏，手绢藏在某个人的身后的箱子里，Haha去找这个手绢，但是他是隔M-1隔人去找一次箱子，看到这里我们可以想到求这个两个数的最大公约数是不是1，如果是的，Haha就可以循环找完这些箱子，不然就找不到，陷入死循中。（也可以说求这两个数是不是为互质数）
- [这里是辗转相除法的定义和用法](https://en.wikipedia.org/wiki/Euclidean_algorithm)维基百科上的。
- 辗转相除法又称为广义欧几里得除法，是用来求解两个数的最大公约数的最佳算法之一。
- 算法原理：若a除以b的余数为r，则有(a,b) = (b,r)((a,b)表示a和b的最大公约数)

实现：

```c++
int gcd(int a,int b)
{
if(b==0)return a;
else return gcd(b,a%b);
} //递归法求最大公约数，当最大公约数是1的时候，两个数互质
if(gcd(x,y)==1)那么x,y互质
```

换种写法：

```c++
#include <iostream>
#include <conio.h>
using namespace std;
 
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}
 
int main()
{
	cout << gcd(169, 48) << endl;
	_getch();
	return 0;
}
```

- 如果看的懂题，并且知道了用什么方法，那就容易多了。

```c++
#include<iostream>
using namespace std;

int main(void)
{
    int m,n,temp;//这个用的就是辗转相除法
    while(cin>>m>>n && m != -1 || n != -1)
    {
    while(n != 0)
    {
        temp = n;
        n = m%n;
        m = temp;
    }
    if(m == 1)//这里要用m的值，当初我用的是n，举个列子就明白了。。。
    {
        printf("YES\n");
    }
    else
        printf("POOR Haha\n");
    }
    return 0;
}

```

这里还在网上找了一个我感觉写的挺好的方法，挺巧妙的

```c++
#include<iostream>
using namespace std;

int n,m;
int zz(int a,int b)
{
    return b == 0 ? a : zz(b,a%b);
}
int main(void)
{
    while(cin>>n>>m && n!= -1 || m != -1)
        cout<<(zz(n,m) == 1 ? "YES" : "POOR Haha")<<endl;
    return 0;
}
```