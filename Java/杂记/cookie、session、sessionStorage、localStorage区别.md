[toc]

---

## cookie、session区别

- cookie 存储于浏览器端，而 session 存储于服务端

- cookie 的安全性相比于 session 较弱，别人可以分析存放在本地的COOKIE并进行COOKIE欺骗
  考虑到安全应当使用session。

- session 会在一定时间内保存在服务器上。当访问增多时，会占用服务器的资源，所以考虑到服务器性能方面，可以使用cookie

- cookie 存储容量有限制，单个cookie 保存数据不能超过4k，且很多浏览器限制一个站点最多保存20个cookie。而对于 session ，其默认大小一般是1024k

## cookie、sessionStorage、localStorage 异同点

html5 中 webStorage 包含 sessionStorage 和 localStorage

- 共同点：

都保存在浏览器端，且是同源的

- 区别：

cookie 数据始终在同源的http请求中携带，而 webStorage 不会再请求中携带，仅仅在本地存储
存储大小区别，cookie 是4k，webStorage 可以达到5M甚至更大

数据有效时间区别： sessionStorage 仅仅是会话级别的存储，它只在当前浏览器关闭前有效，不能持久保持；localStorage 始终有效，即使窗口或浏览器关闭也一直有效，除非用户手动删除，其才会失效；cookie 只在设置的 cookie 过期时间之前一直有效。

作用域区别：sessionStorage 不在不同的浏览器窗口中共享，即使是同一个页面； localStorage 和 cookie 在所有同源窗口是共享的

Web Storage 支持事件通知机制，可以将数据更新的通知发送给监听者。Web Storage 的 api 接口使用更方便。
web storage和cookie的区别

Web Storage的概念和cookie相似，区别是它是为了更大容量存储设计的。Cookie的大小是受限的，并且每次你请求一个新的页面的时候Cookie都会被发送过去，这样无形中浪费了带宽，另外cookie还需要指定作用域，不可以跨域调用。

除此之外，Web Storage拥有setItem,getItem,removeItem,clear等方法，不像cookie需要前端开发者自己封装setCookie，getCookie。

但是Cookie也是不可以或缺的：Cookie的作用是与服务器进行交互，作为HTTP规范的一部分而存在 ，而Web Storage仅仅是为了在本地“存储”数据而生。

Cookies:服务器和客户端都可以访问；大小只有4KB左右；有有效期，过期后将会删除；

本地存储：只有本地浏览器端可访问数据，服务器不能访问本地存储直到故意通过POST或者GET的通道发送到服务器；每个域5MB；没有过期数据，它将保留知道用户从浏览器清除或者使用Javascript代码移除

---

<table style="text-align:center">
    <tr>
        <td>特性</td>
        <td>Cookie</td>
        <td>localStorage</td>
        <td>sessionStorage</td>
    </tr>
    <tr>
        <td>数据的生命期</td>
        <td>一般由服务器生成，可设置失效时间。如果在浏览器端生成Cookie，默认是关闭浏览器后失效</td>
        <td>除非被清除，否则永久保存</td>
        <td>仅在当前会话下有效，关闭页面或浏览器后被清除</td>
    </tr>
    <tr>
        <td>存放数据大小</td>
        <td>4K左右</td>
        <td colspan="2">一般为5MB</td>
    </tr>
    <tr>
        <td>与服务器端通信</td>
        <td>每次都会携带在HTTP头中，如果使用cookie保存过多数据会带来性能问题</td>
        <td colspan="2">仅在客户端（即浏览器）中保存，不参与和服务器的通信</td>
    </tr>
    <tr>
        <td>易用性</td>
         <td>需要程序员自己封装，源生的Cookie接口不友好</td>
         <td colspan="2" >源生接口可以接受，亦可再次封装来对Object和Array有更好的支持</td>
    </tr>
</table>

---

## 应用场景

有了对上面这些差别的直观理解，我们就可以讨论三者的应用场景了。

因为考虑到每个 HTTP 请求都会带着 Cookie 的信息，所以 Cookie 当然是能精简就精简啦，比较常用的一个应用场景就是判断用户是否登录。针对登录过的用户，服务器端会在他登录时往 Cookie 中插入一段加密过的唯一辨识单一用户的辨识码，下次只要读取这个值就可以判断当前用户是否登录啦。曾经还使用 Cookie 来保存用户在电商网站的购物车信息，如今有了 localStorage，似乎在这个方面也可以给 Cookie 放个假了~

而另一方面 localStorage 接替了 Cookie 管理购物车的工作，同时也能胜任其他一些工作。比如HTML5游戏通常会产生一些本地数据，localStorage 也是非常适用的。如果遇到一些内容特别多的表单，为了优化用户体验，我们可能要把表单页面拆分成多个子页面，然后按步骤引导用户填写。这时候 sessionStorage 的作用就发挥出来了。

## 安全性的考虑

需要注意的是，不是什么数据都适合放在 Cookie、localStorage 和 sessionStorage 中的。使用它们的时候，需要时刻注意是否有代码存在 XSS 注入的风险。因为只要打开控制台，你就随意修改它们的值，也就是说如果你的网站中有 XSS 的风险，它们就能对你的 localStorage 肆意妄为。所以千万不要用它们存储你系统中的敏感数据。