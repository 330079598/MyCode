[TOC]

---

---

# Mybatis介绍

 	MyBatis 本是apache的一个开源项目iBatis, 2010年这个项目由apache software foundation 迁移到了google code，并且改名为MyBatis 。2013年11月迁移到Github。

 	MyBatis是一个优秀的持久层框架，它对jdbc的操作数据库的过程进行封装，使开发者只需要关注 SQL 本身，而不需要花费精力去处理例如注册驱动、创建connection、创建statement、手动设置参数、结果集检索等jdbc繁杂的过程代码。

Mybatis通过xml或注解的方式将要执行的各种statement（statement、preparedStatemnt、CallableStatement）配置起来，并通过java对象和statement中的sql进行映射生成最终执行的sql语句，最后由mybatis框架执行sql并将结果映射成java对象并返回。

# 使用JDBC编程的问题

## JDBC编程步骤

1. 加载数据库驱动
2. 创建并获取数据库连接
3. 创建JDBC statement对象
4. 设置SQL语句
5. 设置SQL语句中的参数(使用preparedStatement)
6. 通过statement执行SQL并获取结果
7. 对SQL执行结果进行解析处理
8. 释放(resultSet,preparedstatement,connection)

## JDBC程序

```java
public static void main(String[] args) {
	Connection connection = null;
	PreparedStatement preparedStatement = null;
	ResultSet resultSet = null;

	try {
		// 加载数据库驱动
		Class.forName("com.mysql.jdbc.Driver");

		// 通过驱动管理类获取数据库链接
		connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mybatis?characterEncoding=utf-8", "root", "root");
		// 定义sql语句 ?表示占位符
		String sql = "select * from user where username = ?";
		// 获取预处理statement
		preparedStatement = connection.prepareStatement(sql);
		// 设置参数，第一个参数为sql语句中参数的序号（从1开始），第二个参数为设置的参数值
		preparedStatement.setString(1, "王五");
		// 向数据库发出sql执行查询，查询出结果集
		resultSet = preparedStatement.executeQuery();
		// 遍历查询结果集
		while (resultSet.next()) {
			System.out.println(resultSet.getString("id") + "  " + resultSet.getString("username"));
		}
	} catch (Exception e) {
		e.printStackTrace();
	} finally {
		// 释放资源
		if (resultSet != null) {
			try {
				resultSet.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		if (preparedStatement != null) {
			try {
				preparedStatement.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		if (connection != null) {
			try {
				connection.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
//使用JDBC的原始方法(未经封装)实现了查询数据表记录的操作
```

## JDBC问题总结

1. 数据库连接创建、释放频繁造成系统资源浪费，从而影响系统性能。如果使用数据库连接池可解决此问题。
2. Sql语句在代码中硬编码，造成代码不易维护，实际应用中sql变化的可能较大，sql变动需要改变java代码。
3. 使用preparedStatement向占有位符号传参数存在硬编码，因为sql语句的where条件不一定，可能多也可能少，修改sql还要修改代码，系统不易维护。
4. 对结果集解析存在硬编码（查询列名），sql变化导致解析代码变化，系统不易维护，如果能将数据库记录封装成pojo对象解析比较方便。

# Mybatis架构

![](../Image/Mybatis架构.png)

1. mybatis配置:
   - SqlMapConfig.xml，此文件作为mybatis的全局配置文件，配置了mybatis的运行环境等信息。
   - mapper.xml文件即sql映射文件，文件中配置了操作数据库的sql语句。此文件需要在SqlMapConfig.xml中加载。
2. 通过mybatis环境等配置信息构造SqlSessionFactory即会话工厂
3. 由会话工厂创建sqlSession即会话，操作数据库需要通过sqlSession进行。
4. mybatis底层自定义了Executor执行器接口操作数据库，Executor接口有两个实现，一个是基本执行器、一个是缓存执行器。
5. Mapped Statement也是mybatis一个底层封装对象，它包装了mybatis配置信息及sql映射信息等。mapper.xml文件中一个sql对应一个Mapped Statement对象，sql的id即是Mapped statement的id。
6. Mapped Statement对sql执行输入参数进行定义，包括HashMap、基本类型、pojo，Executor通过Mapped Statement在执行sql前将输入的java对象映射至sql中，输入参数映射就是jdbc编程中对preparedStatement设置参数。
7. Mapped Statement对sql执行输出结果进行定义，包括HashMap、基本类型、pojo，Executor通过Mapped Statement在执行sql后将输出结果映射至java对象中，输出结果映射过程相当于jdbc编程中对结果的解析处理过程。

# Mybatis的一些使用方法

- 在写SQL语句的xml文件中,如果传入的参数事简单数据类型,`${}`里面的必须写value,其他类型随意即可(建议见名知意).

- **`#{}和${}`**区别:

  - #{}表示一个占位符号，通过#{}可以实现preparedStatement向占位符中设置值，自动进行java类型和jdbc类型转换。#{}可以有效防止sql注入。 #{}可以接收简单类型值或pojo属性值。 如果parameterType传输单个简单类型值，#{}括号中可以是value或其它名称。
  - ${}表示拼接sql串，通过${}可以将parameterType 传入的内容拼接在sql中且不进行jdbc类型转换， ${}可以接收简单类型值或pojo属性值，如果parameterType传输单个简单类型值，${}括号中只能是value。

- parameterType和resultType

  - parameterType：指定输入参数类型，mybatis通过ognl从输入对象中获取参数值拼接在sql中。
  - resultType：指定输出结果类型，mybatis将sql查询结果的一行记录数据映射为resultType指定类型的对象。如果有多条数据，则分别进行映射，并把对象放到容器List中.

- **selectOne和selectList**

  - selectOne查询一条记录，如果使用selectOne查询多条记录则抛出异常：

  ```java
  org.apache.ibatis.exceptions.TooManyResultsException: Expected one result (or null) to be returned by selectOne(), but found: 3
  	at org.apache.ibatis.session.defaults.DefaultSqlSession.selectOne(DefaultSqlSession.java:70)
  ```

  - selectList可以查询一条或多条记录。
  - 动态代理对象调用sqlSession.selectOne()和sqlSession.selectList()是根据mapper接口方法的返回值决定，如果返回list则调用selectList方法，如果返回单个对象则调用selectOne方法。
  
- namespace

  - mybatis官方推荐使用mapper代理方法开发mapper接口，程序员不用编写mapper接口实现类，使用mapper代理方法时，输入参数可以使用pojo包装对象或map对象，保证dao的通用性。
  
- if 标签:

```xml
<!-- 根据条件查询用户 -->
<select id="queryUserByWhere" parameterType="user" resultType="user">
	SELECT id, username, birthday, sex, address FROM `user`
	WHERE 1=1
	<if test="sex != null and sex != ''">
		AND sex = #{sex}
	</if>
	<if test="username != null and username != ''">
		AND username LIKE
		'%${username}%'
	</if>
</select>
```

> 注意字符串类型的数据需要要做不等于空字符串校验。

- Where标签
  - 上面的sql还有where 1=1 这样的语句，很麻烦可以使用where标签进行改造

```xml
<!-- 根据条件查询用户 -->
<select id="queryUserByWhere" parameterType="user" resultType="user">
	SELECT id, username, birthday, sex, address FROM `user`
<!-- where标签可以自动添加where，同时处理sql语句中第一个and关键字 -->
	<where>
		<if test="sex != null">
			AND sex = #{sex}
		</if>
		<if test="username != null and username != ''">
			AND username LIKE
			'%${username}%'
		</if>
	</where>
</select>
```

- SQL片段
  - Sql中可将重复的sql提取出来，使用时用include引用即可，最终达到sql重用的目的。

```xml
<!-- 把上面例子中的id, username, birthday, sex, address提取出来，作为sql片段 -->
<!-- 根据条件查询用户 -->
<select id="queryUserByWhere" parameterType="user" resultType="user">
	<!-- SELECT id, username, birthday, sex, address FROM `user` -->
	<!-- 使用include标签加载sql片段；refid是sql片段id -->
	SELECT <include refid="userFields" /> FROM `user`
	<!-- where标签可以自动添加where关键字，同时处理sql语句中第一个and关键字 -->
	<where>
		<if test="sex != null">
			AND sex = #{sex}
		</if>
		<if test="username != null and username != ''">
			AND username LIKE
			'%${username}%'
		</if>
	</where>
</select>

<!-- 声明sql片段 -->
<sql id="userFields">
	id, username, birthday, sex, address
</sql>
```

> 如果要使用别的Mapper.xml配置的sql片段，可以在refid前面加上对应的Mapper.xml的namespace
> 

- foreach标签

  - 向sql传递数组或List，mybatis使用foreach解析，如下：根据多个id查询用户信息

    查询sql：`SELECT * FROM user WHERE id IN (1,10,24)`

# SplMapConfig.xml配置文件

1. SqlMapConfig.xml中配置的内容和顺序如下：

   - **properties**（属性）

     - 在 properties 元素体内定义的属性首先被读取。
     - 然后会读取properties 元素中resource或 url 加载的属性，它会覆盖已读取的同名属性。

   - settings（全局配置参数）

   - **typeAliases**（类型别名）

     - |    别名    | 映射的类型 |
       | :--------: | :--------: |
       |   _long    |    long    |
       |   _shrot   |   short    |
       |    _int    |    int     |
       |  _integer  |    int     |
       |  _double   |   double   |
       |   _float   |   float    |
       |  _boolean  |  boolean   |
       |   sring    |   String   |
       |    byte    |    Byte    |
       |    long    |    Long    |
       |   short    |   Short    |
       |    int     |  Integer   |
       |  integer   |  Integer   |
       |   double   |   Double   |
       |  boolean   |  Boolean   |
       |    data    |    Date    |
       |  decimal   | BigDecimal |
       | bigdecimal | BigDecimal |
       |    map     |    Map     |

   - typeHandlers（类型处理器）

   - objectFactory（对象工厂）

   - plugins（插件）

   - environments（环境集合属性对象）

     - environment（环境子属性对象）
       - transactionManager（事务管理）
       - dataSource（数据源）

   - **mappers**（映射器）

     - Mapper配置的几种方法：

       - `<mapper resource=" " />` 

         - 使用相对于类路径的资源（现在的使用方式）,如`<mapper resource="sqlmap/User.xml" />`

       - `<mapper class=" " />`

         - 使用mapper接口类路径.如`<mapper class="cn.itcast.mybatis.mapper.UserMapper"/>`

           > 注意：此种方法要求mapper接口名称和mapper映射文件名称相同，且放在同一个目录中。

       - `<package name=""/>`
       
         - 注册指定包下的所有mapper接口,如`<package name="cn.test.mybatis.mapper"/>`
       
           > 注意：此种方法要求mapper接口名称和mapper映射文件名称相同，且放在同一个目录中。

# Mybatis解决JDBC编程的问题

1.  数据库连接创建、释放频繁造成系统资源浪费从而影响系统性能，如果使用数据库连接池可解决此问题。

   解决：在SqlMapConfig.xml中配置数据连接池，使用连接池管理数据库链接。

2. Sql语句写在代码中造成代码不易维护，实际应用sql变化的可能较大，sql变动需要改变java代码。

   解决：将Sql语句配置在XXXXmapper.xml文件中与java代码分离。

3. 向sql语句传参数麻烦，因为sql语句的where条件不一定，可能多也可能少，占位符需要和参数一一对应。

   解决：Mybatis自动将java对象映射至sql语句，通过statement中的parameterType定义输入参数的类型。

4. 对结果集解析麻烦，sql变化导致解析代码变化，且解析前需要遍历，如果能将数据库记录封装成pojo对象解析比较方便。

   解决：Mybatis自动将sql执行结果映射至java对象，通过statement中的resultType定义输出结果的类型。

# Mybatis与Hibernate区别

- Mybatis和hibernate不同，它不完全是一个ORM框架，因为MyBatis需要程序员自己编写Sql语句。mybatis可以通过XML或注解方式灵活配置要运行的sql语句，并将java对象和sql语句映射生成最终执行的sql，最后将sql执行的结果再映射生成java对象。
- Mybatis学习门槛低，简单易学，程序员直接编写原生态sql，可严格控制sql执行性能，灵活度高，非常适合对关系数据模型要求不高的软件开发，例如互联网软件、企业运营类软件等，因为这类软件需求变化频繁，一但需求变化要求成果输出迅速。但是灵活的前提是mybatis无法做到数据库无关性，如果需要实现支持多种数据库的软件则需要自定义多套sql映射文件，工作量大。
- Hibernate对象/关系映射能力强，数据库无关性好，对于关系模型要求高的软件（例如需求固定的定制化软件）如果用hibernate开发可以节省很多代码，提高效率。但是Hibernate的学习门槛高，要精通门槛更高，而且怎么设计O/R映射，在性能和对象模型之间如何权衡，以及怎样用好Hibernate需要具有很强的经验和能力才行。
- 总之，按照用户的需求在有限的资源环境下只要能做出维护性、扩展性良好的软件架构都是好架构，所以框架只有适合才是最好。

