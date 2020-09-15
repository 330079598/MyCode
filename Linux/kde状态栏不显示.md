> 在arch的一次更新后，kde的桌面背景，插件，状态栏变成了一片黑，如下图所示。

![kde-widgets](./Image/kde-widgets.png)

- 解决办法：删除``/home/stone/.config/plasma-org.kde.plasma.desktop-appletsrc`就行了，但是kde状态栏上面的插件会没有，需要重新设置，一些设置也会消失。
- 猜测：可能是某个插件造成了冲突，如果添加插件还会造成这样的结果，就可以确定是这个插件的问题了！

