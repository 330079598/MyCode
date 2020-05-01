[toc]

---------

### 了解需要设置的代理

- HTTP形式

`git clone https://github.com/owner/git.git`

- ssh形式

`git clone [git@github.com](mailto:git@github.com):owner/git.git`

#### HTTP形式

- 走HTTP代理

```shell
git config --global http.proxy "http://127.0.0.1:8080"
git config --global https.proxy "http://127.0.0.1:8080"
```



- 走 socks5 代理（如 Shadowsocks）

```shell
git config --global http.proxy "socks5://127.0.0.1:1080"
git config --global https.proxy "socks5://127.0.0.1:1080"
```

- 查看全局配置

```shell
git config --global -l
```

- 取消代理

```shell
git config --global --unset http.proxy
git config --global --unset https.proxy
```

#### ssh形式

- 修改`~/.ssh/conf`文件(不存在则新建):

```shell
# 必须是 github.com
Host github.com
   HostName github.com
   User git
   # 走 HTTP 代理
   # ProxyCommand socat - PROXY:127.0.0.1:%h:%p,proxyport=8080
   # 走 socks5 代理（如 Shadowsocks）
   # ProxyCommand nc -v -x 127.0.0.1:1080 %h %p
   
### 提示
#对于Windows用户，要使用socks5代理提示没有nc这个命令可以将
ProxyCommand nc -v -x 127.0.0.1:1080 %h %p
#换成
ProxyCommand connect -S 127.0.0.1:1080 %h %p
```

