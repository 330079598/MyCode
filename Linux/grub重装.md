- 手贱，进Bois里，F9恢复出厂设置了，结构我的双系统的grub引导没了，，，这个急死我了，但我深知问题不大资料是不会丢失的，结果问人又被嘲讽一番
- 电脑的引导是 UEFI + GPT，archLinux + Windows10。开机直接进win10了，没有grub开机引导了



1. 找个u盘，写入archLinux的镜像，进入安装界面
2. 用`lsblk`和`fdisk -l`查看硬盘分区，找到你的Linux分区并挂载

```
mount /dev/你的Linux分区 /mnt
arch-chroot /mnt
```

3. 再找到你的efi分区并挂载

```
mount /dev/nvme0n1p1 /boot/efi
//这个是你的efi分区在那，挂载指定的位置
```

4. 直接安装就行啦

```
grub-install
grub-mkconfig
```

5. 退出重启，OK！！！

----

---

----

附加了解:

- `--efi-directory`:指定的是efi目录,专门放grub.efi的
- `--boot--directory`:指定的是grub的配置目录以及各种模块的的目录

如果想把EFI的目录设置在/boot/efi下面,可以用一下方法安装



- 部署`grub`:

```shell
grub-install --target=x86_64-efi --efi-directory=/boot/efi --boot-directory=/boot/efi --bootloader-id=grub
```

- 生成配置文件:

```shell
grub-mkconfig -o /boot/efi/grub/grub.cfg
```

