- 在gnome和xfce下面可以直接打开deepin-win下的tim和qq，但是在kde下却不可以直接打开，我们可以下载一个gnome的插件来解决这个问题。

- 插件名字`gnome-settings-daemon`

- 启动这个插件后就可以直接打开tim啦。启动命令：

  ```
  /usr/lib/gsd-xsettings 
  ```

  我们可以写一个shell脚本，开机自启即可！
  
  

---

- （不是kde的问题）在使用百度网盘的过程中，如果突然出现卡顿或者打不开的情况，需要删除：`/home/stone/.local/share/baidu/`，这个文件夹即可！