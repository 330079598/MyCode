>  最近打算换硬盘,所以估计要重装系统,用了这么久,把常用的软件写下来备份一下!

- electro-ssr:这个不用说也知道吧!!!
- youdao-dict:有道词典
- google-chrome,chromium,firefox:浏览器
- eclipse,IDEA,PyChar,Webstorm,codeblocks,visual studio code:开发工具
- baidunetdisk:百度网盘
- vmware:虚拟机
- foxit-reader:PDF阅读器
- telegram,tim,electronic-wechat:通讯工具
- thunderbird:邮箱管理
- flameshot:截图工具(很好用的工具)
- lightworks:视频剪辑工具
- thunder-speed:迅雷
- WPS:良心系列
- dbeaver:数据库管理工具
- gimp,krita:图像处理工具
- simplescreenrecorder:录屏工具
- peek:gif录制工具
- netease-cloud-music:网易云
- red-shift:护眼工具
- typora:Markdown工具
- VLC:视频播放工具
- speedtest-cli:网速测试(一个Python写的插件)
- slimbook:省电装置
- radeontop:查看显卡使用率(AMD)
- albert:比kruner好用,速度快

---

因为我在用蓝牙键盘,但是我发现系统刚开机是没有自动连接蓝牙的,需要输入开机密码之后才可以自动连接,可以修改以下配置:

```shell
vim /etc/bluetooth/main.conf

[Policy]
AutoEnable=true
```



----

大概就这么,先放着,用到再加!!!