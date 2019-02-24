[TOC]

---

---

# typora快捷键

- 表格

  - 可以用快捷键 **Ctrl+t** 
  - **|空格|空格|**，接着**enter**会弹出来表格

- 文字背景颜色

  - 打开**高亮功能**，`==内容==`，下面是演示
  - ==文本内容==

  



---

# 任务列表

代码：

```tex
- [ ] 吃饭
- [ ] 看电影
- [ ] 看书
- [ ] 记单词
```



效果：

- [ ] 吃饭
- [ ] 看电影
- [ ] 看书
- [x] 记单词



---



# 数学符号表示

**必须在导言区先载入amssymb 宏包而且系统中安装了AMS 数学**



## 数学模式重音符号

![](../Image/表1.png)



## 希腊字母

![](../Image/表2.png)



## 二元关系

可以在下面的命令前面加上`\not`命令，而得到起否定形式。

![1550937542912](../Image/表3.png)



![1550937613447](../Image/表4.png)



## “大”运算符

![1550937691238](../Image/表5.png)



## 箭头

![1550937772453](../Image/表6.png)



## 定界符

![1550937951512](../Image/表7.png)



## 大定界符

![1550938001826](../Image/表8.png)



## 其他符号

![1550938044785](../Image/表9.png)



## 非数学符号

![1550978014447](../Image/表10.png)



## AMS定界符

![1550978068863](../Image/表11.png)



## AMS希腊和希伯来字母

![1550978119162](../Image/表12.png)



## AMS二元关系

![1550978157140](../Image/表13.png)



## AMS箭头

![1550978267230](../Image/表14.png)



## AMS二元否定关系和箭头

![1550978311118](../Image/表15.png)



## AMS二元运算符

![1550978356834](../Image/表15.png)





## AMS其他符号

![1550978393881](../Image/表17.png)



## 数学字母

![1550978435611](../Image/表18.png)



---

# 流程图

## Sequence（序列，顺序发生）

[more](https://knsv.github.io/mermaid/#sequence-diagrams)

```gfm
​```mermaid
%% Example of sequence diagram
  sequenceDiagram
    Alice->>Bob: Hello Bob, how are you?
    alt is sick
    Bob->>Alice: Not so good :(
    else is well
    Bob->>Alice: Feeling fresh like a daisy
    end
    opt Extra response
    Bob->>Alice: Thanks for asking
    end
​```
```

实现：

```mermaid
%% Example of sequence diagram
  sequenceDiagram
    Alice->>Bob: Hello Bob, how are you?
    alt is sick
    Bob->>Alice: Not so good :(
    else is well
    Bob->>Alice: Feeling fresh like a daisy
    end
    opt Extra response
    Bob->>Alice: Thanks for asking
    end
```

```gfm
​```sequence
Alice->Bob: Hello Bob, how are you?
Note right of Bob: Bob thinks
Bob-->Alice: I am good thanks!
​```
```







实现：

```sequence
Alice->Bob: Hello Bob, how are you?
Note right of Bob: Bob thinks
Bob-->Alice: I am good thanks!
```



## Flowchat（流程图）

[more](https://knsv.github.io/mermaid/#flowcharts-basic-syntax)

```gfm
​```mermaid
graph LR
A[Hard edge] -->B(Round edge)
    B --> C{Decision}
    C -->|One| D[Result one]
    C -->|Two| E[Result two]
​```
```

实现：

```mermaid
graph LR
A[Hard edge] -->B(Round edge)
    B --> C{Decision}
    C -->|One| D[Result one]
    C -->|Two| E[Result two]
```







```gfm
​```flow
st=>start: Start
op=>operation: Your Operation
cond=>condition: Yes or No?
e=>end

st->op->cond
cond(yes)->e
cond(no)->op
​```
```



实现：

```flow
st=>start: Start
op=>operation: Your Operation
cond=>condition: Yes or No?
e=>end

st->op->cond
cond(yes)->e
cond(no)->op
```



# Gantt（图表）

[more](https://knsv.github.io/mermaid/#gant-diagrams)

```gfm
​```mermaid
%% Example with slection of syntaxes
        gantt
        dateFormat  YYYY-MM-DD
        title Adding GANTT diagram functionality to mermaid

        section A section
        Completed task            :done,    des1, 2014-01-06,2014-01-08
        Active task               :active,  des2, 2014-01-09, 3d
        Future task               :         des3, after des2, 5d
        Future task2               :         des4, after des3, 5d

        section Critical tasks
        Completed task in the critical line :crit, done, 2014-01-06,24h
        Implement parser and jison          :crit, done, after des1, 2d
        Create tests for parser             :crit, active, 3d
        Future task in critical line        :crit, 5d
        Create tests for renderer           :2d
        Add to mermaid                      :1d

        section Documentation
        Describe gantt syntax               :active, a1, after des1, 3d
        Add gantt diagram to demo page      :after a1  , 20h
        Add another diagram to demo page    :doc1, after a1  , 48h

        section Last section
        Describe gantt syntax               :after doc1, 3d
        Add gantt diagram to demo page      : 20h
        Add another diagram to demo page    : 48h
​```
```





实现：

```mermaid
%% Example with slection of syntaxes
        gantt
        dateFormat  YYYY-MM-DD
        title Adding GANTT diagram functionality to mermaid

        section A section
        Completed task            :done,    des1, 2014-01-06,2014-01-08
        Active task               :active,  des2, 2014-01-09, 3d
        Future task               :         des3, after des2, 5d
        Future task2               :         des4, after des3, 5d

        section Critical tasks
        Completed task in the critical line :crit, done, 2014-01-06,24h
        Implement parser and jison          :crit, done, after des1, 2d
        Create tests for parser             :crit, active, 3d
        Future task in critical line        :crit, 5d
        Create tests for renderer           :2d
        Add to mermaid                      :1d

        section Documentation
        Describe gantt syntax               :active, a1, after des1, 3d
        Add gantt diagram to demo page      :after a1  , 20h
        Add another diagram to demo page    :doc1, after a1  , 48h

        section Last section
        Describe gantt syntax               :after doc1, 3d
        Add gantt diagram to demo page      : 20h
        Add another diagram to demo page    : 48h
```