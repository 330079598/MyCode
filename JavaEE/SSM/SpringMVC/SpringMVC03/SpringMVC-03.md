# 03-SpringMVC

# 10、Restful风格

## 10.1、Restful 风格的介绍

​	Restful 一种软件架构风格、设计风格，而不是标准，只是提供了一组设计原则和约束条件。它主要用于客户端和服务器交互类的软件。基于这个风格设计的软件可以更简洁，更有层次，更易于实现缓存等机制。

### 原则条件

​	REST 指的是一组架构[约束条件](https://baike.baidu.com/item/约束条件)和原则。满足这些约束条件和原则的应用程序或设计就是 RESTful。Web 应用程序最重要的 REST 原则是，客户端和服务器之间的交互在请求之间是无状态的。从客户端到服务器的每个请求都必须包含理解请求所必需的信息。如果服务器在请求之间的任何时间点重启，客户端不会得到通知。此外，无状态请求可以由任何可用服务器回答，这十分适合[云计算](https://baike.baidu.com/item/云计算)之类的环境。客户端可以缓存数据以改进性能。

​	在服务器端，应用程序状态和功能可以分为各种资源。资源是一个有趣的概念实体，它向客户端公开。资源的例子有：应用程序对象、数据库记录、算法等等。每个资源都使用 URI (Universal Resource Identifier) 得到一个唯一的地址。**所有资源都共享统一的接口**，以便在客户端和服务器之间传输状态。使用的是标准的 **HTTP 方法**，比如 GET、PUT、[POST](https://baike.baidu.com/item/POST) 和 [DELETE](https://baike.baidu.com/item/DELETE)。[Hypermedia](https://baike.baidu.com/item/Hypermedia) 是应用程序状态的[引擎](https://baike.baidu.com/item/引擎/2874935)，资源表示通过[超链接](https://baike.baidu.com/item/超链接)互联。

```java
@RequestMapping(vaule="user/findAll",method=RequestMethod.GET)
public @ResponseBody List<Person> findAll(){
    .....
    return List<Person>;
}
```

​	**Restful是一种设计风格。对于我们Web开发人员来说。就是使用一个url地址表示一个唯一的资源。然后把原来的请求参数加入到请求资源地址中。然后原来请求的增，删，改，查操作。改为使用HTTP协议中请求方式GET、POST、PUT、DELETE表示。**

1. 把请求参数加入到请求的资源地址中
2. 原来的增，删，改，查。使用HTTP请求方式，POST、DELETE、PUT、GET分别一一对应。

## 10.2、如何学习restful风格，这里需要明确两点：

### 10.2.1、就是把传统的请求参数加入到请求地址是什么样子？

传统的方式是：

比如：http://ip:port/工程名/资源名?请求参数

举例：http://127.0.0.1:8080/springmvc/book?action=delete&id=1

restful风格是：

比如：http://ip:port/工程名/资源名/请求参数/请求参数

举例：http://127.0.0.1:8080/springmvc/book/delete/1

请求的动作删除由请求方式delete决定

### 10.2.2、restful风格中请求方式GET、POST、PUT、DELETE分别表示查、增、改、删。

GET请求		对应   查询

http://ip:port/工程名/book/1		HTTP请求GET		表示要查询id为1的图书

http://ip:port/工程名/book			HTTP请求GET		表示查询全部的图书

POST请求	对应	添加

http://ip:port/工程名/book			HTTP请求POST		表示要添加一个图书

PUT请求		对应	修改

http://ip:port/工程名/book/1		HTTP请求PUT		表示要修改id为1的图书信息

DELETE请求	对应	删除

http://ip:port/工程名/book/1		HTTP请求DELETE		表示要删除id为1的图书信息

### 10.2.3、SpringMVC中如何发送GET请求、POST请求、PUT请求、DELETE请求。

 我们知道发起GET请求和POST请求，只需要在表单的form标签中，设置method=”get” 就是GET请求。

设置form标签的method=”post”。就会发起POST请求。而PUT请求和DELETE请求。要如何发起呢。

1. 要有post请求的form标签
2. 在form表单中，添加一个额外的隐藏域_method=”PUT”或_method=”DELETE”
3. 在web.xml中配置一个Filter过滤器org.springframework.web.filter.HiddenHttpMethodFilter**（注意，这个Filter一定要在处理乱码的Filter后面）**

## 10.3、Restful风格的Controller如何实现

jsp:

```jsp
<%--get--%>
<a href="${pageContext.request.contextPath}/book/1">通过id查询图书信息</a>
<a href="${pageContext.request.contextPath}/book">查询全部图书信息</a>

<%--post--%>
<form action="${pageContext.request.contextPath}/book" method="post">
  <input type="submit" value="添加图书" />
</form>

<%--put--%>
<form action="${pageContext.request.contextPath}/book/1" method="post">
  <%-- 隐藏域表示请求方式PUT --%>
  <input type="hidden" name="_method" value="PUT" />
  <input type="submit" value="修改图书" />
</form>

<%--delete--%>
<form action="${pageContext.request.contextPath}/book/1" method="post">
  <%-- 隐藏域表示请求方式 DELETE --%>
  <input type="hidden" name="_method" value="DELETE" />
  <input type="submit" value="删除图书" />
</form>
```

controller

```java
@RequestMapping(value = "/book/1", method = RequestMethod.GET)
public String findBookById() {
    System.err.println("通过id查询一个图书");
    return "redirect:/index.jsp";
}

@GetMapping()
@RequestMapping(value = "/book", method = RequestMethod.GET)
public String findBookAll() {
    System.err.println("查询全部图书信息");
    return "redirect:/index.jsp";
}

@PostMapping()
@RequestMapping(value = "/book", method = RequestMethod.POST)
public String addBook() {
    System.err.println("添加书籍信息");
    return "redirect:/index.jsp";
}

@RequestMapping(value = "/book/1", method = RequestMethod.PUT)
public String updateBookById() {
    System.err.println("通过id修改一个图书");
    return "redirect:/index.jsp";
}

@RequestMapping(value = "/book/1", method = RequestMethod.DELETE)
public String deleteBookById() {
    System.err.println("通过id删除一个图书");
    return "redirect:/index.jsp";
}
```

## 10.4、Restful风格在高版本Tomcat中无法转发到jsp页面

在Tomcat8之后的一些高版本，使用restful风格访问然后转发到jsp页面。就会有如下的错误提示：

1. 使用请求重定向 <br/>

2. 在jsp页面的page指定中设置 isErrorPage=true.

![img](C:\class\课件\SSM\SpringMVC\Springmvc第3天\笔记\SpringMVC-03.assets\wps7.jpg) 

## 10.5、@PathVariable 路径参数获取

前面我们已经知道如何编写和配置restful风格的请求和控制器。

那么 现在的问题是。如何接收restful风格请求的参数。比如前面的id值。

```java
/**
     * 查询id为1的图书 <br/>
     * value = "/book/{id} 请求地址中 {id} 表示路径参数(路径变量). 大括号中的id,是参数名(变量名) <br/>
     *
     * @return
     * @PathVariable("id") Integer id ,@PathVariable表示取路径变量的值(取参数名或变量名为 id的值)赋给方法参数id
     * 注意:{name}如果不传递,则404
     * book/1/xixi
     * @RequestHeader("")获取请求头的数据
     */
@RequestMapping(value = "/book/{id}/{name}", method = RequestMethod.GET)
public String findBookById(
    @PathVariable(value = "id") Integer id,@PathVariable(value = "name",required = false)String name) {
    System.err.println("通过id查询一个图书");
    System.err.println(id);
    System.err.println(name);
    return "forward:/index.jsp";
}
```

# 11、Restful风格实现的CRUD图书

把前面的传统请求方式的图书的CRUD换成刚刚讲的Restful风格的图书模块的CRUD。只需要修改页面端的请求方式和地址，以及服务器端Controller的接收。

## 11.2、列表功能实现

Controller中的代码:

```java
@RequestMapping(value = "",method = RequestMethod.GET)
public String list(Map<String, Object> map) {
    List<Book> list = bookService.queryAllBooks();
    map.put("list", list);
    return "bookList";
}
```

页面中请求方式修改:

![img](SpringMVC.assets\wps8.jpg) 

## 11.3、删除功能实现

Controller中的代码:

```java
@RequestMapping(value = "/book/{id}",method = RequestMethod.DELETE)
public String delete(@PathVariable("id") Integer id) {
    //通过调用bookService.deleteBookById()删除图书
    bookService.deleteBookById(id);
    //重定向到查询页面
    return "redirect:/book";
}
```

![](SpringMVC.assets\wps9.jpg) 

![](SpringMVC.assets\wps10.jpg) 

## 11.4、添加功能实现

Controller中的修改代码:

```java
@RequestMapping(value = "/book" , method = RequestMethod.POST)
public String add(Book book) {
    /**
   * 中文乱码解决方法有两个 <br>
   *   1 请求转为get请求,在Tomcat8之后get请求没有中文乱码 <br/>
   *   2 使用Spring提供的Filter过滤器解决中文乱码问题 <br/>
   */
    // 调用bookService.saveBook()添加图书
    bookService.saveBook(book);
    // 重定向回图书列表管理页面
    return "redirect:/book";
}
```

jsp页面中的修改:

![](SpringMVC.assets\wps11.jpg)

# 中文乱码

```xml
配置最上边
<filter>
    <filter-name>encoding</filter-name>
    <filter-class>org.springframework.web.filter.CharacterEncodingFilter</filter-class>
    <init-param>
        <param-name>encoding</param-name>
        <param-value>utf-8</param-value>
    </init-param>
    <init-param>
        <param-name>forceRequestEncoding</param-name>
        <param-value>true</param-value>
    </init-param>
    <init-param>
        <param-name>forceResponseEncoding</param-name>
        <param-value>true</param-value>
    </init-param>
</filter>

<filter-mapping>
    <filter-name>encoding</filter-name>
    <url-pattern>/*</url-pattern>
</filter-mapping>
```

## 11.5、更新功能实现

更新图书分为两个步骤：

1. 查询需要更新的图书，填充到更新页面
2. 提交请求，发送数据给服务器更新保存修改。

### 11.5.1、查询需要更新的图书，填充到更新页面

Controller中的代码:

```java
@RequestMapping(value = "/{id}",method = RequestMethod.GET)
public String getABook(@PathVariable("id") Integer id, Map<String, Object> map) {
    Book book = bookService.queryBookbyId(id);
    map.put("book", book);
    return "bookEdit";
}
```

jsp页面中修改

![](SpringMVC.assets\wps12.jpg) 

### 11.5.2、提交请求，发送数据给服务器更新保存修改。

Controller代码中的修改:

```java
@RequestMapping(value = "",method = RequestMethod.PUT)
public String update(Book book) {
    // 调用bookService.updateBook()修改图书
    bookService.updateBookById(book);
    // 重定向到图书列表管理页面
    return "redirect:/book";
}
```

jsp页面中的修改:

![](SpringMVC.assets\wps13.jpg) 

# 12、文件上传

文件上传在SpringMVC中如何实现：

准备工作前端控制器 , SpringMVC两个标配

1. 准备一个文件上传的表单

2. 导入文件上传需要的jar包

- commons-fileupload-1.2.1.jar
- commons-io-1.4.jar

3. 配置文件上传解析器	**CommonsMultipartResolver**

4. 配置Controller控制器的代码

## 12.1、准备一个文件上传的表单

```html
<html>  
    <head>    
        <title>$Title$</title>  
    </head>
    <body>   
        <%-- 准备一个文件上传的表单 --%>    
        <form action="${pageContext.request.contextPath}/upload" enctype="multipart/form-data" method="post">
            用户名:<input type="text" name="username"/>  <br/>        
            头像: <input type="file" name="photo"/> <br/>        
            <input name="send" type="submit"/>    
        </form>

    </body>
</html>
```

## 12.2、导入文件上传需要的jar包

commons-fileupload-1.2.1.jar

commons-io-1.4.jar

## 12.3、配置文件上传解析器

```xml
<!-- 配置解析上传数据的解析器
      而且要求id值必须是: multipartResolver ( 否则不能使用 )
 -->
<bean id="multipartResolver"
      class="org.springframework.web.multipart.commons.CommonsMultipartResolver">
    <!-- 配置字符集,防止中文乱码 -->
    <property name="defaultEncoding" value="UTF-8" />
</bean>
```

## 12.4、编写文件上传的Controller控制器中的代码：

```java
/**
     * 文件上传
     *
     * @return
     */
    @RequestMapping("fileUpload")
    public String fileUpload(@RequestParam("username") String username, @RequestParam("photo") MultipartFile photo) {
        System.err.println("用户名称是" + username);
        //生成一个文件名称
        String fileName = UUID.randomUUID().toString().replaceAll("-", "") + ".";
        //substring:字符串截取(start,end)
        String fileNameExt = photo.getOriginalFilename().substring(photo.getOriginalFilename().lastIndexOf(".") + 1);
        //具体文件名称
        fileName += fileNameExt;
        //上传文件
        try {
            File file = new File("C:/workspace/0621/" + fileName);
            photo.transferTo(file);
            String path = file.getAbsolutePath();
            //<img src="${path}"/>
            //存入数据库---关联与当前文件有关的是其他数据
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "success";
    }
```

## 使用ResponseEntity返回值处理文件下载

```java

    /**
     * @param fileName 下载的文件名
     * @return
     */
    @RequestMapping(value = "/download")
    public ResponseEntity<byte[]> download(String fileName, HttpSession session) throws IOException {
    // 获取ServletContext对象
    ServletContext context = session.getServletContext();
    // 1 读取需要下载的文件内容( 获取它的数据 )
    InputStream resourceAsStream = context.getResourceAsStream("/files/" + fileName);
    // 将流中听数据直接转换字节数组
    byte[] bytes = IOUtils.toByteArray(resourceAsStream);
    resourceAsStream.close();
    // 获取指定文件的数据类型
    String mimeType = context.getMimeType("/files/" + fileName);
    // 文件下载大概的步骤如下:
    // 3 设置响应头 ContentType 告诉浏览器 返回的数据类型
    // 4 设置响应头,Content-Disposition 告诉浏览器,收到的数据,怎么处理
    MultiValueMap headers = new HttpHeaders();
    headers.add("Content-Type", mimeType); // 添加一个响应头
    headers.add("Content-Disposition", "attachement; filename=" + fileName);
    /**
         * 第一个参数是 : 响应体 <br/>
         * 第二个参数是 : 响应头 <br/>
         * 第三个参数是 : 响应行( 响应状态码 )
         */
    // 2 将下载的文件内容保存到,响应体中
    ResponseEntity<byte[]> responseEntity = new ResponseEntity<>(bytes, headers, HttpStatus.OK);
    return responseEntity;
}
```

# 13、HandlerInterceptor拦截器

## 13.1、HandlerInterceptor拦截器的介绍

SpringMVC的拦截器和JavaWeb的Filter过滤器非常接近.( 就是对请求的目标资源进行拦截,做一些操作,然后决定是否放行. )

使用的步骤如下:

1. 先编写一个类去实现HandlerInterceptor接口
2. 实现拦截器的方法
3. 到springMVC.xml中去配置拦截器的拦截路径

## 13.2、单个HandlerInterceptor拦截器的示例

1、编写一个类去实现HandlerInterceptor接口

2、到Spring的容器配置文件中去配置拦截器，让SpringMVC知道都拦截哪些目标方法

Controller中的代码:

```java
@Controller
public class HelloController {
    @RequestMapping(value = "/hello")
    public String hello() {
        System.out.println(" 这是controller#hello() ");
        return "ok";
   }
}
```

拦截器:

```java
public class FirstHandlerInceptor implements HandlerInterceptor {
    /**
     * 目标方法之前的操作 <br/>
     * * @return
     *
     * @throws Exception
     */
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        System.out.println(" frist preHandle() ");
        // 返回值决定是否放行==目标资源
        // 返回true 表示可以访问目标资源
        // 返回false 表示不允许访问目标资源
        return true;
    }

    /**
     * 目标方法之后的操作
     *
     * @throws Exception
     */
    @Override
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler, ModelAndView modelAndView) throws Exception {
        System.out.println(" frist postHandle() ");
    }

    /**
     * 页面渲染完毕
     *
     * @param request
     * @param response
     * @param handler
     * @param ex
     * @throws Exception
     */
    @Override
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler, Exception ex) throws Exception {
        System.err.println("页面渲染完毕");
    }
}
```

SpringMVC的配置文件:

```xml
<!-- 配置拦截器 -->
<mvc:interceptors>
    <mvc:interceptor>
        <!-- path配置拦截的路径 -->
        <mvc:mapping path="/hello"/>
        <!-- 拦截器是哪个类 -->
        <bean class="com.atguigu.incerptor.FirstHandlerInceptor"/>
    </mvc:interceptor>
</mvc:interceptors>

拦截全部
<mvc:interceptors>
    <!-- 拦截器是哪个类 -->
    <bean class="com.atguigu.interceptor.FirstHandlerInceptor"/>
</mvc:interceptors>
```

正常情况下.它拉执行顺序是:

​	preHandle()  ==>>  目标方法  ==>> postHandle()  ==>>  渲染页面  ==>> afterCompletion() 

面试:拦截器与过滤器的区别?

## 13.3、单个拦截器异常时的执行顺序

一：目标方法前返回false的情况：

1. 目标方法前执行 	返回false
2. 这是目标方法			不执行
3. 目标方法之后			不执行
4. 这是渲染页面			不执行
5. 页面渲染完成！		不执行

二：目标方法前返回true的情况，目标方法异常

1. 目标方法前执行 	返回true
2. 这是目标方法			异常
3. 目标方法之后			不执行
4. 这是渲染页面			渲染异常页面
5. 页面渲染完成！		执行

三：目标方法前返回true的情况，目标方法后异常

1. 目标方法前执行 	返回true
2. 这是目标方法			执行
3. 目标方法之后			异常
4. 这是渲染页面			渲染异常页面
5. 页面渲染完成！		执行

四：目标方法前返回true的情况，渲染页面异常

1. 目标方法前执行 	返回true
2. 这是目标方法			执行
3. 目标方法之后			执行
4. 这是渲染页面			异常
5. 页面渲染完成！		执行

## 多个拦截器的执行介绍：

![](SpringMVC.assets\1575693-20190304145305454-1179901883.png)

 frist preHandle() 					第一个前置

 second preHandle() 				第一个前置

 这是controller#hello() 			目标方法

 second postHandle() 				第二个后置

 frist postHandle() 					  第一个后置

 这是ok.jsp页面 					       渲染页面

 second afterCompletion() 			第二个页面渲染完成

 frist afterCompletion() 				第一个页面渲染完成

多个拦截器异常情况下,我们只需要记住一点 : **如果preHandle() 方法返回了true.它的afterCompletion() 方法就一定会执行,由于目标方法不执行,所以postHandle()不会执行**

```xml
<mvc:interceptors>
    <mvc:interceptor>
        <mvc:mapping path="/hello"/>
        <bean class="com.atguigu.intercepter.FirstHandlerInceptor"></bean>
    </mvc:interceptor>
    <mvc:interceptor>
        <mvc:mapping path="/hello"/>
        <bean class="com.atguigu.intercepter.SecondHandlerInceptor"></bean>
    </mvc:interceptor>
</mvc:interceptors>
```

# SpringMVC 拦截器执行源码解析：

1:查看前端控制器中doDispatch(HttpServletRequest request, HttpServletResponse response)

1. 发现handler获取之后获取得到所有拦截器,正序;获取后置方法|页面渲染完毕方法(倒序)
2. 执行是先执行前置拦截器,会判断里面的返回值,如果返回false,那么会执行页面渲染完毕方法(相对于多个拦截器)(后置拦截器则不执行)

2:查看

```
// Determine handler for the current request.
返回拦截器链
mappedHandler = getHandler(processedRequest);
```

3:断点进入

```
@Nullable
protected HandlerExecutionChain getHandler(HttpServletRequest request) throws Exception {
   if (this.handlerMappings != null) {
      for (HandlerMapping mapping : this.handlerMappings) {
         //获取handler链
         HandlerExecutionChain handler = mapping.getHandler(request);
         if (handler != null) {
            return handler;
         }
      }
   }
   return null;
}
```

4:进入getHandler

```
获取handler链
HandlerExecutionChain executionChain = getHandlerExecutionChain(handler, request);
```

5:查看getHandlerExecutionChain

```java
protected HandlerExecutionChain getHandlerExecutionChain(Object handler, HttpServletRequest request) {
    HandlerExecutionChain chain = (handler instanceof HandlerExecutionChain ?
                                   (HandlerExecutionChain) handler : new HandlerExecutionChain(handler));

    String lookupPath = this.urlPathHelper.getLookupPathForRequest(request, LOOKUP_PATH);
    for (HandlerInterceptor interceptor : this.adaptedInterceptors) {
        if (interceptor instanceof MappedInterceptor) {
            MappedInterceptor mappedInterceptor = (MappedInterceptor) interceptor;
            if (mappedInterceptor.matches(lookupPath, this.pathMatcher)) {
                chain.addInterceptor(mappedInterceptor.getInterceptor());
            }
        }
        else {
            放入链中
            chain.addInterceptor(interceptor);
        }
    }
    return chain;
}
```

6:再次回到doDispatch()

```
执行前置
if (!mappedHandler.applyPreHandle(processedRequest, response)) {
return;
}
```

7:进入前置

```java
boolean applyPreHandle(HttpServletRequest request, HttpServletResponse response) throws Exception {
   得到所有拦截器
   HandlerInterceptor[] interceptors = getInterceptors();
   if (!ObjectUtils.isEmpty(interceptors)) {
      for (int i = 0; i < interceptors.length; i++) {
         HandlerInterceptor interceptor = interceptors[i];
          //执行前置:会进入我们自己拦截器的前置方法中,返回false,则为true
         if (!interceptor.preHandle(request, response, this.handler)) {
            //页面渲染方法 
            triggerAfterCompletion(request, response, null);
            return false;
         }
         this.interceptorIndex = i;
      }
   }
   return true;
}
```

8:页面渲染方法

```java
private void triggerAfterCompletion(HttpServletRequest request, HttpServletResponse response,
                                    @Nullable HandlerExecutionChain mappedHandler, Exception ex) throws Exception {

    if (mappedHandler != null) {
        mappedHandler.triggerAfterCompletion(request, response, ex);
    }
    throw ex;
}

void triggerAfterCompletion(HttpServletRequest request, HttpServletResponse response, @Nullable Exception ex)
			throws Exception {

		HandlerInterceptor[] interceptors = getInterceptors();
		if (!ObjectUtils.isEmpty(interceptors)) {
			for (int i = this.interceptorIndex; i >= 0; i--) {
				HandlerInterceptor interceptor = interceptors[i];
				try {
                    //拦截器页面渲染方法
					interceptor.afterCompletion(request, response, this.handler, ex);
				}
				catch (Throwable ex2) {
					logger.error("HandlerInterceptor.afterCompletion threw exception", ex2);
				}
			}
		}
	}
```

9:整体doDispatch执行顺序

```java
protected void doDispatch(HttpServletRequest request, HttpServletResponse response) throws Exception {
    // Determine handler for the current request.
    1:获取handler链包括拦截器链
    mappedHandler = getHandler(processedRequest);
    if (mappedHandler == null) {
        noHandlerFound(processedRequest, response);
        return;
    }
    2:执行前置:在前置中如果不放行那么会触发页面渲染完毕方法
    if (!mappedHandler.applyPreHandle(processedRequest, response)) {
        return;
    }
    3:后置
    mappedHandler.applyPostHandle(processedRequest, response, mv);
}
catch (Exception ex) {
    dispatchException = ex;
}
catch (Throwable err) {
    dispatchException = new NestedServletException("Handler dispatch failed", err);
}
processDispatchResult(processedRequest, response, mappedHandler, mv, dispatchException);
}
catch (Exception ex) {
    4:页面渲染完毕
    triggerAfterCompletion(processedRequest, response, mappedHandler, ex);
}
catch (Throwable err) {
     5:页面渲染完毕
    triggerAfterCompletion(processedRequest, response, mappedHandler,
                           new NestedServletException("Handler processing failed", err));
}
}
```

面试:拦截器在Handler之前还是之后获取?

![](SpringMVC.assets\无标题.png)

![](SpringMVC.assets\无标题-1597129170123.png)

# 视图源码解析：

1:doDispatch

```
处理调度结果
processDispatchResult(processedRequest, response, mappedHandler, mv, dispatchException)
```

2:进入processDispatchResult

```
private void processDispatchResult(HttpServletRequest request, HttpServletResponse response,
      @Nullable HandlerExecutionChain mappedHandler, @Nullable ModelAndView mv,
      @Nullable Exception exception) throws Exception {

   处理程序是否返回了要渲染的视图
   // Did the handler return a view to render?
   if (mv != null && !mv.wasCleared()) {
      渲染
      render(mv, request, response);
      if (errorView) {
         WebUtils.clearErrorRequestAttributes(request);
      }
   }
   else {
      if (logger.isTraceEnabled()) {
         logger.trace("No view rendering, null ModelAndView returned.");
      }
   }

   if (WebAsyncUtils.getAsyncManager(request).isConcurrentHandlingStarted()) {
      // Concurrent handling started during a forward
      return;
   }

   if (mappedHandler != null) {
      // Exception (if any) is already handled..
      mappedHandler.triggerAfterCompletion(request, response, null);
   }
}
```

3:render

```java
protected void render(ModelAndView mv, HttpServletRequest request, HttpServletResponse response) throws Exception {
    // Determine locale for request and apply it to the response.
    国际化组件
    Locale locale =
        (this.localeResolver != null ? this.localeResolver.resolveLocale(request) : request.getLocale());
    response.setLocale(locale);

    View view;
    获取视图名称
    String viewName = mv.getViewName();
    if (viewName != null) {
        // We need to resolve the view name.
        解析视图名称
        view = resolveViewName(viewName, mv.getModelInternal(), locale, request);
        if (view == null) {
            throw new ServletException("Could not resolve view with name '" + mv.getViewName() +
                                       "' in servlet with name '" + getServletName() + "'");
        }
    }
        渲染:见最后
        view.render(mv.getModelInternal(), request, response);
    }
    catch (Exception ex) {
        if (logger.isDebugEnabled()) {
            logger.debug("Error rendering view [" + view + "]", ex);
        }
        throw ex;
    }
}
```

4:resolveViewName

```
@Nullable
protected View resolveViewName(String viewName, @Nullable Map<String, Object> model,
      Locale locale, HttpServletRequest request) throws Exception {

   if (this.viewResolvers != null) {
      for (ViewResolver viewResolver : this.viewResolvers) {
         解析视图名称
         View view = viewResolver.resolveViewName(viewName, locale);
         if (view != null) {
            return view;
         }
      }
   }
   return null;
}
```

5:resolveViewName

```
public View resolveViewName(String viewName, Locale locale) throws Exception {
   缓存中取
   if (!isCache()) {
      创建一个
      return createView(viewName, locale);
   }
   else {
      Object cacheKey = getCacheKey(viewName, locale);
      View view = this.viewAccessCache.get(cacheKey);
      if (view == null) {
         synchronized (this.viewCreationCache) {
            view = this.viewCreationCache.get(cacheKey);
            if (view == null) {
               // Ask the subclass to create the View object.
               view = createView(viewName, locale);
               if (view == null && this.cacheUnresolved) {
                  view = UNRESOLVED_VIEW;
               }
               if (view != null && this.cacheFilter.filter(view, viewName, locale)) {
                  同步更新缓存
                  this.viewAccessCache.put(cacheKey, view);
                  this.viewCreationCache.put(cacheKey, view);
               }
            }
         }
      }
      else {
         if (logger.isTraceEnabled()) {
            logger.trace(formatKey(cacheKey) + "served from cache");
         }
      }
      return (view != UNRESOLVED_VIEW ? view : null);
   }
}
```

6:createView

```java
@Override
protected View createView(String viewName, Locale locale) throws Exception {
    // If this resolver is not supposed to handle the given view,
    // return null to pass on to the next resolver in the chain.
    if (!canHandle(viewName, locale)) {
        return null;
    }
	
    重定向
    // Check for special "redirect:" prefix.
    if (viewName.startsWith(REDIRECT_URL_PREFIX)) {
        String redirectUrl = viewName.substring(REDIRECT_URL_PREFIX.length());
        RedirectView view = new RedirectView(redirectUrl,
                                             isRedirectContextRelative(), isRedirectHttp10Compatible());
        String[] hosts = getRedirectHosts();
        if (hosts != null) {
            view.setHosts(hosts);
        }
        return applyLifecycleMethods(REDIRECT_URL_PREFIX, view);
    }
    
 	转发  
    // Check for special "forward:" prefix.
    if (viewName.startsWith(FORWARD_URL_PREFIX)) {
        String forwardUrl = viewName.substring(FORWARD_URL_PREFIX.length());
        InternalResourceView view = new InternalResourceView(forwardUrl);
        return applyLifecycleMethods(FORWARD_URL_PREFIX, view);
    }

    // Else fall back to superclass implementation: calling loadView.
    return super.createView(viewName, locale);
}

```

7:RedirectView

```java
@Override
	protected void renderMergedOutputModel(Map<String, Object> model, HttpServletRequest request,
			HttpServletResponse response) throws IOException {

		String targetUrl = createTargetUrl(model, request);
		targetUrl = updateTargetUrl(targetUrl, model, request, response);

		// Save flash attributes
		RequestContextUtils.saveOutputFlashMap(targetUrl, request, response);

		// Redirect
		sendRedirect(request, response, targetUrl, this.http10Compatible);
	}

```

8:InternalResourceView

```
@Override
protected void renderMergedOutputModel(
      Map<String, Object> model, HttpServletRequest request, HttpServletResponse response) throws Exception {

   // Expose the model object as request attributes.
   exposeModelAsRequestAttributes(model, request);

   // Expose helpers as request attributes, if any.
   exposeHelpers(request);

   // Determine the path for the request dispatcher.
   String dispatcherPath = prepareForRendering(request, response);

   // Obtain a RequestDispatcher for the target resource (typically a JSP).
   RequestDispatcher rd = getRequestDispatcher(request, dispatcherPath);
   if (rd == null) {
      throw new ServletException("Could not get RequestDispatcher for [" + getUrl() +
            "]: Check that the corresponding file exists within your web application archive!");
   }

   // If already included or response already committed, perform include, else forward.
   if (useInclude(request, response)) {
      response.setContentType(getContentType());
      if (logger.isDebugEnabled()) {
         logger.debug("Including [" + getUrl() + "]");
      }
      rd.include(request, response);
   }

   else {
      // Note: The forwarded resource is supposed to determine the content type itself.
      if (logger.isDebugEnabled()) {
         logger.debug("Forwarding to [" + getUrl() + "]");
      }
      rd.forward(request, response);
   }
}
```

9:createView创建视图

```
return super.createView(viewName, locale);
```

10:super.createView(viewName, locale);

```
@Nullable
protected View createView(String viewName, Locale locale) throws Exception {
   return loadView(viewName, locale);
}
```

11:构建视图

```java
protected View loadView(String viewName, Locale locale) throws Exception {
    AbstractUrlBasedView view = buildView(viewName);
    View result = applyLifecycleMethods(viewName, view);
    return (view.checkResource(locale) ? result : null);
}
```

12:super.buildView

```
@Override
protected AbstractUrlBasedView buildView(String viewName) throws Exception {
   InternalResourceView view = (InternalResourceView) super.buildView(viewName);
   if (this.alwaysInclude != null) {
      view.setAlwaysInclude(this.alwaysInclude);
   }
   view.setPreventDispatchLoop(true);
   return view;
}
```

13:渲染

```
view.render(mv.getModelInternal(), request, response);
```

14:render

```java
@Override
public void render(@Nullable Map<String, ?> model, HttpServletRequest request,
      HttpServletResponse response) throws Exception {

   if (logger.isDebugEnabled()) {
      logger.debug("View " + formatViewName() +
            ", model " + (model != null ? model : Collections.emptyMap()) +
            (this.staticAttributes.isEmpty() ? "" : ", static attributes " + this.staticAttributes));
   }
   拿到model中数据填充到mergedModel中	
   Map<String, Object> mergedModel = createMergedOutputModel(model, request, response);
   prepareResponse(request, response);
   放入request域中 
   renderMergedOutputModel(mergedModel, getRequestToExpose(request), response);
}
```

15:再次回到renderMergedOutputModel

```
@Override
protected void renderMergedOutputModel(
      Map<String, Object> model, HttpServletRequest request, HttpServletResponse response) throws Exception {

   // Expose the model object as request attributes.
   放入request域
   exposeModelAsRequestAttributes(model, request);

   // Expose helpers as request attributes, if any.
   exposeHelpers(request);

   // Determine the path for the request dispatcher.
   得到请求路径
   String dispatcherPath = prepareForRendering(request, response);

   // Obtain a RequestDispatcher for the target resource (typically a JSP).
   RequestDispatcher rd = getRequestDispatcher(request, dispatcherPath);
   if (rd == null) {
      throw new ServletException("Could not get RequestDispatcher for [" + getUrl() +
            "]: Check that the corresponding file exists within your web application archive!");
   }

   // If already included or response already committed, perform include, else forward.
   if (useInclude(request, response)) {
      response.setContentType(getContentType());
      if (logger.isDebugEnabled()) {
         logger.debug("Including [" + getUrl() + "]");
      }
      rd.include(request, response);
   }

   else {
      // Note: The forwarded resource is supposed to determine the content type itself.
      if (logger.isDebugEnabled()) {
         logger.debug("Forwarding to [" + getUrl() + "]");
      }
      rd.forward(request, response);
   }
}
```

16:exposeModelAsRequestAttributes

```java
protected void exposeModelAsRequestAttributes(Map<String, Object> model,
                                              HttpServletRequest request) throws Exception {

    model.forEach((name, value) -> {
        if (value != null) {
            request.setAttribute(name, value);
        }
        else {
            request.removeAttribute(name);
        }
    });
}
```

17:prepareForRendering

```java
protected String prepareForRendering(HttpServletRequest request, HttpServletResponse response)
    throws Exception {

    String path = getUrl();
    Assert.state(path != null, "'url' not set");

    if (this.preventDispatchLoop) {
        String uri = request.getRequestURI();
        if (path.startsWith("/") ? uri.equals(path) : uri.equals(StringUtils.applyRelativePath(uri, path))) {
            throw new ServletException("Circular view path [" + path + "]: would dispatch back " +
                                       "to the current handler URL [" + uri + "] again. Check your ViewResolver setup! " +
                                       "(Hint: This may be the result of an unspecified view, due to default view name generation.)");
        }
    }
    return path;
}
```

![image-20200810230509374](SpringMVC.assets\image-20200810230509374-1597118239454.png)

![](SpringMVC.assets\无标题-1597118239455.png)

![](SpringMVC.assets\无标题-1597130847407.png)