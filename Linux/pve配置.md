最近把以前的笔记本装了`pve`，把配置过程记录一下，方便下次重装或者修改。

1. 修改`IP`：`/etc/network/interfaces`

```shell
auto lo
iface lo inet loopback

iface enp3s0 inet manual

auto vmbr0
iface vmbr0 inet static
        address 192.168.1.111/24
        gateway 192.168.1.1
        bridge-ports enp3s0
        bridge-stp off
        bridge-fd 0

iface wlp5s0 inet manual
```

2. 修改`DNS`，`/etc/resolv.conf`

```shell
search com
nameserver 192.168.101.1
```

3. 修改主机名解析的`IP`，`/etc/hosts`

```shell
127.0.0.1 localhost.localdomain localhost
192.168.1.111 pve.com pve

# The following lines are desirable for IPv6 capable hosts

::1     ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
ff02::3 ip6-allhosts
```

4. 修改开机界面提示`URL`，`/etc/issue`

```shell
------------------------------------------------------------------------------

Welcome to the Proxmox Virtual Environment. Please use your web browser to 
configure this server - connect to:

  https://192.168.1.111:8006/

------------------------------------------------------------------------------

```

5. 修改使用国内源

```bash
# 使用阿里云源
#deb http://ftp.debian.org/debian buster main contrib
#deb http://ftp.debian.org/debian buster-updates main contrib
# security updates
#deb http://security.debian.org buster/updates main contrib

# debian aliyun source
deb https://mirrors.aliyun.com/debian buster main contrib non-free
deb https://mirrors.aliyun.com/debian buster-updates main contrib non-free
deb https://mirrors.aliyun.com/debian-security buster/updates main contrib non-free

# proxmox source
# deb http://download.proxmox.com/debian/pve buster pve-no-subscription
deb https://mirrors.ustc.edu.cn/proxmox/debian/pve buster pve-no-subscription

# 关闭Proxmox企业版更新源，注释
#修改 /etc/apt/sources.list.d/pve-enterprise.list
# deb https://enterprise.proxmox.com/debian/pve buster pve-enterprise
也可以直接执行 rm -rf /etc/apt/sources.list.d/pve-enterprise.list 命令删除企业源

或执行 mv /etc/apt/sources.list.d/pve-enterprise.list /etc/apt/sources.list.d/pve-enterprise.list.bak 命令将 pve-enterprise.list 文件更改为 pve-enterprise.list.bak 文件
```

6. `Ceph`源修改

```bash
# 编辑修改 /etc/apt/sources.list.d/ceph.list Ceph软件包仓库位置的配置文件

## deb http://download.proxmox.com/debian/ceph-nautilus buster main
deb http://mirrors.ustc.edu.cn/proxmox/debian/ceph-nautilus buster main
```

7. 执行更新源

```bash
# 最后执行 apt update #更新源
# 注：下面命令请根据自己情况选择执行
apt update && apt dist-upgrade -y #如需升级pve，则执行该命令
apt upgrade #更新已安装的包 
```

8. 合盖不断电和自动熄灭屏幕

```shell
setterm -blank 5 # 分钟
# 修改grub文件
/etc/default/grub
GRUB_CMDLINE_LINUX="consoleblank=300" #秒
```

9. 去除《无有效订阅》弹窗通知

修改文件`/usr/share/javascript/proxmox-widget-toolkit/proxmoxlib.js`，搜索`data.status`：

将

```bash
if (res === null || res === undefined || !res || res
			.data.status.toLowerCase() !== 'active') {
```

修改为

```bash
if (false) {
```

然后执行 `systemctl restart pveproxy` 命令重启网页服务,使用 `CTRL+F5` 快捷键强制重新加载网页页面。
