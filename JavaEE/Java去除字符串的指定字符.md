Java去除字符串中的特殊符号或者指定的字符

```java
import org.junit.Test;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @Author: stone
 * @Date: 2021/03/30 22:58:32
 * @ClassName: FormartCode
 * @Description:
 **/

public class FormartCode {

	String regEx = "[\n`~!@#$%^&*()+=|{}':;',\\[\\].<>/?~！@#￥%……&*（）——+|{}【】‘；：”“’。， ·、？]";
	String aa = "";//这里是将特殊字符换为aa字符串,""代表直接去掉

	@Test
    //方法一
	public void test1() {
		Pattern p = Pattern.compile(regEx);
		Matcher m = p.matcher("测试来着，赛风·到付·“，、！扫扥看");//这里把想要替换的字符串传进来
		String newString = m.replaceAll(aa).trim();//将替换后的字符串存在变量newString中
		System.out.println("newString = " + newString);
	}
	/*
	输出结果：
	newString = 测试来着赛风到付扫扥看
	 */

	@Test
    // 方法二
	public void test2() {
		String str = "测试来着，赛风·到付·“，、！扫扥看";
		String newString = str.replaceAll(regEx, aa);//不想保留原来的字符串可以直接写成 “str = str.replaceAll(regEX,aa);”
		str.replaceAll(regEx, aa);
		System.out.println("newString = " + newString);
	}
	/*
	输出结果：
	newString = 测试来着赛风到付扫扥看
	 */

}
```

- `replaceAll`支持正则

- `replace`不支持正则

---

[原文地址](https://www.cnblogs.com/hkgov/p/11693252.html)