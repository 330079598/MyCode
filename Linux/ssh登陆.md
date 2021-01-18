[toc]

## SSH免密登陆

1. 本机生成SSH私钥和公钥

```shell
ssh-keygen -t rsa
```

这样会在当前目录生成名为id_rsa的私钥文件和名为id_rsa.pub的公钥文件，-t表示密钥类型是rsa. 如果你只输入ssh-keygen生成的RSA密钥长度为2048，如果你对安全性要求比较高可以指定4096位的长度：

```shell
ssh-keygen -b 4096 -t rsa
```

这里-b就是多少位，当然你对这些参数感兴趣可以使用--help参数看看具体的含义和解释。当你在生成SSHKEY的时候在命令行下会提示你Enter file in which to save the key，让你确认密钥文件保存的路径，一般回车即可（一般默认会在当前用户家目录下的.ssh目录下）。第二个提示是 Enter passphrase (empty for no passphrase) 让你输入一个密钥的密码，如果不输入则留空；回车生成公私钥完毕 :)

此时你可以使用cat命令看下自己的公私钥。

2. 服务器配置

- 方法一:
  - 将本地的公钥文件上传到服务器上，然后在服务器需要免密登录的用户家目录下查看是否有 `~/.ssh/authorized_keys`这个文件，
    如果没有手动创建一个:

  ```shell
  touch ~/.ssh/authorized_keys
  ```

  - 然后我们将公钥内容写入到authorized_keys文件中，因为这个文件可能已经有内容了，所以你可以使用如下方式

  ```shell
  cat -n ~/.ssh/rsa.pub ~/.ssh/authorized_keys
  ```

  这样就将公钥内容追加到authorized_keys中了，然后需要注意配置权限了，否则SSH不会工作的.

  1. 将.ssh目录的权限为700
  2. 将authorized_keys目录的权限为600

- 方法二:

  - `ssh-copy-id` 复制公钥

  ```shell
  ssh-copy-id username@remote-server -p prot
  ```

  它会将本地的所有公钥都传到服务器.

3. 运行使用

```shell
ssh user@host -p22
```

## SSH别名登陆

- 配置本地ssh,修改`~/.ssh/config `,没有config则自己创建

```shell
Host yourserverName 		#设置的别名
  HostName xx.xx.xx.xx      #服务器IP
  Port 22   				#端口号
  User username				#登陆用户名
  IdentitiesOnly yes		#IdentitiesOnly yes固有配置,多个配置则no
  IdentityFile ~/.ssh/id_rsa#对应服务器公钥的本地私钥文件路径,可以不写,我不写也能正常连接
```

## 常见问题

**ssh key Key is invalid**

> 密钥错误，或者配置错误

**github ssh key Key is invalid. Ensure you’ve copied the file correctly**

> 在github上添加新key时，没有正确拷贝 ~/.ssh/id_rsa.pub 内容所致。
> 一般发生在linux下，因为windows下用notepa++打开这个文件并复制一般是没有问题的，
> 而linux下使用vim打开再复制就会因为vim添加了回车而导致key添加失败。

解决办法是：使用cat命令将 **~/.ssh/id_rsa.pub** 内容输出到终端，再拷贝。

---

参考资料:

- [知乎](https://zhuanlan.zhihu.com/p/28423720)