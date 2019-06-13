```text
基于Centos7
```

1. 安装FTP服务

   - 安装VSFTPD

   使用 yum 安装 vsftpd

   ```shell
   yum install -y vsftpd 
   ```

   - 启动 VSFTPD

   ```shell
   service vsftpd start
   ```

   - 启动后，可以看到系统已经监听了 21 端口：

   ```shell
   netstat -nltp | grep 21
   ```

此时,访问ftp://自己的网址就可以浏览/var/ftp目录了.

2. 配置FTP权限

   - 了解 VSFTP 配置

     vsftpd 的配置目录为 /etc/vsftpd，包含下列的配置文件：

     - vsftpd.conf 为主要配置文件
     - ftpusers 配置禁止访问 FTP 服务器的用户列表
     - user_list 配置用户访问控制

   - 阻止匿名访问和切换根目录

     匿名访问和切换根目录都会给服务器带来安全风险，我们把这两个功能关闭。

     - 编辑 /etc/vsftpd/vsftpd.conf，找到下面两处配置并修改：

       ```shell
       # 禁用匿名用户  12 YES 改为NO
       anonymous_enable=NO

       # 禁止切换根目录 101 行 删除#
       chroot_local_user=YES 
       ```
       - 编辑完成后保存配置，重新启动 FTP 服务
   
       ```shell
       service vsftpd restart
       ```
   
   - 创建FTP用户
   
     - 创建一个用户 ftpuser
   
       ```shell
       useradd ftpuser
       ```
   
     - 为用户 ftpuser 设置密码
   
       ```shell
       echo "12345" | passwd ftpuser --stdin
       ```
   
     - 为用户分配主目录
   
       为用户 ftpuser创建主目录并约定：
   
       /data/ftp 为主目录, 该目录不可上传文件 
       /data/ftp/pub 文件只能上传到该目录下
   
       在/data中创建相关的目录
   
       ```shell
       mkdir -p /data/ftp/pub
       ```
   
   - 创建登录欢迎文件
   
     ```shell
     echo "Welcome to use FTP service." > /data/ftp/welcome.txt
     ```
   
     - 设置访问权限
   
       ```shell
       chmod a-w /data/ftp && chmod 777 -R /data/ftp/pub
       ```
   
     - 设置为用户的主目录：
   
       ```shell
       usermod -d /data/ftp ftpuser
       ```
   
3. 访问FTP

   > 注意:记得关闭防火墙或开放ftp默认端口(21)



```txt
# 关闭SELinux服务
setenforce 0 
# 关闭防火墙
iptables -F 
```

- 通过Windows资源管理器访问

```shell
ftp://ftpuser:12345@ftp网址
```

