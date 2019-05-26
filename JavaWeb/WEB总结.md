[TOC]

---

------

---



![](/Image/WEB总结.png)



# WEB总结

## web前端

### html
* 基本标签
    * div
    * img
    * a
    * ul li
* 表单标签（重要）
    * form
    * input
        * type属性
            * 代表输入框：text、password
            * 代表选择：radio、checkbox
            * 代表按钮：button、submit、reset、image
            * 特殊的：hidden、file
    * select
        * option
    * textatra
### css
* 选择器
    * 基本选择器
        * id选择器：#id
        * 类选择器：.class
        * 元素选择器：html标签名
    * 层级选择器
    * 属性选择器
        * 基本选择器[属性=‘属性值’]
* 属性和属性值
    * color
    * font-size
    * background
    * display
    * float
    * margin
    * padding
    * border
### js(重点)
* ECMAScript
    * 基本语法
    * 函数
        * 普通函数  function 函数名(参数){函数体}
        * 匿名函数 function(参数){函数体}
    * 事件
        * onclick
        * onsubmit
        * onchange
        * onload
        * onfocus
        * onblur
        * onkeyup
        * onkeydown
        * onmouseover
        * onmouseout
    * js的内置对象
        * Date----var date = new Date();
        * String
* BOM
    * window
        * 弹框的方法
            * alert
            * confirm
            * prompt
        * 定时器
            * setInterval（function,毫秒值）----clearInterval()
            * setTimeout
        * 全局函数 
            * eval()  encodeUrl
    * location
        * href
* DOM
    * 通过js相应的api去获得标签元素和操作标签元素
        * document.getElementById()
        * getElementsByTagName
        * getElementsByName
        * innerHTML
        * getAttribute()
        * appendChild()
### jquery(重点)
* 选择器
    * 基本选择器
        * id
        * class
        * 元素
    * 层级选择器
        * 父元素   子元素
        * 父元素>子元素
    * 属性选择器
        * 基本选择器[属性=‘属性值’]
    * 表单属性过滤选择器 :selected  :checked
* jquery的Dom操作
    * html()
    * val()
    * css()
    * attr()  prop()
    * each()
    * append()  appendTo()  before()  after()
### ajax
* js原生ajax----通过本地浏览器中的ajax引擎
* jquery的ajax
    * $.post(url,data,function,type)
    * $.get()
    * $.ajax({})
### bootstrap
* 1、导入jquery、bootstrap.js、bootstrap.css
* 2、使用栅格系统进行布局
* 3、拷贝bootstrap代码
## web服务器端
### Tomcat服务器
* Servlet
    * 生命周期
        * 创建：默认第一次访问该servlet---init(ServletConfig)
        * 销毁：服务器关闭---destory()
    * request
        * 获得请求行
            * getMethod
            * getContextPath
        * 获得请求头
            * getHeader(name)
        * 获得请求体
            * getParameter/getParameterMap
        * 转发和域对象
            * request.getRequestDispatcher(url).forward();
            * setAttrubute / getAttribute
    * response
        * 设置响应行
            * setStatus()
        * 设置响应头
            * setHeader(name,value)
        * 设置响应体
            * getWriter().write()
            * getOutputStream().write()
* 会话技术
    * cookie
        * 怎样向客户端设置cookie
            * Cookie cookie = new Cookie(name,value)
            * 持久化时间：cookie.setMaxAge()
            * 携带路径：cookie.setPath()
        * 怎样获得客户端的cookie
            * Cookie[] cookies = request.getCookies()
            * cookie.getName()
            * cookie.getValue()
    * session
        * session的生命周期
            * 创建：request.getSession()
            * 销毁：过期、手动销毁session.invalidate()、服务器关闭
        * session域
* jsp/el/jstl
    * jsp
        * 脚本和注释
        * 指令
            * page
            * include（静态包含）
            * taglib
        * 内置对象
            * request
            * response
            * pageContext
            * session
            * application
            * page
            * out
            * config
            * exception
        * jsp标签/动作
            * <jsp:include page=""/> 动态包含
    * el
        * 获得域中数据${}
        * 有11个内置对象
        * 可以进行运算操作
    * jstl
        * <c:if test="">
        * <c:forEach items="" var="" varStatus="">
* listener
    * 6个与于域对象本身相关
        * ServletContextListener
    * 2与session域中存储对象相关
        * 绑定与解绑
        * 钝化与活化
* filter
    * API
        * doFilter(request,response,FilterChain)----chain.doFilter(request.response)
    * 配置
        * <url-pattern>配置
* ServletContext
    * 获得web应用的全局的参数

<context-param>

	<param-name></param-name>
	
	<param-value></param-value>

</context-param>
    * 获得web应用下任何资源的绝对路径 context.getRealPath(相对web应用)
    * 域对象：整个web应用
* 事务
    * jdbc事务控制
    * DBUtils事务控制
* ThreadLocal
## 数据库
### 数据库安装与卸载
### sql分类
* DDL
    * 定义数据库
    * 定义数据表---创建表的语句
* DML
    * insert
    * delete
    * update
* DQL
    * 单表查询
        * select * from user
        * select name,age from user
        * select salary+5000 as newsalary from user
        * select count(*)/sum(salary)/avg(salary) from user
        * select * from user where name is null
        * select * from user order by age desc,salary asc
        * select distinct name from user
        * select sum(salary) from user group by groupName having sum(salary)>10000
        * select * from user where name like ___   /  %
        * select * from user limit 0,5
    * 多表查询
        * 表的关系与设计原则
            * 一对一
            * 一对多
            * 多对多
        * 查询语句
            * 内连接
                * inner join .. on

select 表，表，表 where 条件
            * 左外
                * left join...on
            * 右外
                * right join ...on
    * 子查询
        * 子查询的结果是单行单列 
        * 多行单列的子查询
        * 多行多列的子查询
* DCL
### 事务
### redis（nosql数据库）
* 安装与启动
* jedis的操作
    * Jedis jedis = new Jedis(host,port);
    * JedisPool pool = new JedisPool(JedisConfig,host,port)
* 数据结构的操作5种
* 多数据库、广播域订阅、持久化（RDB、AOF）
## 其他
### 基础加强
* 反射
* 类加载器
* 注解
* 动态代理----aop
### Linux
* 根据文档可以操作linux系统
* 会将win系统的eclispe开发的工程发布到linux的tomcat中
