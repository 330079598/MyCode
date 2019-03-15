- 可直接生成ssh key  : `ssh-keygen -t rsa`,连按三下回车键
- id_rsa是密钥，id_rsa.pub是公钥，接下来需要将id_rsa.pub的内容添加到GitHub上，这样本地的id_rsa密钥才能跟GitHub上的id_rsa.pub公钥进行配对，才能够授权成功。

# 换电脑重新写以前的工程

1. `git config --global user.name “name”`
2. `git config --global user.email “email”`
3. 配置ssh:`ssh-keygen -t rsa -C “email”`
4. 在GitHub中添加ssh秘钥信息
5. ssh -T git@github.com 输入yes
6. git clone你以前的工程。不要用http的格式的地址
7. 然后就行了

