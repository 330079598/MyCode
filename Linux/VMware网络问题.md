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

