[toc]

### **一、 集合容器概念**

#### **1.1 什么是集合**

**集合框架：**用于存储数据的容器。

集合框架是为表示和操作集合而规定的一种统一的标准的体系结构。
任何集合框架都包含三大块内容：对外的接口、接口的实现和对集合运算的算法。
**接口：**表示集合的抽象数据类型。接口允许我们操作集合时不必关注具体实现，从而达到“多态”。在面
向对象编程语言中，接口通常用来形成规范。

**实现：**集合接口的具体实现，是重用性很高的数据结构。

**算法：**在一个实现了某个集合框架中的接口的对象身上完成某种有用的计算的方法，例如查找、排序
等。这些算法通常是多态的，因为相同的方法可以在同一个接口被多个类实现时有不同的表现。事实
上，算法是可复用的函数。
它减少了程序设计的辛劳。

集合框架通过提供有用的数据结构和算法使你能集中注意力于你的程序的重要部分上，而不是为了让程
序能正常运转而将注意力于低层设计上。
通过这些在无关API之间的简易的互用性，使你免除了为改编对象或转换代码以便联合这些API而去写大量的代码。 它提高了程序速度和质量。

#### **1.2 集合的特点**

集合的特点主要有如下两点：

- 对象封装数据，对象多了也需要存储。集合用于存储对象。
- 对象的个数确定可以使用数组，对象的个数不确定的可以使用集合。因为集合是可变长度的。

#### **1.3 集合和数组的区别**

- 数组是固定长度的；集合是可变长度的。
- 数组可以存储基本数据类型，也可以存储引用数据类型；集合只能存储引用数据类型。
- 数组存储的元素必须是同一个数据类型；集合存储的对象可以是通不同的数据类型。

**数据结构：**就是容器中存储数据的方式。

对于集合容器，有很多种。因为每一个容器的自身特点不同，其实原理在于每个容器的内部数据结构不同。

集合容器在不断向上抽取过程中，出现了集合体系。**在使用一个体系的原则：参阅顶层内容。建立底层对象。**

#### **1.4 使用集合框架的好处**

1. 容量自增长；
2. 提供了高性能的数据结构和算法，使编码更轻松，提高了程序速度和质量；
3. 允许不同 API 之间的互操作，API之间可以来回传递集合；
4. 可以方便地扩展或改写集合，提高代码复用性和可操作性。
5. 通过使用JDK自带的集合类，可以降低代码维护和学习新API成本

#### **1.5 常用的集合类有哪些？**

Map接口和Collection接口是所有集合框架的父接口：

1. Collection接口的子接口包括：Set接口和List接口
2. Map接口的实现类主要有：`HashMap、TreeMap、Hashtable、ConcurrentHashMap`以及`Properties`等
3. Set接口的实现类主要有：`HashSet、TreeSet、LinkedHashSet`等
4. List接口的实现类主要有：`ArrayList、LinkedList、Stack`以及``Vector`等

#### **1.6 List，Set，Map三者的区别？List、Set、Map 是否继承自 Collection 接口？List、Map、Set 三个接口存取元素时，各有什么特点？**

![Collection-Map](./img/Collection-Map.png)

Java容器分为`Collection`和`Map`两大类，`Collection`集合的子接口有`Set、List、Queue`三种子接口。我们比较常用的是`Set、List`，`Map`接口不是`Collection`的子接口。

`Collection`集合主要有`List`和`Set`两大接口

- `List`：一个有序（元素存入集合的顺序和取出的顺序一直）容器，元素可以重复，可以插入多个`null`元素，元素都有索引。常用的实现类有`ArrayList`、`LinkedList`和`Vector`。
- `Set`：一个无序（存入和取出顺序有可能不一致）容器，不可以存储重复元素，只允许一个`null`元素，必须保证元素的唯一性。`Set`接口常用实现类是`HashSet`、`LinkedHashSet`以及`TreeSet`。

`Map`是一个键值对集合，存储键、值之间的映射。`Key`无序，唯一；`Value`不要求有序，允许重复。`Map`没有继承与`Collection`接口，从`Map`集合中检索元素时，只要给出键对象，就会返回对应的值对象。

`Map`的常用实现类：`HashMap、TreeMap、HashTable、LinkedHashMap、ConcurrentHashMap`。

#### **1.7 集合框架底层数据结构**

 **`Collection`**

- `List`

  - `ArrayList`：`Object`数组

  - `Vector`：`Object`数组

  - `LinkedList`：双向循环链表

- `Set`

  - `HashSet`（无序，唯一）：基于`HashMap`实现的，底层采用`HashMap`来保存元素

  - `LinkedHashSet`：`LinkedHashSet`继承与`HashSet`，并且其内部是通过`LinkedHashMap`来实现的。有点类似于我们之前说的`LinkedHashMap`其内部是基于`Hashmap`实现一样，不过还是有一点点区别的。

  - `TreeSet`（有序，唯一）： 红黑树(自平衡的排序二叉树。)

**`Map`**

- `HashMap`：`JDK1.8`之前`HashMap`是由数组 + 链表组成的，数组是`HashMap`的主体，链表则是为了主要为了解决哈希冲突而存在的（“拉链式”解决冲突），`JDK1.8`以后在解决哈希冲突有了较大的变化，当链表长度大于阈值（默认8）时，将链表转化为红黑树，以减小搜索时间。
- `LinkedHashMap`：`LinkedHashMap`继承自`HashMap`，所以它的底层仍然是基于拉链式散列结构，即由数组和链表或红黑树组成。另外，`LinkedHashMap`在上面结构的基础上，增加了一条双向链表，使得上面的结构可以保持键值对的插入顺序。同时通过对链表进行相应的操作，实现了访问顺序相关逻辑。
- `HashTable`：数组 + 链表组成，数组是`HashMap`的主体，链表则是为了解决哈希冲突而存在的。
- `TreeMap`：红黑树（自平衡的排序二叉树）。

#### **1.8 那些集合类是线程安全的？**

- `vector`：就比`ArrayList`多了个同步化机制（线程安全），因为效率较低，现在已经不太建议使用。在web应用中，特别是前台页面，往往效率（页面响应速度）是优先考虑的。
- `statck`：堆栈类，先进后出。
- `HashTable`：就比hashmap多了个线程安全。
- `enumeration`：枚举，相当于迭代器。

#### **1.9 Java集合的快速失败机制“fail-fast”？**

是java集合的一种错误检测机制，当多个线程对集合进行结构上的改变的操作时，有可能会产生 fail-fast机制。

例如：假设存在两个线程（线程1、线程2），线程1通过Iterator在遍历集合A中的元素，在某个时候线程2修改了集合A的结构（是结构上面的修改，而不是简单的修改集合元素的内容），那么这个时候程序就会抛出 ConcurrentModificationException 异常，从而产生fail-fast机制。

原因：迭代器在遍历时直接访问集合中的内容，并且在遍历过程中使用一个 modCount 变量。集合在被遍历期间如果内容发生变化，就会改变modCount的值。每当迭代器使用hashNext()/next()遍历下一个元素之前，都会检测modCount变量是否为expectedmodCount值，是的话就返回遍历；否则抛出异常，终止遍历。

解决办法：

1. 在遍历过程中，所有涉及到改变modCount值得地方全部加上synchronized。
2. 使用CopyOnWriteArrayList来替换ArrayList

#### **1.10 怎么确保一个集合不能被修改？**

可以使用`Collection.unmodefiableCollection(Collection c)`方法来创建一个只读集合，这样改变集合的任何操作都会抛出` Java.lang.UnsupportedOperationException`异常。

示例代码：

```java
List<String> list = new ArrayList<>();
list.add("x");
Collection<String> clist = Collections.unmodifiableCollection(list);
clist.add("y"); // 运行时此行报错
System.out.println(list.size());
```

### **二、List接口**

#### **2.1 迭代器Iterator是什么？**

`Iterator`接口提供遍历任何`Collection`的接口。我们可以从一个`Collection`中使用迭代器方法来获取迭代器实例。迭代器取代了 Java 集合框架中的`Enumeration`，迭代器允许调用者在迭代过程中移除元素。

#### **2.2 Iterator怎么使用？有什么特点？**

`Iterator`使用代码如下：

```java
List<String> list = new ArrayList<>();
Iterator<String> it = list.iterator();
while(it. hasNext()){
	String obj = it. next();
	System. out. println(obj);
}
```

`Iterator`的特点是只能单向遍历，但是更加安全，因为它可以确保，在当前遍历的集合元素被更改的时候，就会抛出`ConcurrentModificationException `异常。

#### **2.3 如何边遍历边移除Collection中的元素？**

边遍历边修改`Collection`的唯一正确方式是使用`Iterator.remove()`方法

```java
Iterator<Integer> it = list.iterator();
while(it.hasNext()){
	*// do something*
	it.remove();
}
```

一种最常见的**错误代码**：

```java
for(Integer i : list){
	list.remove(i)
}
```

运行以上错误代码会报`ConcurrentModificationException`异常。这是因为当使用`foreach(for(Integer i : list))`语句时，会自动生成一个`iterator`来遍历该`list`，但同时该`list`正在被`Iterator.remove()`修改。Java 一般不允许一个线程在遍历`Collection`时另一个线程修改它。

#### **2.4 `Iterator`和`ListIterator`有什么区别？**

- `Iterator`可以遍历`Set`和`List`集合，而`ListIterator`只能遍历`List`。
- `Iterator`只能单向遍历，而`ListIterator`可以双向遍历（向前/后遍历）。
- `ListIterator`实现`Iterator`接口，然后添加了一些额外的功能，比如添加一个元素、替换一个元素、获取前面或后面元素的索引位置。

#### **2.5 遍历一个 List 有哪些不同的方式？每种方法的实现原理是什么？Java 中 List遍历的最佳实践是什么？**

遍历方式有以下几种：

-  for 循环遍历，基于计数器。在集合外部维护一个计数器，然后依次读取每一个位置的元素，当读取到最后一个元素后停止。
- 迭代器遍历，Iterator。Iterator 是面向对象的一个设计模式，目的是屏蔽不同数据集合的特点，统一遍历集合的接口。Java 在 Collections 中支持了 Iterator 模式。
- foreach 循环遍历。foreach 内部也是采用了 Iterator 的方式实现，使用时不需要显式声明Iterator 或计数器。优点是代码简洁，不易出错；缺点是只能做简单的遍历，不能在遍历过程中操作数据集合，例如删除、替换。

**最佳实践**：Java Collections 框架中提供了一个 RandomAccess 接口，用来标记 List 实现是否支持Random Access。

- 如果一个数据集合实现该接口，就意味着它支持`Random Access`，按位置读取元素的平均时间复杂度为`O（1）`，如`ArrayList`。
- 如果没有实现该接口，表示不支持`Random Access`，如`LinkedList`。

推荐做法：支持`Random Access`的列表可用 for 循环遍历，否则建议使用`Iterator`或`foreach`遍历。

#### **2.6 说一下`ArrayList`的优缺点**

`ArrayList`的优点：

- `ArrayList`底层以数组实现，是一种随机访问模式。`ArrayList`实现了`RandomAccess`接口，因此查找的时候非常快。
- `ArrayList`在顺序添加一个元素的时候非常方便。

`ArrayList`的缺点：

- 删除元素的时候，需要做一次元素复制操作。如果要复制的元素很多，那么就会比较耗费性能。
- 插入元素的时候，也需要做一次元素复制操作，缺点同上。

**`ArrayList`比较适合顺序添加、随机访问的场景。**

#### **2.7 如何实现数组和List之间的转换？**

- 数组转`List`：使用`Arrays.asList(array)`进行转换
- `List`转数组：使用`List`自带的`toArray()`方法

示例代码：

```java
// list to array
List<String> list = new ArrayList<String>();
list.add("123");
list.add("456");
list.toArray();
// array to list
String[] array = new String[]{"123","456"};
Arrays.asList(array);
```

#### **2.8 `ArrayList`和`LinkedList`的区别**

- 数据结构实现：`ArrayList` 是动态数组的数据结构实现，而 `LinkedList`是双向链表的数据结构实现。
- 随机访问效率：`ArrayList`比`LinkedList`在随机访问的时候效率要高，因为`LinkedList`是线性的数据存储方式，所以需要移动指针从前往后依次查找。
- 增加和删除效率：在非首尾的增加和删除操作，`LinkedList`要比`ArrayList`效率要高，因为`ArrayList`增删操作要影响数组内的其他数据的下标。
- 内存空间占用：`LinkedList`比`ArrayList`更占内存，因为`LinkedList`的节点除了存储数据，还存储了两个引用，一个指向前一个元素，一个指向后一个元素。
- 线程安全：`ArrayList`和`LinkedList`都是不同步的，也就是不保证线程安全；

综合来说，在需要频繁读取集合中的元素时，更推荐使用`ArrayList`，而在插入和删除操作较多时，更推荐使用`LinkedList`。

补充：数据结构基础之双向链表

双向链表也叫双链表，是链表的一种，它的每个数据结点中都有两个指针，分别指向直接后继和直接前驱。所以，从双向链表中的任意一个结点开始，都可以很方便地访问它的前驱结点和后继结点。

#### **2.9 `ArrayList`和`Vector`的区别**

这两个类都实现了`List`接口（`List`接口继承了`Collection`接口），它们都是有序集合。

- 线程安全：`Vector`使用了`Synchronized`来实现线程同步，是线程安全的，而`ArrayList`是非线程安全的。
- 性能：`ArrayList`在性能方面要优于`Vector`。
- 扩容：`ArrayList`和`Vector`都会根据实际的需求动态调整容量，只不过在`Vector`扩容每次会增加一倍，而`ArrayList`只会增加50%。

`Vector`类的所有方法都是同步的。可以由两个线程安全地访问一个`Vector`对象，但是一个线程访问`Vector`的话代码要在同步操作上耗费大量的时间。

`ArrayList`是不同步的，所以在不需要保证线程同步时建议使用`ArrayList`。

#### **2.10 插入数据时，`ArrayList`、`LinkedList`、`Vector`谁速度较快？阐述`ArrayList`、`LinkedList`、`Vector`的存储性能和特性**

`ArrayList`、`LinkedList`、`Vector`底层的实现都是使用数组方式存储数据。数组元素数大于实际存储的数据以便增加和插入数据，它们都允许直接按序号索引数据，但是插入元素要涉及数组元素移动等内存操作，所以索引数据快而插入数据慢。

`Vector`中的方法由于加入了`synchronized`修饰，因此**`Vector`是线程安全容器，但性能上较`ArrayList`差**。

`LinkedList`使用双向链表实现存储，按序号索引需要进行前向或后向遍历，但插入数据只需要记录当前项的前后项即可，所以**`LinkedList`插入速度较快**。

#### **2.11 多线程场景下如何使用`ArrayList`？**

`ArrayList`不是线程安全的，如果遇到多线程场景，可以通过`Collections`的`synchronizedList`方法将其转换成线程安全的容器后再使用。

```java
List<String> synchronizedList = Collections.synchronizedList(list);
synchronizedList.add("aaa");
synchronizedList.add("bbb");
for (int i = 0; i < synchronizedList.size(); i++) {
	System.out.println(synchronizedList.get(i));
}
```

#### **2.12 为什么`ArrayList`的`elementData`加上`transient`修饰？**

`ArrayList`中的数组定义如下：

```java
private transient Object[] elementData;
```

再看一下`ArrayList`的定义：

```java
public class ArrayList<E> extends AbstractList<E>
	implements List<E>, RandomAccess, Cloneable, java.io.Serializable
```

可以看到`ArrayList`实现了`Serializable`接口，这意味着`ArrayList`支持序列化。`transient`的作用是说不希望 `elementData`数组被序列化，重写了`writeObject`实现：

```java
private void writeObject(java.io.ObjectOutputStream s) throws
java.io.IOException{
    *// Write out element count, and any hidden stuff*
    int expectedModCount = modCount;
    s.defaultWriteObject();
    *// Write out array length*
    s.writeInt(elementData.length);
    *// Write out all elements in the proper order.*
    for (int i=0; i<size; i++)
    s.writeObject(elementData[i]);
    if (modCount != expectedModCount) {
    throw new ConcurrentModificationException();
	}
}
```

每次序列化时，先调用`defaultWriteObject()`方法序列化`ArrayList`中的非`transient`元素，然后遍历`elementData`，只序列化已存入的元素，这样既加快了序列化的速度，又减小了序列化之后的文件大小。

#### **2.13 `List`和`Set`的区别**

`List`、`Set`都是继承自`Collection`接口

`List`特点：一个有序（元素存入集合的顺序和取出的顺序一致）容器，元素可以重复，可以插入多个`null`元素，元素都有索引。常用的实现类有 `ArrayList、LinkedList、Vector`。

`Set`特点：一个无序（存入和取出顺序有可能不一致）容器，不可以存储重复元素，只允许存入一个`null`元素，必须保证元素唯一性。`Set`接口常用实现类是`HashSet、LinkedHashSet、TreeSet`。

另外`List`支持`for`循环，也就是通过下标来遍历，也可以用迭代器，但是`set`只能用迭代，因为他无序，无法用下标来取得想要的值。

`Set`和`List`对比：

- `Set`：检索元素效率低下，删除和插入效率高，插入和删除不会引起元素位置改变。
- `List`：和数组类似，`List`可以动态增长，查找元素效率高，插入删除元素效率低，因为会引起其他元素位置改变

### **三、`Set`接口**

#### **3.1 说一下`HashSet`的视线原理**

`HashSet`是基于`HashMap`实现的，`HashSet`的值存放于`HashMap`的 key 上，`HashMap`的 value 统一为 PRESENT，因此`HashSet`的实现比较简单，相关`HashSet`的操作，基本上都是直接调用底层`HashMap`的相关方法来完成，`HashSet`不允许重复的值。

#### **3.2 `HashSet`如何检查重复？`HashSet`是如何保证数据不可重复的？**

向`HashSet`中`add()`元素时，判断元素是否存在的依据，不仅要比较 hash 值，同时还要结合 equles 方法比较。

`HashSet`中的`add()`方法会使用`HashMap`的`put()`方法。

`HashMap`的 key 是唯一的，由源码可以看出 `HashSet` 添加进去的值就是作为`HashMap`的 key，并且在`HashMap`中如果`K/V`相同时，会用新的 V 覆盖掉旧的 V，然后返回旧的V。所以不会重复（ HashMap 比较key是否相等是先比较hashcode 再比较equals ）。

以下是`HashSet`部分源码：

```java
private static final Object PRESENT = new Object();
private transient HashMap<E,Object> map;

public HashSet() {
	map = new HashMap<>();
}

public boolean add(E e) {
	// 调用HashMap的put方法,PRESENT是一个至始至终都相同的虚值
	return map.put(e, PRESENT)==null;
}
```

`HashCode()`与`equals()`的相关规定：

- 如果两个对象相等，则`hashCode`一定也是相同的
- 两个对象相等，对两个`equals`方法返回 true
- 两个对象有相同的`hashCode`值，它们也不一定是相等的
- 综上，equals 方法被覆盖过，则`hashCode`方法也必须被覆盖
- `hashCode()`的默认行为是对堆上的对象产生独特值。如果没有重写`hashCode()`，则该 class 的两个对象无论如何都不会相等（即使这两个对象指向相同的数据）。

`==`与`equals`的区别：

- `==`是判断两个变量或实例是不是指向同一个内存空间 equals 是判断两个变量或实例所指向的内存空间的值是不是相同
- `==`是指对内存地址进行比较`equals()`是对字符串的内容进行比较
- `==`指引用是否相同，`equals()`指的是值是否相同

#### **3.3 `HashSet`与`HashMap`的区别**

|                         `HashMap`                          |                          `HashSet`                           |
| :--------------------------------------------------------: | :----------------------------------------------------------: |
|                      实现了`Map就接口                      |                       实现了`Set`接口                        |
|                         存储键值对                         |                          仅存储对象                          |
|                调用`put()`向`Map`中添加元素                |                调用`add()`方法向`Set`添加元素                |
|            `HashMap`使用键（Key）计算`HashCode`            | `HashSet`使用成员对象来计算`hashCode`值，对于两个对象来说，`hashCode`可能不同，所以`equals()`方法用来判断对象的相等性，如果两个对不同的话，那么就会false |
| `HashMap`相对于`HashSet`较快，因为它是使用唯一的键获取对象 |                `HashSet`较`HashMap`来说比较慢                |

### **四、 `Queue`**

#### **4.1 `BlockingQueue`是什么？**

`Java.util.concurrent.BlockingQueue`是一个队列，在进行检索或移除一个元素的时候，它会等待队列变为非空；当在添加一个元素时，它会等待队列中的可用空间。`BlockingQueue`接口是Java集合框架的一部分，主要用于实现生产者-消费者模式。我们不需要担心等待生产者有可用的空间，或消费者有可用的对象，因为它都在`BlockingQueue`的实现类中被处理了。Java提供了集中`BlockingQueue`的实现，比如`ArrayBlockingQueue`、`LinkedBlockingQueue`、`PriorityBlockingQueue`、`SynchronousQueue`等。

#### **4.2 在`Queue`中`poll()`和`remove()`有什么区别？**

- 相同点：都是返回第一个元素，并在队列中删除返回的对象。
- 不同点：如果没有元素`poll()`会返回`null`，而`remove()`会直接抛出`NoSuchElementException`异常

代码示例：

```java
Queue<String> queue = new LinkedList<String>();
queue. offer("string"); // add
System. out. println(queue. poll());
System. out. println(queue. remove());
System. out. println(queue. size());
```

### **五、`Map`接口**

#### **5.1 `HashMap`的实现原理**

`HashMap`概述： `HashMap`是基于哈希表的`Map`接口的非同步实现。此实现提供所有可选的映射操作，并允许使用`null值`和`null键`。此类不保证映射的顺序，特别是它不保证该顺序恒久不变。

`HashMap`的数据结构： 在Java编程语言中，最基本的结构就是两种，一个是数组，另外一个是模拟指针（引用），所有的数据结构都可以用这两个基本结构来构造的，`HashMap`就也不例外。`HashMap`实际上是一个“链表散列”的数据结构，即数组和链表的结合体。

`HashMap`基于`Hash`算法实现的

- 当我们往`Hashmap`中put元素时，利用key的`hashCode`重新hash计算出当前对象的元素在数组中的下标
-  存储时，如果出现hash值相同的key，此时有两种情况。
  - 如果key相同，则覆盖原始值；
  - 如果key不同（出现冲突），则将当前的key-value放入链表中
- 获取时，直接找到hash值对应的下标，在进一步判断key是否相同，从而找到对应值。
- 理解了以上过程就不难明白`HashMap`是如何解决hash冲突的问题，核心就是使用了数组的存储方式，然后将冲突的key的对象放入链表中，一旦发现冲突就在链表中做进一步的对比。

需要注意`Jdk 1.8`中对`HashMap`的实现做了优化，当链表中的节点数据超过八个之后，该链表会转为红黑树来提高查询效率，从原来的`O(n)`到`O(logn)`。

#### **5.2 `HashMap`在`JDK1.7`和`JDK1.8`中有哪些不同？`HashMap`的底层实现**

在Java中，保存数据有两种比较简单的数据结构：数组和链表。

- 数组的特点：寻址容易，插入和删除困难；
- 链表的特点：寻址困难，但插入和删除容易

所以我们将数组和链表结合在一起，发挥两者各自的优势，使用一种叫做**拉链法**的方法可以解决哈希冲突。

**`JDK1.8`之前**

`JDK1.8`之前采用的是拉链法。**拉链法**：将链表和数组相结合。也就是说创建一个链表数组，数组中每一格就是一个链表。若遇到哈希冲突，则将冲突的值加到链表中即可。

![zipper](./img/zipper.png)

**`JDK1.8`之后**

相比于之前的版本，jdk1.8在解决哈希冲突时有了较大的变化，当链表长度大于阈值（默认为8）时，将链表转化为红黑树，以减少搜索时间。

![redBlackTree](./img/redBlackTree.png)

**`JDK1.7` VS `JDK1.8`比较**

`JDK1.8`主要解决或优化了一下问题：

1. resize扩容优化
2. 引入了红黑树，目的是避免单条链表过长而影响查询效率
3. 解决了多线程死循环问题，但仍是非线程安全的，多线程时可能会造成数据丢失问题

|         **不同**         |                          **JDK1.7**                          |                          **JDK1.8**                          |
| :----------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
|         存储结构         |                         数组 + 链表                          |                     数组 + 链表 + 红黑树                     |
|        初始化方式        |                  单独函数：`inflateTable()`                  |                直接集成到扩容函数`resize()`中                |
|     `hash`值计算方式     |         扰动处理 = 9次扰动 = 4次位运算 + 5次异或运算         |         扰动处理 = 2次扰动 = 1次位运算 + 1次异或运算         |
|      存放数据的规则      |             无冲突时，存放数组；冲突时，存放链表             | 无冲突时，存放数组；冲突 & 链表长度 < 8：存放单链表；冲突 & 链表长度 > 8：树化并存放红黑树 |
|       插入数据方式       |   头插法（先讲原位置的数据移到后1位，再插入数据到该位置）    |             尾插法（直接插入到链表尾部/红黑树）              |
| 扩容后存储位置的计算方式 | 全部按照原来方法进行计算（即hashCode ->> 扰动函数 ->>(h&length-1)） | 按照扩容后的规律计算（即扩容后的位置=原位置 or 原位置 + 旧容量） |

#### **5.3 `HashMap`的 put 方法的具体流程**

当我们 put 的时候，首先计算 key 的 hash 值，这里调用了 hash 方法， hash 方法实际是让`key.hashCode()`与 `key.hashCode()>>>16`进行异或操作，高16bit补0，一个数和0异或不变，所以hash 函数大概的作用就是：高16bit不变，低16bit和高16bit做了一个异或，目的是减少碰撞。按照函数注释，因为bucket数组大小是2的幂，计算下标`index = (table.length - 1) & hash`，如果不做hash 处理，相当于散列生效的只有几个低 bit 位，为了减少散列的碰撞，设计者综合考虑了速度、作用、质量之后，使用高16bit和低16bit异或来简单处理减少碰撞，而且JDK8中用了复杂度`O（logn）`的树结构来提升碰撞下的性能。

putVal 方法的执行流程图

![putVal](./img/putVal.png)

```java
public V put(K key, V value) {
	return putVal(hash(key), key, value, false, true);
}

static final int hash(Object key) {
	int h;
	return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
}

//实现Map.put和相关方法
final V putVal(int hash, K key, V value, boolean onlyIfAbsent,boolean evict) {
    Node<K,V>[] tab; Node<K,V> p; int n, i;
    // 步骤①：tab为空则创建
    // table未初始化或者长度为0，进行扩容
    if ((tab = table) == null || (n = tab.length) == 0)
    	n = (tab = resize()).length;
    // 步骤②：计算index，并对null做处理
    // (n - 1) & hash 确定元素存放在哪个桶中，桶为空，新生成结点放入桶中(此时，这个结点是放在数组中)
    if ((p = tab[i = (n - 1) & hash]) == null)
    	tab[i] = newNode(hash, key, value, null);
    // 桶中已经存在元素
    else {
    	Node<K,V> e; K k;
    	// 步骤③：节点key存在，直接覆盖value
    	// 比较桶中第一个元素(数组中的结点)的hash值相等，key相等
    	if (p.hash == hash && ((k = p.key) == key || (key != null && key.equals(k))))
    		// 将第一个元素赋值给e，用e来记录
   			e = p;
        // 步骤④：判断该链为红黑树
        // hash值不相等，即key不相等；为红黑树结点
        // 如果当前元素类型为TreeNode，表示为红黑树，putTreeVal返回待存放的node, e可能为null
    	else if (p instanceof TreeNode)
    	// 放入树中
    	e = ((TreeNode<K,V>)p).putTreeVal(this, tab, hash, key, value);
    	// 步骤⑤：该链为链表
    	// 为链表结点
    else {
        // 在链表最末插入结点
        for (int binCount = 0; ; ++binCount) {
            // 到达链表的尾部
            //判断该链表尾部指针是不是空的
            if ((e = p.next) == null) {
            // 在尾部插入新结点
            p.next = newNode(hash, key, value, null);
            //判断链表的长度是否达到转化红黑树的临界值，临界值为8
            if (binCount >= TREEIFY_THRESHOLD - 1) // -1 for 1st
            //链表结构转树形结构
            treeifyBin(tab, hash);
            // 跳出循环
            break;
    	}
        // 判断链表中结点的key值与插入的元素的key值是否相等
        if (e.hash == hash && ((k = e.key) == key || (key != null && key.equals(k))))
            // 相等，跳出循环
            break;
        // 用于遍历桶中的链表，与前面的e = p.next组合，可以遍历链表
        p = e;
        }
    }
    //判断当前的key已经存在的情况下，再来一个相同的hash值、key值时，返回新来的value这个值
    if (e != null) {
        // 记录e的value
        V oldValue = e.value;
        // onlyIfAbsent为false或者旧值为null
        if (!onlyIfAbsent || oldValue == null)
        //用新值替换旧值
        e.value = value;
        // 访问后回调
        afterNodeAccess(e);
        // 返回旧值
        return oldValue;
        }
    }
    // 结构性修改
    ++modCount;
    // 步骤⑥：超过最大容量就扩容
    // 实际大小大于阈值则扩容
    if (++size > threshold)
    resize();
    // 插入后回调
    afterNodeInsertion(evict);
    return null;
}
```

①.判断键值对数组table[i]是否为空或为null，否则执行resize()进行扩容；

②.根据键值key计算hash值得到插入的数组索引i，如果table[i]==null，直接新建节点添加，转向⑥，如果table[i]不为空，转向③；

③.判断table[i]的首个元素是否和key一样，如果相同直接覆盖value，否则转向④，这里的相同指的是hashCode以及equals；

④.判断table[i] 是否为treeNode，即table[i] 是否是红黑树，如果是红黑树，则直接在树中插入键值对，否则转向⑤；

⑤.遍历table[i]，判断链表长度是否大于8，大于8的话把链表转换为红黑树，在红黑树中执行插入操作，否则进行链表的插入操作；遍历过程中若发现key已经存在直接覆盖value即可；

⑥.插入成功后，判断实际存在的键值对数量size是否超多了最大容量threshold，如果超过，进行扩容。

#### **5.4 `HashMap`的扩容操作是怎么实现的？**

①.在jdk1.8中，resize方法是在hashmap中的键值对大于阀值时或者初始化时，就调用resize方法进行扩容；

②.每次扩展的时候，都是扩展2倍；

③.扩展后Node对象的位置要么在原位置，要么移动到原偏移量两倍的位置。在putVal()中，我们看到在这个函数里面使用到了2次resize()方法，resize()方法表示的在进行第一次初始化时会对其进行扩容，或者当该数组的实际大小大于其临界值值(第一次为12),这个时候在扩容的同时也会伴随的桶上面的元素进行重新分发，这也是JDK1.8版本的一个优化的地方，在1.7中，扩容之后需要重新去计算其Hash值，根据Hash值对其进行分发，但在1.8版本中，则是根据在同一个桶的位置中进行判断(e.hash & oldCap)是否为0，重新进行hash分配后，该元素的位置要么停留在原始位置，要么移动到原始位置+增加的数组大小这个位置上。

#### **5.5 `HashMap`是怎么解决哈希冲突的？**

Hash，一般翻译为“散列”，也有直接音译为“哈希”的，这就是把任意长度的输入通过散列算法，变换成定长度的输出，该输出就是散列值（哈希值）；这种转换是一种压缩映射，也就是，散列值的空间通常远小于输入的空间，不同的输入可能会散列成相同的输出，所以不可能从散列值来唯一的确定输入值。简单的说就是一种将任意长度的消息压缩到某一固定长度的消息摘要的函数。所有散列函数都有如下一个基本特性：**根据同一散列函数计算出的散列值如果不同，那么输入值肯定也不同。但是，根据同一散列函数计算出的散列值如果相同，输入值不一定相同**。

**什么是哈希冲突？**

**当两个不同的输入值，根据同一散列函数计算出相同的散列值的现象，我们就把它叫做碰撞（哈希碰撞）。**

**HashMap的数据结构**

在Java中，保存数据有两种比较简单的数据结构：数组和链表。数组的特点是：寻址容易，插入和删除困难；链表的特点是：寻址困难，但插入和删除容易；所以我们将数组和链表结合在一起，发挥两者各自的优势，使用一种叫做链地址法的方式可以解决哈希冲突：

![hash](./img/hash.png)

这样我们就可以将拥有相同哈希值的对象组织成一个链表放在hash值所对应的bucket下，但相比于`hashCode`返回的int类型，我们`HashMap`初始的容量大小`DEFAULT_INITIAL_CAPACITY = 1 <<4`（即2的四次方16）要远小于int类型的范围，所以我们如果只是单纯的用`hashCode`取余来获取对应的bucket这将会大大增加哈希碰撞的概率，并且最坏情况下还会将HashMap变成一个单链表，所以我们还需要对`hashCode`作一定的优化

`hash()`函数

上面提到的问题，主要是因为如果使用`hashCode`取余，那么相当于参与运算的只有`hashCode`的低位，高位是没有起到任何作用的，所以我们的思路就是让`hashCode`取值出的高位也参与运算，进一步降低hash碰撞的概率，使得数据分布更平均，我们把这样的操作称为扰动，在JDK 1.8中的`hash()`函数如下：

```java
static final int hash(Object key) {
	int h;
	return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);// 与自己右移16位进行异或运算（高低位异或）
}
```

这比在JDK 1.7中，更为简洁，相比在1.7中的4次位运算，5次异或运算（9次扰动），在1.8中，只进行了1次位运算和1次异或运算（2次扰动）；

**JDK1.8新增红黑树**

![转换红黑树](./img/toRedBlackTree.png)

通过上面的**链地址法（使用散列表）**和**扰动函数**我们成功让我们的数据分布更平均，哈希碰撞减少，但是当我们的HashMap中存在大量数据时，加入我们某个bucket下对应的链表有n个元素，那么遍历时间复杂度就为`O(n)`，为了针对这个问题，JDK1.8在HashMap中新增了红黑树的数据结构，进一步使得遍历复杂度降低至`O(logn)`。

**总结**

简单总结一下HashMap是使用了哪些方法来有效解决哈希冲突的：

1.  使用链地址法（使用散列表）来链接拥有相同hash值的数据；
2. 使用2次扰动函数（hash函数）来降低哈希冲突的概率，使得数据分布更平均；
3. 引入红黑树进一步降低遍历的时间复杂度，使得遍历更快；

#### **5.6 能否使用任何类作为`Map`的`Key`？**

可以使用任何类作为 Map 的 key，然而在使用之前，需要考虑以下几点：

- 如果类重写了 equals() 方法，也应该重写 hashCode() 方法。
- 类的所有实例需要遵循与 equals() 和 hashCode() 相关的规则。
- 如果一个类没有使用 equals()，不应该在 hashCode() 中使用它。
- 用户自定义 Key 类最佳实践是使之为不可变的，这样 hashCode() 值可以被缓存起来，拥有更好的性能。不可变的类也可以确保 hashCode() 和 equals() 在未来不会改变，这样就会解决与可变相关的问题了。

#### **5.7 为什么HashMap中String、Integer这样的包装类适合作为K？**

答：String、Integer等包装类的特性能够保证Hash值的不可更改性和计算准确性，能够有效的减少
Hash碰撞的几率

1. 都是final类型，即不可变性，保证key的不可更改性，不会存在获取hash值不同的情况
2. 内部已重写了 equals() 、 hashCode() 等方法，遵守了HashMap内部的规范，不容易出现Hash值计算错误的情况；

#### **5.8 如果使用Object作为HashMap的Key，应该怎么办呢？**

答：重写 hashCode() 和 equals() 方法
1. 重写 hashCode() 是因为需要计算存储数据的存储位置，需要注意不要试图从散列码计算中排除掉一个对象的关键部分来提高性能，这样虽然能更快但可能会导致更多的Hash碰撞；
2. 重写 equals() 方法，需要遵守自反性、对称性、传递性、一致性以及对于任何非null的引用值x，x.equals(null)必须返回false的这几个特性，目的是为了保证key在哈希表中的唯一性；

#### **5.9 `HashMap`与`HashTable`的区别**

1. 线程安全： HashMap 是非线程安全的，HashTable 是线程安全的；HashTable 内部的方法基本都经过 synchronized 修饰。（如果你要保证线程安全的话就使用 ConcurrentHashMap吧！）；
2. 效率： 因为线程安全的问题，HashMap 要比 HashTable 效率高一点。另外，HashTable 基本被淘汰，不要在代码中使用它；
3. 对Null key 和Null value的支持： HashMap 中，null 可以作为键，这样的键只有一个，可以有一个或多个键所对应的值为 null。但是在 HashTable 中 put 进的键值只要有一个 null，直接抛NullPointerException。
4. 初始容量大小和每次扩充容量大小的不同 ： ①创建时如果不指定容量初始值，Hashtable 默认的初始大小为11，之后每次扩充，容量变为原来的2n+1。HashMap 默认的初始化大小为16。之后每次扩充，容量变为原来的2倍。②创建时如果给定了容量初始值，那么 Hashtable 会直接使用你给定的大小，而 HashMap 会将其扩充为2的幂次方大小。也就是说 HashMap 总是使用2的幂作为哈希表的大小，后面会介绍到为什么是2的幂次方。
5. 底层数据结构： JDK1.8 以后的 HashMap 在解决哈希冲突时有了较大的变化，当链表长度大于阈值（默认为8）时，将链表转化为红黑树，以减少搜索时间。Hashtable 没有这样的机制。
6. 推荐使用：在 Hashtable 的类注释可以看到，Hashtable 是保留类不建议使用，推荐在单线程环境下使用 HashMap 替代，如果需要多线程使用则用 ConcurrentHashMap 替代。

#### **5.10 如何决定使用`HashMap`还是`TreeMap`？**

对于在Map中插入、删除和定位元素这类操作，HashMap是最好的选择。然而，假如你需要对一个有序的key集合进行遍历，TreeMap是更好的选择。基于你的collection的大小，也许向HashMap中添加元素会更快，将map换为TreeMap进行有序key的遍历。

#### **5.11  HashMap 和 ConcurrentHashMap 的区别**

1. ConcurrentHashMap对整个桶数组进行了分割分段(Segment)，然后在每一个分段上都用lock锁进行保护，相对于HashTable的synchronized锁的粒度更精细了一些，并发性能更好，而HashMap没有锁机制，不是线程安全的。（JDK1.8之后ConcurrentHashMap启用了一种全新的方式实现,利用CAS算法。）
2. HashMap的键值对允许有null，但是ConCurrentHashMap都不允许。
