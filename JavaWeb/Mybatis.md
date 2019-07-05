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