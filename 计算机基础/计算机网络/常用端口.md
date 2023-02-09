## 服务器常用端口

| 端口        |                  服务                  |                             说明                             |
| :---------- | :------------------------------------: | :----------------------------------------------------------: |
| 21          |                  FTP                   |            FTP 服务器所开放的端口，用于上传、下载            |
| 22          |                  SSH                   | 22 端口就是 ssh 端口，用于通过命令行模式远程连接 Linux 系统服务器 |
| 25          |                  SMTP                  |            SMTP 服务器所开放的端口，用于发送邮件             |
| 80          |                  HTTP                  |      用于网站服务例如 IIS、Apache、Nginx 等提供对外访问      |
| 110         |                  POP3                  |          110 端口是为 POP3（邮件协议 3）服务开放的           |
| 137/138/139 |                NETBIOS                 | 其中 137、138 是 UDP 端口，当通过网上邻居传输文件时用这个端口。而 139 端口：通过这个端口进入的连接试图获得 NetBIOS/SMB 服务。这个协议被用于 windows 文件和打印机共享和 SAMBA |
| 143         |                  IMAP                  | 143 端口主要是用于“Internet Message AccessProtocol”v2（Internet 消息访问协议，简称 IMAP），和 POP3 一样，是用于电子邮件的接收的协议 |
| 443         |                 HTTPS                  |   网页浏览端口，能提供加密和通过安全端口传输的另一种 HTTP    |
| 1433        |               SQL Server               | 1433 端口，是 SQL Server 默认的端口，SQL Server 服务使用两个端口：TCP-1433、UDP-1434。其中 1433 用于供 SQL Server 对外提供服务，1434 用于向请求者返回 SQL Server 使用了哪个 TCP/IP 端口 |
| 3306        |                 MySQL                  | 3306 端口，是 MySQL 数据库的默认端口，用于 MySQL 对外提供服务 |
| 3389        | Windows Server Remote Desktop Services | 3389 端口是 Windows 远程桌面的服务端口，可以通过这个端口，用 “远程桌面” 等连接工具来连接到远程的服务器 |
| 8080        |                代理端口                | 8080 端口同 80 端口，是被用于 WWW 代理服务的，可以实现网页浏览，经常在访问某个网站或使用代理服务器的时候，会加上 “:8080” 端口号。另外 Apache Tomcat web server 安装后，默认的服务端口就是 8080 |

## TCP/UDP 端口列表

IANA 的端口分配列表 - http://www.iana.org/assignments/port-numbers

> 以下列表仅列出常用端口，详细的列表请参阅 IANA 网站

|       端口        |                             描述                             |
| :---------------: | :----------------------------------------------------------: |
|     0/TCP,UDP     | 保留端口；不使用（若发送过程不准备接受回复消息，则可以作为源端口） |
|     1/TCP,UDP     |         TCPMUX（传输控制协议端口服务多路开关选择器）         |
|     5/TCP,UDP     |                     RJE（远程作业登录）                      |
|     7/TCP,UDP     |                       ECHO（回显）协议                       |
|     9/TCP,UDP     |                     DISCARD（丢弃）协议                      |
|    11/TCP,UDP     |                         SYSTAT 协议                          |
|    13/TCP,UDP     |                         DAYTIME 协议                         |
|    15/TCP,UDP     |                         NETSTAT 协议                         |
|    17/TCP,UDP     |            QOTD（Quote of the Day，每日引用）协议            |
|    18/TCP,UDP     |                         消息发送协议                         |
|    19/TCP,UDP     |                  CHARGEN（字符发生器）协议                   |
|    20/TCP,UDP     |                 文件传输协议 - 默认数据端口                  |
|    21/TCP,UDP     |                   文件传输协议 - 控制端口                    |
|    22/TCP,UDP     | SSH（Secure Shell） - 远程登录协议，用于安全登录文件传输（SCP，SFTP）及端口重新定向 |
|    23/TCP,UDP     |             Telnet 终端仿真协议 - 未加密文本通信             |
|    25/TCP,UDP     |  SMTP（简单邮件传输协议） - 用于邮件服务器间的电子邮件传递   |
|    26/TCP,UDP     |              RSFTP - 一个简单的类似 FTP 的协议               |
|    35/TCP,UDP     |                   QMS Magicolor 2 printer                    |
|    37/TCP,UDP     |                        TIME 时间协议                         |
|    39/TCP,UDP     |          Resource Location Protocol（资源定位协议）          |
|    41/TCP,UDP     |                             图形                             |
|    42/TCP,UDP     |                Host Name Server（主机名服务）                |
|    42/TCP,UDP     |                   WINS（WINS 主机名服务）                    |
|      43/TCP       |                          WHOIS 协议                          |
|    49/TCP,UDP     |                     TACACS 登录主机协议                      |
|    53/TCP,UDP     |                     DNS（域名服务系统）                      |
|    56/TCP,UDP     |                         远程访问协议                         |
|      57/TCP       |                      MTP，邮件传输协议                       |
|      67/UDP       |    BOOTP（BootStrap 协议）服务；同时用于动态主机设置协议     |
|      68/UDP       |            BOOTP 客户端；同时用于动态主机设定协议            |
|      69/UDP       |                   TFTP（小型文件传输协议）                   |
|      70/TCP       |                     Gopher 信息检索协议                      |
|      79/TCP       |                         Finger 协议                          |
|      80/TCP       |             HTTP（超文本传输协议）- 用于传输网页             |
|      81/TCP       |                  HTTP 预备 (超文本传输协议)                  |
|      81/TCP       |                Torpark - Onion routing ORport                |
|      82/UDP       |                      Torpark - 控制端口                      |
|      88/TCP       |                     Kerberos - 认证代理                      |
|      101/TCP      |                            主机名                            |
|      102/TCP      |                        ISO-TSAP 协议                         |
|      107/TCP      |                       远程 Telnet 协议                       |
|      109/TCP      |       POP (Post Office Protocol)，“邮局协议”，第 2 版        |
|      110/TCP      |        POP3（“邮局协议”，第 3 版）- 用于接收电子邮件         |
|    111/TCP,UDP    |                           Sun 协议                           |
|      113/TCP      | ident - 旧的服务器身份识别系统，仍然被 IRC 服务器用来认证它的用户 |
|      115/TCP      |                    SFTP, 简单文件传输协议                    |
|      117/TCP      |                          UUCP-PATH                           |
|    118/TCP,UDP    |                           SQL 服务                           |
|      119/TCP      |           网络新闻传输协议 - 用来收取新闻组的消息            |
|      123/UDP      |         NTP（Network Time Protocol） - 用于时间同步          |
|    135/TCP,UDP    |   EPMAP (End Point Mapper) / Microsoft RPC Locator Service   |
|    137/TCP,UDP    |                 NetBIOS NetBIOS Name Service                 |
|    138/TCP,UDP    |               NetBIOS NetBIOS Datagram Service               |
|    139/TCP,UDP    |               NetBIOS NetBIOS Session Service                |
|    143/TCP,UDP    | IMAP4（Internet Message Access Protocol 4） - used for retrieving E-mails |
|    152/TCP,UDP    |            BFTP, Background File Transfer Program            |
|    153/TCP,UDP    |           SGMP, Simple Gateway Monitoring Protocol           |
|    156/TCP,UDP    |                           SQL 服务                           |
|    158/TCP,UDP    |           DMSP, Distributed Mail Service Protocol            |
|    161/TCP,UDP    |          SNMP (Simple Network Management Protocol)           |
|    162/TCP,UDP    |                           SNMPTRAP                           |
|      170/TCP      |                          Print-srv                           |
|      179/TCP      |                BGP (Border Gateway Protocol)                 |
|      194/TCP      |                    IRC（互联网中继聊天）                     |
|    201/TCP,UDP    |                AppleTalk Routing Maintenance                 |
|    209/TCP,UDP    |                     Quick Mail 传输协议                      |
|    213/TCP,UDP    |                             IPX                              |
|    218/TCP,UDP    |                      MPP，信息发布协议                       |
|    220/TCP,UDP    |                IMAP，交互邮件访问协议第 3 版                 |
|    259/TCP,UDP    |           ESRO, Efficient Short Remote Operations            |
|    264/TCP,UDP    |           BGMP，Border Gateway Multicast Protocol            |
|      308/TCP      |                    Novastor Online Backup                    |
|      311/TCP      |       Apple Server-Admin-Tool, Workgroup-Manager-Tool        |
|    318/TCP,UDP    |         TSP，时间戳协议（英语：Time Stamp Protocol）         |
|    323/TCP,UDP    |           IMMP, Internet Message Mapping Protocol            |
|    383/TCP,UDP    |              HP OpenView HTTPs Operations Agent              |
|    366/TCP,UDP    | SMTP, Simple Mail Transfer Protocol. ODMR, On-Demand Mail Relay |
|    369/TCP,UDP    |                         Rpc2portmap                          |
|    371/TCP,UDP    |                        ClearCase albd                        |
|    384/TCP,UDP    |                    一个远程网络服务器系统                    |
|    387/TCP,UDP    |        AURP, AppleTalk Update-based Routing Protocol         |
|    389/TCP,UDP    |                       轻型目录访问协议                       |
|    401/TCP,UDP    |               UPS Uninterruptible Power Supply               |
|      411/TCP      |                   Direct Connect Hub port                    |
|      412/TCP      |             Direct Connect Client-To-Client port             |
|    427/TCP,UDP    |               SLP (Service Location Protocol)                |
|      443/TCP      |            HTTPS - HTTP over TLS/SSL（加密传输）             |
|    444/TCP,UDP    |             SNPP，Simple Network Paging Protocol             |
|      445/TCP      | Microsoft-DS (Active Directory，Windows shares, Sasser worm，Agobot, Zobotworm) |
|      445/UDP      |                Microsoft-DS SMB file sharing                 |
|    464/TCP,UDP    |                 Kerberos Change/Set password                 |
|      465/TCP      |                        Cisco protocol                        |
|      465/TCP      |                        SMTP over SSL                         |
|      475/TCP      |        tcpnethaspsrv（Hasp services, TCP/IP version）        |
|      497/TCP      |                     dantz backup service                     |
|    500/TCP,UDP    |              ISAKMP，IKE-Internet Key Exchange               |
|    502/TCP,UDP    |                       Modbus，Protocol                       |
|      512/TCP      |                exec, Remote Process Execution                |
|      512/UDP      | comsat, together with biff：notifies users of new c.q. yet unread e-mail |
|      513/TCP      |                             登陆                             |
|      513/UDP      |                             Who                              |
|      514/TCP      | rsh protocol - used to execute non-interactive commandline commands on a remote system and see the screen return |
|      514/UDP      |          syslog protocol - used for system logging           |
|      515/TCP      |  Line Printer Daemon protocol - used in LPD printer servers  |
|      517/UDP      |                             Talk                             |
|      518/UDP      |                            NTalk                             |
|      520/TCP      |                             efs                              |
|      520/UDP      |                        Routing - RIP                         |
|      513/UDP      |                            Router                            |
|    524/TCP,UDP    | NCP（NetWare Core Protocol）is used for a variety things such as access to primary NetWare server resources, Time Synchronization, etc. |
|      525/UDP      |                      Timed，Timeserver                       |
|    530/TCP,UDP    |                         远程过程调用                         |
|    531/TCP,UDP    |                  AOL Instant Messenger, IRC                  |
|      532/TCP      |                           netnews                            |
|      533/UDP      |              netwall, For Emergency Broadcasts               |
|      540/TCP      |              UUCP (Unix-to-Unix Copy Protocol)               |
|    542/TCP,UDP    |               commerce (Commerce Applications)               |
|      543/TCP      |                    klogin, Kerberos login                    |
|      544/TCP      |                kshell, Kerberos Remote shell                 |
|    546/TCP,UDP    |                        DHCPv6 客户端                         |
|    547/TCP,UDP    |                        DHCPv6 服务器                         |
|      548/TCP      |                 AFP (Apple Filing Protocol)                  |
|      550/UDP      |                      new-rwho, new-who                       |
|    554/TCP,UDP    |             RTSP (Real Time Streaming Protocol)              |
|      556/TCP      |                  Remotefs, rfs, rfs_server                   |
|      560/UDP      |                   rmonitor, Remote Monitor                   |
|      561/UDP      |                           monitor                            |
|    563/TCP,UDP    |              NNTP protocol over TLS/SSL (NNTPS)              |
|      587/TCP      |          email message submission（SMTP，RFC 2476）          |
|      591/TCP      | FileMaker 6.0（及之后版本）网络共享（HTTP 的替代，见 80 端口） |
|    593/TCP,UDP    | HTTP RPC Ep Map（RPC over HTTP, often used by DCOM services and Microsoft Exchange Server） |
|      604/TCP      |                            TUNNEL                            |
|    631/TCP,UDP    |                        互联网列印协定                        |
|    636/TCP,UDP    |          LDAP over SSL（加密传输，也被称为 LDAPS）           |
|    639/TCP,UDP    |          MSDP, Multicast Source Discovery Protocol           |
|      646/TCP      |               LDP, Label Distribution Protocol               |
|      647/TCP      |                    DHCP Failover Protocol                    |
|      648/TCP      |               RRP, Registry Registrar Protocol               |
|      652/TCP      |         DTCP, Dynamic Tunnel Configuration Protocol          |
|      654/UDP      |            AODV, Ad hoc On-Demand Distance Vector            |
|      665/TCP      |            sun-dr, Remote Dynamic Reconfiguration            |
|      666/UDP      |        毁灭战士，电脑平台上的一系列第一人称射击游戏。        |
|      674/TCP      |       ACAP, Application Configuration Access Protocol        |
|      691/TCP      |                     MS Exchange Routing                      |
|      692/TCP      |                        Hyperwave-ISP                         |
|      694/UDP      |          Linux-HA High availability Heartbeat port           |
|      695/TCP      |                         IEEE-MMS-SSL                         |
|      698/UDP      |              OLSR, Optimized Link State Routing              |
|      699/TCP      |                        Access Network                        |
|      700/TCP      |            EPP, Extensible Provisioning Protocol             |
|      701/TCP      |                LMP, Link Management Protocol.                |
|      702/TCP      |                        IRIS over BEEP                        |
|      706/TCP      |           SILC, Secure Internet Live Conferencing            |
|      711/TCP      |                TDP, Tag Distribution Protocol                |
|      712/TCP      |  TBRPF, Topology Broadcast based on Reverse-Path Forwarding  |
|      720/TCP      |             SMQP, Simple Message Queue Protocol              |
|   749/TCP, UDP    |            kerberos-adm, Kerberos administration             |
|      750/UDP      |                     Kerberos version IV                      |
|      782/TCP      |          Conserver serial-console management server          |
|      829/TCP      |            CMP (Certificate Management Protocol)             |
|      860/TCP      |                            iSCSI                             |
|      873/TCP      |             rsync File synchronisation protocol              |
|      901/TCP      |             Samba Web Administration Tool (SWAT)             |
|        902        |                    VMware 服务器控制台[2]                    |
|        904        |          VMware 服务器替代（如果 902 端口已被占用）          |
|      911/TCP      | Network Console on Acid（NCA） - local tty redirection over OpenSSH |
|      981/TCP      | SofaWare Technologies Remote HTTPS management for firewall devices running embedded Checkpoint Firewall-1 software |
|    989/TCP,UDP    |               FTP Protocol (data) over TLS/SSL               |
|    990/TCP,UDP    |             FTP Protocol (control) over TLS/SSL              |
|    991/TCP,UDP    |                  NAS (Netnews Admin System)                  |
|    992/TCP,UDP    |                 Telnet protocol over TLS/SSL                 |
|      993/TCP      |           IMAP4 over SSL (encrypted transmission)            |
|      995/TCP      |            POP3 over SSL (encrypted transmission)            |
|     1025/tcp      |                          NFS-or-IIS                          |
|     1026/tcp      |          Often utilized by Microsoft DCOM services           |
|     1029/tcp      |          Often utilized by Microsoft DCOM services           |
|     1058/tcp      |             nim AIX Network Installation Manager             |
|     1059/tcp      |                            nimreg                            |
|     1080/tcp      |                         SOCKS proxy                          |
|     1099/tcp      |                         RMI Registry                         |
|     1099/udp      |                         RMI Registry                         |
|     1109/tcp      |                         Kerberos POP                         |
|     1140/tcp      |                           AutoNOC                            |
|     1167/udp      |                  phone, conference calling                   |
|     1176/tcp      |       Perceptive Automation Indigo home control server       |
|   1182/tcp,udp    |                          AcceleNet                           |
|     1194/udp      |                           OpenVPN                            |
|   1198/tcp,udp    | The cajo project Free dynamic transparent distributed computing in Java |
|     1200/udp      |                     Steam Friends Applet                     |
|     1214/tcp      |                            Kazaa                             |
|   1223/tcp,udp    |      TGP: “TrulyGlobal Protocol” aka “The Gur Protocol”      |
|   1241/tcp,udp    |                   Nessus Security Scanner                    |
|     1248/tcp      |             NSClient/NSClient++/NC_Net (Nagios)              |
|   1270/tcp,udp    |      Microsoft Operations Manager 2005 agent (MOM 2005)      |
|     1311/tcp      |                 Dell Open Manage Https Port                  |
|     1313/tcp      |                  Xbiim (Canvii server) Port                  |
|     1337/tcp      |             WASTE Encrypted File Sharing Program             |
|     1352/tcp      |                  IBM Lotus Notes/Domino RPC                  |
|     1387/tcp      |      Computer Aided Design Software Inc LM (cadsi-lm )       |
|     1387/udp      |      Computer Aided Design Software Inc LM (cadsi-lm )       |
|     1414/tcp      |                         IBM MQSeries                         |
|     1431/tcp      |                             RGTP                             |
|   1433/tcp,udp    |                Microsoft SQL database system                 |
|   1434/tcp,udp    |                    Microsoft SQL Monitor                     |
|     1494/tcp      |            Citrix Presentation Server ICA Client             |
|   1512/tcp,udp    |                             WINS                             |
|     1521/tcp      |                    nCube License Manager                     |
|     1521/tcp      | Oracle database default listener, in future releases official port 2483 |
|   1524/tcp,udp    |                      ingreslock, ingres                      |
|     1526/tcp      |       Oracle database common alternative for listener        |
|     1533/tcp      |            IBM Sametime IM - Virtual Places Chat             |
|     1547/tcp      |                           Laplink                            |
|     1547/udp      |                           Laplink                            |
|       1550        |             Gadu-Gadu (Direct Client-to-Client)              |
|     1581/udp      |                    MIL STD 2045-47001 VMF                    |
|     1589/udp      |            Cisco VQP (VLAN Query Protocol) / VMPS            |
|       1627        |                           iSketch                            |
|     1677/tcp      |    Novell GroupWise clients in client/server access mode     |
|     1701/udp      |              l2tp, Layer 2 Tunnelling protocol               |
|     1716/tcp      |           America’s Army MMORPG Default Game Port            |
|     1723/tcp      |                      Microsoft PPTP VPN                      |
|     1723/udp      |                      Microsoft PPTP VPN                      |
|     1725/udp      |                      Valve Steam Client                      |
|     1755/tcp      |         Microsoft Media Services (MMS, ms-streaming)         |
|     1755/udp      |         Microsoft Media Services (MMS, ms-streaming)         |
|   1761/tcp,udp    |                            cft-0                             |
|     1761/tcp      |            Novell Zenworks Remote Control utility            |
| 1762-1768/tcp,udp |                        cft-1 to cft-7                        |
|     1812/udp      |            radius, RADIUS authentication protocol            |
|     1813/udp      |             radacct, RADIUS accounting protocol              |
|     1863/tcp      |                 Windows Live Messenger, MSN                  |
|     1900/udp      |       Microsoft SSDP Enables discovery of UPnP devices       |
|     1935/tcp      |       Real Time Messaging Protocol (RTMP) raw protocol       |
|   1970/tcp,udp    |              Danware Data NetOp Remote Control               |
|   1971/tcp,udp    |                  Danware Data NetOp School                   |
|   1972/tcp,udp    |                      InterSystems Caché                      |
|    1975-77/udp    |                  Cisco TCO (Documentation)                   |
|     1984/tcp      |            Big Brother - network monitoring tool             |
|     1985/udp      |                          Cisco HSRP                          |
|     1994/TCP      |               STUN-SDLC protocol for tunneling               |
|     1998/tcp      |                   Cisco X.25 service (XOT)                   |
|     2000/udp      |                     Cisco SCCP (Skinny)                      |
|     2000/tcp      |                     Cisco SCCP (Skinny)                      |
|     2002/tcp      |     Cisco Secure Access Control Server (ACS) for Windows     |
|       2030        |       Oracle Services for Microsoft Transaction Server       |
|     2031/tcp      |          mobrien-chat - Mike O’Brien November 2004           |
|     2031/udp      |          mobrien-chat - Mike O’Brien November 2004           |
|     2049/udp      |                       nfs, NFS Server                        |
|     2049/udp      |                            shilp                             |
|     2053/tcp      |                knetd, Kerberos de-multiplexor                |
|     2056/udp      |                  Civilization 4 multiplayer                  |
|     2073/tcp      |                      DataReel Database                       |
|     2073/udp      |                      DataReel Database                       |
|     2074/tcp      |            Vertel VMF SA (i.e. App.. SpeakFreely)            |
|     2074/udp      |            Vertel VMF SA (i.e. App.. SpeakFreely)            |
|     2082/tcp      |                   Infowave Mobility Server                   |
|     2082/tcp      |                     CPanel, default port                     |
|     2083/tcp      |                Secure Radius Service (radsec)                |
|     2083/tcp      |                   CPanel default SSL port                    |
|     2086/tcp      |                            GNUnet                            |
|     2086/tcp      |                 WebHost Manager default port                 |
|     2087/tcp      |               WebHost Manager default SSL port               |
|     2095/tcp      |                 CPanel default webmail port                  |
|     2096/tcp      |               CPanel default SSL webmail port                |
|     2161/tcp      |                         ?-APC Agent                          |
|     2181/tcp      |              EForward-document transport system              |
|     2181/udp      |              EForward-document transport system              |
|     2200/tcp      |                     Tuxanci game server                      |
|     2219/tcp      |                     NetIQ NCAP Protocol                      |
|     2219/udp      |                     NetIQ NCAP Protocol                      |
|     2220/tcp      |                        NetIQ End2End                         |
|     2220/udp      |                        NetIQ End2End                         |
|     2222/tcp      |                  DirectAdmin’s default port                  |
|     2222/udp      |     Microsoft Office OS X antipiracy network monitor [1]     |
|     2301/tcp      |          HP System Management Redirect to port 2381          |
|     2302/udp      |             ArmA multiplayer (default for game)              |
|     2302/udp      |               Halo: Combat Evolved multiplayer               |
|     2303/udp      | ArmA multiplayer (default for server reporting) (default port for game +1) |
|     2305/udp      | ArmA multiplayer (default for VoN) (default port for game +3) |
|     2369/tcp      | Default port for BMC Software CONTROL-M/Server - Configuration Agent port number - though often changed during installation |
|     2370/tcp      | Default port for BMC Software CONTROL-M/Server - Port utilized to allow the CONTROL-M/Enterprise Manager to connect to the CONTROL-M/Server - though often changed during installation |
|     2381/tcp      |        HP Insight Manager default port for webserver         |
|     2404/tcp      |                       IEC 60870-5-104                        |
|     2427/udp      |                          Cisco MGCP                          |
|     2447/tcp      |      ovwdb - OpenView Network Node Manager (NNM) daemon      |
|     2447/udp      |      ovwdb - OpenView Network Node Manager (NNM) daemon      |
|   2483/tcp,udp    | Oracle database listening port for unsecure client connections to the listener, replaces port 1521 |
|   2484/tcp,udp    | Oracle database listening port for SSL client connections to the listener |
|   2546/tcp,udp    |            Vytal Vault - Data Protection Services            |
|   2593/tcp,udp    |                 RunUO - Ultima Online server                 |
|     2598/tcp      | new ICA - when Session Reliability is enabled, TCP port 2598 replaces port 1494 |
|   2612/tcp,udp    |                    QPasa from MQSoftware                     |
|     2710/tcp      |                    XBT Bittorrent Tracker                    |
|     2710/udp      |  XBT Bittorrent Tracker experimental UDP tracker extension   |
|     2710/tcp      |                         Knuddels.de                          |
|     2735/tcp      |                    NetIQ Monitor Console                     |
|     2735/udp      |                    NetIQ Monitor Console                     |
|     2809/tcp      |    corbaloc:iiop URL, per the CORBA 3.0.3 specification.     |
|                   |                                                              |
|                   |   Also used by IBM WebSphere Application Server Node Agent   |
|     2809/udp      |    corbaloc:iiop URL, per the CORBA 3.0.3 specification.     |
|     2944/udp      |                      Megaco Text H.248                       |
|     2945/udp      |                 Megaco Binary (ASN.1) H.248                  |
|     2948/tcp      |         WAP-push Multimedia Messaging Service (MMS)          |
|     2948/udp      |         WAP-push Multimedia Messaging Service (MMS)          |
|     2949/tcp      |      WAP-pushsecure Multimedia Messaging Service (MMS)       |
|     2949/udp      |      WAP-pushsecure Multimedia Messaging Service (MMS)       |
|     2967/tcp      |             Symantec AntiVirus Corporate Edition             |
|     3000/tcp      |                    Miralix License server                    |
|     3000/udp      | Distributed Interactive Simulation (DIS), modifiable default port |
|     3001/tcp      |                    Miralix Phone Monitor                     |
|     3002/tcp      |                         Miralix CSTA                         |
|     3003/tcp      |                     Miralix GreenBox API                     |
|     3004/tcp      |                       Miralix InfoLink                       |
|     3006/tcp      |                 Miralix SMS Client Connector                 |
|     3007/tcp      |                      Miralix OM Server                       |
|     3025/tcp      |                          netpd.org                           |
|   3050/tcp,udp    |                 gds_db (Interbase/Firebird)                  |
|   3074/tcp,udp    |                          Xbox Live                           |
|     3128/tcp      | HTTP used by web caches and the default port for the Squid cache |
|     3260/tcp      |                         iSCSI target                         |
|     3268/tcp      | msft-gc, Microsoft Global Catalog (LDAP service which contains data from Active Directory forests) |
|     3269/tcp      | msft-gc-ssl, Microsoft Global Catalog over SSL (similar to port 3268, LDAP over SSL version) |
|     3300/tcp      |                     TripleA game server                      |
|   3305/tcp,udp    |                          ODETTE-FTP                          |
|   3306/tcp,udp    |                    MySQL Database system                     |
|     3333/tcp      |                   Network Caller ID server                   |
|   3386/tcp,udp    |           GTP’ 3GPP GSM/UMTS CDR logging protocol            |
|     3389/tcp      |                     远端桌面协定（RDP）                      |
|     3396/tcp      |                  Novell NDPS Printer Agent                   |
|     3689/tcp      |  DAAP Digital Audio Access Protocol used by Apple’s iTunes   |
|     3690/tcp      |              Subversion version control system               |
|   3702/tcp,udp    | Web Services Dynamic Discovery (WS-Discovery), used by various components of Windows Vista |
|     3724/tcp      |            World of Warcraft Online gaming MMORPG            |
|   3784/tcp,udp    |            Ventrilo VoIP program used by Ventrilo            |
|     3785/udp      |            Ventrilo VoIP program used by Ventrilo            |
|   3868 tcp,udp    |                    Diameter base protocol                    |
|     3872/tcp      |                Oracle Management Remote Agent                |
|     3899/tcp      |                     Remote Administrator                     |
|     3900/tcp      |                    Unidata UDT OS udt_os                     |
|     3945/tcp      | Emcads server service port, a Giritech product used by G/On  |
|     4000/tcp      |        Diablo II game NoMachine Network Server (nxd)         |
|     4007/tcp      |         PrintBuzzer printer monitoring socket server         |
|     4089/udp      |               OpenCORE Remote Control Service                |
|     4089/tcp      |               OpenCORE Remote Control Service                |
|     4093/udp      |           PxPlus Client server interface ProvideX            |
|     4093/tcp      |           PxPlus Client server interface ProvideX            |
|     4096/udp      |                  Bridge-Relay Element ASCOM                  |
|       4100        |       WatchGuard Authentication Applet - default port        |
|   4111/tcp,udp    |                            Xgrid                             |
|     4111/tcp      |   Microsoft Office SharePoint Portal Server - 默认管理端口   |
|   4226/tcp,udp    |                  Aleph One (computer game)                   |
|     4224/tcp      |              Cisco CDP Cisco discovery Protocol              |
|     4569/udp      |                   Inter-Asterisk eXchange                    |
|     4662/tcp      |                   OrbitNet Message Service                   |
|     4662/tcp      |                        通常用于 eMule                        |
|     4664/tcp      |                       Google 桌面搜索                        |
|     4672/udp      |                       eMule - 常用端口                       |
|     4894/tcp      |                      LysKOM Protocol A                       |
|     4899/tcp      |                     Radmin 远程控制工具                      |
|     5000/tcp      |                        commplex-main                         |
|     5000/tcp      |        UPnP - Windows network device interoperability        |
|   5000/tcp,udp    |                       VTun - VPN 软件                        |
|   5001/tcp,udp    | Iperf (Tool for measuring TCP and UDP bandwidth performance) |
|     5001/tcp      |                   Slingbox 及 Slingplayer                    |
|     5003/tcp      |                   FileMaker Filemaker Pro                    |
|     5004/udp      |               RTP Real-time Transport Protocol               |
|     5005/udp      |               RTP Real-time Transport Protocol               |
|   5031/tcp,udp    |       AVM CAPI-over-TCP (ISDN over Ethernet tunneling)       |
|     5050/tcp      |                       Yahoo! Messenger                       |
|     5051/tcp      |              ita-agent Symantec Intruder Alert               |
|     5060/tcp      |              Session Initiation Protocol (SIP)               |
|     5060/udp      |              Session Initiation Protocol (SIP)               |
|     5061/tcp      | Session Initiation Protocol (SIP) over Transport Layer Security (TLS) |
|     5093/udp      |              SPSS License Administrator (SPSS)               |
|     5104/tcp      |              IBM NetCOOL / IMPACT HTTP Service               |
|     5106/tcp      |                   A-Talk Common connection                   |
|     5107/tcp      |                    A-Talk 远程服务器连接                     |
|     5110/tcp      |                        ProRat Server                         |
|     5121/tcp      |                      Neverwinter Nights                      |
|     5176/tcp      |              ConsoleWorks default UI interface               |
|     5190/tcp      |                ICQ and AOL Instant Messenger                 |
|     5222/tcp      |               XMPP/Jabber - client connection                |
|     5223/tcp      |     XMPP/Jabber - default port for SSL Client Connection     |
|     5269/tcp      |               XMPP/Jabber - server connection                |
|   5351/tcp,udp    | NAT Port Mapping Protocol - client-requested configuration for inbound connections through network address translators |
|     5353/udp      |                     mDNS - multicastDNS                      |
|   5402/tcp,udp    |                   StarBurst AutoCast MFTP                    |
|   5405/tcp,udp    |                          NetSupport                          |
|   5421/tcp,udp    |                        Net Support 2                         |
|     5432/tcp      |                  PostgreSQL database system                  |
|     5445/udp      |                   Cisco Vidéo VT Advantage                   |
|     5495/tcp      |                   Applix TM1 Admin server                    |
|     5498/tcp      |              Hotline tracker server connection               |
|     5499/udp      |               Hotline tracker server discovery               |
|     5500/tcp      | VNC remote desktop protocol - for incoming listening viewer, Hotline control connection |
|     5501/tcp      |               Hotline file transfer connection               |
|     5517/tcp      |     Setiqueue Proxy server client for SETI@Home project      |
|     5555/tcp      | Freeciv multiplay port for versions up to 2.0, Hewlett Packard Data Protector, SAP |
|     5556/tcp      |                    Freeciv multiplay port                    |
|     5631/tcp      |                     赛门铁克 pcAnywhere                      |
|     5632/udp      |                     赛门铁克 pcAnywhere                      |
|     5666/tcp      |                        NRPE (Nagios)                         |
|     5667/tcp      |                        NSCA (Nagios)                         |
|     5800/tcp      |       VNC remote desktop protocol - for use over HTTP        |
|   5814/tcp,udp    | Hewlett-Packard Support Automation (HP OpenView Self-Healing Services) |
|     5900/tcp      |          VNC remote desktop protocol (used by ARD)           |
|     6000/tcp      |  X11 - used between an X client and server over the network  |
|     6001/udp      |  X11 - used between an X client and server over the network  |
|     6005/tcp      | Default port for BMC Software CONTROL-M/Server - Socket Port number used for communication between CONTROL-M processes - though often changed during installation |
|     6050/tcp      |                  Brightstor Arcserve Backup                  |
|     6051/tcp      |                  Brightstor Arcserve Backup                  |
|     6100/tcp      |                         Vizrt System                         |
|     6110/tcp      |                    softcm HP SoftBench CM                    |
|     6110/udp      |                    softcm HP SoftBench CM                    |
|     6111/tcp      |             spc HP SoftBench Sub-Process Control             |
|     6111/udp      |             spc HP SoftBench Sub-Process Control             |
|     6112/tcp      | “dtspcd” - a network daemon that accepts requests from clients to execute commands and launch applications remotely |
|     6112/tcp      | Blizzard’s Battle.net gaming service, ArenaNet gaming service |
|     6129/tcp      |                   Dameware Remote Control                    |
|     6257/udp      |                   WinMX （参见 6699 端口）                   |
|   6346/tcp,udp    |     gnutella-svc (FrostWire, Limewire, Bearshare, etc.)      |
|   6347/tcp,udp    |                         gnutella-rtr                         |
|   6444/tcp,udp    |              Sun Grid Engine - Qmaster Service               |
|   6445/tcp,udp    |             Sun Grid Engine - Execution Service              |
|   6502/tcp,udp    |              Danware Data NetOp Remote Control               |
|     6522/tcp      |           Gobby (and other libobby-based software)           |
|     6543/udp      | Jetnet - default port that the Paradigm Research & Development Jetnet protocol communicates on |
|     6566/tcp      | SANE (Scanner Access Now Easy) - SANE network scanner daemon |
|     6600/tcp      |                  Music Playing Daemon (MPD)                  |
|   6619/tcp,udp    |                   ODETTE-FTP over TLS/SSL                    |
|   6665-6669/tcp   |                     Internet Relay Chat                      |
|     6679/tcp      |       IRC SSL （安全互联网中继聊天） - 通常使用的端口        |
|     6697/tcp      |       IRC SSL （安全互联网中继聊天） - 通常使用的端口        |
|     6699/tcp      |                   WinMX （参见 6257 端口）                   |
| 6881-6999/tcp,udp |                  BitTorrent 通常使用的端口                   |
| 6891-6900/tcp,udp |             Windows Live Messenger （文件传输）              |
|   6901/tcp,udp    |               Windows Live Messenger （语音）                |
|     6969/tcp      |                           acmsoda                            |
|     6969/tcp      |                   BitTorrent tracker port                    |
|     7000/tcp      | Default port for Azureus’s built in HTTPS Bittorrent Tracker |
|     7001/tcp      | Default port for BEA WebLogic Server’s HTTP server - though often changed during installation |
|     7002/tcp      | Default port for BEA WebLogic Server’s HTTPS server - though often changed during installation |
|   7005/tcp,udp    | Default port for BMC Software CONTROL-M/Server and CONTROL-M/Agent’s - Agent to Server port though often changed during installation |
|   7006/tcp,udp    | Default port for BMC Software CONTROL-M/Server and CONTROL-M/Agent’s - Server to Agent port though often changed during installation |
|     7010/tcp      | Default port for Cisco AON AMC (AON Management Console) [2]  |
|     7025/tcp      |        Zimbra - lmtp [mailbox] - local mail delivery         |
|     7047/tcp      |                  Zimbra - conversion server                  |
|     7171/tcp      |                            Tibia                             |
|     7306/tcp      |                   Zimbra - mysql [mailbox]                   |
|     7307/tcp      |               Zimbra - mysql [logger] - logger               |
|     7312/udp      |                 Sibelius License Server port                 |
|     7670/tcp      |             BrettspielWelt BSW Boardgame Portal              |
|     7777/tcp      |    Default port used by Windows backdoor program tini.exe    |
|     8000/tcp      | iRDMI - often mistakenly used instead of port 8080 (The Internet Assigned Numbers Authority (iana.org) officially lists this port for iRDMI protocol) |
|     8000/tcp      | Common port used for internet radio streams such as those using SHOUTcast |
|     8002/tcp      |     Cisco Systems Unified Call Manager Intercluster Port     |
|     8008/tcp      |                        HTTP 替代端口                         |
|     8008/tcp      |                 IBM HTTP Server 默认管理端口                 |
|     8009/tcp      | Apache JServ 协议 v13 (ajp13) 例如：Apache mod_jk Tomcat 会使用。 |
|     8010/tcp      |                     XMPP/Jabber 文件传输                     |
|     8074/tcp      |                          Gadu-Gadu                           |
|     8080/tcp      | HTTP 替代端口 （http_alt） - commonly used for web proxy and caching server, or for running a web server as a non-root user |
|     8080/tcp      |                        Apache Tomcat                         |
|     8086/tcp      |        HELM Web Host Automation Windows Control Panel        |
|     8086/tcp      |             Kaspersky AV Control Center TCP Port             |
|     8087/tcp      |              Hosting Accelerator Control Panel               |
|     8087/udp      |             Kaspersky AV Control Center UDP Port             |
|     8090/tcp      | Another HTTP Alternate (http_alt_alt) - used as an alternative to port 8080 |
|     8118/tcp      |    Privoxy web proxy - advertisements-filtering web proxy    |
|     8087/tcp      |                    SW Soft Plesk 控制面板                    |
|     8200/tcp      |                           GoToMyPC                           |
|     8220/tcp      |                          Bloomberg                           |
|       8222        | VMware Server Management User Interface (insecure web interface)[3]. See also, port 8333 |
|     8291/tcp      | Winbox - Default port on a MikroTik RouterOS for a Windows application used to administer MikroTik RouterOS |
|     8294/tcp      |                          Bloomberg                           |
|       8333        | VMware 服务器管理用户界面（安全网络界面）[4]. See also, port 8222 |
|       8400        |              Commvault Unified Data Management               |
|     8443/tcp      |                 SW Soft Plesk Control Panel                  |
|     8500/tcp      | ColdFusion Macromedia/Adobe ColdFusion default Webserver port |
|     8501/udp      |             Duke Nukem 3D - Default Online Port              |
|     8767/udp      |                 TeamSpeak - Default UDP Port                 |
|       8880        |       WebSphere Application Server SOAP Connector port       |
|     8881/tcp      |  Atlasz Informatics Research Ltd Secure Application Server   |
|     8882/tcp      |  Atlasz Informatics Research Ltd Secure Application Server   |
|   8888/tcp,udp    |                       NewsEDGE server                        |
|     8888/tcp      | Sun Answerbook dwhttpd server (deprecated by [docs.sun.com](http://docs.sun.com/)) |
|     8888/tcp      |     GNUmp3d HTTP music streaming and web interface port      |
|     8888/tcp      |               Hero Fighter Network Game Server               |
|     9000/tcp      |                Buffalo LinkSystem web access                 |
|     9000/tcp      |                             DBGp                             |
|     9000/udp      |                           UDPCast                            |
|       9001        |              cisco-xremote router configuration              |
|       9001        |                   Tor network default port                   |
|     9001/tcp      |                          DBGp Proxy                          |
|   9009/tcp,udp    |          Pichat Server - Peer to peer chat software          |
|     9043/tcp      | WebSphere Application Server Administration Console secure port |
|     9060/tcp      |     WebSphere Application Server Administration Console      |
|     9100/tcp      |                 Jetdirect HP Print Services                  |
|     9110/udp      |                    SSMP Message protocol                     |
|       9101        |                       Bacula Director                        |
|       9102        |                      Bacula File Daemon                      |
|       9103        |                    Bacula Storage Daemon                     |
|   9119/TCP,UDP    |                    MXit Instant Messenger                    |
|     9535/tcp      |                    man, Remote Man Server                    |
|       9535        |          mngsuite - Management Suite Remote Control          |
|   9800/tcp,udp    |                      WebDAV Source Port                      |
|       9800        |                   WebCT e-learning portal                    |
|       9999        |         Hydranode - edonkey2000 telnet control port          |
|       9999        |                     Urchin Web Analytics                     |
|       10000       |             Webmin - web based Linux admin tool              |
|       10000       |                          BackupExec                          |
|       10008       | Octopus Multiplexer - CROMP protocol primary port, hoople.org |
|       10017       |          AIX,NeXT, HPUX - rexd daemon control port           |
|     10024/tcp     |         Zimbra - smtp [mta] - to amavis from postfix         |
|     10025/tcp     |      Ximbra - smtp [mta] - back to postfix from amavis       |
|     10050/tcp     |                         Zabbix-Agent                         |
|     10051/tcp     |                        Zabbix-Server                         |
|     10113/tcp     |                        NetIQ Endpoint                        |
|     10113/udp     |                        NetIQ Endpoint                        |
|     10114/tcp     |                         NetIQ Qcheck                         |
|     10114/udp     |                         NetIQ Qcheck                         |
|     10115/tcp     |                        NetIQ Endpoint                        |
|     10115/udp     |                        NetIQ Endpoint                        |
|     10116/tcp     |                     NetIQ VoIP Assessor                      |
|     10116/udp     |                     NetIQ VoIP Assessor                      |
|       10480       |                   SWAT 4 Dedicated Server                    |
|       11211       |                          memcached                           |
|       11235       |           Savage:Battle for Newerth Server Hosting           |
|       11294       |                  Blood Quest Online Server                   |
|       11371       |                    OpenPGP HTTP Keyserver                    |
|       11576       |            IPStor Server management communication            |
|     12035/udp     |                   Linden Lab viewer to sim                   |
|       12345       | NetBus - remote administration tool (often Trojan horse). Also used by NetBuster. Little Fighter 2 (TCP). |
|     12975/tcp     |    LogMeIn Hamachi (VPN tunnel software;also port 32976)     |
|  13000-13050/udp  |                   Linden Lab viewer to sim                   |
|     13720/tcp     |         Symantec NetBackup - bprd (formerly VERITAS)         |
|     13721/tcp     |        Symantec NetBackup - bpdbm (formerly VERITAS)         |
|     13724/tcp     |      Symantec Network Utility - vnet (formerly VERITAS)      |
|     13782/tcp     |         Symantec NetBackup - bpcd (formerly VERITAS)         |
|     13783/tcp     |         Symantec VOPIED protocol (formerly VERITAS)          |
|     14567/udp     |                  Battlefield 1942 and mods                   |
|     15000/tcp     |                            psyBNC                            |
|     15000/tcp     |                           Wesnoth                            |
|     15567/udp     |                 Battlefield Vietnam and mods                 |
|     15345/udp     |                            XPilot                            |
|     16000/tcp     |                          shroudBNC                           |
|     16080/tcp     |        Mac OS X Server performance cache for HTTP[5]         |
|     16384/udp     |            Iron Mountain Digital - online backup             |
|     16567/udp     |                    Battlefield 2 and mods                    |
|     17788/udp     |                         PPS 网路电视                         |
|     19226/tcp     |        Panda Software AdminSecure Communication Agent        |
|     19638/tcp     |                     Ensim Control Panel                      |
|     19813/tcp     |           4D database Client Server Communication            |
|       20000       |                 Usermin - 基于网络的用户工具                 |
|     20720/tcp     |                  Symantec i3 Web GUI server                  |
|   22347/tcp,udp   | WibuKey - default port for WibuKey Network Server of WIBU-SYSTEMS AG |
|   22350/tcp,udp   | CodeMeter - default port for CodeMeter Server of WIBU-SYSTEMS AG |
|   24554/tcp,udp   |          binkp - Fidonet mail transfers over TCP/IP          |
|       24800       |           Synergy：keyboard/mouse sharing software           |
|       24842       |     StepMania：Online: Dance Dance Revolution Simulator      |
|     25999/tcp     |                            Xfire                             |
|   26000/tcp,udp   |                 id Software’s Quake server,                  |
|     26000/tcp     |            CCP’s EVE Online Online gaming MMORPG,            |
|     27000/udp     |    (through 27006) id Software’s QuakeWorld master server    |
|     27010/udp     |           Half-Life 及其修改版，如 Counter-Strike            |
|     27015/udp     |           Half-Life 及其修改版，如 Counter-Strike            |
|       27374       | Sub7’s default port. Most script kiddies do not change the default port. |
|     27500/udp     |           (through 27900) id Software’s QuakeWorld           |
|     27888/udp     |                       Kaillera server                        |
|       27900       |          (through 27901) Nintendo Wi-Fi Connection           |
|     27901/udp     |     (through 27910) id Software’s Quake II master server     |
|     27960/udp     | (through 27969) Activision’s Enemy Territory and id Software’s Quake III Arena and Quake III and some ioquake3 derived games |
|       28910       |                      任天堂 Wi-Fi 连接                       |
|       28960       |   Call of Duty 2 Common Call of Duty 2 port - (PC Version)   |
|       29900       |          (through 29901) Nintendo Wi-Fi Connection           |
|       29920       |                      任天堂 Wi-Fi 连接                       |
|       30000       |                      Pokemon Netbattle                       |
|     30564/tcp     |   Multiplicity：keyboard/mouse/clipboard sharing software    |
|     31337/tcp     | Back Orifice - remote administration tool（often Trojan horse） |
|     31337/tcp     |             xc0r3 - xc0r3 security antivir port              |
|       31415       | ThoughtSignal - Server Communication Service（often Informational） |
|  31456-31458/tcp  |     TetriNET ports (in order: IRC, game, and spectating)     |
|     32245/tcp     |       MMTSG-mutualed over MMT (encrypted transmission)       |
|       33434       |                          traceroute                          |
|     37777/tcp     |               Digital Video Recorder hardware                |
|       36963       | Counter Strike 2D multiplayer port (2D clone of popular CounterStrike computer game) |
|       40000       |                         SafetyNET p                          |
|       40523       |                         data packets                         |
|  43594-43595/tcp  |                          RuneScape                           |
|       47808       |       BACnet Building Automation and Control Networks        |