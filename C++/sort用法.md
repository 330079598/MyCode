1. sort函数可以三个参数也可以两个参数，必须的头文件#include < algorithm>和using namespace std; 
2. 它使用的排序方法是类似于快排的方法，时间复杂度为n*log2(n)

3. Sort函数有三个参数：（第三个参数可不写）
   1. 第一个是要排序的数组的起始地址。
   2. 第二个是结束的地址（最后一位要排序的地址）
   3. 第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，此时默认的排序方法是从小到大排序。

- 升序降序样例:

```c++
// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }//升序排列
bool myfunction2 (int i,int j) { return (i>j); }//降序排列

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
    int myints[8] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
    //std::sort (myints,myints+8,myfunction);不用vector的用法

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)//输出
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
```

- 也可以用C++标准库

```c++
less<数据类型>()    	 //从小到大排序

greater<数据类型>()      //从大到小排序
```

- 排序后可以去重

> unique()函数是将重复的元素折叠缩编，使成唯一。
>
> unqiue_copy()函数是将重复的元素折叠缩编，使成唯一，并复制到他处。这两个函数的剔除字符原理是，看当前字符与他前一个字符是否相同，如果相同就剔除当前字符，如果不同就跳转到下一个字符。所以在求一个字符串的字符集的时候要先把字符串排个序再调用上面两个函数剔除重复字符，获取字符集。

> 该函数的作用是“去除”容器或者数组中相邻元素的重复出现的元素，注意 
> (1) 这里的去除并非真正意义的erase，而是将重复的元素放到容器的末尾，返回值是去重之后的尾地址。 
> (2) unique针对的是相邻元素，所以对于顺序顺序错乱的数组成员，或者容器成员，需要先进行排序，可以调用std::sort()函数



- 用法:

```c++
#include <iostream>
#include <algorithm>

int main(void)
{
    int a[8] = {2, 2, 2, 4, 4, 6, 7, 8};
    int c;

    //std::sort(a, a + 8);  //对于无序的数组需要先排序

    c = (std::unique(a, a + 8) - a );

    std::cout<< "c = " << c << std::endl;

    //打印去重后的数组成员
    for (int i = 0; i < c; i++)
        std::cout<< "a = [" << i << "] = " << a[i] << std::endl;

    return 0;
}
```

