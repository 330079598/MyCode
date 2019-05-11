在Jav a Web中可以使用以下两个方法实现页面跳转:

- 方法一

```javascript
response.sendRedirect("jump.jsp");
```

- 方法二:

```javascript
request.getRequestDispatcher("jump.jsp").forward(request,response);
```

区别:

- response.sendRedirect是向客户浏览器发送页面重定向指令，浏览器接收后将向web服务器重新发送页面请求，所以执行完后浏览器的url显示的是跳转后的页面。跳转页面可以是一个任意的url（本服务器的和其他服务器的均可）。
- RequestDispatcher.forward则是直接在服务器中进行处理，将处理完后的信息发送给浏览器进行显示,所以完成后在url中显示的是跳转前的页面。在forward的时候将上一页面中传送的request和response信息一同发送给下一页面（而response.sendRedirect不能将上一页面的request和response信息发送到下一页面）。由于forward是直接在服务器中进行处理，所以forward的页面只能是本服务器的。