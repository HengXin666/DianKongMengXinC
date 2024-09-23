<h1 align="center" style="color:red">DGUT 2024 K队 电控 C 语言学习指北</h1>

## 一、前言 & 通知

> [!TIP]
> 本文内容由`Heng_Xin`编写, 部分题目来源于网络(某些概念题), 看起来有意思的题目为原创题目 ~~(绝对不是我找不到题目了qwq)~~ 
>
> 难度肯定是有点的; 如果可以认真好好完成, 绝对乱杀学校的C语言考试 (八股文就算了)
>
> 修改了一些格式问题, `等时间截止了, 这里就会更新答案`!
>
> 如果有问题, 可以去 [issues](https://github.com/HengXin666/DianKongMengXinC/issues) 进行提问, 这样别人也可以看到!

> [!IMPORTANT]
> 如果可以的话, 可以学习一下 [MarkDown语法](https://markdown.com.cn/basic-syntax/), 做笔记/写技术文档都是会用到的, 而且简单、简洁且方便! (文件以`.md`结尾(千万不要被 $md$ 这两个字给吓到了~)) 
>
> 此外, 代码风格也是很重要的! 具体可以看看: [代码规范指北](document/CodeSpecifications.md)

---

> [!NOTE]
> - 第一次考核暂定在`10月10日`(周四) **下午公休的时间段**, 会在实验室线下进行考试, 请务必按时完成作业

---

~~广告: [C++20协程和基于`io_uring`の百万并发http/https服务器/客户端](https://github.com/HengXin666/HXNet)~~

## 二、 作业提交
### 2.1 C语言评分标准

| 提交时间 | 作业完成度 | 线下考试 |
| :----: | :----: | :----: |
| 20% | 30% | 50% |
|PS: 记得作业的ddl哦!|PS: 功能实现情况和代码的编写情况(抄袭与否)|PS: C语言题目, 难易结合|

### 2.2 作业提交方式
- 面试者需要按照安排来完成自学任务并且提交作业, 作业以一个 **压缩包** 的方式提交到此邮箱(`yyy1177@kinetic.freeqiye.com`),

- 压缩包内需含有: 
    - 代码文件(`.c`结尾的源文件)
    - 运行的结果截图
    - 相对应的学习笔记截图(`.word`(超不推荐)、`.md`、`.pdf`、`.txt`等格式均可)

- 压缩包命名格式为: `24电控组_姓名_第几次作业`
    - 例如: `24电控组_张三_第5次作业`

> [!WARNING]
> 请严格按照格式要求提交, 否则后果自负!!!

- 有题号的记得标好题号, 良好的习惯也是加分项哦(好像跟卷面分一样的感觉UwU)!

## 三、学习内容和时间安排
### 3.0 前言
> [!NOTE]
> 注: `[练习]`为自己练习(**不需要**提交) | `[作业]`为学长精挑细选, **需要提交**.

> [!TIP]
> 学习链接: B站 - 小甲鱼: [【C语言】《带你学C带你飞》](https://www.bilibili.com/video/BV17s411N78s)
>
> 注: 由于越往后面越难, 请速通前面的任务, 尽可能把时间留给`指针`等后边的内容!

> [!CAUTION]
> *本时间安排只是安排 **最晚** 完成时间 qwq*

---

### 3.1 [2024年9月23日] 星期一

- 任务: 配置好`C语言`环境

> [!TIP]
> - C语言环境安装 (-> [vscode 关于C/C++的环境配置全站最简单易懂](https://www.bilibili.com/video/BV1kR4y1M7R8/)) | 个人推荐
>
> - VS2022安装指南(->[Visual Studio (VS) 2022 中文软件安装包下载及安装教程！](https://mp.weixin.qq.com/s/9gP4SyuCsX2rkWq57tlRqA))
>
> - dev C++安装指南(->[Dev C++ 6.5 软件安装包下载及安装激活教程！](https://mp.weixin.qq.com/s/pSqIKW9Cyw_0GKtuRc6Lbg))

> [!WARNING]
> 自己去网上找也没问题! 但是最好就是跟一个教程就仔仔细细的从头跟到末尾! **`不要、不准`** 这一个教程那一个教程的, 一个只看一半!

> [!CAUTION]
> <h1 align="center" style="color:red"> !!!安装路径不要有中文!!! </h1>

- 练习: Hello World! 程序 (保证C语言环境配置完毕) 编写一个 [HelloWorld.c](src/HelloWorld.c) 内容如下:

```C
#include <stdio.h>

int main() {
    printf("Hello World!\n");
    return 0;
}
```

---

### 3.2 [2024年9月24日] 星期二
- 小甲鱼 [初识C语言] P 1 ~ 9

- 练习: 交互式程序(使用`scanf`)依次对输入数据, 加减乘除

> [!WARNING]
> #### 第一次作业 (最晚提交时间: `9.24 23:59:59`)

- 填充下边代码, 使得打印结果为：`-1`和`255` 

> [!IMPORTANT]
> 注: 只能修改注释要求的地方, 其他地方都不能修改, 否则作答无效!!!

- [我来助你!]: 打印格式请参考[printf - 格式化输出](https://fishc.com.cn/thread-66471-1-1.html)

```C
//第一次作业

#include <stdio.h>

int main() {
    // 此处声明 i
    // 此处声明 j

    i = 255;
    j = 255;

    printf("???", i); // 请将 ??? 修改为格式化打印
    printf("???", j); // 请将 ??? 修改为格式化打印

    return 0;
}
```

程序执行后的结果为:
```C
i 的值是 -1
j 的值是 255
```

---

### 3.3 [2024年9月25-26日] 星期三 ~ 星期四
- 小甲鱼 [流程控制语句篇] P 10 ~ 16

- 练习: 9 * 9 乘法表

> [!WARNING]
> #### 第二次作业 (最晚提交时间: `9.26 23:59:59`)

- `长 * 宽`=`p * q`的**余数表**, 要求用户可以输入两个正整数 ( $p$ , $q$ ; 其中 $p >= q$ ), 特别要求: 因为`六丁六甲, 从不吃素`, 所以我们需要剔除 **任何** 含有`6`及其**倍数**的数字作为`被除数`和`除数`时候的式子(需要用到`continue;`和`break;`), 下面是运行示例:

```C
//第二次作业

请输入p和q: 3 3

这个是 3 * 3 的余数表
1 ÷ 1 = 1 ... 0
2 ÷ 1 = 2 ... 0, 2 ÷ 2 = 1 ... 0
3 ÷ 1 = 3 ... 0, 3 ÷ 2 = 1 ... 1, 3 ÷ 3 = 1 ... 0
```

---

### 3.3 [2024年9月27日 ~ 2024年9月29日] 星期五 ~ 星期日
- 小甲鱼 [数组篇] P 17 ~ 20
   
- 练习: 实现二维坐标数组(默认值全0), 交互式输入 (x, y), 对 `arr[y][x]` 进行加法, 然后打印结果.

> [!WARNING]
> #### 第三次作业 (最晚提交时间: `9.29 23:59:59`)

- 实现一个`长 * 宽`=`11 * 9`的二维`int`数组, 并且初始化全部为`0`, 除了`arr[6][6]`需要赋值为`6`, 使用一个`while (1)`作为主循环, 我们可以输入`wasd`其中一个字母, `6`就会往那个方向移动一格, 并且打印移动后的结果, 如果碰到了边界, 我们不能移动`6`, 而是输出一句`"前面的路 请以后再来探索~"`.
	
- 你可以自由定义打印的样式, 但必须可以区分`6`和`0` (即, 你可以尝试使用`"空地"`和`"玩家"`来代替`0`和`6`)

---

### 3.4 [2024年9月30日 ~ 2024年10月4日] 星期一 ~ (下一周)星期五 (5 Days)
- 小甲鱼 [指针篇] P 21 ~ 27

- 注: 体会指针; 可以区别指针和普通变量即可 (更多的会在作业中学习到 (不止于[指针篇]))

- 练习: 
    - [P25] 请问下边代码会打印什么? (无需提交, 只需要自己思考~)

```C
#include <stdio.h>

int main() {
	int array[5] = {1, 2, 3, 4, 5};
	int *pi = &array[2];
	void *pv;

	pv = pi;
	pv++;
	pi = pv;

	printf("%d\n", *pi);

	return 0;
}
```

> [!WARNING]
> #### 第四次作业 (最晚提交时间: `9.30 23:59:59`)
>
> 注: 简答题可以写`Markdown`来作答~

学习 P 21 后完成:

1. 请问`int * a, b, c;`定义了多少个指针变量? 

2. 请问`int *(a, b, c);`定义了多少个指针变量? 

3. 你觉得将取址运算符(`&`)作用于一个常数, 然后试图打印该常数在内存中的地址, 这样做可取吗? 

```C
#include <stdio.h>

int main() {
	printf("%p\n", &114514);
	return 0;
}
```

4. 请问下边代码是否可以成功执行呢? 为什么? 

```C
#include <stdio.h>

int main() {
	int a, b;

	b = 110;
	a = &b;

	printf("%d\n", *a);

	return 0;
}
```

5. 请问为什么每次执行下边代码都会得到不同的结果?

```C
#include <stdio.h>

int main() {
	int *a;

	printf("%p\n", a);

	return 0;
}
```

> [!WARNING]
> #### 第五次作业 (最晚提交时间: `10.2 23:59:59`)

学习 P 22 后完成:

6. `str[3]`用指针法如何表示?

7. 请问`str[20]`是否可以写成`20[str]`?

学习 P 23 后完成:

8. 为什么不能使用`if (str1 == str2)`这样的形式来比较两个字符串?


学习 P 24 后完成:

9. 请问`array[x][y][z]`用指针法如何表示?

10. 编程题: 编写一个程序, 接收用户的输入, 并将前 n * n 个字符以正方形矩阵(n * n)的方式输出, 注: 要求程序自动计算用户输入的字符, 并以最大的正方形矩阵输出, 比如 用户输入了 21 个字符, 则一个输出其前 4 * 4 = 16 个字符, 拼成的正方形矩阵; 下面是运行示例:

```C
请输入: 0123456789abcdef01234
最大矩阵为 4 * 4
0 1 2 3
4 5 6 7
8 9 a b
c d e f
```

> [!WARNING]
> #### 第六次作业 (最晚提交时间: `10.3 23:59:59`)

学习 P 25 后完成:

11. 你猜下边代码会打印多少? 那`sizeof(void *)`呢?

```C
#include <stdio.h>

int main() {
	void a;

	printf("%d\n", sizeof(a));

	return 0;
}
```

12. 如何有效地避免出现悬空指针?

13. 对`NULL`指针进行解引用, 结果是什么?

学习 P 26 后完成

14. 请问什么时候`*&p`和`p`等价, 什么时候`&*p`和`p`等价?

15. 如果有`int a[10];`, 请问`&a`和`&a[0]`表达式的类型有何不同

> [!WARNING]
> #### 第七次作业 (最晚提交时间: `10.4 23:59:59`) (学习 完指针篇全部 后再完成)

16. 编程题: 分割字符串。用户输入一个英文句子, 你的程序将这个字符串按空格进行分割, 返回由单词组成的二维数组。

要求:

- 返回的二维数组必须尽可能地节省空间 (利用C语言的变长数组来实现) 

- 不能使用现成的函数帮忙 (你只能`#include <stdio.h>`) 

程序实现如下:

分割后的结果存放在`result`二维数组中, 这个二维数组的尺寸是根据用户输入的单词长度而定的 (再次提醒：不能使用`malloc`等没学过的知识噢~) 

```C
请输入一个英文句子：I love DianKong!
分割结果已存放到result[3][10]的二维数组中...
现在依次打印每个单词：
I
Love
DianKong!
```

不论是一个空格还是多个空格, 你的程序都能够正确识别出单词来:

```C
请输入一个英文句子：I  love       DianKong!
分割结果已存放到result[3][10]的二维数组中...
现在依次打印每个单词：
I
Love
DianKong!
```

---

### 3.5 [2024年10月5日 ~ 2024年10月6日] 星期六 ~ 星期日
- 小甲鱼 [函数篇] P 28 ~ 29 (P30 选学(函数指针 & 指针函数))
- 小甲鱼 [静态变量/全局变量] P 31 (选学: P 32 ~ 33)
- 小甲鱼 [函数应用篇] P 34 (递归) (P35 选学)

- 注: 体会使用指针作为参数和使用普通变量作为参数时候的区别

- 练习:
    - 使用函数实现一个计算器(支持加减乘除、平方和取模)

    - 使用递归实现`斐波那契数列`的计算

> [!WARNING]
> #### 第八次作业(最晚提交时间: `10.6 23:59:59`)

- 实现一个洗牌程序。所谓洗牌程序, 就是将所有的扑克牌放入 **一个** 数组中, 要求把数组内的扑克牌顺序随机打乱, 然后输出 (示例见下)

- [我来助你!]: 
    - 这道题需要你进行一些额外的学习, 比如既然是洗牌, 那就是要求随机打乱一个数组内的所有元素。这个“随机”如何实现呢? 我们可以通过 C 语言`stdlib.h`库的 [srand](https://fishc.com.cn/thread-84362-1-1.html) 函数和 [rand](https://fishc.com.cn/thread-84363-1-1.html) 函数来实现。

    - 那方角、梅花、红桃和黑桃如何表示呢? 你可以使用整数`1~54`来代表扑克的`54`张牌, 比如`1~10`代表`方角1~方角10`, `11~20`代表`梅花1~梅花10`... 那么`41`、`42`、`43`就可以用来表示`方角J`、`方角Q`和`方角K`, 以此类推。

    - 建议: 洗牌、发牌、显示分别用独立的函数来封装, 实现模块化编程。

```C
请输入 1号 玩家的名字: awa
请输入 2号 玩家的名字: qwq
请输入 3号 玩家的名字: 0.0
方 = 方块,  梅 = 梅花,  红 = 红桃,  黑 = 黑桃
玩家 [awa] 手上的是: 方Q 方1  黑3  小王 方4  大王 黑2  黑J 黑4  方6  红J 黑9  梅Q 红9  黑10  红1  梅4  
玩家 [qwq] 手上的是: 梅K 红4  方J 梅2  梅9  梅J 方7  方2  梅10  黑5  黑Q 黑7  梅8  梅3  红Q 梅6  红6
玩家 [0.0] 手上的是: 方5  红5  红7  方9  方K 红3  方10  红K 方3  黑6  红10  红8  方8  梅1  梅7  梅5  红2
是否重新洗牌?(y/n): n
```

---

### 3.6 [2024年10月7日] 周一
- 小甲鱼 [动态内存分配] P 37 ~ 38 (P39 选学)

- 练习: 写一个`int* initArr(int len)`函数, 作用: 动态分配长度为`len`的数组, 并且返回其指针. 另外实现一个`freeArr(int** arr)`函数, 释放`arr`数组的内存空间, 并且置`arr`为`NULL`. (思考: 为什么传参是`int** arr`, `int *arr`不行吗?)

> [!WARNING]
> #### 第九次作业(最晚提交时间: `10.7 23:59:59`)

- 实现一个`长 * 宽`=`n * m`阶梯型的二维数组, 要求其内存刚刚好, 例如: 需要申请 $3 \times 3$ 的阶梯型的二维数组, 那么它的内存模型大致可以是这样的:
    - [我来助你!]：需要用到指针的知识!

```C
[ ]         // 索引 [0][0], 如果 [0][1] 则下标越界
[ ] [ ]     // 索引 [1][0]、[1][1] 合法, 如果 [1][2] 则下标越界
[ ] [ ] [ ] // 索引 [2][0]、[2][1]、[2][2] 均合法
```

---

### 3.7 [2024年10月8-9日] 周二 ~ 周三
- 小甲鱼 [结构体] P 42 ~ 44

- 练习: 使用函数实现, 动态分配内存给结构体(指针)变量, 及其释放

> [!WARNING]
> #### 第十次作业 (最晚提交时间: `10.9 23:59:59`)

- 张三最近被`黑神话: 悟空`虐爆了! 因为他真的非常的菜! (真不知道他是怎么成为法外狂徒的!); 但是他依旧为了展示他的实力, 需要记录打过的Boss的名称以及失败的次数; 但是非常不凑巧的是, 某些Boss有二阶段, 他希望可以区分一个Boss是在第一个阶段被虐的多还是第二阶段; 可是非常不巧的是, 张三是一个垃圾佬(电脑是捡垃圾组装的), 因此内存十分的小!
    
    - 而我的朋友, 你(请假装你是李四, 是C语言大佬!)今天的任务就是帮助张三, 以展示他的实力! 你精心为他设计了一个超级节约内存的C语言程序--内置两种结构体, 通过malloc动态内存分配的超级无敌世吞mk-2.exe

    - 其包含以下功能:
        1. 内置两种结构体 (分别存放了: {Boss名称, 被虐次数}, {Boss名称, 一阶段被虐次数, 二阶段被虐次数})

        2. 只能存储一只的Boss数据, 如果张三打到下一只, 那么就不需要这些数据了, 请清空!

        3. 打印函数, 打印当前Boss, 张三被虐的次数

        4. 显而易见的录入函数

        5. ~~一身破烂, 难怪登门 (李四的设计也太鸡肋了吧...)~~

    - 下面是运行示例:

```C
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
a. 我要开始打Boss了
b. 被Boss击败了
c. 击败这个Boss了
p. 查看战绩

请选择: a
请问Boss的名称: 白衣居士
请问Boss有几个阶段(1 ~ 2): 2

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
a. 我要开始打Boss了
b. 被Boss击败了
c. 击败这个Boss了
p. 查看战绩

请选择: b
请问在第几阶段击败的(1 ~ 2): 2

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
a. 我要开始打Boss了
b. 被Boss击败了
c. 击败这个Boss了
p. 查看战绩

请选择: p
Boss名称: 白衣居士
一阶段被虐次数: 0 次
二阶段被虐次数: 1 次

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
a. 我要开始打Boss了
b. 被Boss击败了
c. 击败这个Boss了
p. 查看战绩

请选择: c
六丁六甲, 从不吃素!

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
a. 我要开始打Boss了
b. 被Boss击败了
c. 击败这个Boss了
p. 查看战绩

请选择: a
请问Boss的名称: 虎先锋
请问Boss有几个阶段(1 ~ 2): 1

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
a. 我要开始打Boss了
b. 被Boss击败了
c. 击败这个Boss了
p. 查看战绩

请选择: b
猴头留着下酒, 剩下的交给大王~ // 请注意! 这里的输出变了, 因为只有一个阶段, 必然只有一种可能!

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
a. 我要开始打Boss了
b. 被Boss击败了
c. 击败这个Boss了
p. 查看战绩

请选择: p
Boss名称: 虎先锋
被虐次数: 1 次 // 请注意! 这里的输出变了, 因为只有一个阶段, 必然只有一种可能!
```

---

### 3.8 选学(不一定用得上)

- P49 typedef
- P51 共用体
- P52 枚举类型