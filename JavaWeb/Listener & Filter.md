[TOC]

---

# Listener

- 监听器 : 监听器就是一个**实现特定接口的普通java程序**，这个程序专门用于**监听另一个java对象的方法调用或属性改变**，当被监听对象发生上述事件后，监听器某个方法将立即被执行。
- 监听器的内部机制:其实就是接口回调.
- 监听器的作用:监听器可以用来检测网站的在线人数,统计网站的访问量等.
- 监听器组件:
  - 事件源
  - 时间对象
  - 时间监听器
- 在Servlet规范中定义了多种类型的监听器，它们**用于监听的事件源分别 ServletContext, HttpSession和ServletRequest这三个域对象**

```java
request         ---httpServletRequest
session         ---httpSession
aapplication 	--- ServletContext

	1. ServletContextListener

		servletcontext创建：

			1. 启动服务器的时候

		servletContext销毁：

			2. 关闭服务器. 从服务器移除项目
			

	2. ServletRequestListener

		request创建:

			访问服务器上的任意资源都会有请求出现。

			访问 html： 会
			访问 jsp:	会
			访问 servlet : 会 
			

		request销毁：

			服务器已经对这次请求作出了响应。


			public class MyRequestListener implements ServletRequestListener {
					@Override
					public void requestDestroyed(ServletRequestEvent sre) {
						System.out.println("servletrequest 销毁了");
					}
				
					@Override
					public void requestInitialized(ServletRequestEvent sre) {
						System.out.println("servletrequest 初始化了");
					}
				}

			  
			  <listener>
			  	<listener-class>com.itheima.listener.MyRequestListener</listener-class>
			  </listener>

			

	3. HttpSessionListener

		session的创建
			只要调用getSession

			html:		不会
			jsp:		会	  getSession();
			servlet: 	会

		session的销毁
			超时  30分钟
			
			非正常关闭 销毁

			正常关闭服务器(序列化)

			public class MySessionListener implements HttpSessionListener {

				@Override
				public void sessionCreated(HttpSessionEvent se) {
					System.out.println("创建session了");
				}
			
				@Override
				public void sessionDestroyed(HttpSessionEvent se) {
					System.out.println("销毁session了");
				}
			}
```

