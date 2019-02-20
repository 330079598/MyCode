# GitHub上传所有新文件

```
git add -A      提交所有变化
git add -u      提交被修改(modified)和被删除(deleted)文件，不包括新文件(new)
git add .       提交新文件(new)和被修改(modified)文件，不包括被删除(deleted)文件    
```





- 进入本地库中

```
git status
git add -A
git commit -a -m "update"
```

- 上传本地库

```
git push
```



---



#  或许会有的错误：

-  显示    **Everything up-to-date**，这个可能原因是你没有add或者commit，查看status，然后决定接下来的操作。