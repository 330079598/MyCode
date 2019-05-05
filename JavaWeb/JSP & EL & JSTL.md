

[TOC]

---

---

# JSP

- Java Server Page
- 什么是jsp

> ​	从用户角度看待 ，就是是一个网页 ， 从程序员角度看待 ， 其实是一个java类， 它继承了servlet，所以可以直接说jsp 就是一个Servlet.

- 为什么会有jsp?

>html 多数情况下用来显示静态内容 ， 一成不变的。 但是有时候我们需要在网页上显示一些动态数据， 比如： 查询所有的学生信息， 根据姓名去查询具体某个学生。 这些动作都需要去查询数据库，然后在网页上显示。 html是不支持写java代码 ， jsp里面可以写java代码。

## 怎么用JSP

- 指令写法

  ```jsp
  <%@ 指令名字%>
  ```

- page指令

  - language

    > 表明jsp页面可以写java代码

  - contentType

    > 其实即使说这个文件是什么类型,告诉浏览器我是什么内容类型,以及使用什么编码

  ```jsp
  contentType="text/html; charset=UTF-8"
  text/html  MIMEType 这是一个文本，html网页
  ```

  - pageEncoding jsp内容编码

  - extends 用于指定jsp翻译成java文件后，继承的父类是谁，一般不用改。

  - import 导包使用的，一般不用手写。

    - 在eclipse中使用 : 使用`alt+/`  不过要在刚写完类名后敲alt+/   ；如Person (alt+/) person=newPerson();即在写完Person后敲alt+/ 才生效。

  - session

    > 可选的有true or false .
    > 用于控制在这个jsp页面里面，能够直接使用session对象。
    > 具体的区别是，请看翻译后的java文件 如果该值是true , 那么在代码里面会有getSession（）的调用，如果是false : 那么就不会有该方法调用，也就是没有session对象了。在页面上自然也就不能使用session了。

  - errorPage:指的是错误的页面,值需要给错误的页面路径
  - isErrorPage:上面的errorPage用于指定错误的时候跑到哪一个页面去,name这个isErrorPage,就是声明某一个页面到底是不是错误的页面.
  - include : 包含另一个jsp的内容进来

  ```jsp
   <%@ include file="other02.jsp"%>
  ```

   - 细节:

  > 把另外一个页面的所有内容拿过来一起输出.所有的标签元素都包含进来.

  - taglib

  ```jsp
  <%@ taglib prefix=""  uri=""%>  
  uri: 标签库路径
  prefix : 标签库的别名
  ```

  ## JSP动作标签

  ```jsp
  <jsp:include page=""></jsp:include>
  <jsp:param value="" name=""/>
  <jsp:forward page=""></jsp:forward>
  ```

- jsp:include

```jsp
<jsp:include page="other02.jsp"></jsp:include>
<!--包含指定的页面， 这里是动态包含。 也就是不把包含的页面所有元素标签全部拿过来输出，而是把它的运行结果拿过来 -->
```

- jsp:forward

```jsp
<jsp:forward page=""></jsp:forward>
<!-- 前往哪一个页面 -->
```

- jsp:param

```jsp
<jsp:forward page="other02.jsp">
<jsp:param value="beijing" name="address"/>
</jsp:forward>
	在other02.jsp中获取参数
	<br>收到的参数是：<br>
	<%= request.getParameter("address")%>
```

## JSP内置对象

- 所谓的内置对象,就是我们可以直接在jsp的页面中使用这些对象,不用创建.

  - pageContext
  - request
  - session
  - application

  以上四个是作用域对象

- 作用域

  - 表示这些对象可以存值,他们的取值范围有限定.setAttribute和getAttribute

  ```jsp
      使用作用域来存储数据<br>
  
      <%
          pageContext.setAttribute("name", "page");
          request.setAttribute("name", "request");
          session.setAttribute("name", "session");
          application.setAttribute("name", "application");
      %>
  
      取出四个作用域中的值<br>
  
      <%=pageContext.getAttribute("name")%>
      <%=request.getAttribute("name")%>
      <%=session.getAttribute("name")%>
      <%=application.getAttribute("name")%>
  ```

  - 作用域范围大小:

  `pageContext -- request --- session -- application 
  `

- 四个作用域的区别

  - pageContext 【PageContext】

  > 作用域仅限于当前的页面。
  >
  > 还可以获取到其他八个内置对象.

  - request 【HttpServletRequest】

  > 作用域仅限于一次请求， 只要服务器对该请求做出了响应。 这个域中存的值就没有了。

  - session 【HttpSession】

  > 作用域限于一次会话（多次请求与响应） 当中。

  - application 【ServletContext】

  > 整个工程都可以用访问,服务器关闭后就不能访问了...

  - out【JspWriter】

  ![](Image/out-response.png)

  - exception 【Throwable】page	

    - 【Object】 ---就是这个jsp翻译成的java类的实例对象

    - config 【ServletConfig】

# EL表达式

- 是为了简化咱们的jsp代码，具体一点就是为了简化在jsp里面写的那些java代码。
- 写法格式

```jsp
${表达式 }
```

> 如果从作用域中取值，会先从小的作用域开始取，如果没有，就往下一个作用域取。 一直把四个作用域取完都没有， 就没有显示。

## 使用:

1. 取出4个作用域中存放的值。

```jsp
<%
        pageContext.setAttribute("name", "page");
        request.setAttribute("name", "request");
        session.setAttribute("name", "session");
        application.setAttribute("name", "application");
    %>

    按普通手段取值<br>

    <%= pageContext.getAttribute("name")%>
    <%= request.getAttribute("name")%>
    <%= session.getAttribute("name")%>
    <%= application.getAttribute("name")%>

    <br>使用EL表达式取出作用域中的值<br>

    ${ pageScope.name }
    ${ requestScope.name }
    ${ sessionScope.name }
    ${ applicationScope.name }
```

- 如果域中所存的是数组

```jsp
<%
    String [] a = {"aa","bb","cc","dd"};
    pageContext.setAttribute("array", a);
%>

使用EL表达式取出作用域中数组的值<br>

${array[0] } , ${array[1] },${array[2] },${array[3] }
```

- 如果域中所存的是集合

```jsp
使用EL表达式取出作用域中集合的值<br>

${li[0] } , ${li[1] },${li[2] },${li[3] }

<br>-------------Map数据----------------<br>
<%
    Map map = new HashMap();
    map.put("name", "zhangsna");
    map.put("age",18);
    map.put("address","北京..");

    map.put("address.aa","深圳..");


    pageContext.setAttribute("map", map);
%>
```

- 取出Map集合的值

```jsp
<% Map map = new HashMap(); map.put("name", "zhangsna"); map.put("age",18); map.put("address","北京..");

map.put("address.aa","深圳..");
pageContext.setAttribute("map", map);
%> 使用EL表达式取出作用域中Map的值
${map.name } , ${map.age } , ${map.address } , ${map["address.aa"] }
```

- 取值细节:

  1. 从域中取值。 得先存值。

  ```jsp
  <%
  //pageContext.setAttribute("name", "zhangsan"); session.setAttribute("name", "lisi..."); %>
  直接指定说了，到这个作用域里面去找这个name
  ${ pageScope.name }
  
  //先从page里面找，没有去request找，去session，去application 
  ${ name }
  
  指定从session中取值
  ${ sessionScope.name }
  ```

  2. 取值方式

  如果这份值是有下标的,name直接使用[]

  ```jsp
  <%
      String [] array = {"aa","bb","cc"}
      session.setAttribute("array",array);
  %>
  
  
  ${ array[1] } --> 这里array说的是attribute的nam
  ```

  如果没有下标,那么使用.的方式去取

  ```jsp
  <%
      User user = new User("zhangsan",18);
  
      session.setAttribute("u", user);
  %>
  
  ${ u.name }  , ${ u.age } 
  ```

  > 一般使用EL表达式，用的比较多的，都是从一个对象中取出它的属性值，比如取出某一个学生的姓名

# EL表达式的11个内置对象

${ 对象名.成员 }

- ${ 对象名.成员 }

>  作用域相关对象 - pageScope - requestScope - sessionScope - applicationScope
>
> 头信息相关对象 - header - headerValues
>
> 参数信息相关对象 - param - paramValues

- cookie 全局初始化参数
- initParagm

# JSTL

> 全称: JSP Standard Tag Library jsp标准标签库
>
> 简化jsp的代码编写。 替换 <%%> 写法。 一般与EL表达式配合

## 使用

1. 导入jar文件到工程的WebContent/Web-Inf/lib jstl.jar standard.jar

2. 导入jar文件到工程的WebContent/Web-Inf/lib jstl.jar standard.jar

3. 注意： 如果想支持 EL表达式，那么引入的标签库必须选择1.1的版本，1.0的版本不支持EL表达式。

   `<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>`

## 常用标签

```jsp
<c:set></c:set> <c:if test=""></c:if> <c:forEach></c:forEach>
```

- c:set

```jsp
<!-- 声明一个对象name， 对象的值 zhangsan , 存储到了page（默认） ， 指定是session -->
<c:set var="name" value="zhangsan" scope="session"></c:set>

${sessionScope.name }
```

- s:if

```jsp
  <c:set var="age" value="18" ></c:set>
    <c:if test="${ age > 26 }">
        年龄大于了26岁...
    </c:if>

    <c:if test="${ age <= 26 }">
        年龄小于了26岁...
    </c:if>


    ------------------------------

    定义一个变量名 flag  去接收前面表达式的值，然后存在session域中

    <c:if test="${ age > 26 }" var="flag" scope="session">
        年龄大于了26岁...
    </c:if>
```

- c:forEach

```jsp
从1 开始遍历到10 ，得到的结果 ，赋值给 i ,并且会存储到page域中， step , 增幅为2， 
<c:forEach begin="1" end="10" var="i" step="2">
    ${i }
</c:forEach>


-----------------------------------------------

<!-- items : 表示遍历哪一个对象，注意，这里必须写EL表达式。 
var: 遍历出来的每一个元素用user 去接收。 -->
<c:forEach var="user" items="${list }">
    ${user.name } ----${user.age }
</c:forEach>
```

