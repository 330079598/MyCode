[toc]

---

### 建表

1. 学生表  student(s_id,s_name,s_birth,s_sex) 

-- 学生编号,学生姓名, 出生年月,学生性别 

2.课程表  course(c_id,c_name,t_id) 

-- 课程编号, 课程名称, 教师编号 

3.教师表  teacher(t_id,t_name) 

-– 教师编号,教师姓名 

4.成绩表  score(s_id,c_id,s_score) 

--学生编号,课程编号,分数

```sql
--  建立课程表
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course`  (
  `c_id` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '课程编号',
  `c_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '课程名称',
  `t_id` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '教师编号',
  PRIMARY KEY (`c_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;
-- 课程表数据
INSERT INTO `course` VALUES ('01', '语文', '02');
INSERT INTO `course` VALUES ('02', '数学', '01');
INSERT INTO `course` VALUES ('03', '英语', '03');
-- 分数表
DROP TABLE IF EXISTS `score`;
CREATE TABLE `score`  (
  `s_id` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '学生编号',
  `c_id` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '课程编号',
  `s_score` int(3) NULL DEFAULT NULL COMMENT '分数',
  PRIMARY KEY (`s_id`, `c_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;
-- 分数数据
INSERT INTO `score` VALUES ('01', '01', 80);
INSERT INTO `score` VALUES ('01', '02', 90);
INSERT INTO `score` VALUES ('01', '03', 99);
INSERT INTO `score` VALUES ('02', '01', 70);
INSERT INTO `score` VALUES ('02', '02', 60);
INSERT INTO `score` VALUES ('02', '03', 80);
INSERT INTO `score` VALUES ('03', '01', 80);
INSERT INTO `score` VALUES ('03', '02', 80);
INSERT INTO `score` VALUES ('03', '03', 80);
INSERT INTO `score` VALUES ('04', '01', 50);
INSERT INTO `score` VALUES ('04', '02', 30);
INSERT INTO `score` VALUES ('04', '03', 20);
INSERT INTO `score` VALUES ('05', '01', 76);
INSERT INTO `score` VALUES ('05', '02', 87);
INSERT INTO `score` VALUES ('05', '03', 95);
INSERT INTO `score` VALUES ('06', '01', 31);
INSERT INTO `score` VALUES ('06', '02', 88);
INSERT INTO `score` VALUES ('06', '03', 34);
INSERT INTO `score` VALUES ('07', '01', 66);
INSERT INTO `score` VALUES ('07', '02', 89);
INSERT INTO `score` VALUES ('07', '03', 98);
INSERT INTO `score` VALUES ('08', '01', 59);
INSERT INTO `score` VALUES ('08', '02', 88);
INSERT INTO `score` VALUES ('09', '02', 67);
INSERT INTO `score` VALUES ('09', '03', 88);
INSERT INTO `score` VALUES ('10', '01', 65);
INSERT INTO `score` VALUES ('10', '02', 78);
-- 建立学生表
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student`  (
  `s_id` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '学生编号',
  `s_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '学生姓名',
  `s_birth` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '出生年月',
  `s_sex` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '学生性别',
  PRIMARY KEY (`s_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;
-- 学生数据
INSERT INTO `student` VALUES ('01', '斯内克', '1990-01-01', '男');
INSERT INTO `student` VALUES ('02', '张益达', '1990-12-21', '男');
INSERT INTO `student` VALUES ('03', '张大炮', '1990-05-20', '男');
INSERT INTO `student` VALUES ('04', '李云龙', '1990-08-06', '男');
INSERT INTO `student` VALUES ('05', '楚云飞', '1991-12-01', '女');
INSERT INTO `student` VALUES ('06', '赵日天', '1992-03-01', '女');
INSERT INTO `student` VALUES ('07', '小甜甜', '1989-07-01', '女');
INSERT INTO `student` VALUES ('08', '王菊花', '1990-01-20', '女');
INSERT INTO `student` VALUES ('09', '李慕白', '1994-01-20', '男');
INSERT INTO `student` VALUES ('10', '东京热', '1980-01-20', '女');
-- 建立老师表
DROP TABLE IF EXISTS `teacher`;
CREATE TABLE `teacher`  (
  `t_id` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '教师编号',
  `t_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '教师姓名',
  PRIMARY KEY (`t_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;
-- 老师表数据
INSERT INTO `teacher` VALUES ('01', '墨白');
INSERT INTO `teacher` VALUES ('02', '默狐');
INSERT INTO `teacher` VALUES ('03', '柠檬');
SET FOREIGN_KEY_CHECKS = 1;
```

### 1. 查询"语文"课程比"数学"课程成绩高的学生的信息及课程分数 

```sql
SELECT st.*,
	chinese.s_score AS '语文',
	math.s_score AS '数学'
FROM
	student st
	left JOIN score chinese ON chinese.s_id = st.s_id
	AND chinese.c_id = '01'
	INNER JOIN score math ON math.s_id = st.s_id
	AND	math.c_id = '02'
WHERE
	chinese.s_score > math.s_score;
```

### 2. 查询平均成绩大于等于60分的同学的学生编号和学生姓名和平均成绩

```sql
SELECT
	st.s_id,
	st.s_name,
	ROUND(AVG(sc.s_score), 2) "平均成绩"
FROM
	student st
	left JOIN score sc ON st.s_id = sc.s_id
GROUP BY
	st.s_id
HAVING
	AVG(sc.s_score) >= 60;
```

### 3. 查询平均成绩小于60分的同学的学生编号和学生姓名和平均成绩(包括有成绩的和无成绩的)

```sql
SELECT
	st.s_id,
	st.s_name,
	(CASE	WHEN
		ROUND(AVG(sc.s_score), 2) IS NULL 
	THEN 0
	ELSE
		ROUND(AVG(sc.s_score), 2) END) "平均成绩"
	FROM
		student st
	LEFT JOIN score sc ON sc.s_id = st.s_id
	GROUP BY 
		st.s_id
	HAVING
		(AVG(sc.s_score) < 60 OR AVG(sc.s_score) IS NULL);
```

### 4. 查询所有同学的学生编号、学生姓名、选课总数、所有课程的总成绩

```sql
SELECT
	st.s_id,
	st.s_name,
	COUNT(sc.s_id) "选课总数",
	SUM(CASE WHEN sc.s_score IS NULL THEN 0 ELSE sc.s_score END) "总成绩"
	FROM
	student st
	LEFT JOIN score sc ON st.s_id = sc.s_id
	GROUP BY st.s_id
```

### 5. 查询"墨"姓老师的数量 

```sql
SELECT
	t.t_name,
	COUNT(t.t_id)
FROM
	teacher t
GROUP BY
	t.t_id
HAVING
	t.t_name LIKE '墨%';
```

### 6. 查询学过"墨白"老师授课的同学的信息 

```sql
SELECT
	st.*
FROM
	student st
	LEFT JOIN score sc ON sc.s_id = st.s_id
	LEFT JOIN course co ON co.c_id = sc.c_id
	LEFT JOIN teacher te ON te.t_id = co.t_id
WHERE
	te.t_name = "墨白";
```

### 7. 查询没学过"柠檬"老师授课的同学的信息

```sql
SELECT
	st.*
FROM
	student st
WHERE
	st.s_id NOT IN(
		SELECT sc.s_id
			FROM score sc
			WHERE sc.c_id IN (
				SELECT c.c_id FROM course c LEFT JOIN teacher t ON t.t_id = c.t_id WHERE t.t_name = '柠檬')
	);
```

### 8. 查询学过编号为"01"并且也学过编号为"02"的课程的同学的信息

```sql
-- 方式一：
SELECT
	st.*
FROM
	student st,
	score a,
	score b
WHERE
	st.s_id = a.s_id
	AND st.s_id = b.s_id
	AND a.c_id = '01' AND b.c_id = '02';
	
-- 方式二：
SELECT
    st.* 
FROM
    student st
    INNER JOIN score sc ON sc.s_id = st.s_id
    INNER JOIN course c ON c.c_id = sc.c_id 
    AND c.c_id = "01" 
WHERE
    st.s_id IN (
    SELECT
        st2.s_id 
    FROM
        student st2
        INNER JOIN score sc2 ON sc2.s_id = st2.s_id
        INNER JOIN course c2 ON c2.c_id = sc2.c_id 
    AND c2.c_id = "02" 
    )
```

### 9. 查询学过编号为"01"但是没有学过编号为"02"的课程的同学的信息

```sql
SELECT
	st.*
FROM
	student st
	INNER JOIN score sc1 ON sc1.s_id = st.s_id
	INNER JOIN course c ON c.c_id = sc1.c_id
	AND c.c_id = '01'
WHERE
	st.s_id NOT IN (
		SELECT 
			student.s_id
		FROM
			student
			INNER JOIN score sc2 ON sc2.s_id = student.s_id
			INNER JOIN course c2 ON c2.c_id = sc2.c_id
		AND c2.c_id = '02'
		);
```

### 10. 查询没有学全所有课程的同学的信息

```sql
-- 如果一个课程有过重修，这种搜索方式就会有问题
SELECT
	st.*
FROM
	student st
LEFT JOIN score sc ON st.s_id = sc.s_id
GROUP BY st.s_id HAVING COUNT(sc.c_id) < (SELECT COUNT(1) FROM course);

-- 优化之后
-- 学生编号和科目编号交叉得到笛卡尔集，然后和实际成绩表用学生编号和科目编号左连接，得到一张实际情况表，其中如果有没有考的科目，科目编号就会出现null。再统计出学生编号和null匹配的结果就是没有学全的人的编号
select * from student
where s_id in
(SELECT b.s_id FROM 
 (SELECT s_id,c_id FROM student,course) b  
   LEFT JOIN score sc 
   ON b.s_id=sc.s_id AND b.c_id=sc.c_id
 WHERE ISNULL(sc.c_id) );

-- 另外一种方法
SELECT
    * 
FROM
    student 
WHERE
    s_id NOT IN (
    SELECT
        st.s_id 
    FROM
        student st
        INNER JOIN score sc ON sc.s_id = st.s_id 
        AND sc.c_id = "01" 
    WHERE
    st.s_id IN ( SELECT st1.s_id FROM student st1 INNER JOIN score sc2 ON sc2.s_id = st1.s_id AND sc2.c_id = "02" ) 
    AND st.s_id IN ( SELECT st2.s_id FROM student st2 INNER JOIN score sc2 ON sc2.s_id = st2.s_id AND sc2.c_id = "03" ));
```

### 11. 查询至少有一门课与学号为"01"的同学所学相同的同学的信息

```sql
SELECT
	st.*
FROM
	student st
	LEFT JOIN score sc ON sc.s_id = st.s_id
WHERE
	sc.c_id = '01';

-- 方式二
SELECT DISTINCT
    st.* 
FROM
    student st
    LEFT JOIN score sc ON sc.s_id = st.s_id 
WHERE
    sc.c_id IN (
    SELECT
        sc2.c_id 
    FROM
        student st2
        LEFT JOIN score sc2 ON sc2.s_id = st2.s_id 
    WHERE
    st2.s_id = '01' 
    );
```

### 12. 查询和"01"号的同学学习的课程完全相同的其他同学的信息

```sql
SELECT 
	st.*
FROM 
	score sc
LEFT JOIN 
	student st ON st.s_id = sc.s_id
WHERE 
	sc.c_id IN (SELECT c_id FROM score WHERE s_id = '01') AND sc.s_id NOT IN ('01')
GROUP BY 
	sc.s_id
HAVING COUNT(1) = (SELECT COUNT(1) FROM score WHERE s_id = '01');
```

- 使用`chatgpt`得到的答案

可以使用子查询和集合运算符 (union、intersect、except) 来实现。

查询和“01”号的同学学习的课程完全相同的其他同学的信息，可以通过以下步骤完成：

1. 首先，查询学号为“01”的同学所学的所有课程编号。

```sql
SELECT c_id FROM score WHERE s_id = '01'
```

2. 然后，查询学习了查询结果中所有课程的学生学号。这些学生就是与学号为“01”的同学所学的课程完全相同的同学。

```sql
SELECT s_id FROM score WHERE c_id IN (SELECT c_id FROM score WHERE s_id = '01') AND s_id != '01'
INTERSECT
SELECT s_id FROM score WHERE s_id != '01' GROUP BY s_id HAVING COUNT(DISTINCT c_id) = (SELECT COUNT(DISTINCT c_id) FROM score WHERE s_id = '01')
```

3. 最后，查询这些同学的详细信息。假设学生表的名称为“student”，则可以使用以下语句来查询这些同学的详细信息：

```sql
SELECT * FROM student WHERE s_id IN (SELECT s_id FROM score WHERE c_id IN (SELECT c_id FROM score WHERE s_id = '01') AND s_id != '01'
INTERSECT
SELECT s_id FROM score WHERE s_id != '01' GROUP BY s_id HAVING COUNT(DISTINCT c_id) = (SELECT COUNT(DISTINCT c_id) FROM score WHERE s_id = '01'))
```

其中，“student”是学生表的名称，它根据实际情况进行修改。

这里使用 `INTERSECT` 运算符，表示取两个结果集的交集，确保除“01”号同学外的其他同学所学的课程与“01”号同学完全相同。同时使用 `HAVING` 子句来筛选出学习的完全相同课程的同学。

### 13. 查询没学过"默狐"老师讲授的任一门课程的学生姓名

```sql
SELECT
	st.s_name
FROM student st
WHERE
	st.s_id not in (
		SELECT sc.s_id
		FROM score sc
			INNER JOIN course c ON c.c_id = sc.c_id
			INNER JOIN teacher t ON t.t_id = c.t_id
			WHERE t.t_name = '默狐'
	)
```

### 14. 查询两门及其以上不及格课程的同学的学号，姓名及其平均成绩

```sql
-- 方法一
SELECT
	st.s_id,
	st.s_name,
	AVG(sc.s_score)
FROM
	student st
	LEFT JOIN score sc ON st.s_id = sc.s_id
WHERE
	sc.s_id IN(
		SELECT sc.s_id
		FROM score sc
			WHERE sc.s_score < 60 OR sc.s_score IS NULL
			GROUP BY sc.s_id
			HAVING COUNT(1) >= 2
	)
GROUP BY st.s_id

-- 方法二
SELECT
	st.s_id,
	st.s_name,
	AVG(CASE WHEN sc.s_score >= 1 THEN sc.s_score ELSE NULL END)
FROM
	student st
	LEFT JOIN score sc ON st.s_id = sc.s_id AND sc.s_score >= 1
GROUP BY 
	st.s_id, st.s_name
HAVING 
	COUNT(CASE WHEN sc.s_score < 60 OR sc.s_score IS NULL THEN 1 ELSE NULL END) >= 2;
```

### 15. 检索"01"课程分数小于60，按分数降序排列的学生信息

```sql
-- 方法一
SELECT
	st.*,
	sc.s_score
FROM
	student st
	INNER JOIN score sc ON sc.s_id = st.s_id
	AND sc.c_id = "01"
	AND sc.s_score < 60
ORDER BY
	sc.s_score DESC;
	
-- 方法二
SELECT
    st.*,
    sc.s_score 
FROM
    student st
    LEFT JOIN score sc ON sc.s_id = st.s_id 
WHERE
    sc.c_id = "01" 
    AND sc.s_score < 60 
ORDER BY
    sc.s_score DESC
```

### 16. 按平均成绩从高到低显示所有学生的所有课程的成绩以及平均成绩

```sql
SELECT s_id,MAX(CASE WHEN c_id='01' THEN s_score ELSE NULL END)"语文",MAX(CASE WHEN c_id='01' THEN s_score ELSE NULL END)"数学",MAX(CASE WHEN c_id='01' THEN s_score ELSE NULL END)"英语",AVG(s_score)"平均成绩"
FROM score
GROUP BY s_id
ORDER BY AVG(s_score) DESC
```

