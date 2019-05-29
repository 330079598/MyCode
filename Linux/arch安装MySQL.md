- arch默认已经不在支持MySQL,所以安装的事MariaDB,操作基本相同.

# 1. 安装

```
systemctl stop mysqld    //停止mysql服务
sudo pacman -S mariadb libmariadbclient mariadb-clients    //安装mariadb
sudo mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
```

# 2. 启动

```
systemctl start mariadb
mysql_secure_installation    //设置密码等管理操作
systemctl restart mariadb
```

# 3. 登录

```
mysql -u root -p
```