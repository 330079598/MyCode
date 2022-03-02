[toc]

---

---

---

### 1. JVM 快速入门

可能出现的面试题：

1. 谈谈对jvm的理解？java8的虚拟机有什么更新
2. 什么是OOM？什么是StackOverFlowError？有哪些方法分析？
3. JVM的常用参数调优你知道有那些？
4. 内存快照抓取MAT分析和DUMP文件知道么？
5. 谈谈JVM中，对类加载器的认识?

位置:JVM是运行在操作系统之上的,它与硬件没有直接的交互

---

#### 1.1 结构图

![JVM结构](../Img/JVM结构.png)

- `方法区`: 存储已被虚拟机加载的类元素局信息(元空间)
- `堆`: 存放对象实例,几乎所有的对象实例都在这里分配内存
- `虚拟机栈`: 虚拟机栈描述的是Java方法执行的内存模型: 每个方法被执行的时候都会同时创建一个栈帧(Stack Frame)用于存储局部变量表,操作栈,动态链接,方法出口等信息 
- `程序计数器`: 当前线程所执行的字节码的行号指示器
- `本地方法栈`:本地方法栈则是为了虚拟机使用到的`Native`方法服务

---

#### 1.2类加载器

负责加载`class`文件,`class`文件在文件开头有特有的文件提示,并且`ClassLoader`负责`class`文件的加载,至于它是否可以运行,则有`Execution Engine`决定.

![ClassLoader](../Img/ClassLoader.png)

类加载器分为四种：前三种为虚拟机自带的加载器。

- `BootstrapClassLoader`（启动类加载器）:根类加载器。负责加载`$JAVA_HOME`中`jre/lib/rt.jar`里所有的`class`，由`C++`实现，不是`ClassLoader`子类。
- `ExtClassLoader`（扩展类加载器）:负责加载`java`平台中**扩展功能**的一些`jar`包，包括`$JAVA_HOME中jre/lib/*.jar`或`Djava.ext.dirs`指定目录下的`jar`包
- `AppClassLoader`(应用程序类加载器）：也叫系统类加载器，负责加载`classpath`中指定的`jar`包及目录中的`class`
- 自定义类加载:继承`ClassLoader`基类，`Java.lang.ClassLoader`的子类，用户可以定制类的加载方式
- 双亲委派原则:
  - 保证JDK的稳定性及安全性

工作过程：

1. 当`APPClassLoader`加载一个`class`时，它首先不会自己去尝试加载这个类，而是把类加载请求委派给父类加载器`ExtClassLoader`去完成。