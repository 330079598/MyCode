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



- 在CentOS中，有三种定义的主机名:静态的（static），瞬态的（transient），和灵活的（pretty）。`静态`主机名也称为内核主机名，是系统在启动时从/etc/hostname自动初始化的主机名。`瞬态`主机名是在系统运行时临时分配的主机名，例如，通过DHCP或mDNS服务器分配。静态主机名和瞬态主机名都遵从作为互联网域名同样的字符限制规则。而另一方面，`灵活`主机名则允许使用自由形式（包括特殊/空白字符）的主机名，以展示给终端用户（如qqmm）。
     在CentOS 7中，有个叫hostnamectl的命令行工具，它允许你查看或修改与主机名相关的配置。

1. 要查看主机名相关的设置：

```
[root@localhost ~]# hostnamectl
   Static hostname: localhost.localdomain
         Icon name: computer-vm
           Chassis: vm
        Machine ID: 21ff9d4ebdd94e949b9fd6cbdb1926c0
           Boot ID: 2a952e91c02841e3ae10de0d16dd3f01
    Virtualization: kvm
  Operating System: CentOS Linux 7 (Core)
       CPE OS Name: cpe:/o:centos:centos:7
            Kernel: Linux 3.10.0-327.el7.x86_64
      Architecture: x86-64
[root@localhost ~]# hostnamectl status
   Static hostname: localhost.localdomain
         Icon name: computer-vm
           Chassis: vm
        Machine ID: 21ff9d4ebdd94e949b9fd6cbdb1926c0
           Boot ID: 2a952e91c02841e3ae10de0d16dd3f01
    Virtualization: kvm
  Operating System: CentOS Linux 7 (Core)
       CPE OS Name: cpe:/o:centos:centos:7
            Kernel: Linux 3.10.0-327.el7.x86_64
      Architecture: x86-64
```

1. 只查看静态、瞬态或灵活主机名，分别使用`--static`，`--transient`或`--pretty`选项。

```
[root@localhost ~]# hostnamectl --static
localhost.localdomain
[root@localhost ~]# hostnamectl --transient
localhost.localdomain
[root@localhost ~]# hostnamectl --pretty
```

1. 要同时修改所有三个主机名：静态、瞬态和灵活主机名：

```
[root@localhost ~]# hostnamectl set-hostname qqmm
[root@localhost ~]# hostnamectl --pretty
[root@localhost ~]# hostnamectl --static
qqmm
[root@localhost ~]# hostnamectl --transient
qqmm
```

就像上面展示的那样，在修改静态/瞬态主机名时，任何特殊字符或空白字符会被移除，而提供的参数中的任何大写字母会自动转化为小写。
 一旦修改了静态主机名，`/etc/hostname` 将被自动更新。然而，`/etc/hosts` 不会更新以保存所做的修改，所以你每次在修改主机名后一定要手动更新`/etc/hosts`，之后再重启CentOS 7。否则系统再启动时会很慢。

1. 手动更新`/etc/hosts` 

```
vim /etc/hosts
#127.0.0.1   localhost localhost.localdomain localhost4 localhost4.localdomain4
127.0.0.1  qqmm
#::1         localhost localhost.localdomain localhost6 localhost6.localdomain6
::1        qqmm
```

1. 重启CentOS 7 之后`（reboot -f ）`，

```
[root@qqmm ~]# hostname
qqmm
[root@qqmm ~]# hostnamectl
   Static hostname: qqmm
         Icon name: computer-vm
           Chassis: vm
        Machine ID: 21ff9d4ebdd94e949b9fd6cbdb1926c0
           Boot ID: 2a952e91c02841e3ae10de0d16dd3f01
    Virtualization: kvm
  Operating System: CentOS Linux 7 (Core)
       CPE OS Name: cpe:/o:centos:centos:7
            Kernel: Linux 3.10.0-327.el7.x86_64
      Architecture: x86-64
```

1. 如果你只想修改特定的主机名（静态，瞬态或灵活），你可以使用`--static`，`--transient`或`--pretty`选项。例如，要永久修改主机名，你可以修改静态主机名：

```
[root@localhost ~]# hostnamectl --static set-hostname qqmm
```

重启CentOS 7 之后（`reboot -f` ），

```
[root@localhost ~]# hostnamectl --static
qqmm
[root@localhost ~]# hostnamectl --transient
qqmm
[root@localhost ~]# hostnamectl --pretty
qqmm
[root@localhost ~]# hostname
qqmm
```

其实，你不必重启机器以激活永久主机名修改。上面的命令会立即修改内核主机名。
 注销并重新登入后在命令行提示来观察新的静态主机名

---

> 如果有问题,我会继续补充!