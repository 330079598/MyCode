[toc]

---

## `Spring`获取`ApplicationContext`的几种方法

### 方法一

-  在初始化时保存`ApplicationContext`对象 代码：

```java
ApplicationContext ac = new FileSystemXmlApplicationContext("applicationContext.xml"); 
ac.getBean("userService");
 
//比如：在application.xml中配置：
<bean id="userService" class="com.cloud.service.impl.UserServiceImpl"></bean>
```

> 说明：这种方式适用于采用Spring框架的独立应用程序，需要程序通过配置文件手工初始化Spring的情况。

### 方法二

- 通过Spring提供的工具类获取``ApplicationContext`对象

```java
import org.springframework.web.context.support.WebApplicationContextUtils;
ApplicationContext ac1 = WebApplicationContextUtils.getRequiredWebApplicationContext(ServletContext sc);
ApplicationContext ac2 = WebApplicationContextUtils.getWebApplicationContext(ServletContext sc);
ac1.getBean("beanId");
ac2.getBean("beanId");

//当我们需要获取某个接口的查找结果时
//在没有调用这个接口时,我们可以使用下面这种方法获得接口查找到的数据
ApplicationContext applicationContext =
				WebApplicationContextUtils.getWebApplicationContext(request.getSession().getServletContext());
PermissionService permissionService = applicationContext.getBean(PermissionService.class);
```

> 说明： 这种方式适合于采用Spring框架的B/S系统，通过ServletContext对象获取ApplicationContext对象，然后在通过它获取需要的类实例。 上面两个工具方式的区别是，前者在获取失败时抛出异常，后者返回null。

### 方法三

- 继承自抽象类ApplicationObjectSupport

```java
@Service
public class SpringContextHelper2 extends ApplicationObjectSupport {
    
    
    //提供一个接口，获取容器中的Bean实例，根据名称获取
    public Object getBean(String beanName)
    {
        return getApplicationContext().getBean(beanName);
    }
    
}
```



> 说明：抽象类ApplicationObjectSupport提供getApplicationContext()方法，可以方便的获取到ApplicationContext。 Spring初始化时，会通过该抽象类的setApplicationContext(ApplicationContext context)方法将ApplicationContext 对象注入。

### 方法四

- 继承自抽象类WebApplicationObjectSupport

> 似上面方法，调用getWebApplicationContext()获取WebApplicationContext

### 方法五

- 实现接口ApplicationContextAware(推荐)

```java
/**
 * Spring ApplicationContext 工具类
*/
@SuppressWarnings("unchecked")
@Component
public class SpringUtils implements ApplicationContextAware {
 
    private static ApplicationContext applicationContext;
 
    public void setApplicationContext(ApplicationContext applicationContext) throws BeansException {
        SpringUtils.applicationContext = applicationContext;
    }
 
    public static <T> T getBean(String beanName) {
        if(applicationContext.containsBean(beanName)){
            return (T) applicationContext.getBean(beanName);
        }else{
            return null;
        }
    }
 
    public static <T> Map<String, T> getBeansOfType(Class<T> baseType){
        return applicationContext.getBeansOfType(baseType);
    }
}
```



> 说明：实现该接口的`setApplicationContext(ApplicationContext context)`方法，并保存`ApplicationContext `象。 `Spring`初始化时，会通过该方法将`ApplicationContext`对象注入。然后在代码中就可以获取spring容器bean了。例如：`LoadExploreTree bean = SpringUtils.getBean("loadExploreTree")`;

### 注意

- 虽 然,`spring`提供了后三种方法可以实现在普通的类中继承或实现相应的类或接口来获取spring 的ApplicationContext对象，但是在使用是一定要注意实现了这些类或接口的普通java类一定要在Spring 的配置文件application-context.xml文件中进行配置。否则获取的ApplicationContext对象将为null。

```java
import org.springframework.beans.BeansException;
import org.springframework.context.ApplicationContext;
import org.springframework.context.ApplicationContextAware;

public class SpringContextUtil implements ApplicationContextAware {

    // Spring应用上下文环境
    private static ApplicationContext applicationContext;

    /**
     * 实现ApplicationContextAware接口的回调方法，设置上下文环境
     * 
     * @param applicationContext
     */
    public void setApplicationContext(ApplicationContext applicationContext) {
        SpringContextUtil.applicationContext = applicationContext;
    }

    /**
     * @return ApplicationContext
     */
    public static ApplicationContext getApplicationContext() {
        return applicationContext;
    }

    /**
     * 获取对象
     * @param name
     * @param <T>
     * @return
     * @throws BeansException
     */
    @SuppressWarnings("unchecked")
    public static <T> T getBean(String name) throws BeansException {
        if (applicationContext == null){
            return null;
        }
        return (T)applicationContext.getBean(name);
    }
}
```

- `XML`文件中的配置信息

```
Title
 import org.springframework.web.context.ContextLoader;  
 import org.springframework.web.context.WebApplicationContext;  

     WebApplicationContext wac = ContextLoader.getCurrentWebApplicationContext();  
     wac.getBean(beanID); 
```

