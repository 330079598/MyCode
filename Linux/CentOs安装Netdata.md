- 环境：CentOs 7
- 准备环境：

```
yum install autoconf automake curl gcc git libmnl-devel libuuid-devel lm_sensors make MySQL-python nc pkgconfig python python-psycopg2 PyYAML zlib-devel
```

- 安装

```
git clone https://github.com/firehol/netdata.git --depth=1
cd netdata
./netdata-installer.sh # 执行脚本成功后，netdata会立即启动。如果不希望立即启动，加入--dont-start-it
```

- 设置开机启动

```
# copy the netdata startup file to /etc/init.d
cp system/netdata-init-d /etc/init.d/netdata

# make sure it is executable
chmod +x /etc/init.d/netdata

# enable it
chkconfig --add netdata
```

- 如果服务器打不开的的话，把防火墙的19999的端口打开.
- 通过浏览器中输入:`http://你的IP地址:19999`访问.