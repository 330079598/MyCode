# 02-SpringMVC

# 8、数据在域中的保存

## 8.1、Request对象中保存数据

Controller中的代码:

```java
@RequestMapping("/requestScope")
public String requestScope(HttpServletRequest request){
    System.println( "requestScope() 方法调用了" );
    request.setAttribute("reqKey1", "reqValue1");
    request.setAttribute("reqKey2", "reqValue2");
    return "scope";
}
```

jsp页面的输出测试:

request域中 reqKey1 的值是 ==>> ${requestScope.reqKey1} <br/>
request域中 reqKey2 的值是 ==>> ${requestScope.reqKey2} <br/>

## 8.2、Session域中保存数据

Controller中的代码:

```java
@RequestMapping("/sessionScope")
public String sessionScope(HttpSession session){
    System.out.println( "sessionScope() 方法调用了" );
    session.setAttribute("sessionKey1", "sessionValue1");
    session.setAttribute("sessionKey2", "sessionValue2");
    return "scope";
}
```

jsp页面的输出:

session 域中 sessionKey1 的值是 ==>> ${sessionScope.sessionKey1} <br/>
session 域中 sessionKey2 的值是 ==>> ${sessionScope.sessionKey2} <br/>

## 8.3、ServletContext域中保存数据

在Controller中的代码。在Controller的中获取SerlvetContext对象有两种方法，

一种是@Autowired注入，

一种是通过Session获取。

Context中的代码:  

```java
pageContext.setAttribute(k,v,(1,2,3,4))
//获取ServletContext对象
@Autowired
ServletContext context;

@RequestMapping("/servletContextScope")
public String servletContextScope(HttpSession session){
    //从session中获取ServletContext对象
    ServletContext context = session.getServletContext();
    System.out.println( "servletContextScope() 方法调用了" );
    context.setAttribute("contextKey1", "contextValue1");
    context.setAttribute("contextKey2", "contextValue2");
    return "scope";
}
```

jsp页面的输出:

ServletContext 域中 contextKey1 的值是 ==>> ${applicationScope.contextKey1} <br/>
ServletContext 域中 contextKey2 的值是 ==>> ${applicationScope.contextKey2} <br/>

## 8.4、Map或Model或ModelMap形式保存数据在request域中

在四个域中，我们使用最频繁的域就是request对象。

往request域对象中，保存数据，还在以下的几种形式。

我们可以在Controller的方法中，添加Map类型的参数，或者是Model类型的参数。或者是ModelMap类型的参数。都可以直接用来保存域数据到Request对象中。

Map全类名是：					java.util.Map

Model全类名是：				org.springframework.ui.Model

ModelMap全类名是：		org.springframework.ui.ModelMap

Map形式保存数据到Reqeust域中:

```java
@RequestMapping("/mapToRequest")
public String mapToRequest(Map<String,Object> map){
  System.out.println( " mapToRequest () 方法调用了" );
  // 这些数据同时也会同步到Reqeust域中
  map.put("key1", "value1");
  map.put("key2", "value2");
  return "scope";
}
```

```
map 中 key1 的值是 ==>> ${requestScope.key1} <br/>
map 中 key2 的值是 ==>> ${requestScope.key1} <br/>
```

Model形式保存数据到Reqeust域 中:

```java
@RequestMapping("/modelToRequest")
public String modelToRequest(Model model){
  System.out.println( " modelToRequest () 方法调用了" );
  // 这些数据同时也会同步到Reqeust域中
  model.addAttribute("modelKey1", "modelValue1");
  model.addAttribute("modelKey2", "modelValue2");
  return "scope";
}
```

```
Model 中 key1 的值是 ==>> ${requestScope.modelKey1} <br/>
Model 中 key2 的值是 ==>> ${requestScope.modelKey1} <br/>
```

ModelMap形式保存数据到Request域中.

```java
@RequestMapping("/modelMapToRequest")
public String modelMapToRequest(ModelMap modelMap){
  System.out.println( " modelMapToRequest () 方法调用了" );
  // 这些数据同时也会同步到Reqeust域中
  modelMap.addAttribute("modelMapKey1", "modelMapValue1");
  modelMap.addAttribute("modelMapKey2", "modelMapValue2");
  return "scope";
}
```

```
ModelMap 中 modelMapKey1 的值是 ==>> ${requestScope.modelMapKey1} <br/>
ModelMap 中 modelMapKey1 的值是 ==>> ${requestScope.modelMapKey1} <br/>
```

BindingAwareModelMap隐含模型对象的介绍

```java
/**
     *  
     * BindingAwareModelMap 对象,我们管它叫隐含模型对象 <br/> 
     *  隐含模型对象的作用是 :  给视图准备需要渲染的数据<br/> 
     *  隐含,是不需要你自己手动定义<br/> 
     *  模型保存数据的对象<br/> 
     *  视图,就是用户最终收到的数据的一个载体 (html页面,jsp页面) <br/> 
     *  渲染,就是执行视图的代码叫渲染<br/> 
     *  视图需要的数据,其实就是 页面上显示的数据 <br/> 
     *  
     * class org.springframework.validation.support.BindingAwareModelMap 类                                
     * BindingAwareModelMap extends ExtendedModelMap          
     * ExtendedModelMap extends ModelMap implements Model         
     * ModelMap extends LinkedHashMap<String, Object> 
     */
    @RequestMapping("/mapAndModelAndModelMap")
    public String mapAndModelAndModelMap(Map<String, Object> map, Model model, ModelMap modelMap) {
        System.out.println(map);
        System.out.println(model);
        System.out.println(modelMap);
        System.out.println("==================================================");

        map.put("map1", "mapv1");
        System.out.println(map);
        System.out.println(model);
        System.out.println(modelMap);
        System.out.println("==================================================");

        model.addAttribute("model1", "modelv1");
        System.out.println(map);
        System.out.println(model);
        System.out.println(modelMap);
        System.out.println("==================================================");

        modelMap.addAttribute("modelMap1", "modelMapv1");
        System.out.println(map);
        System.out.println(model);
        System.out.println(modelMap);
        System.out.println("==================================================");

        System.out.println(map.getClass());
        System.out.println(model.getClass());
        System.out.println(modelMap.getClass());
        return "scope";
    }
```

## 8.5、ModelAndView方式保存数据到request域中

ModelAndView 分为两部分:

一 , 是Model ,就是模型数据( 同隐含模型数据一样,就是给页面视图渲染使用 )

二 , 是 view 视图

Controller代码:

```java
@RequestMapping("/modelAndViewToRequest")
public ModelAndView modelAndViewToRequest(){
    //创建模型和视图对象
    ModelAndView modelAndView = new ModelAndView("scope");
    System.out.println(" modelAndViewToRequest () 方法调用了");
    // 这些数据也会同步 到 Reqeust 域中
    modelAndView.addObject("mavKey1","mavValue1");
    modelAndView.addObject("mavKey2","mavValue2");
    return modelAndView;
}
```

jsp输出测试:

<hr>
Request 域中 mavKey1 的值是 ==>> ${requestScope.mavKey1} <br/>
Request 域中 mavKey2 的值是 ==>> ${requestScope.mavKey2} <br/>

## 8.6、@SessionAttributes保存数据到Session域中（了解内容）

@SessionAttributes 注解可以标注在类上。它的作用是指定隐含模型中哪些数据也同步到Session域中。@SessionAttributes(value = { "key1","key2" }, types = { String.class, Book.class })

value属性，它表示把request域中key为key1，key2的键值对信息，也保存到Session中

types属性，它表示把request域中value类型为String.class\**或Book.class类型的键值对，也保存到Session中

Controller中的代码:

```java
/**
 * @SessionAttributes 是指定隐含模型中哪些数据可以同步到Session域中 <br/>
 * names   指定 哪些 key 的数据同步 到Session域 <br/>
 * names = {"key1","key2"} 表示key1,和key2的数据,也同步 到Session域中 <br/>
 * types   指定 哪些value 类型的 数据,同步 到Session域中<br/>
 */
@SessionAttributes(types = {Integer.class,Person.class})
@Controller
public class ScopeController {
    @RequestMapping("/sessionAttributesToSession")
    public String sessionAttributesToSession(Map<String,Object> map){
        map.put("key1", "value1");
        map.put("key2",new Integer(100));
        return "scope";
    }
}
```

jsp测试输出:

<hr>
<h1>测试数据也同步到Session中</h1>
Request 域中 key1 的值是 ==>> ${requestScope.key1} <br/>
Request 域中 key2 的值是 ==>> ${requestScope.key2} <br/>
SessionAttributes 中 key1 的值是 ==>> ${sessionScope.key1} <br/>
SessionAttributes 中 key2 的值是 ==>> ${sessionScope.key2} <br/>

## 8.7、@ModelAttribute注解

@ModelAttribute这个注解可以标注在方法和参数上。

@ModelAttribute三个常见作用：

1. 被标注了@ModelAttribute的方法都会在Controller的目标方法之前执行。
2. 目标方法的参数（JavaBean对象）会先从隐含模型中获取值传入。
3. 被标注在参数上，参数值会按照指定的key从隐含模型中获取值。

```java
@ModelAttribute
public void abc(Map<String,Object> map){
    System.out.println("  @ModelAttribute 标识 的方法 abc() ");
    map.put("person1", new Person(100, "技多不压身"));
}

/**
 * 当取值的时候,以是参数的类型的类名,首字母改小写.做为key到隐含模型中取值<br/>
 * 不一致时可以使用@ModelAttribute("person1") 取出指定的key赋值
 * 先拿到@ModelAttribute中的值,再执行我们自己的
 * Person => person
 */
@RequestMapping("/target")
public String target(@ModelAttribute("person1") Person person){
    System.out.println(" target() 方法 ==>> " + person);
    return "scope";
}
```

# 9、传统的增删改查   ( 使用SpringMVC框架 )

## 9.1、准备单表的数据库

```sql
CREATE DATABASE IF NOT EXISTS springmvc DEFAULT CHARSET utf8;

use springmvc; 

##创建图书表

create table t_book(
	`id` int(11) primary key auto_increment, 	## 主键
	`name` varchar(50) not null,				## 书名 
	`author` varchar(50) not null,				## 作者
	`price` decimal(11,2) not null,				## 价格
	`sales` int(11) not null,					## 销量
	`stock` int(11) not null					## 库存
);

## 插入初始化测试数据

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , 'java从入门到放弃' , '国哥' , 80 , 9999 , 9);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '数据结构与算法' , '严敏君' , 78.5 , 6 , 13);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '怎样拐跑别人的媳妇' , '龙伍' , 68, 99999 , 52);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '木虚肉盖饭' , '小胖' , 16, 1000 , 50);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , 'C++编程思想' , '刚哥' , 45.5 , 14 , 95);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '蛋炒饭' , '周星星' , 9.9, 12 , 53);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '赌神' , '龙伍' , 66.5, 125 , 535);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , 'Java编程思想' , '阳哥' , 99.5 , 47 , 36);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , 'JavaScript从入门到精通' , '婷姐' , 9.9 , 85 , 95);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , 'cocos2d-x游戏编程入门' , '国哥' , 49, 52 , 62);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , 'C语言程序设计' , '谭浩强' , 28 , 52 , 74);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , 'Lua语言程序设计' , '雷丰阳' , 51.5 , 48 , 82);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '西游记' , '罗贯中' , 12, 19 , 9999);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '水浒传' , '华仔' , 33.05 , 22 , 88);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '操作系统原理' , '刘优' , 133.05 , 122 , 188);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '数据结构 java版' , '封大神' , 173.15 , 21 , 81);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , 'UNIX高级环境编程' , '乐天' , 99.15 , 210 , 810);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , 'javaScript高级编程' , '国哥' , 69.15 , 210 , 810);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '大话设计模式' , '国哥' , 89.15 , 20 , 10);

insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) 
values(null , '人月神话' , '刚哥' , 88.15 , 20 , 80); 

## 查看表内容
select id,name,author,price,sales,stock from t_book;
```

## 9.2、SpringMVC的单表的增，删，改，查

创建一个web的模块,并导入需要的jar包:

- druid-1.1.9.jar
- junit_4.12.jar
- mysql-connector-java-5.1.37-bin.jar
- org.hamcrest.core_1.3.0.jar
- spring-aop-5.2.5.RELEASE.jar
- spring-beans-5.2.5.RELEASE.jar
- spring-context-5.2.5.RELEASE.jar
- spring-core-5.2.5.RELEASE.jar
- spring-expression-5.2.5.RELEASE.jar
- spring-jcl-5.2.5.RELEASE.jar
- spring-jdbc-5.2.5.RELEASE.jar
- spring-orm-5.2.5.RELEASE.jar
- spring-test-5.2.5.RELEASE.jar
- spring-tx-5.2.5.RELEASE.jar
- spring-web-5.2.5.RELEASE.jar
- spring-webmvc-5.2.5.RELEASE.jar

![img](SpringMVC.assets\wps1.jpg) 

配置jdbc.properties属性配置文件

```properties
user=root
password=root
url=jdbc:mysql://localhost:3306/springmvc?characterEncoding=UTF-8
driverClassName=com.mysql.jdbc.Driver
initialSize=5
maxActive=10
```

配置springmvc.xml配置文件:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd http://www.springframework.org/schema/context https://www.springframework.org/schema/context/spring-context.xsd">

    <!-- 加载配置文件 -->
    <context:property-placeholder location="classpath:jdbc.properties"/>

    <!-- 注解扫描 -->
    <context:component-scan base-package="com.atguigu"/>

    <!-- 连接池 -->
    <bean id="dataSource" class="com.alibaba.druid.pool.DruidDataSource">
        <property name="name" value="${driverClassName}"/>
        <property name="url" value="${url}"/>
        <property name="username" value="${user}"/>
        <property name="password" value="${password}"/>
        <property name="initialSize" value="${initialSize}"/>
        <property name="maxActive" value="${maxActive}"/>
    </bean>

    <!-- 视图解析器 -->
    <bean id="viewResolver" class="org.springframework.web.servlet.view.InternalResourceViewResolver">
        <property name="prefix" value="/book/"/>
        <property name="suffix" value=".jsp"/>
    </bean>


    <bean id="jdbcTemplate" class="org.springframework.jdbc.core.JdbcTemplate">
        <property name="dataSource" ref="dataSource"/>
    </bean>

</beans>
```

配置web.xml配置文件:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
    <servlet>
        <servlet-name>dispatcherServlet</servlet-name>
        <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>
        <init-param>
            <param-name>contextConfigLocation</param-name>
            <param-value>classpath:springmvc.xml</param-value>
        </init-param>
        <load-on-startup>1</load-on-startup>
    </servlet>
    <servlet-mapping>
        <servlet-name>dispatcherServlet</servlet-name>
        <url-pattern>/</url-pattern>
    </servlet-mapping>
</web-app>
```

测试:

```java
@ContextConfiguration(locations = "classpath:springmvc.xml")
@RunWith(SpringJUnit4ClassRunner.class)
public class SpringTest {
    @Autowired
    DataSource dataSource;
    @Autowired
    JdbcTemplate jdbcTemplate;
    @Test
    public void test() throws SQLException {
        System.out.println(dataSource.getConnection());
        System.out.println(jdbcTemplate);
    }
}
```

编写JavaBean ==>> Book

```java
public class Book {
    private Integer id;
    private String name;
    private String author;
    private BigDecimal price;
    private Integer sales;
    private Integer stock;

}
```

编写 BookDao 类  

```java
@Repository
public class BookDao {

    @Autowired
    private JdbcTemplate jdbcTemplate;

    public int saveBook(Book book) {
        String sql = "insert into t_book(`id` , `name` , `author` , `price` , `sales` , `stock`) values (?,?,?,?,?,?)";
        return jdbcTemplate.update(sql, book.getId(), book.getName(), book.getAuthor(), book.getPrice(), book.getSales(), book.getStock());
    }

    public int deleteBook(Integer id) {
        String sql = "delete from t_book where id = ?";
        return jdbcTemplate.update(sql, id);
    }


    public int updateBook(Book book) {
        String sql = "update t_book set name = ?,author=?,price=?,sales=?,stock=? where id = ?";
        return jdbcTemplate.update(sql, book.getName(), book.getAuthor(), book.getPrice(), book.getSales(), book.getStock(), book.getId());
    }

   public Book findById(Integer id) {
        String sql = "select `id` , `name` , `author` , `price` , `sales` , `stock` from t_book where id = ? ";
        return jdbcTemplate.queryForObject(sql, new BeanPropertyRowMapper<Book>(Book.class),id);
    }

    public List<Book> findList() {
        String sql = "select `id` , `name` , `author` , `price` , `sales` , `stock` from t_book ";
        return jdbcTemplate.query(sql, new BeanPropertyRowMapper<Book>(Book.class));
    }

}
```

BookDao的测试:

```java
package com.atguigu.test;

import com.atguigu.dao.BookDao;
import com.atguigu.pojo.Book;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import java.math.BigDecimal;
import java.util.List;

@ContextConfiguration(locations = "classpath:springmvc.xml")
@RunWith(SpringJUnit4ClassRunner.class)
public class BookDaoTest {

    @Autowired
    private BookDao bookDao;

    @Test
    public void test1(){
        List<Book> list = bookDao.findList();
        list.forEach(book -> {
            System.err.println(book);
        });
    }

    @Test
    public void saveBook() {
        bookDao.saveBook(new Book(null,"SpringMVC CRUD 测试", "00316", new BigDecimal(10000),1234,1234));
    }

    @Test
    public void deleteBookById() {
        bookDao.deleteBook(21);
    }

    @Test
    public void updateBookById() {
        bookDao.updateBook(new Book(21,"SpringMVC CRUD 改改改", "00316", new BigDecimal(10000),1234,1234));
    }

    @Test
    public void queryBookById() {
        Book book = bookDao.findById(1);
        System.out.println(book);
    }

}
```

bookService 程序代码:

```java
@Service
public class BookService {

    @Autowired
    private BookDao bookDao;

    public void saveBook(Book book){
        bookDao.saveBook(book);
    }

    public void deleteBookById(Integer id){
        bookDao.deleteBook(id);
    }

    public void updateBookById(Book book){
        bookDao.updateBook(book);
    }

    public Book queryBookbyId(Integer id){
        return bookDao.findById(id);
    }

    public List<Book> queryAllBooks(){
        return bookDao.findList();
    }


}
```

测试代码:

```java
@ContextConfiguration(locations = "classpath:springmvc.xml")
@RunWith(SpringJUnit4ClassRunner.class)
public class BookServiceTest {

    @Autowired
    private BookService bookService;

    @Test
    public void saveBook() {
        bookService.saveBook(new Book(null, "保存", "作死", new BigDecimal(1234), 1234, 1234));
    }

    @Test
    public void deleteBookById() {
        bookService.deleteBookById(22);
    }

    @Test
    public void updateBookById() {
        bookService.updateBookById(new Book(22, "休休休", "作死", new BigDecimal(1234)
                                            , 1234, 1234));
    }

    @Test
    public void queryBookbyId() {
        System.out.println(bookService.queryBookbyId(1));
    }

    @Test
    public void queryAllBooks() {
        bookService.queryAllBooks().forEach(System.out::println);
    }

}
```

拷贝笔记中的crud页面到模块的web目录下:

![img](SpringMVC.assets\wps2.jpg) 

导入jstl标签库的jar包( 也在crud页面目录下 ):

![img](SpringMVC.assets\wps3.jpg) 

BookController中的代码:

```java
@RequestMapping("/list")
public String list(Map<String,Object> map) {
    // 查询全部图书
    // 保存到Request域中
    map.put("books", bookService.queryAllBooks());
    // 请求转发给 /book/bookList.jsp页面
    return "bookList";
}
```

bookList.jsp页面的代码:

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>图书列表</title>
        <%
        String basePath = request.getScheme()
            + "://"
            + request.getServerName()
            + ":"
            + request.getServerPort()
            + request.getContextPath()
            + "/";
        %>
        <base href="<%=basePath %>"/>
        <style type="text/css">
            table {
                border: 1px blue solid;
                width: 700px;
                border-collapse: collapse;
            }

            td, th {
                border: 1px green solid;
            }

            div.menu {
                width: 700px;
                text-align: right;
            }
        </style>
    </head>
    <body>
        <center>
            <h2>图书列表管理页面</h2>
            <div class="menu"><a href="#">添加图书</a></div>
            <table>
                <tr bgcolor="#FF8888">
                    <th>书名</th>
                    <th>作者</th>
                    <th>价格</th>
                    <th>销量</th>
                    <th>库存</th>
                    <th>操作</th>
                </tr>
                <c:forEach items="${requestScope.books}" var="book">
                    <tr>
                        <td>${book.name}</td>
                        <td>${book.author}</td>
                        <td>${book.price}</td>
                        <td>${book.sales}</td>
                        <td>${book.stock}</td>
                        <td><a href="#">删除</a>、<a href="#">修改</a></td>
                    </tr>
                </c:forEach>
            </table>
        </center>
    </body>
</html>
```

报错:

![](SpringMVC.assets\image-20200809191951955.png)



1:在WEB-INF下加入tld依赖

![image-20200809192647532](SpringMVC.assets\image-20200809192647532.png)

删除图书Controller中的代码:

```java
@RequestMapping("/deleteById")
public String deleteById(Integer id) {
    // 通过调用bookService.deleteBookById()删除图书
    bookService.deleteBookById(id);
    // 重定向到图书列表管理页面
    return "redirect:/book/list";
}
```

给删除添加添加class样式:

```xml
<a href="${pageContext.request.contextPath}/book/deleteById?id=${book.id}">删除</a>
```

添加询问功能:

引入jquery

```javascript
<script type="text/javascript" src="${pageContext.request.contextPath}/script/jquery-1.7.2.js"></script>
```

在SpringMVC中我们配置了前端控制器,DispatcherServlet.而它的请求地址是:

```xml
<!-- 配置前端控制器的访问地址 -->
<servlet-mapping>
    <servlet-name>dispatcher</servlet-name>
    <url-pattern>/</url-pattern>
</servlet-mapping>
```

前端控制器的请求地址是 : / 而这个斜框刚好和我们使用的Tomcat服务器中一个用来加载静态资源的Servlet程序的路径重复了,把Tomcat服务器加载静态资源的Servlet程序的覆盖了.

tomcat中web.xml

```xml
 <servlet>
        <servlet-name>default</servlet-name>
        <servlet-class>org.apache.catalina.servlets.DefaultServlet</servlet-class>
        <init-param>
            <param-name>debug</param-name>
            <param-value>0</param-value>
        </init-param>
        <init-param>
            <param-name>listings</param-name>
            <param-value>false</param-value>
        </init-param>
        <load-on-startup>1</load-on-startup>
    </servlet>
 <servlet-mapping>
        <servlet-name>default</servlet-name>
        <url-pattern>/</url-pattern>
    </servlet-mapping>
```

那么需要添加如下的配置,就可以解决静态资源加载的问题:

```xml
<!-- 后面我们只要使用 SpringMVC,都需要添加以下两个配置 -->
<!-- 需要添加配置,让SpringMVC的前端控制器也能处理静态资源 -->
<mvc:default-servlet-handler/>
<!-- 配置支持Springmvc高级注解功能 -->
<mvc:annotation-driven></mvc:annotation-driven>
```

js代码:

```javascript
<script type="text/javascript">
    $(function () {
    $("a.deleteBook").click(function () {
        /**
        * this:js对象
        * $(this):jquery对象
        */
        return confirm("确认要删除["+$(this).parent().parent().find("td:first").text()+"]书吗?");
    })
})
</script>
```

添加图书功能实现

Controller中的代码:

```java
@RequestMapping("/addBook")
public String add(Book book) {
  /**
   * 中文乱码解决方法有两个 <br>
   *   1 请求转为get请求,在Tomcat8之后get请求没有中文乱码 <br/>
   *   2 使用Spring提供的Filter过滤器解决中文乱码问题 <br/>
   */
  // 调用bookService.saveBook()添加图书
  bookService.saveBook(book);
  // 重定向回图书列表管理页面
  return "redirect:/book/list";
}
```

修改bookList.jsp页面中 [ 添加图书 ] 的请求地址

![img](SpringMVC.assets\wps5.jpg) 

bookEdit.jsp页面的修改:

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>图书列表</title>
		<%
			String basePath = request.getScheme() 
								+ "://"
								+ request.getServerName()
								+ ":"
								+ request.getServerPort()
								+ request.getContextPath()
								+ "/";
		%>
		<base href="<%=basePath %>" />
	</head>
	<body>
		<center>
			<h3>添加图书</h3>
			<form action="${pageContext.request.contextPath}/book/addBook">
				<table>
					<tr>
						<td>书名</td>
						<td><input name="name" type="text" /></td>
					</tr>
					<tr>
						<td>作者</td>
						<td><input name="author" type="text" /></td>
					</tr>
					<tr>
						<td>价格</td>
						<td><input name="price" type="text" /></td>
					</tr>
					<tr>
						<td>销量</td>
						<td><input name="sales" type="text" /></td>
					</tr>
					<tr>
						<td>库存</td>
						<td><input name="stock" type="text" /></td>
					</tr>
					<tr>
						<td align="center" colspan="2">
							<input type="submit" />
						</td>
					</tr>
				</table>
			</form>
		</center>
	</body>
</html>
```

修改图书第一步,要先回显图书的信息:

给bookList.jsp页面中 修改 添加请求地址:

![img](SpringMVC.assets\wps6.jpg) 

BookController中的代码:

```java
@RequestMapping("/findBookById")
public String getABook(Integer id,Map<String,Object>map){
    Book book = bookService.queryBookbyId(id);
    map.put("book",book);
    return "bookEdit";
}
```

bookEdit.jsp页面的回显:

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>图书列表</title>
        <%
        String basePath = request.getScheme() 
            + "://"
            + request.getServerName()
            + ":"
            + request.getServerPort()
            + request.getContextPath()
            + "/";
        %>
        <base href="<%=basePath %>" />
    </head>
    <body>
        <center>
            <h3>添加图书</h3>
            <!-- 修改提交地址进行判断 -->
            <form action="${pageContext.request.contextPath}/book/${empty param.id ? 'addBook':'updateBook'}">
                <table>
                    <input type="hidden" name="id" value="${book.id}"/>
                    <tr>
                        <td>书名</td>
                        <td><input name="name" type="text" value="${book.name}" /></td>
                    </tr>
                    <tr>
                        <td>作者</td>
                        <td><input name="author" type="text" value="${book.author}" /></td>
                    </tr>
                    <tr>
                        <td>价格</td>
                        <td><input name="price" type="text" value="${book.price}" /></td>
                    </tr>
                    <tr>
                        <td>销量</td>
                        <td><input name="sales" type="text" value="${book.sales}" /></td>
                    </tr>
                    <tr>
                        <td>库存</td>
                        <td><input name="stock" type="text" value="${book.stock}" /></td>
                    </tr>
                    <tr>
                        <td align="center" colspan="2">
                            <input type="submit" />
                        </td>
                    </tr>
                </table>
            </form>
        </center>
    </body>
</html>
```

java代码:

```java
@RequestMapping("/updateBook")
public String update(Book book) {
    // 调用bookService.updateBook()修改图书
    bookService.updateBookById(book);
    // 重定向到图书列表管理页面
    return "redirect:/book/list";
}
```
