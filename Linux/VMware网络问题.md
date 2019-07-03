- 在Linux下面,我每次启动VMware的时候,打开虚拟机后,虚拟网卡总是没开,起初我以为是我的网卡没有设置好,查了Google之后,我才发现是一些VMware的服务没有开启:

```
sudo modprobe vmnet && sudo vmware-networks --start
```

这个便好!!!