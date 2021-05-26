- 为什么会有这个需求呢？

前两天有个面试题，让写出读取文件夹下所有文件的名称，诶，说来惭愧，好长一段时间都在用框架写怎删改查，关于文件读写的`API`早就忘了，再加上当时学的不牢固，那题就没做出来（说到底还是自己的基础不好）。这不是闲了下来，自己赶紧记录下来

- 递归读取指定文件夹下的所有文件，并保存到指定的txt文件中，不过递归的效率确实不怎么好。

```java
import org.junit.Test;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;

/**
 * @Author: stone
 * @Date: 2021/03/28 23:26:13
 * @ClassName: ReadTxt
 * @Description:
 **/

public class ReadTxt {

	@Test
	public void WriteTxt() throws Exception {
		String path = ""; //这里写你要读取的文件夹
		String outputPath = "E:\\fileNameList.txt"; //这里写你要保存到什么文件中，追加保存，不会覆盖上一次保存的文件
		ArrayList<String> fileNameList = readFiles(path, new ArrayList<String>());
		System.out.println(fileNameList.size());
		for (int i = 0; i < fileNameList.size(); i++) {
			outputToTxt(fileNameList.get(i), outputPath);
		}

	}

	/**
	 * @Author: stone
	 * @Param:
	 * @return:
	 * @Description: 递归读取文件路径下的所有文件
	 **/
	public ArrayList<String> readFiles(String path, ArrayList<String> fileNameList) {
		File file = new File(path);
		if (file.isDirectory()) {
			File[] files = file.listFiles();
			for (int i = 0; i < files.length; i++) {
				if (files[i].isDirectory()) {
					readFiles(files[i].getPath(), fileNameList);
				} else {
					String path1 = files[i].getPath();
					String fileName = path1.substring(path1.lastIndexOf("\\") + 1); // Windows下，目录是双斜杠
					fileNameList.add(fileName);
				}
			}
		} else {
			String path1 = file.getPath();
			String fileName = path1.substring(path1.lastIndexOf("\\") + 1);
			fileNameList.add(fileName);
		}
		return fileNameList;
	}

	/**
	 * @Author: stone
	 * @Param:
	 * @return:
	 * @Description: 将内容输入到txt文件保存
	 **/
	public void outputToTxt(String content, String outputPath) throws Exception {
		FileWriter fileWriter = new FileWriter(outputPath, true); // true代表追加内容
		PrintWriter printWriter = new PrintWriter(fileWriter);
		printWriter.println(content);
		printWriter.close();
		fileWriter.close();
		printWriter.flush();
	}
}



```

- 使用`Java` 的 `API`

```java
import org.junit.Test;

import java.io.File;

/**
 * @Author: stone
 * @Date: 2021/03/29 12:32:04
 * @ClassName: fileTest
 * @Description:
 **/

public class fileTest {

	public void listFilesForFolder(File folder) {
		for (File fileEntry : folder.listFiles()) {
			if (fileEntry.isDirectory()) {
				listFilesForFolder(fileEntry);
			} else {
				System.out.println(fileEntry.getName());
			}
		}
	}

	@Test
	public void testFIle() {
		File folder = new File(""); //自己定义要查找的路径
		listFilesForFolder(folder); // 结果打印在控制台
	}
}
```

---

参考：

- [stackoverflow](https://stackoverflow.com/questions/1844688/how-to-read-all-files-in-a-folder-from-java?page=1&tab=votes#tab-top)

