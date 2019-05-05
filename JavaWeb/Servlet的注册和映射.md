- Servlet程序需要在web.xml中注册和映射,才可以被Servlet引擎(容器)加载和被外界访问.

# Servlet注册

- xml代码:

```xml
<web-app>  
  ...  
    <!--向Tomcat报告,这个应用里面有这个Servlet,名字叫做HelloWeb,具体的路径是org.springframework.web.servlet.DispatcherServlet-->
   <servlet>
      <servlet-name>HelloWeb</servlet-name>
      <servlet-class>
     org.springframework.web.servlet.DispatcherServlet
      </servlet-class>
      <load-on-startup>1</load-on-startup>
   </servlet>  
  ...  
</web-app>
```

- 其中`load-on-startup>1</load-on-startup>`的作用

> 在servlet的配置当中，<load-on-startup>5</load-on-startup>的含义是：
>
> 标记容器是否在启动的时候就加载这个servlet。
>
> 当值为0或者大于0时，表示容器在应用启动时就加载这个servlet；
>
> 当是一个负数时或者没有指定时，则指示容器在该servlet被选择时才加载。
>
> 正数的值越小，启动该servlet的优先级越高。
>
> 一般不写负数，从2开始。

|      元素       |                             功能                             |               说明                |
| :-------------: | :----------------------------------------------------------: | :-------------------------------: |
|  servlet-name   | 指定Servlet的名称，在同一个Web应用程序中，其名称必须是唯一的 |             必须包含              |
|  servlet-class  |             指定Servlet类的完整限定名(包含包名)              | 必须包含(servlet-class或jsp-file) |
|    jsp-file     | 指定在Web应用程序中的JSP文件的完整路径，该路径以斜杠(/)开始  | 必须包含(servlet-class或jsp-file) |
|   init-param    | 定义Servlet的初始化参数。如果使用了init-param元素，则必须包含param-name和param-value元素，可以包含零个或多个description元素 |         可以有零个或多个          |
| load-on-startup | 指定当Web应用程序启动时，Servlet被加载的次序，先加载数值小的Servlet，再加载数值大的Servlet |         可以有零个或一个          |
|   description   |                  为Servlet指定一个文本描述                   |         可以有零个或多个          |

# Servlet映射

- xml代码:

```xml
<web-app>  
  ...  
   <servlet-mapping>
      <servlet-name>HelloWeb</servlet-name>
      <url-pattern>/</url-pattern>
   </servlet-mapping>
  ...  
</web-app>
```

- 在web.xml文件中,servlet-mapping元素是用来在Servlet和URL样式之间定义一个映射。它包含两个元素servlet-name和url-pattern。
  - servlet-name：Servlet名称，其必须是在servlet元素中声明过的Servlet名称
  - url-pattern：指定对应于Servlet的URL路径

> 注意：在Servlet2.5规范中，允许servlet-mapping元素中的url-pattern子元素出现多次，之前的规范只允许一个servlet-mapping元素包含一个url-pattern子元素。

# 如何映射请求到Servlet？？

- 在配置了Servlet与URL样式之间的映射之后，当Servlet容器接收到一个请求时，它首先确定该请求应该由哪一个Web应用程序来响应。这是通过比较请求URL的开始部分与Web应用程序的上下文路径来确定的。映射到Servlet的路径是请求URL路径减去上下文路径。下面的URL路径映射规则按顺序使用找到第一个匹配后，将不会进一步尝试匹配。
  - 容器尝试对请求的路径(减去上下文路径后的路径)和Servlet映射的路径(url-pattern参数所指定的路径样式)进行精确匹配，如果匹配成功，则调用这个Servlet来处理请求
  - 容器试着匹配最长的路径前缀，以斜杠(/)为路径分隔符，按照路径树逐级递减匹配，选择最长匹配的Servlet来处理请求
  - 如果请求的URL路径最后有扩展名，如.jsp，Servlet容器将会试着匹配处理这个扩展名的Servlet
  - 如果按照前面三条规则没有找到匹配的Servlet，容器将会调用Web应用程序默认的Servlet来对请求进行处理；如果没有定义默认的Servlet，容器将会向客户端发送HTTP 404错误信息（请求资源不存在）

# 映射规范：

- 在web应用部署描述中，一下语法用于定义映射：
  - 以‘/’字符开始，以‘/*’后缀结尾的字符串用于路径匹配
  - 以‘*.’开始的字符串用于扩展名映射
  - 单独的‘/’字符，用于默认的Servlet
  - 所有其他的字符被用于**精确匹配**，如‘/login’



# Servlet的生命周期

- 生命周期
  - 从创建到销毁的一段时间
- 生命周期方法
  - 从创建到销毁，所调用的那些方法。
- init方法
  - `在创建该servlet的实例时，就执行该方法。
    一个servlet只会初始化一次， init方法只会执行一次
    默认情况下是 ： 初次访问该servlet，才会创建实例`。
- service方法
  - `只要客户端来了一个请求，那么就执行这个方法了。
    该方法可以被执行很多次。 一次请求，对应一次service方法的调用`
- destroy方法
  - servlet销毁的时候会执行该方法
    1. 该项目从Tomcat里面移除。
    2. 正常关闭Tomcat就会执行shutdown.bat

> doGet 和 doPost不算生命周期方法，所谓的生命周期方法是指，从对象的创建到销毁一定会执行的方法， 但是这两个方法，不一定会执行。

----

-----

- 完整的代码:

```xml
1. 新建一个类， 实现Servlet接口

2. 配置Servlet ， 用意： 告诉服务器，我们的应用有这么些个servlet。

    在webContent/WEB-INF/web.xml里面写上以下内容。


  <!-- 向tomcat报告， 我这个应用里面有这个servlet， 名字叫做HelloServlet , 具体的路径是com.itheima.servlet.HelloServlet -->
  <servlet>
    <servlet-name>HelloServlet</servlet-name>
    <servlet-class>com.itheima.servlet.HelloServlet</servlet-class>
  </servlet>

  <!-- 注册servlet的映射。  servletName : 找到上面注册的具体servlet，  url-pattern: 在地址栏上的path 一定要以/打头 -->
  <servlet-mapping>
    <servlet-name>HelloServlet</servlet-name>
    <url-pattern>/a</url-pattern>
  </servlet-mapping>

3. 在地址栏上输入 http://localhost:8080/项目名称/a
```

---

----

# ServletConfig

- servlet的配置,通过这个对象,可以获取servlet在配置的时候一些信息

```java
//1. 得到servlet配置对象 专门用于在配置servlet的信息
		ServletConfig config = getServletConfig();
		
		//获取到的是配置servlet里面servlet-name 的文本内容
		String servletName = config.getServletName();
		System.out.println("servletName="+servletName);
	
		//2. 可以获取具体的某一个参数。 
		String address = config.getInitParameter("address");
		System.out.println("address="+address);


		//3.获取所有的参数名称
		Enumeration<String> names = config.getInitParameterNames();
		//遍历取出所有的参数名称
		while (names.hasMoreElements()) {
			String key = (String) names.nextElement();
			String value = config.getInitParameter(key);
			System.out.println("key==="+key + "   value="+value);
			
		}
```

- 为什么需要这个ServletConfig

  1. 未来我们自己开发的一些应用，使用到了一些技术，或者一些代码，我们不会。 但是有人写出来了。它的代码放置在了自己的servlet类里面。
  2. 刚好这个servlet 里面需要一个数字或者叫做变量值。 但是这个值不能是固定了。 所以要求使用到这个servlet的公司，在注册servlet的时候，必须要在web.xml里面，声明init-params

  在开发当中用的比较少.