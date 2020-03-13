[toc]

---

# 1xx消息

这一类型的状态码，代表请求已被接受，需要继续处理。这类响应是临时响应，只包含状态行和某些可选的响应头信息，并以空行结束。由于HTTP/1.0协议中没有定义任何1xx状态码，所以除非在某些试验条件下，服务器禁止向此类客户端发送1xx响应。 这些状态码代表的响应都是信息性的，标示客户应该采取的其他行动。

- 100 Continue

  服务器已经接收到请求头，并且客户端应继续发送请求主体（在需要发送身体的请求的情况下：例如，POST请求），或者如果请求已经完成，忽略这个响应。服务器必须在请求完成后向客户端发送一个最终响应。要使服务器检查请求的头部，客户端必须在其初始请求中发送`Expect: 100-continue`作为头部，并在发送正文之前接收`100 Continue`状态代码。响应代码417期望失败表示请求不应继续。

- 101 Switching Protocols

  服务器已经理解了客户端的请求，并将通过Upgrade消息头通知客户端采用不同的协议来完成这个请求。在发送完这个响应最后的空行后，服务器将会切换到在Upgrade消息头中定义的那些协议。

  只有在切换新的协议更有好处的时候才应该采取类似措施。例如，切换到新的HTTP版本（如[HTTP/2](https://zh.wikipedia.org/wiki/HTTP/2)）比旧版本更有优势，或者切换到一个实时且同步的协议（如[WebSocket](https://zh.wikipedia.org/wiki/WebSocket)）以传送利用此类特性的资源。

- 102 Processing（[WebDAV](https://zh.wikipedia.org/wiki/WebDAV)；[RFC 2518](https://tools.ietf.org/html/rfc2518)）

  WebDAV请求可能包含许多涉及文件操作的子请求，需要很长时间才能完成请求。该代码表示服务器已经收到并正在处理请求，但无响应可用。这样可以防止客户端超时，并假设请求丢失。

# 2xx成功

这一类型的状态码，代表请求已成功被服务器接收、理解、并接受。

- 200 OK

  请求已成功，请求所希望的响应头或数据体将随此响应返回。实际的响应将取决于所使用的请求方法。在GET请求中，响应将包含与请求的资源相对应的实体。在POST请求中，响应将包含描述或操作结果的实体。

- 201 Created

  请求已经被实现，而且有一个新的资源已经依据请求的需要而建立，且其[URI](https://zh.wikipedia.org/wiki/URI)已经随Location头信息返回。假如需要的资源无法及时建立的话，应当返回'[202 Accepted](https://zh.wikipedia.org/wiki/HTTP状态码#202)'。

- 202 Accepted

  服务器已接受请求，但尚未处理。最终该请求可能会也可能不会被执行，并且可能在处理發生时被禁止。

- 203 Non-Authoritative Information（自HTTP / 1.1起）

  服务器是一个转换代理服务器（transforming proxy，例如[网络加速器](https://zh.wikipedia.org/wiki/網絡加速器)），以`200 OK`状态码为起源，但回应了原始响应的修改版本。

- 204 No Content

  服务器成功处理了请求，没有返回任何内容。在[强制门户](https://zh.wikipedia.org/wiki/强制门户)功能中，Wifi设备连接到需要进行Web认证的Wifi接入点时，通过访问一个能生成HTTP 204响应的的网站，如果能正常收到204响应，则代表无需Web认证，否则会弹出网页浏览器界面，显示出Web网页认证界面用于让用户认证登录。

- 205 Reset Content

  服务器成功处理了请求，但没有返回任何内容。与204响应不同，此响应要求请求者重置文档视图。

- 206 Partial Content（[RFC 7233](https://tools.ietf.org/html/rfc7233)）

  服务器已经成功处理了部分GET请求。类似于[FlashGet](https://zh.wikipedia.org/wiki/FlashGet)或者[迅雷](https://zh.wikipedia.org/wiki/迅雷)这类的HTTP[下载工具](https://zh.wikipedia.org/wiki/Category:下載工具)都是使用此类响应实现断点续传或者将一个大文档分解为多个下载段同时下载。

- 207 Multi-Status（WebDAV；[RFC 4918](https://tools.ietf.org/html/rfc4918)）

  代表之后的消息体将是一个[XML](https://zh.wikipedia.org/wiki/XML)消息，并且可能依照之前子请求数量的不同，包含一系列独立的响应代码。

- 208 Already Reported （WebDAV；[RFC 5842](https://tools.ietf.org/html/rfc5842)）

  DAV绑定的成员已经在（多状态）响应之前的部分被列举，且未被再次包含。

- 226 IM Used （[RFC 3229](https://tools.ietf.org/html/rfc3229)）

  服务器已经满足了对资源的请求，对实体请求的一个或多个实体操作的结果表示。

# 3xx重定向

这类状态码代表需要客户端采取进一步的操作才能完成请求。通常，这些状态码用来重定向，后续的请求地址（重定向目标）在本次响应的Location域中指明。

当且仅当后续的请求所使用的方法是GET或者HEAD时，用户[浏览器](https://zh.wikipedia.org/wiki/浏览器)才可以在没有用户介入的情况下自动提交所需要的后续请求。客户端应当自动监测[无限循环](https://zh.wikipedia.org/wiki/死循環)重定向（例如：A→B→C→……→A或A→A），因为这会导致服务器和客户端大量不必要的资源消耗。按照HTTP/1.0版规范的建议，浏览器不应自动访问超过5次的重定向。

- 300 Multiple Choices

  被请求的资源有一系列可供选择的回馈信息，每个都有自己特定的地址和浏览器驱动的商议信息。用户或浏览器能够自行选择一个首选的地址进行重定向。

  除非这是一个HEAD请求，否则该响应应当包括一个资源特性及地址的列表的实体，以便用户或浏览器从中选择最合适的重定向地址。这个实体的格式由Content-Type定义的格式所决定。浏览器可能根据响应的格式以及浏览器自身能力，自动作出最合适的选择。当然，RFC 2616规范并没有规定这样的自动选择该如何进行。

  如果服务器本身已经有了首选的回馈选择，那么在Location中应当指明这个回馈的[URI](https://zh.wikipedia.org/wiki/URI)；浏览器可能会将这个Location值作为自动重定向的地址。此外，除非额外指定，否则这个响应也是可缓存的。

- [301 Moved Permanently](https://zh.wikipedia.org/wiki/HTTP_301)

  被请求的资源已永久移动到新位置，并且将来任何对此资源的引用都应该使用本响应返回的若干个URI之一。如果可能，拥有链接编辑功能的客户端应当自动把请求的地址修改为从服务器反馈回来的地址。除非额外指定，否则这个响应也是可缓存的。

  新的永久性的URI应当在响应的Location域中返回。除非这是一个HEAD请求，否则响应的实体中应当包含指向新的URI的[超链接](https://zh.wikipedia.org/wiki/超链接)及简短说明。

  如果这不是一个GET或者HEAD请求，那么浏览器禁止自动进行重定向，除非得到用户的确认，因为请求的条件可能因此发生变化。

  注意：对于某些使用HTTP/1.0协议的浏览器，当它们发送的POST请求得到了一个301响应的话，接下来的重定向请求将会变成GET方式。

- [302 Found](https://zh.wikipedia.org/wiki/HTTP_302)

  要求客户端执行临时重定向（原始描述短语为“Moved Temporarily”）。由于这样的重定向是临时的，客户端应当继续向原有地址发送以后的请求。只有在Cache-Control或Expires中进行了指定的情况下，这个响应才是可缓存的。

  新的临时性的URI应当在响应的Location域中返回。除非这是一个HEAD请求，否则响应的实体中应当包含指向新的URI的超链接及简短说明。

  如果这不是一个GET或者HEAD请求，那么浏览器禁止自动进行重定向，除非得到用户的确认，因为请求的条件可能因此发生变化。

  注意：虽然RFC 1945和RFC 2068规范不允许客户端在重定向时改变请求的方法，但是很多现存的浏览器将302响应视作为[303响应](https://zh.wikipedia.org/wiki/HTTP状态码#303)，并且使用GET方式访问在Location中规定的URI，而无视原先请求的方法。因此状态码303和[307](https://zh.wikipedia.org/wiki/HTTP状态码#307)被添加了进来，用以明确服务器期待客户端进行何种反应。

- [303 See Other](https://zh.wikipedia.org/wiki/HTTP_303)

  对应当前请求的响应可以在另一个URI上被找到，当响应于POST（或PUT / DELETE）接收到响应时，客户端应该假定服务器已经收到数据，并且应该使用单独的GET消息发出重定向。这个方法的存在主要是为了允许由脚本激活的POST请求输出重定向到一个新的资源。这个新的URI不是原始资源的替代引用。同时，303响应禁止被缓存。当然，第二个请求（重定向）可能被缓存。

  新的URI应当在响应的Location域中返回。除非这是一个HEAD请求，否则响应的实体中应当包含指向新的URI的超链接及简短说明。

  注意：许多HTTP/1.1版以前的浏览器不能正确理解303状态。如果需要考虑与这些浏览器之间的互动，[302状态码](https://zh.wikipedia.org/wiki/HTTP状态码#302)应该可以胜任，因为大多数的浏览器处理302响应时的方式恰恰就是上述规范要求客户端处理303响应时应当做的。

- 304 Not Modified

  表示资源在由请求头中的If-Modified-Since或If-None-Match参数指定的这一版本之后，未曾被修改。在这种情况下，由于客户端仍然具有以前下载的副本，因此不需要重新传输资源。

- 305 Use Proxy

  被请求的资源必须通过指定的代理才能被访问。Location域中将给出指定的代理所在的URI信息，接收者需要重复发送一个单独的请求，通过这个代理才能访问相应资源。只有原始服务器才能建立305响应。许多HTTP客户端（像是[Mozilla](https://zh.wikipedia.org/wiki/Mozilla)和[Internet Explorer](https://zh.wikipedia.org/wiki/Internet_Explorer)）都没有正确处理这种状态代码的响应，主要是出于安全考虑。

  注意：RFC 2068中没有明确305响应是为了重定向一个单独的请求，而且只能被原始服务器建立。忽视这些限制可能导致严重的安全后果。

- 306 Switch Proxy

  在最新版的规范中，306状态码已经不再被使用。最初是指“后续请求应使用指定的代理”。状态码#cite_note-27)

- [307 Temporary Redirect](https://zh.wikipedia.org/wiki/HTTP_307)

  在这种情况下，请求应该与另一个URI重复，但后续的请求应仍使用原始的URI。 与302相反，当重新发出原始请求时，不允许更改请求方法。 例如，应该使用另一个POST请求来重复POST请求。

- 308 Permanent Redirect ([RFC 7538](https://tools.ietf.org/html/rfc7538))

  请求和所有将来的请求应该使用另一个URI重复。 307和308重复302和301的行为，但不允许HTTP方法更改。 例如，将表单提交给永久重定向的资源可能会顺利进行。

# 4xx客户端错误

这类的状态码代表了客户端看起来可能发生了错误，妨碍了服务器的处理。除非响应的是一个HEAD请求，否则服务器就应该返回一个解释当前错误状况的实体，以及这是临时的还是永久性的状况。这些状态码适用于任何请求方法。浏览器应当向用户显示任何包含在此类错误响应中的实体内容。

如果错误发生时客户端正在传送数据，那么使用[TCP](https://zh.wikipedia.org/wiki/传输控制协议)的服务器实现应当仔细确保在关闭客户端与服务器之间的连接之前，客户端已经收到了包含错误信息的[数据包](https://zh.wikipedia.org/wiki/数据包)。如果客户端在收到错误信息后继续向服务器发送数据，服务器的TCP栈将向客户端发送一个重置数据包，以清除该客户端所有还未识别的输入[缓冲](https://zh.wikipedia.org/w/index.php?title=缓冲&action=edit&redlink=1)，以免这些数据被服务器上的[应用程序](https://zh.wikipedia.org/wiki/应用程序)读取并干扰后者。

- 400 Bad Request

  由于明显的客户端错误（例如，格式错误的请求语法，太大的大小，无效的请求消息或欺骗性路由请求），服务器不能或不会处理该请求。

- 401 Unauthorized（[RFC 7235](https://tools.ietf.org/html/rfc7235)）

  参见：[HTTP基本认证](https://zh.wikipedia.org/wiki/HTTP基本认证)、[HTTP摘要认证](https://zh.wikipedia.org/wiki/HTTP摘要认证)

  类似于403 Forbidden，401语义即“[未认证](https://zh.wikipedia.org/wiki/身份验证)”，即用户没有必要的凭据。该状态码表示当前请求需要用户验证。该响应必须包含一个适用于被请求资源的WWW-Authenticate信息头用以询问用户信息。客户端可以重复提交一个包含恰当的Authorization头信息的请求。如果当前请求已经包含了Authorization证书，那么401响应代表着服务器验证已经拒绝了那些证书。如果401响应包含了与前一个响应相同的身份验证询问，且浏览器已经至少尝试了一次验证，那么浏览器应当向用户展示响应中包含的实体信息，因为这个实体信息中可能包含了相关诊断信息。

  注意：当网站（通常是网站域名）禁止IP地址时，有些网站状态码显示的401，表示该特定地址被拒绝访问网站。

- 402 Payment Required

  该状态码是为了将来可能的需求而预留的。该状态码最初的意图可能被用作某种形式的数字现金或在线支付方案的一部分，但几乎没有哪家服务商使用，而且这个状态码通常不被使用。如果特定开发人员已超过请求的每日限制，[Google Developers](https://zh.wikipedia.org/wiki/Google_Developers) API会使用此状态码。

- 403 Forbidden

主条目：[HTTP 403](https://zh.wikipedia.org/wiki/HTTP_403)



- 404 Not Found

主条目：[HTTP 404](https://zh.wikipedia.org/wiki/HTTP_404)



- 405 Method Not Allowed

  请求行中指定的请求方法不能被用于请求相应的资源。该响应必须返回一个Allow头信息用以表示出当前资源能够接受的请求方法的列表。例如，需要通过POST呈现数据的表单上的GET请求，或只读资源上的PUT请求。

  鉴于PUT，DELETE方法会对服务器上的资源进行写操作，因而绝大部分的[网页服务器](https://zh.wikipedia.org/wiki/网页服务器)都不支持或者在默认配置下不允许上述请求方法，对于此类请求均会返回405错误。

- 406 Not Acceptable

  参见：[内容协商](https://zh.wikipedia.org/wiki/内容协商)

  请求的资源的内容特性无法满足请求头中的条件，因而无法生成响应实体，该请求不可接受。

  除非这是一个HEAD请求，否则该响应就应当返回一个包含可以让用户或者浏览器从中选择最合适的实体特性以及地址列表的实体。实体的格式由Content-Type头中定义的媒体类型决定。浏览器可以根据格式及自身能力自行作出最佳选择。但是，规范中并没有定义任何作出此类自动选择的标准。

- 407 Proxy Authentication Required（[RFC 2617](https://tools.ietf.org/html/rfc2617)）

  与[401响应](https://zh.wikipedia.org/wiki/HTTP状态码#401)类似，只不过客户端必须在代理服务器上进行身份验证。代理服务器必须返回一个Proxy-Authenticate用以进行身份询问。客户端可以返回一个Proxy-Authorization信息头用以验证。

- 408 Request Timeout

  请求超时。根据HTTP规范，客户端没有在服务器预备等待的时间内完成一个请求的发送，客户端可以随时再次提交这一请求而无需进行任何更改。

- 409 Conflict

  表示因为请求存在冲突无法处理该请求，例如多个同步更新之间的[编辑冲突](https://zh.wikipedia.org/w/index.php?title=编辑冲突&action=edit&redlink=1)。

- 410 Gone

  表示所请求的资源不再可用，将不再可用。当资源被有意地删除并且资源应被清除时，应该使用这个。在收到410状态码后，用户应停止再次请求资源。但大多数服务端不会使用此状态码，而是直接使用[404状态码](https://zh.wikipedia.org/wiki/HTTP状态码#404)。

- 411 Length Required

  服务器拒绝在没有定义Content-Length头的情况下接受请求。在添加了表明请求消息体长度的有效Content-Length头之后，客户端可以再次提交该请求。

- 412 Precondition Failed（[RFC 7232](https://tools.ietf.org/html/rfc7232)）

  服务器在验证在请求的头字段中给出先决条件时，没能满足其中的一个或多个。这个状态码允许客户端在获取资源时在请求的元信息（请求头字段数据）中设置先决条件，以此避免该请求方法被应用到其希望的内容以外的资源上。

- 413 Request Entity Too Large（[RFC 7231](https://tools.ietf.org/html/rfc7231)）

  前称“Request Entity Too Large”，表示服务器拒绝处理当前请求，因为该请求提交的实体数据大小超过了服务器愿意或者能够处理的范围。此种情况下，服务器可以关闭连接以免客户端继续发送此请求。

  如果这个状况是临时的，服务器应当返回一个Retry-After的响应头，以告知客户端可以在多少时间以后重新尝试。

- 414 Request-URI Too Long（[RFC 7231](https://tools.ietf.org/html/rfc7231)）

  前称“Request-URI Too Long”，表示请求的URI长度超过了服务器能够解释的长度，因此服务器拒绝对该请求提供服务。通常将太多数据的结果编码为GET请求的查询字符串，在这种情况下，应将其转换为POST请求。这比较少见，通常的情况包括：本应使用POST方法的表单提交变成了GET方法，导致[查询字符串](https://zh.wikipedia.org/w/index.php?title=查询字符串&action=edit&redlink=1)过长。重定向URI“黑洞”，例如每次重定向把旧的URI作为新的URI的一部分，导致在若干次重定向后URI超长。客户端正在尝试利用某些服务器中存在的[安全漏洞](https://zh.wikipedia.org/wiki/安全漏洞)攻击服务器。这类服务器使用固定长度的缓冲读取或操作请求的URI，当GET后的参数超过某个数值后，可能会产生缓冲区溢出，导致任意代码被执行。没有此类漏洞的服务器，应当返回414状态码。

- 415 Unsupported Media Type

  对于当前请求的方法和所请求的资源，请求中提交的[互联网媒体类型](https://zh.wikipedia.org/wiki/互联网媒体类型)并不是服务器中所支持的格式，因此请求被拒绝。例如，客户端将图像上传格式为svg，但服务器要求图像使用上传格式为jpg。

- 416 Requested Range Not Satisfiable（[RFC 7233](https://tools.ietf.org/html/rfc7233)）

  前称“Requested Range Not Satisfiable”。客户端已经要求文件的一部分（[Byte serving](https://zh.wikipedia.org/w/index.php?title=Byte_serving&action=edit&redlink=1)），但服务器不能提供该部分。例如，如果客户端要求文件的一部分超出文件尾端。

- 417 Expectation Failed

  在请求头Expect中指定的预期内容无法被服务器满足，或者这个服务器是一个代理服显的证据证明在当前[路由](https://zh.wikipedia.org/wiki/路由)的下一个节点上，Expect的内容无法被满足。

- 418 I'm a teapot（[RFC 2324](https://tools.ietf.org/html/rfc2324)）

  本操作码是在1998年作为[IETF](https://zh.wikipedia.org/wiki/IETF)的传统[愚人节笑话](https://zh.wikipedia.org/wiki/惡搞RFC), 在RFC 2324[超文本咖啡壶控制协议](https://zh.wikipedia.org/wiki/超文本咖啡壶控制协议)'中定义的，并不需要在真实的HTTP服务器中定义。當一個控制茶壺的[HTCPCP](https://zh.wikipedia.org/wiki/HTCPCP)收到BREW或POST指令要求其煮咖啡時應當回傳此錯誤。这个HTTP状态码在某些网站（包括Google.com）與項目（如[Node.js](https://zh.wikipedia.org/wiki/Node.js)、[ASP.NET](https://zh.wikipedia.org/wiki/ASP.NET)和[Go語言](https://zh.wikipedia.org/wiki/Go语言)）中用作[彩蛋](https://zh.wikipedia.org/wiki/彩蛋_(媒体))。

- 421 Misdirected Request （[RFC 7540](https://tools.ietf.org/html/rfc7540)）

  该请求针对的是无法产生响应的服务器（例如因为连接重用）。

- 422 Unprocessable Entity（[WebDAV](https://zh.wikipedia.org/wiki/WebDAV)；[RFC 4918](https://tools.ietf.org/html/rfc4918) ）

  请求格式正确，但是由于含有[语义](https://zh.wikipedia.org/wiki/语义)错误，无法响应。

- 423 Locked（[WebDAV](https://zh.wikipedia.org/wiki/WebDAV)；[RFC 4918](https://tools.ietf.org/html/rfc4918)）

  当前资源被锁定。

- 424 Failed Dependency（[WebDAV](https://zh.wikipedia.org/wiki/WebDAV)；[RFC 4918](https://tools.ietf.org/html/rfc4918)）

  由于之前的某个请求发生的错误，导致当前请求失败，例如PROPPATCH。

- 425 Too Early ([RFC 8470](https://tools.ietf.org/html/rfc8470))

  服务器拒绝处理在Early Data中的请求，以规避可能的[重放攻击](https://zh.wikipedia.org/wiki/重放攻击)。

- 426 Upgrade Required（[RFC 2817](https://tools.ietf.org/html/rfc2817)）

  客户端应切换到[Upgrade头字段](https://zh.wikipedia.org/w/index.php?title=Upgrade头字段&action=edit&redlink=1)中给出的不同协议，如[TLS/1.0](https://zh.wikipedia.org/wiki/传输层安全)。

- 428 Precondition Required ([RFC 6585](https://tools.ietf.org/html/rfc6585))

  原服务器要求该请求满足一定条件。这是为了防止“未更新”问题，即客户端读取（GET）一个资源的状态，更改它，并将它写（PUT）回服务器，但这期间第三方已经在服务器上更改了该资源的状态，因此导致了冲突。”

- 429 Too Many Requests （[RFC 6585](https://tools.ietf.org/html/rfc6585)）

  用户在给定的时间内发送了太多的请求。旨在用于[网络限速](https://zh.wikipedia.org/w/index.php?title=网络限速&action=edit&redlink=1)。

- 431 Request Header Fields Too Large （[RFC 6585](https://tools.ietf.org/html/rfc6585)）

  服务器不愿处理请求，因为一个或多个头字段过大。

- 451 Unavailable For Legal Reasons

主条目：[HTTP 451](https://zh.wikipedia.org/wiki/HTTP_451)



# 5xx服务器错误

表示服务器无法完成明显有效的请求。这类状态码代表了服务器在处理请求的过程中有错误或者异常状态发生，也有可能是服务器意识到以当前的软硬件资源无法完成对请求的处理。除非这是一个HEAD请求，否则服务器应当包含一个解释当前错误状态以及这个状况是临时的还是永久的解释信息实体。浏览器应当向用户展示任何在当前响应中被包含的实体。这些状态码适用于任何响应方法。

- 500 Internal Server Error

  通用错误消息，服务器遇到了一个未曾预料的状况，导致了它无法完成对请求的处理。没有给出具体错误信息。

- 501 Not Implemented

  服务器不支持当前请求所需要的某个功能。当服务器无法识别请求的方法，并且无法支持其对任何资源的请求。（例如，网络服务API的新功能）

- 502 Bad Gateway

  作为[网关](https://zh.wikipedia.org/wiki/网关)或者[代理](https://zh.wikipedia.org/wiki/代理服务器)工作的服务器尝试执行请求时，从上游服务器接收到无效的响应。

- 503 Service Unavailable

  由于临时的服务器维护或者[过载](https://zh.wikipedia.org/wiki/過載)，服务器当前无法处理请求。这个状况是暂时的，并且将在一段时间以后恢复。如果能够预计延迟时间，那么响应中可以包含一个Retry-After头用以标明这个延迟时间。如果没有给出这个Retry-After信息，那么客户端应当以处理[500响应](https://zh.wikipedia.org/w/index.php?title=500_Internal_Error&action=edit&redlink=1)的方式处理它。

- 504 Gateway Timeout

  作为网关或者代理工作的服务器尝试执行请求时，未能及时从上游服务器（URI标识出的服务器，例如[HTTP](https://zh.wikipedia.org/wiki/HTTP)、[FTP](https://zh.wikipedia.org/wiki/FTP)、[LDAP](https://zh.wikipedia.org/wiki/LDAP)）或者辅助服务器（例如[DNS](https://zh.wikipedia.org/wiki/DNS)）收到响应。

  注意：某些代理服务器在DNS查询[超时](https://zh.wikipedia.org/w/index.php?title=超时&action=edit&redlink=1)时会返回[400](https://zh.wikipedia.org/wiki/HTTP状态码#400)或者[500](https://zh.wikipedia.org/wiki/HTTP状态码#500)错误。

- 505 HTTP Version Not Supported

  服务器不支持，或者拒绝支持在请求中使用的HTTP版本。这暗示着服务器不能或不愿使用与客户端相同的版本。响应中应当包含一个描述了为何版本不被支持以及服务器支持哪些协议的实体。

- 506 Variant Also Negotiates（[RFC 2295](https://tools.ietf.org/html/rfc2295)）

  由《透明内容协商协议》（[RFC 2295](https://tools.ietf.org/html/rfc2295)）扩展，代表服务器存在内部配置错误，[[65\]](https://zh.wikipedia.org/wiki/HTTP状态码#cite_note-RFC_2295-65)被请求的协商变元资源被配置为在透明内容协商中使用自己，因此在一个协商处理中不是一个合适的重点。

- 507 Insufficient Storage（[WebDAV](https://zh.wikipedia.org/wiki/WebDAV)；[RFC 4918](https://tools.ietf.org/html/rfc4918)）

  服务器无法存储完成请求所必须的内容。这个状况被认为是临时的。

- 508 Loop Detected （[WebDAV](https://zh.wikipedia.org/wiki/WebDAV)；[RFC 5842](https://tools.ietf.org/html/rfc5842)）

  服务器在处理请求时陷入死循环。 （可代替 [208状态码](https://zh.wikipedia.org/wiki/HTTP状态码#208)）

- 510 Not Extended（[RFC 2774](https://tools.ietf.org/html/rfc2774)）

  获取资源所需要的策略并没有被满足。

- 511 Network Authentication Required （[RFC 6585](https://tools.ietf.org/html/rfc6585)）

  客户端需要进行身份验证才能获得网络访问权限，旨在限制用户群访问特定网络。（例如连接[WiFi热点](https://zh.wikipedia.org/wiki/热点_(Wi-Fi))时的[强制网络门户](https://zh.wikipedia.org/wiki/强制门户)）

# 非官方状态码

- 420 Enhance Your Caim

  Twitter Search与Trends API在客户端被限速的情况下返回。

- 444 No Response

  Nginx上HTTP服務器擴展。服務器不向客戶端返回任何信息，並關閉連接（有助於阻止惡意軟體）。

- 450 Blocked by Windows Parental Controls

  這是一個由Windows家庭控制（Microsoft）HTTP阻止的450狀態代碼的示例，用於信息和測試。

- 494 Request Header Too Large

  在错误代码431提出之前Nginx上使用的扩展HTTP代码。