# Vmware在arch下安装：

- 安装Vmware Workstation所需要的所有依赖

```shell
sudo pacman -S fuse2 gtkmm linux-headers pcsclite libcanberra
#-console安装程序所需的另一个包是ncurses5-compat-libs，这可以在AUR上找到：
yay -S --noconfirm --needed ncurses5-compat-libs
````

- 安装**VMware Workstation Pro**

```shel
# vmware-workstation软件包在AUR上可用，可以通过运行命令进行安装：
yay -S --noconfirm --needed  vmware-workstation
```

- 根据需要，启用以下某些服务：

  - 用于访客网络访问的vmware-networks.service
  - vmware-usbarbitrator.service用于将USB设备连接到guest虚拟机
  - vmware-hostd.service用于共享虚拟机

- 例如：

  ```shell
  sudo systemctl enable vmware-networks.service  vmware-usbarbitrator.service vmware-hostd.service
  sudo systemctl start vmware-networks.service  vmware-usbarbitrator.service vmware-hostd.service
  
  #确认服务状态：
  sudo systemctl status vmware-networks.service  vmware-usbarbitrator.service vmware-hostd.service
  #最后，加载VMware模块：
  sudo modprobe -a vmw_vmci vmmon
  ```

  

---

---

---



- 在Linux下面,我每次启动VMware的时候,打开虚拟机后,虚拟网卡总是没开,起初我以为是我的网卡没有设置好,查了Google之后,我才发现是一些VMware的服务没有开启:

```
sudo modprobe vmnet && sudo vmware-networks --start
```

这个便好!!!

----

---

---

再加一个VMware的安装

```shell
sudo pacman -S linux-headers  #安装内核文件
sudo pacman -S vmware-workstation

#启动VMware workstation系统服务
sudo systemctl start vmware-networks.service #启动网络模块服务
sudo systemctl start vmware-usbarbitrator.service  #启动usb挂载服务
sudo systemctl start vmware-hostd.service  #启动共享服务

#设置开机启动
sudo systemctl enable vmware-networks.service
sudo systemctl enable vmware-usbarbitrator.service
sudo systemctl enable vmware-hostd.service
```

