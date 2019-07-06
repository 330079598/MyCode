#  请用yay

```shell
$ sudo pacman -S yay
$ yay --aururl "https://aur.tuna.tsinghua.edu.cn" --save
$ yay -P -g
```

> 修改的配置文件位于 ~/.config/yay/config.json

---

### 安装搜狗输入法[aur]

```shell
$ sudo pacman -S fcitx-sogoupinyin fcitx-configtool fcitx-im
$ yay -Sa fcitx-qt4
$ sudo nano /etc/environment
--------------------------------------------------------------------------------------------------------
GTK_IM_MODULE=fcitx
QT_IM_MODULE=fcitx
XMODIFIERS="@im=fcitx"
```

> 重启后打开`Fcitx Configuration（Fcitx 配置）`，点击左下角的的`+`号，找到搜狗输入法选中，点击`ok（确认）`，保存退出，注册用户、重新登录

### 安装teamviewer

```shell
$ sudo pacman -S teamviewer
$ sudo nano /opt/teamviewer/tv_bin/desktop/com.teamviewer.TeamViewer.desktop
----------------------------------------------------------------------------------
Exec=/bin/sudo /opt/teamviewer/tv_bin/script/teamviewer passwd 123456
```

### 网易云音乐

```shell
$ sudo pacman -S netease-cloud-music vlc
$ sudo nano /usr/share/applications/netease-cloud-music.desktop
---------------------------------------------------------------------
Exec=/opt/netease/netease-cloud-music/netease-cloud-music %U
```

- redshift: 护眼工具，需要额外配置
- wqy-microhei : 开源免费的中文字体
- git : 下载github代码工具

- wget : 命令行下载工具，支持http，ftp

- vim : 很好用的编辑器

- zsh : 终端美化，主题可以到 ohmyz.sh 去看

- exfat-utils :支持exfat格式的包

- firefox : 火狐浏览器

- google-chrome : 谷歌浏览器

- deepin.com.qq.im[deepin-wine] 

- deepin.com.qq.office[deepin-wine]: 腾讯TIM

- screenfetch ： 装逼神器
- neofetch ： 装逼神器
- lolcat : 彩虹装逼神器，结合screenfetch或者neofetch使用
- file-roller : 桌面GUI解压软件
- unarchiver : 命令行解压，支持unar、lsar命令
- p7zip : 非常流行的解压工具
- kchmviewer : chm文件阅读器
- evince : 支持PDF, Postscript, djvu, tiff, dvi, XPS, SyncTex support with gedit, comics books (cbr,cbz,cb7 and cbt)
- deepin-calculator : deepin的计算器
- flameshot : 火焰截图，强大又易用的屏幕截图软件
- vlc：一款强大开源的全平台播放器
- xmind-zen : 思维导图
- wps-office : 中文办公软件WPS
- ttf-wps-fonts：中文办公软件WPS的字体包, 安装WPS必须安装的包
- krita : photoshop的替代, Krita 是一款自由、免费、开源的专业绘画软件。
- gimp：photoshop的替代品, GIMP 是自由、免费、开源的。
- deepin.com.thunderspeed[aur] [deepin-wine]: 迅雷
- baidunetdisk[aur] : 百度网盘
- 360zip[aur] : 360压缩
- mitalk[aur] ： 米聊，强大的全平台聊天软件

- jmtpfs[aur] : 挂载手机的包，jmtpfs /路径和fusermount -u /路径

