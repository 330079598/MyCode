- Windows下事gbk编码的格式,而Linux下则是UTF-8的格式,所以直接使用`unzip`的话,会出现乱码,每次解压东西,我都痛不欲生....

但是可以安装这个软件

```
yay -S unzip-natspec
```

> unzip-natspec可以自动识别文件编码，用法和unzip一样，直接"unzip xxx.zip"即可，非常方便！

---

---

在Linux做开发或者系统管理遇到乱码是经常的事情，主要windows下中文的默认编码是bg2312，而 linux下是utf-8。很多时候 涉及到和windows平台系统的通信免不了编码的转化，可能大部分人都用iconv库函数（包含在glib中）和iconv命令来执行编码转换，即：

iconv -f gb18030 -t utf-8 file1.txt -o file2.txt

说实话这个命令不好使，一方面容易重复转换，另一方面不支持通配符，无法成批转 换，文件少了还好说，要是一大堆文件岂不是要累死？

今天我要推荐的是另一个Shell下编码转换工具enca。用它不仅可以转换编码，还可以查看文件的原始编码，而且还支持成批转换。使用上也比iconv方便一些。安装enca很简单，一般用源安装就行了，enca用法如下：

enca -L 当前语言  文件名

enca -L zh_CN file ／／检查文件的编码



enca -L 当前语言 -x 目标编码 文件名 

enca -L zh_CN -x UTF-8 file ／／将文件编码转换为”UTF-8″编码

enca -L zh_CN -x UTF-8 < file1 > file2 ／／如果不想覆盖原文件可以这样

除了有检查文件编码的功能以外，”enca”还有一个好处就是如果文件本来就是你要转换的那种编码，它不会报错，还是会print出结果来， 而”iconv”则会报错。这对于脚本编写是比较方便的事情。