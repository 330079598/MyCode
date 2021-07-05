- 重启grub中没有windows启动项(我只是修改了默认的选择顺序,但是不知道为何找不到windows启动项,也可能是我的配置有所变动,具体原因不清楚,便将修复过程记录下来),可以下载`os-prober`进行检测设置.
  1. 安装`os-prober`,`sudo pacman -S os-prober`
  2. 修改`etc/default/grub`文件,添加或者取消注释`GRUB_DISABLE_OS_PROBER=false`
  3. 更新`grub配置文件`,`sudo grub-mkconfig -o /boot/efi/grub/grub.cfg `(根据个人的efi文件夹进行配置)

