# 换电脑重新写以前的工程
1. `git config --global user.name “name”`
2. `git config --global user.email “email”`
3. 配置ssh:`ssh-keygen -t rsa -C “email”`
4. 在GitHub中添加ssh秘钥信息
5. ssh -T git@github.com 输入yes
6. git clone你以前的工程。不要用http的格式的地址
7. 然后就行了