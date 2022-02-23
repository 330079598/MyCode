[toc]

---

### 新建分支

- 可以使用`branch`命令来创建分支:

```shell
$ git branch <branchname>
# 例如新建一个issue的分支
$ git branch issue

#如果不指定参数执行branch,可以显示分支列表,带*的就是当前所在的分支
$ git branch
  issue
* master
```

### 切换分支

- 使用`checkout`命令来切换分支

```shell
$ git checkout issue
Switched to branch 'issue1'

$ git branch
* issue
  master
```

### 合并分支

可以使用`merge`命令来合并分支,如果要将`issue`合并到`master`分支上,操作如下:

- 先切换到`master`分支上:

```shell
$ git checkout master
Switched to branch 'master'
```

- 合并分支:

```shell
$ git merge issue
```

- 可以通过使用以下命令在命令外壳中实时可视化你的分支历史记录来本地验证。

```shell
$ git fetch
$ git log --all --decorate --oneline --graph
```



### 解决冲突

合并两个分支之后,可能会有冲突,我们需要手动来修改这些冲突:

- 查看带有冲突标记的文件:

```shell
$ git diff --check
```

- 然后我们找到这些冲突的文件,进行修改
- 合并冲突表示法:

> 当git合并产生合并冲突时，该部分会以`<<<<<<<`, `=======`和 `>>>>>>>`表示。
>
> 在`=======`之前的部分是当前分支这边的情况，
>
> 在`=======`之后的部分是对方分支的情况。

### 删除分支

如果当前分支没有用了的话,我们可以删除无用的分支:

- 使用`branch`命令指定`-d`选项,删除分支

```shell
$ git branch -d <branchname>

$ git branch -d issue

$ git branch
* master
```

### 扩展

- `rebase`和`merge`区别
  - `merge`:自动创建一个新的commit,如果合并后遇到冲突,仅需要重新commit.
    - 优点:记录了真是的commit情况,包括每个分支的详情
    - 缺点:因为每次merge会自动产生一个merge commit,看到的logs比较混乱.
  - `rebase`:会合并之前的commit历史.
    - 优点:得到更简洁的项目历史,去掉了merge commit.
    - 缺点:如果合并出现代码问题不容易定位,因为`re-write`了`history`.