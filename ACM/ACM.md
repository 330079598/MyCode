一般ACM或者笔试题的时间限制是1秒或2秒。
在这种情况下，C++代码中的操作次数控制在 $10^7$为最佳。

下面给出在不同数据范围下，代码的时间复杂度和算法该如何选择：

- $n \le 30$, 指数级别, dfs+剪枝，状态压缩dp
- $n \le 100$ =&gt; $O(n^3)$，floyd，dp
- $n \le 1000$ =&gt; $O(n^2)​$，$O(n^2logn)​$，dp
- $n \le 10000$ =&gt; $O(n * \sqrt n)$，块状链表
- $n \le 100000$ =&gt; $O(nlogn)$ =&gt; 各种sort，线段树、树状数组、set/map、heap、dijkstra+heap、spfa、求凸包、求半平面交、二分
- $n \le 1000000$ =&gt; $O(n)$, 以及常数较小的 $O(nlogn)$ 算法 =&gt; hash、双指针扫描、kmp、AC自动机，常数比较小的 $O(nlogn)$ 的做法：sort、树状数组、heap、dijkstra、spfa
- $n \le 10000000$ =&gt; $O(n)$，双指针扫描、kmp、AC自动机、线性筛素数
- $n \le 10^9$ =&gt; $O(\sqrt n)$，判断质数
- $n \le 10^{18}$ =&gt; $O(logn)$，最大公约数



此处为摘抄：

原作者：yxc
链接：https://www.acwing.com/blog/content/32/