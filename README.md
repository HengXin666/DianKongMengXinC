# DianKongMengXinC
DGUT 2024届 K队 电控 C 语言学习指北 (含 作业) (一段时间后 含答案)

测试:

> [!NOTE]
> Highlights information that users should take into account, even when skimming.

> [!TIP]
> Optional information to help a user be more successful.

> [!IMPORTANT]
> Crucial information necessary for users to succeed.

> [!WARNING]
> Critical content demanding immediate user attention due to potential risks.

> [!CAUTION]
> Negative potential consequences of an action.

- 第一次考核暂定在`10月10日`(周四) **下午公休的时间段**, 会在实验室线下进行考试, 请务必按时完成作业
## 二、 作业提交
### 2.1 C语言评分标准

| 提交时间 | 作业完成度 | 线下考试 |
| :----: | :----: | :----: |
| 20% | 30% | 50% |
|PS:记得作业的ddl哦!|PS:功能实现情况和代码的编写情况(抄袭与否)|PS:C语言题目，难易结合|

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

### 3.1 [2024年9月23日] 星期一

- 任务: 配置好`C语言`环境

> [!TIP]
> - C语言环境安装 (-> [vscode 关于C/C++的环境配置全站最简单易懂](https://www.bilibili.com/video/BV1kR4y1M7R8/)) | 个人推荐
>
> - VS2022安装指南(->[Visual Studio（VS）2022 中文软件安装包下载及安装教程！](https://mp.weixin.qq.com/s/9gP4SyuCsX2rkWq57tlRqA))
>
> - dev C++安装指南(->[Dev C++ 6.5 软件安装包下载及安装激活教程！](https://mp.weixin.qq.com/s/pSqIKW9Cyw_0GKtuRc6Lbg))

> [!WARNING]
> 自己去网上找也没问题! 但是最好就是跟一个教程就仔仔细细的从头跟到末尾! **`不要、不准`** 这一个教程那一个教程的, 一个只看一半!

> [!CAUTION]
> <h1  align="center" style="color:red"> !!!安装路径不要有中文!!! </h1>

- 练习: Hello World! 程序 (保证C语言环境配置完毕)

### 3.2 [2024年9月24日] 星期二
- 小甲鱼 [初识C语言] P 1 ~ 9

- 练习: 交互式程序(使用`scanf`)依次对输入数据, 加减乘除

> [!WARNING]
> 第一次作业 (最晚提交时间: `9.24 23:59:59`)

- 填充下边代码，使得打印结果为：`-1`和`255` 

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

### 3.3 [2024年9月25-26日] 星期三 ~ 星期四
- 小甲鱼 [流程控制语句篇] P 10 ~ 16

- 练习: 9 * 9 乘法表

> [!WARNING]
> 第二次作业 (最晚提交时间: `9.26 23:59:59`)

- `长 * 宽`=`p * q`的**余数表**, 要求用户可以输入两个正整数 ( $p$ , $q$ ; 其中 $p >= q$ ), 特别要求: 因为`六丁六甲, 从不吃素`, 所以我们需要剔除 **任何** 含有`6`及其**倍数**的数字作为`被除数`和`除数`时候的式子(需要用到`continue;`和`break;`), 下面是运行示例: