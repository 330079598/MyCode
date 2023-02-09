[toc]

---

## `@Controller`和`@RestController`的区别

`@RestController`注解相当于`@ResponseBody ＋ @Controller`合在一起的作用。
`RestController`使用的效果是将方法返回的对象直接在浏览器上展示成`json`格式，而如果单单使用`@Controller`会报错，需要`ResponseBody`配合使用。
1、如果只是使用`@RestController`注解`Controller`类，则方法无法返回`jsp`页面，配置的视图解析器`InternalResourceViewResolver`不起作用，返回的内容就是Return 里的内容。
例如：本来应该到success.jsp页面的，则其显示success.
2、如果需要返回到指定页面，则需要用 `@Controller`配合视图解析器`InternalResourceViewResolver`才行。
3、如果需要返回JSON，XML或自定义`mediaType`内容到页面，则需要在对应的方法上加上`@ResponseBody`注解。

```java
@Controller  
@ResponseBody  
public class MyController {

 }  
或者在方法上加@ResponseBody  
@Controller  
public class MyController {

    @ResponseBody
    @RequestMapping(value = "/sutdent", method = RequestMethod.GET)
    public Student uploadFile() {
        Student student = new Student();
        student.setId("ss");
        student.setAge("ss");
        student.setAddress("ss");
        return student;
    }
 }  
  
@RestController  
public class MyRestController { }  
```

## `restful`风格,`RestController`和`controller`

- `restcontroller`与`controller`

假定一个user对象，对象有很多属性（name,sex,age,birth,address,tel）在我的了解中，这二者的区分为：``@restcontroller`为`@controller`和`@responsebody`的结合在`@controller`注解中，返回的是字符串，或者是字符串匹配的模板名称，即直接渲染视图，与html页面配合使用的，
  在这种情况下，前后端的配合要求比较高，java后端的代码要结合html的情况进行渲染,使用model对象（或者`modelandview`）的数据将填充user视图中的相关属性，然后展示到浏览器，这个过程也可以称为渲染；
  java示例代码如下：

```java
@Controller
@RequestMapping(method = RequestMethod.GET, value = "/")
    public String getuser(Model model) throws IOException {

        model.addAttribute("name",bob);
        model.addAttribute("sex",boy);
        return "user";//user是模板名
    }
```

对应视图user.jsp中的html代码

```java
<html xmlns:th="http://www.thymeleaf.org">
<body>
    <div>
        <p>"${name}"</p>
        <p>"${sex}"</p>
    </div>
</body>
</html>
```

而在@restcontroller中，返回的应该是一个对象，即return一个user对象，这时，在没有页面的情况下，也能看到返回的是一个user对象对应的json字符串，而前端的作用是利用返回的json进行解析渲染页面，java后端的代码比较自由。

```java
@RestController
@RequestMapping(method = RequestMethod.GET, value = "/")
    public User getuser( ) throws IOException {
        User bob=new User();
        bob.setName("bob");
        bob.setSex("boy");
        return bob;
    }
```

访问网址得到的是json字符串{“name”:”bob”,”sex”:”boy”}，前端页面只需要处理这个字符串即可。

请求入口Controller部分提供三种接口样例：视图模板，Json，restful风格
（1）视图模板
返回结果为视图文件路径。视图相关文件默认放置在路径 resource/templates下：

```java
@Controller
public class HelloController {
    private Logger logger = Logger.getLogger(HelloController.class);
    /*
    *   http://localhost:8080/hello?name=cn.7player
     */
 
    @RequestMapping("/hello")
    public String greeting(@RequestParam(value="name", required=false, defaultValue="World") String name, Model model) {
        logger.info("hello");
        model.addAttribute("name", name);
        return "hello";
    }
}
```

（2）Json
返回Json格式数据，多用于Ajax请求。

```java
@Controller
public class UserController {
    private Logger logger = Logger.getLogger(UserController.class);

    @Autowired
    private UserService userService;
    /*
     *  http://localhost:8080/getUserInfo
     */
 
    @RequestMapping("/getUserInfo")
    @ResponseBody
    public User getUserInfo() {
        User user = userService.getUserInfo();
        if(user!=null){
            System.out.println("user.getName():"+user.getName());
            logger.info("user.getAge():"+user.getAge());
        }
        return user;
    }
}
```

3）restful
REST 指的是一组架构约束条件和原则。满足这些约束条件和原则的应用程序或设计就是 RESTful。

```java
@RestController
@RequestMapping(value="/users")
public class SwaggerController {
    
    /*
     *  http://localhost:8080/swagger/index.html
     */
    @ApiOperation(value="Get all users",notes="requires noting")
    @RequestMapping(method=RequestMethod.GET)
    public List<User> getUsers(){
        List<User> list=new ArrayList<User>();
 
        User user=new User();
        user.setName("hello");
        list.add(user);
 
        User user2=new User();
        user.setName("world");
        list.add(user2);
        return list;
    }
 
    @ApiOperation(value="Get user with id",notes="requires the id of user")
    @RequestMapping(value="/{name}",method=RequestMethod.GET)
    public User getUserById(@PathVariable String name){
        User user=new User();
        user.setName("hello world");
        return user;
    }
}
```

