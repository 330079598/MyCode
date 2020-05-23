- `oh-my-zsh`可以装很多插件，先介绍几个，到时候可以写一个安装脚本，但是目前可能断时间写不了，只能先记录一下！

- `zsh-syntax-highlighting`

  - [zsh-syntax-highlighting](https://github.com/zsh-users/zsh-syntax-highlighting)：命令输入正确会绿色高亮显示，输入错误会显示其他的颜色。
  - 安装：

  ```shell
  git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
  ```

- `zsh-autosuggestions`

  - [zsh-autosuggestions](https://github.com/zsh-users/zsh-autosuggestions):如图输入命令时，会给出建议的命令（灰色部分）按键盘 → 补全.
  - 安装：

  ```shell
  git clone git://github.com/zsh-users/zsh-autosuggestions $ZSH_CUSTOM/plugins/zsh-autosuggestions
  ```

  - 可以配置其它的快捷键，在zshrc中添加配置即可：``bindkey ',' autosuggest-accept`。
  
- `git-open`

  - [git-open](https://github.com/paulirish/git-open)
  - 安装：

  ```shell
  git clone https://github.com/paulirish/git-open.git $ZSH_CUSTOM/plugins/git-open
  ```

- 配置插件：

  ````shell
在～/。zshrc中添加如下的插件名称：
  plugins=(
git 
  git-open
autosuggest-accept
  zsh-syntax-highlighting
  )
  
  可以增加配置如下配置：
  HIST_STAMPS="yyyy-mm-dd" #history命令查看历史输入命令的时间展示格式
  #设置别名
  alias go="git-open"
  alias rm="trash" #安装了一个 trash 命令，替代 rm 命令，被删除的文件会放到垃圾桶
  alias cp="cp -i" #防止copy的时候覆盖已存在的文件, 带上i选项，文件已存在的时候，会提示，需要确认才能copy
  ````
  
  [trash官网](https://github.com/sindresorhus/trash)
  
  
  
  
  
  
  
  