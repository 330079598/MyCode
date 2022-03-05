[toc]

---

---

---

### Nginx

```shell
docker run -p 80:80 --name nginx \
-v /mydata/nginx/html:/usr/share/nginx/html \
-v /mydata/nginx/logs:/var/log/nginx \
-v /mydata/nginx/conf:/etc/nginx \
-d nginx:1.10
```

### MySQL

1. 下载镜像文件

```shell
docker pull mysql:5.7
```

2. 创建实例并启动

```shell
docker run -p 3306:3306 --name mysql \
-v /mydata/mysql/log:/var/log/mysql \
-v /mydata/mysql/data:/var/lib/mysql \
-v /mydata/mysql/conf:/etc/mysql \
-e MYSQL_ROOT_PASSWORD=root \
-d mysql:5.7


参数说明:
-p 3306:3306：将容器的 3306 端口映射到主机的 3306 端口
-v /mydata/mysql/conf:/etc/mysql：将配置文件夹挂载到主机
-v /mydata/mysql/log:/var/log/mysql：将日志文件夹挂载到主机
-v /mydata/mysql/data:/var/lib/mysql/：将配置文件夹挂载到主机
-e MYSQL_ROOT_PASSWORD=root：初始化 root 用户的密码
```

3. MySQL配置

```shell
vi /mydata/mysql/conf/my.cnf
[client]
default-character-set=utf8
[mysql]
default-character-set=utf8
[mysqld]
init_connect='SET collation_connection = utf8_unicode_ci'
init_connect='SET NAMES utf8'
character-set-server=utf8
collation-server=utf8_unicode_ci
skip-character-set-client-handshake
skip-name-resolve
```

> 注意：解决 MySQL 连接慢的问题
> 在配置文件中加入如下，并重启 mysql
> [mysqld]
> skip-name-resolve
> 解释：
> skip-name-resolve：跳过域名解析

4. 通过容器的MySQL命令行工具连接

```shell
docker exec -it mysql mysql -uroot -proot
```

5. 设置root远程访问

```shell
grant all privileges on *.* to 'root'@'%' identified by 'root' with grant option;
flush privileges;
```

6. 进入容器文件系统

```shell
docker exec -it mysql /bin/bash
```

### Redis

1. 下载镜像文件

`docker pull redis`

2. 创建实例并启动

```shell
mkdir -p /mydata/redis/conf
touch /mydata/redis/conf/redis.conf
docker run -p 6379:6379 --name redis -v /mydata/redis/data:/data \
-v /mydata/redis/conf/redis.conf:/etc/redis/redis.conf \
-d redis redis-server /etc/redis/redis.conf
```

> redis 自描述文件：
> https://raw.githubusercontent.com/antirez/redis/4.0/redis.conf

3. 使用 redis 镜像执行 redis-cli 命令连接

`docker exec -it redis redis-cli`