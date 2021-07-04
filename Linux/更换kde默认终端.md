 在KDE设置中,设置更换默认终端,然而使用快捷键(shift+F4)还是会使用原来默认终端konsole.

![kde设置](./Image/kde设置.png)

- 查阅一番,找到相关的配置.

修改`/usr/share/kservices5/ServiceMenus/konsolehere.desktop`文件里面的配置`Exec=你想更换的终端命令`即可,重启或者`Log Out`就可以应用成功.

更换之后的配置如图:

![ChangeTermian](./Image/ChangeTerminal.png)

