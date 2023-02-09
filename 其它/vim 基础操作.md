在vi中按u可以撤销一次操作

u   撤销上一步的操作
Ctrl+r 恢复上一步被撤销的操作

**注意：**
如果你输入“u”两次，你的文本恢复原样，那应该是你的Vim被配置在Vi兼容模式了。
重做
如果你撤销得太多，你可以输入CTRL-R（redo）回退前一个命令。换句话说，它撤销一个撤销。要看执行的例子，输入CTRL-R两次。字符A和它后面的空格就出现了：
young intelligent turtle
有一个特殊版本的撤销命令：“U”（行撤销）。行撤销命令撤销所有在前一个编辑行
上的操作。 输入这些命令两次取消前一个“U”：
A very intelligent turtle
xxxx 删除very
A intelligent turtle
xxxxxx 删除turtle
A intelligent
用“U”恢复行
A very intelligent turtle
用“u”撤销“U”
A intelligent
“U”命令自己改变自己，“u”命令撤销操作，CTRL-R命令重做操作。这有点乱，但不用
担心，用“u”和CTRL-R命令你可以切换到任何状态。

流行的文本编辑器通常都有前进和后退功能，可以在文件中曾经浏览过的位置之间来回移动。在 vim 中使用 Ctrl-O 执行后退，使用 Ctrl-I 执行前进。
相关帮助：  :help CTRL-O  :help CTRL-I   :help jump-motions