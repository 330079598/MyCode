[toc]

---

### Javas三大器：过滤器-监听器-拦截器

|       Tables        |   过滤器（Filter）    |       监听器（Listener）       |    拦截器（Interceptor）    |
| :-----------------: | :-------------------: | :----------------------------: | :-------------------------: |
|      关注的点       |        wed请求        |       系统级别参数、对象       |    Action（部分web请求）    |
|     如何实现的      |       函数回调        |              事件              |  Java反射机制（动态代理）   |
|      应用场景       |     设置字符编码      |        统计网站在线人数        |       拦截未登录用户        |
|                     | URL级别的权限访问控制 |        清除过期session         |          审计日志           |
|                     |     过滤敏感词汇      |                                |                             |
|                     |     压缩响应信息      |                                |                             |
| 是否依赖servlet容器 |         依赖          |                                |           不依赖            |
| Serverlet提供的支持 |      Filter接口       | ServletContextListener抽象接口 |    Action（部分web请求）    |
|                     |                       |  HttpSessionListener抽象接口   |                             |
|  Spring提供的支持   |                       |                                | HandlerinterceptorAdapter类 |
|                     |                       |                                |   HandlerInterceptor接口    |
|        级别         |        系统级         |             系统级             |          非系统级           |

**注意：拦截器的对象只能是实现了接口的类，而不能拦截URL这种链接。**

### 一、拦截器的概念

java里的拦截器是动态拦截Action调用的对象，它提供了一种机制可以使开发者在一个Action执行的前后执行一段代码，也可以在一个Action执行前阻止其执行，同时也提供了一种可以提取Action中可重用部分代码的方式。在AOP中，拦截器用于在某个方法或者字段被访问之前进行拦截，然后再之前或者之后加入某些操作。

### 二、拦截器的原理

大部分时候，拦截器方法都是通过代理的方式来调用的。

### 三、自定义拦截器的步骤

- 第一步：自定义一个实现了Interceptor接口的类，或者继承抽象类AbstractInterceptor。
- 第二步：在配置文件中注册定义的拦截器。
- 第三步：在需要使用Action中引用上述定义的拦截器，为了方便也可以将拦截器定义为默认的拦截器，这样在不加特殊说明的情况下，所有的Action都被这个拦截器拦截。

### 四、过滤器与拦截器的区别

过滤器可以简单的理解为“取你所想取”，过滤器关注的是web请求；拦截器可以简单的理解为“拒你所想拒”，拦截器关注的是方法调用，比如拦截敏感词汇。
 1.拦截器是基于java反射机制来实现的，而过滤器是基于函数回调来实现的。（有人说，拦截器是基于动态代理来实现的）
 2.拦截器不依赖servlet容器，过滤器依赖于servlet容器。
 3.拦截器只对Action起作用，过滤器可以对所有请求起作用。
 4.拦截器可以访问Action上下文和值栈中的对象，过滤器不能。
 5.在Action的生命周期中，拦截器可以多次调用，而过滤器只能在容器初始化时调用一次。

### 五、Spring拦截器

- 第一步 定义拦截器类，该类实现HandlerInterceptor接口

```java
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.ModelAndView;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
@Component
public class MyInterceptor implements HandlerInterceptor {
 
    /**
     * 该方法是在执行执行servlet的 service方法之前执行的
     * 即在进入controller之前调用
     * @return 如果返回true表示继续执行下一个拦截器的PreHandle方法；如果没有拦截器了,则执行controller
     */
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception{
        String url = request.getRequestURI();
        System.out.println("进入Controller之前");
        if(url.indexOf("login") >= 0){
            return true;
        }
 
        String username = request.getParameter("username");
        if(username == null){
            return false;
        }
 
        return true;
    }
 
    /**
     *在执行完controller之后，返回视图之前执行，我们可以对controller返回的结果做处理
     * 执行顺序：先执行最后一个拦截器的postHandle方法，一次向前
     */
    @Override
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler,
                           ModelAndView modelAndView) throws Exception{
 
        System.out.println("解析视图之前.....");
    }
 
    /**
     * 整个请求结束之后，即返回视图之后执行
     *该方法需要同一拦截器的preHandle返回true时执行，
     * 如果该拦截器preHandle返回false，则该拦截器的afterCompletion不执行
     * 执行顺序：先执行最后一个返回true的拦截器的afterCompletion，在依次向前
     */
    @Override
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler,
                      Exception ex) throws Exception{
        System.out.println("视图解析完成...");
    }
}
```

- SpringBoot 环境中配置拦截器:

```java
@Configuration
public class InterceptorConfig implements WebMvcConfigurer {
 
    @Autowired
    private MyInterceptor interceptor;
 
    public void addInterceptors(InterceptorRegistry registry) {
        //addPathPatterns指定拦截器要拦截的路径
        //excludePathPatterns指定拦截器不拦截的路径
        registry.addInterceptor(interceptor).addPathPatterns("/**").excludePathPatterns("/logout");
    }
}
```

- `SpringMVC`环境中配置拦截器:

```xml
<mvc:interceptors>  
   <!--  自定义拦截器   -->
    <mvc:interceptor>  
        <!-- 进行拦截：/**表示拦截所有controller -->
        <mvc:mapping path="/**" />
    　　 <!-- 不进行拦截 -->
        <mvc:exclude-mapping path="/logout"/> 
        <bean class="com.example.demp.Interceptor.MyInterceptor"/>
    </mvc:interceptor>  
</mvc:interceptors> 
```

- 上面两种选一种即可,编写Controller测试：

```java
@RestController
public class LoginController {
 
    @RequestMapping("/login")
    public String intercept(){
        System.out.println("Controller执行中....");
        return "Hello Interceptor!";
    }
 
    @RequestMapping("/logout")
    public String logout(){
        System.out.println("注销中....");
        return "logouting.....!";
    }
}
```

- 先访问login，测试结果如下：

```text
进入Controller之前
Controller执行中....
解析视图之前.....
视图解析完成...
```

- 再访问logout:

```text
注销中....
```

### 六、总结：

- 1.过滤器（Filter）：所谓过滤器顾名思义是用来过滤的，Java的过滤器能够为我们提供系统级别的过滤，也就是说，能过滤所有的web请求，这一点，是拦截器无法做到的。在Java Web中，你传入request,response提前过滤掉一些信息，或者提前设置一些参数，然后再传入servlet进行业务逻辑，比如过滤掉非法url（不是login.do的地址请求，如果用户没有登陆都过滤掉）,或者在传入servlet前统一设置字符集，或者去除掉一些非法字符（聊天室经常用到的，一些骂人的话）。filter 流程是线性的，url传来之后，检查之后，可保持原来的流程继续向下执行，被下一个filter, servlet接收。
- 2.监听器（Listener）：Java的监听器，也是系统级别的监听。监听器随web应用的启动而启动。Java的监听器在c/s模式里面经常用到，它会对特定的事件产生一个处理。监听在很多模式下用到，比如说观察者模式，就是一个使用监听器来实现的，在比如统计网站的在线人数。Servlet监听器用于监听一些重要事件的发生，监听器对象可以在事情发生前、发生后可以做一些必要的处理。
- 3.拦截器（Interceptor）：java里的拦截器提供的是非系统级别的拦截，也就是说，就覆盖面来说，拦截器不如过滤器强大，但是更有针对性。Java中的拦截器是基于Java反射机制实现的，更准确的划分，应该是基于JDK实现的动态代理。它依赖于具体的接口，在运行期间动态生成字节码。拦截器是动态拦截Action调用的对象，它提供了一种机制可以使开发者在一个Action执行的前后执行一段代码，也可以在一个Action执行前阻止其执行，同时也提供了一种可以提取Action中可重用部分代码的方式。在AOP中，拦截器用于在某个方法或者字段被访问之前，进行拦截然后再之前或者之后加入某些操作。java的拦截器主要是用在插件上，扩展件上比如 Hibernate Spring Struts2等，有点类似面向切片的技术，在用之前先要在配置文件即xml，文件里声明一段的那个东西。