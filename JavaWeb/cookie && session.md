[TOC]

---

# Cookie

- 饼干.其实是一份小数据,是服务器给客户端,并且存储在客户端上的一份小数据.
  - 每一个cookie文件大小:4kb,如果超过4kb浏览器就会不识别
  - 一个web站点:发送20个
  - 一个浏览器保存总大小:300个
  - cookie不安全,可能会泄露用户信息.浏览器支持禁用cookie操作.
  - 默认情况生命周期:与浏览器一样,当浏览器关闭时cookie销毁.
- 应用场景
  - 自动登录,浏览记录,购物车...
- 存在原因:
  - http的请求是无状态。 客户端与服务器在通讯的时候，是无状态的，其实就是客户端在第二次来访的时候，服务器根本就不知道这个客户端以前有没有来访问过。 为了更好的用户体验，更好的交互 [自动登录]，其实从公司层面讲，就是为了更好的收集用户习惯[大数据].
- 常用方法:

```java
//关闭浏览器后，cookie就没有了。 ---> 针对没有设置cookie的有效期。
		//	expiry： 有效 以秒计算。
		//正值 ： 表示 在这个数字过后，cookie将会失效。
		//负值： 关闭浏览器，那么cookie就失效， 默认值是 -1
		cookie.setMaxAge(60 * 60 * 24 * 7);
		
		//赋值新的值
		//cookie.setValue(newValue);
		
		//用于指定只有请求了指定的域名，才会带上该cookie
		cookie.setDomain(".itheima.com");
		
		//只有访问该域名下的cookieDemo的这个路径地址才会带cookie
		cookie.setPath("/CookieDemo");

```

- cookie总结:

  1. 服务器给客户端发送过来的一小份数据,并且存放在客户端上.
  2. 获取cookie,添加cookie

  ```java
  request.getCookie();
  response.addCookie();
  ```

  3. cookie分类:

     ```java
     会话Cookie
     		默认情况下，关闭了浏览器，那么cookie就会消失。
     
     	持久Cookie
     
     		在一定时间内，都有效，并且会保存在客户端上。 
     
     		cookie.setMaxAge(0); //设置立即删除
     
     		cookie.setMaxAge(100); //100 秒
     ```

  4. cookie的安全问题

     - 由于Cookie会保存在客户端上，所以有安全隐患问题。  还有一个问题， Cookie的大小与个数有限制。 为了解决这个问题 ---> Session.

---

# session

- 会话 ， Session是基于Cookie的一种会话机制。 Cookie是服务器返回一小份数据给客户端，并且存放在客户端上。 Session是，数据存放在服务器端。
- 功能作用:服务器用于共享数据技术.
- 常用API:

```java
//得到会话ID
		String id = session.getId();

		//存值
		session.setAttribute(name, value);
		
		//取值
		session.getAttribute(name);
		
		//移除值
		session.removeAttribute(name);

```

- session生命周期:
  - 创建
    - 如果有在servlet里面调用了 request.getSession()
    - setAttribute 存放的值，及时关闭浏览器也会有.
  - 销毁
    - session 是存放在服务器的内存中的一份数据。 当然可以持久化. Redis . 即使关了浏览器，session也不会销毁。
      1. 关闭服务器
      2. session会话时间过期.有效期过了,默认有效期:30分钟.