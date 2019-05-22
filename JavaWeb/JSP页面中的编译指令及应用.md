1. JSP页面中的编译指令

基本语法:` <%@ 指令名 属性名="值"%>`

其中的各个属性名是区分字母大小写的,有page,include和taglib三条属性。

2. page指令（page Directive）功能

`<%@ page={属性名称="值"} %>`

**无论page指令出现在jsp页面中的什么地方,它作用的都是整个jsp页面,为了保持页面的可读性和遵循良好的编程习惯,最好将page指令放在整个jsp页面的起始位置。**

3. page指令中常用的属性

在page指令中，出了import属性以外，其他的属性在page指令中只能出现一次。可以根据应用的需要，从新设置属性值，未重新给出的属性都采用系统中的默认值。

- import="importList"

import属性列表用于在生成的Servlet程序类中创建相应的import导入语句,如果需要载入不同的包,可以用一个import属性指明多个包,但他们之间要用逗号隔开,如下:

```JavaScript
<%@ page import="java.sql.*,java.util.*" %>
```

也可以分开导入.

- 

