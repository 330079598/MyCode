- Git常用的有两种协议，不同的协议痛的代理配置也不相同。
  - `core.gitproxy` 用于 `git://` 协议，`http.proxy` 用于 `http://` 协议。
- 比如：

```txt
#使用http://协议
git clone https://github.com/...
#使用git://协议
git clone git@github.com:...
```

- http/https协议

> 假设程序在无状态、无工作目录的情况下运行git指令，利用`-c`参数可以在运行时重载git配置，包括关键的`http.proxy`

- git clone 使用 http.proxy 克隆项目

```
git clone -c http.proxy=http://127.0.0.1:1080 https://github.com...
# 我们小飞机的本地端口一般都是：127.0.0.1:1080 
```

- git目录设置目录代理模式，不太建议全部设置为全局配置。因为我有时候还使用coding.net

```
git config http.proxy 'socks5://127.0.0.1:1080'
```

- git协议:  使用git协议的配置

```
git config core.gitProxy  'socks5://192.168.7.1:1080'
```

- 在Windows下用MinGW全部配置：

  1. 打开MinGW，查看我们的全局配置

  ```
  git config --global -l
  ```

  2. 我们可以看到我们自己的配置，要想全局配置（在MinGW里面），我盟需要加上一个本地的代理，这个要在打开shadowsocksr的情况下用。
  3. 添加全局配置：

  ```
  git config --global http.proxy 'socks5://127.0.0.1:1080' 
  git config --global https.proxy 'socks5://127.0.0.1:1080'
  ```

  4. 最后再运行看一下全局配置是否成功

  ```
  git config --global -l
  ```

  如果有就成功啦，不过有个缺点，就是费流量，但是不怕，我流量多。。。。





- 查看.gitconfig配置
  - 具体的配置文件在 `.gitconfig`文件中 这个文件的地址在 · `C:\Users\<your user name>`文件夹下。

- 取消代理：

```
git config --global --unset http.proxy
git config --global --unset https.proxy
```

