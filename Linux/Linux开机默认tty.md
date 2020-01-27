最近桌面出了点问题,进了一次tty之后,开机就会直接进入tty,查了查资料,如下:

```shell
systemctl get-default
multi-user.target #这个默认的是进tty,可以更改启动顺序的

systemctl set-default graphical.target #设置graphical.target为默认的启动模式

systemctl get-default #再重新查看一次
graphical.target #默认图形界面,出现这个是开机正常图形界面
```