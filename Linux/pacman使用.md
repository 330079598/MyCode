 

### Arch-Linux-pacman-pkg

## 1. 软件包基础搜索及安装卸载

$ pacman -Ss 软件名称 //(搜索软件包)
$ pacman -S 软件名称 //(安装软件包)
$ pacman -Rs 软件名称 //(卸载软件包)
$ pacman -Syu (更新)

## 2. 包的查询及清理

列出所有本地软件包（-Q,query查询本地；-q省略版本号）
$ pacman -Qq (列出有816个包)

列出所有显式安装（-e,explicitly显式安装；-n忽略外部包AUR）
$ pacman -Qqe (列出200个包)

列出自动安装的包（-d,depends作为依赖项）
$ pacman -Qqd (列出616个)

列出孤立的包（-t不再被依赖的"作为依赖项安装的包"）
$ pacman -Qqdt (列出35个)
注意：通常这些是可以妥妥的删除的。(sudo pacman -Qqdt | sudo pacman -Rs -)

## 3. 软件包和文件的查询

列出包所拥有的文件
$ sudo pacman -Ql iw
iw /usr/
iw /usr/bin/
iw /usr/bin/iw
iw /usr/share/
iw /usr/share/man/
iw /usr/share/man/man8/
iw /usr/share/man/man8/iw.8.gz

check 检查包文件是否存在（-kk用于文件属性）
$ sudo pacman -Qk iw
iw: 7 total files, 0 missing files

查询提供文件的包
$ sudo pacman -Qo /usr/share/man/man8/iw.8.gz
/usr/share/man/man8/iw.8.gz is owned by iw 5.0.1-1

## 4. 查询包详细信息

查询包详细信息（-Qi;-Qii[Backup Files]）(-Si[Repository,Download Size];-Sii[Signatures,])
$ pacman -Qi 包名
Repository 仓库名称（要联网用pacman -Si或Sii才能看到这一栏；）
Name 名称
Version 版本
Description 描述
Architecture 架构
URL 网址
Licenses 许可证
Groups 组
Provides 提供
**Depends On 依赖于（依赖那些包）**
Optional Deps 可选项
**Required By 被需求的（被那些包需求）**
Optional For 可选项
Conflicts With 与...发生冲突
Replaces 替代对象
Download Size 下载大小（要联网用pacman -Si或Sii才能看到这一栏；）
Installed Size 安装尺寸
Packager 包装者
Build Date 包装日期
**Install Date 安装日期**
**Install Reason 安装原因（主动安装，还是被依赖自动安装）**
Install Script 安装脚本
Validated By 验证者

$ pacman -Q -h 更多参数
-c --changelog 查看包的更改日志
**-d** --deps 列出作为依赖项安装的软件包[filter]
**-e** --explicit 列出显式安装[filter]
-g --groups 查看包组的所有成员
**-i** --info 查看包信息（-ii表示备份文件）
-k --check 检查包文件是否存在（-kk用于文件属性）
**-l** --list 列出查询包所拥有的文件
-n --native 列出已安装的软件包只能在同步数据库中找到[过滤器]
-p --file <package> 查询包文件而不是数据库
**-q** --quiet 显示查询和搜索的信息较少
**-t** --unrequired 列出所有包都不需要（可选）的包（-tt忽略optdepends）[filter]...

$ sudo cat pacman.log |grep boost 查看安装日志
[2019-03-23 17:10] [ALPM] installed boost-libs (1.69.0-1)
[2019-03-28 17:21] [PACMAN] Running 'pacman -S --config /etc/pacman.conf -- extra/rsync extra/wget community/lxc extra/protobuf extra/jsoncpp extra/libuv extra/rhash extra/cmake community/glm extra/boost community/gtest'
[2019-03-28 17:22] [ALPM] installed boost (1.69.0-1)
[2019-03-28 17:22] [PACMAN] Running 'pacman -D --asdeps --config /etc/pacman.conf -- rsync wget lxc protobuf jsoncpp libuv rhash cmake glm boost gtest'

## 5. 卸载不再被需要的软件包

$ sudo pacman -Qqdt | sudo pacman -Rs -  //删除不再被需要的(曾经被依赖自动安装的程序包)
$ sudo pacman -Q |wc -l
769
$ sudo pacman -Qe |wc -l
200
$ sudo pacman -Qd |wc -l
569
$ sudo pacman -Qdt |wc -l
0

## 6. 清除多余的安装包缓存(pkg包)

使用pacman安装的软件包会缓存在这个目录下 /var/cache/pacman/pkg/ ，可以清理如下2种。
-k (-k[n])保留软件包的n个最近的版本，删除比较旧的软件包。
-u (-u)已卸载软件的安装包(pkg包)。

$ paccache -h
 Operations:

| **-d, --dryrun** | perform a dry run, only finding candidate packages. | 执行干运行，只找到候选包。 |
| :--------------: | :-------------------------------------------------: | :------------------------: |
| **-m, --move **  |          move candidate packages to "dir".          |   将候选包裹移到“dir”。    |
| **-r, --remove** |             remove candidate packages.              |        删除候选包。        |

 Options:

|   -a, --arch <arch>   |        scan for "arch" (default: all architectures).         |                扫描“arch”（默认：所有架构）。                |
| :-------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
| -c, --cachedir <dir>  |     scan "dir" for packages. can be used more than once.     |               扫描“dir”包。 可以使用不止一次。               |
|                       |            (default: read from /etc/pacman.conf).            |             （默认：从/etc/pacman.conf中读取）。             |
|      -f, --force      |          apply force to mv(1) and rm(1) operations.          |               对mv（1）和rm（1）操作施加强制。               |
|      -h, --help       |             display this help message and exit.              |                    显示此帮助消息并退出。                    |
|  -i, --ignore <pkgs>  | ignore "pkgs", comma-separated. Alternatively, specify "-" to read package names from stdin, newline-delimited. | 忽略“pkgs”，以逗号分隔。 或者，指定“ - ”以从stdin读取包名称，换行符分隔。 |
|    **-k, --keep **    |    keep "num" of each package in the cache (default: 3).     |            保留缓存中每个包的“num”（默认值：3）。            |
|       --nocolor       |                  remove color from output.                   |                      从输出中删除颜色。                      |
|      -q, --quiet      |                       minimize output                        |                          最小化输出                          |
| **-u, --uninstalled** |                 target uninstalled packages.                 |                     目标已卸载的软件包。                     |
|     -v, --verbose     |          increase verbosity. specify up to 3 times.          |                   增加冗长。 最多指定3次。                   |
|      -z, --null       | use null delimiters for candidate names (only with -v and -vv). |         对候选名称使用null分隔符（仅使用-v和-vv）。          |


paccache -r //删除，默认保留最近的3个版本，-rk3
==> finished: 6 packages removed (disk space saved: 194.11 MiB)
paccache -rk2 //删除，默认保留最近的2个版本
paccache -rk1 //删除，默认保留最近的1个版本

 

## 7. 通过日志查看安装历史

查看软件管理所操作日志。
**$ cat /var/log/pacman.log |wc -l**
6360
$ cat /var/log/pacman.log |grep installed |wc -l
1134
$ cat /var/log/pacman.log |grep running |wc -l
1182
$ cat /var/log/pacman.log |grep Running |wc -l
1122
$ cat /var/log/pacman.log |grep removed |wc -l
217
$ cat /var/log/pacman.log |grep upgraded |wc -l
811

**$ cat /var/log/pacman.log |grep pacman |tail**
[2019-07-11 21:05] [PACMAN] Running 'pacman -S hexchat'
[2019-07-11 21:06] [PACMAN] Running 'pacman -S irssi'

**$ cat /var/log/pacman.log |grep installed |tail**
[2019-07-11 21:06] [ALPM] installed hexchat (2.14.2-3)
[2019-07-11 21:06] [ALPM] installed libotr (4.1.1-2)
[2019-07-11 21:06] [ALPM] installed irssi (1.2.1-1)

**$ cat /var/log/pacman.log |grep PACMAN |tail**
[2019-07-11 21:06] [PACMAN] Running 'pacman -S konversation'
[2019-07-11 21:06] [PACMAN] Running 'pacman -S pidgin'
[2019-07-11 21:07] [PACMAN] Running 'pacman -S weechat'
[2019-07-11 21:07] [PACMAN] Running 'pacman -S ircii'

**$ cat /var/log/pacman.log |grep irssi**
[2019-07-11 21:06] [PACMAN] Running 'pacman -S irssi'
[2019-07-11 21:06] [ALPM] installed irssi (1.2.1-1)

$ cat /var/log/pacman.log |grep pidgin
[2019-07-11 21:06] [PACMAN] Running 'pacman -S pidgin'

更新记录
**$ cat /var/log/pacman.log |grep 'upgraded chromium'**
[2019-06-15 06:39] [ALPM] upgraded chromium (75.0.3770.80-1 -> 75.0.3770.90-2)
[2019-06-19 10:20] [ALPM] upgraded chromium (75.0.3770.90-2 -> 75.0.3770.90-3)
[2019-06-23 17:18] [ALPM] upgraded chromium (75.0.3770.90-3 -> 75.0.3770.100-1)

通过**系统日志**查看安装记录(速度可能较慢)
**$ sudo journalctl |grep irssi**
Jul 11 21:04:46 tompc sudo[11619]: toma : TTY=pts/2 ; PWD=/home/toma ; USER=root ; COMMAND=/usr/bin/pacman -Ss irssi
Jul 11 21:06:11 tompc sudo[11841]: toma : TTY=pts/2 ; PWD=/home/toma ; USER=root ; COMMAND=/usr/bin/pacman -S irssi
Jul 11 21:06:11 tompc pacman[11842]: Running 'pacman -S irssi'
Jul 11 21:06:27 tompc pacman[11842]: installed irssi (1.2.1-1)

$ sudo journalctl |grep pidgin
Jul 11 21:04:55 tompc sudo[11662]: toma : TTY=pts/2 ; PWD=/home/toma ; USER=root ; COMMAND=/usr/bin/pacman -Ss pidgin
Jul 11 21:06:57 tompc sudo[12000]: toma : TTY=pts/2 ; PWD=/home/toma ; USER=root ; COMMAND=/usr/bin/pacman -S pidgin
Jul 11 21:06:57 tompc pacman[12001]: Running 'pacman -S pidgin'

系统日志筛选更新记录
**$ sudo journalctl |grep 'upgraded chromium'**
Jun 15 06:39:47 tompc pacman[5551]: upgraded chromium (75.0.3770.80-1 -> 75.0.3770.90-2)
Jun 19 10:20:45 tompc pacman[1904]: upgraded chromium (75.0.3770.90-2 -> 75.0.3770.90-3)
Jun 23 17:18:33 tompc pacman[7079]: upgraded chromium (75.0.3770.90-3 -> 75.0.3770.100-1)



附: pacman.log文件内容筛选时可用的关键字，供参考

|     关键字1      |    关键字2    |     关键字3     | 计数 |
| :--------------: | :-----------: | :-------------: | :--: |
|     [PACMAN]     |    running    |    pacman -R    |  47  |
|                  |               |   pacman -Rs    |  68  |
|                  |               |    pacman -S    | 310  |
|                  |               |   pacman -Syu   |  85  |
|                  |   starting    |     upgrade     |  85  |
|                  | synchronizing |     (空白)      |  89  |
| [ALPM-SCRIPTLET] |      -k       |      .img       |  70  |
|                  |    Running    |  [autodetect]   |  35  |
|                  |               |     [base]      |  70  |
|                  |               |     [block]     |  70  |
|                  |               |  [filesystems]  |  70  |
|                  |               |     [fsck]      |  70  |
|                  |               |   [keyboard]    |  70  |
|                  |               |    [modconf]    |  70  |
|                  |               |    [resume]     |  66  |
|                  |               |     [udev]      |  70  |
|                  |   Building    |                 |  70  |
|                  |   Creating    |                 |  70  |
|                  |  Generating   |                 |  70  |
|                  |     Image     |                 |  70  |
|                  |   Starting    |                 |  70  |
|                  |    WARNING    |                 |  70  |
|                  |  Certificate  |                 | 280  |
|                  |      gpg      |                 | 245  |
|      [ALPM]      |   installed   |                 | 1123 |
|                  |    removed    |                 | 217  |
|                  |    running    |  60-linux.hook  |  29  |
|                  |               | 70-dkms-install |  24  |
|                  |               | 70-dkms-remove  |  23  |
|                  |               |  90-linux.hook  |  35  |
|                  |               |   gtk-update    | 133  |
|                  |               | update-desktop  | 162  |
|                  |               | systemd-update  | 340  |
|                  |               | systemd-daemon  |  96  |
|                  |  transaction  |    completed    | 342  |
|                  |               |     started     | 342  |
|                  |   upgraded    |                 | 811  |

 

 