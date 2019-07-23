安装步骤就不用写了,主要记录配置静态ip的

- 刚安装的`CentOS 7`中没有vim和一些查看网络的指令

```shell
yum install vim net-tools
# ifconfig属于net-tools
```

- 修改`ifcfg-ens33`

```shell
vim /etc/sysconfig/network-scripts/ifcfg-ens33
```

- 修改以下内容

```shell
BOOTPROTO="static" #dhcp改为static 
ONBOOT="yes" #开机启用本配置
IPADDR=192.168.7.106 #静态IP
GATEWAY=192.168.7.1 #默认网关
NETMASK=255.255.255.0 #子网掩码
DNS1=192.168.7.1 #DNS 配置
```

- 修改后的配置

```shell
TYPE="Ethernet"
PROXY_METHOD="none"
BROWSER_ONLY="no"
BOOTPROTO="static"
DEFROUTE="yes"
IPV4_FAILURE_FATAL="no"
IPV6INIT="yes"
IPV6_AUTOCONF="yes"
IPV6_DEFROUTE="yes"
IPV6_FAILURE_FATAL="no"
IPV6_ADDR_GEN_MODE="stable-privacy"
NAME="ens33"
UUID="5af284d9-6d21-4124-9841-18d48cdece9b"
DEVICE="ens33"
ONBOOT="yes"
IPADDR=172.16.238.151
GETEWAY=172.16.238.2
NETMASK=255.255.255.0
DNS1=114.114.114.114
DNS2=202.102.224.68
```

- 修改`/etc/sysconfig/network`

```shell
NETWORKING=yes
HOSTNAME=localhost.localdomain
GATEWAY=172.16.238.2 #这个和上面的一样
```

- 最后重启网络服务

```shell
service network restart
```

- 然后查看修改效果`ifconfig`或者`ip addr`

---

> 如果有问题,我会继续补充!