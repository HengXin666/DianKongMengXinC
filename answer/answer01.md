# 题目

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

## 答案

### 练习
略

### 作业

> 解析:
> char 类型占一个字节的空间，因此`unsigned char`的取值范围是`0~255`，signed char 的取值范围则是`-128~127`。十进制的`255`即二进制的`11111111`，`signed char`第一位为符号位，因此其值转换为十进制后是`-1`。
>
> printf 函数使用 %c 打印 char 类型的字符，使用 %d 和 %u 则打印其对应的 ASCII 码（其中 %d 打印带符号数，%u 打印无符号数）。signed char 和 unsigned char 使用 hh 说明其长度。

> [!TIP]
> - hh 表示将相应的参数按 signed char 或 unsigned char 类型输出
> - h 表示将相应的参数按 short 或 unsigned short 类型输出
> - l 表示将相应的参数按 long 或 unsigned long 类型输出
> - ll 表示将相应的参数按 long long 或 unsigned long long 类型输出
> - L 表示将相应的参数按 long double 类型输出

- 参考答案1:
```C
#include <stdio.h>

int main() {
    signed char i;
    unsigned char j;

    i = 255;
    j = 255;

    printf("i 的值是 %hhd\n", i);
    printf("j 的值是 %hhu\n", j);

    return 0;
}
```

> 可以按要求输出即可!

- 参考答案2:
```C
#include <stdio.h>

int main() {
    char i;
    unsigned char j;

    i = 255;
    j = 255;

    printf("i 的值是 %d\n", i);
    printf("j 的值是 %u\n", j);

    return 0;
}
```

- 错误示例:

```C
#include <stdio.h>

int main() {
    int i;
    int j;

    i = -1; // 直接没有按要求来!!!
    j = 255;

    printf("i 的值是 %d\n", i);
    printf("j 的值是 %d\n", j);

    return 0;
}
```

- 评分标准:

|分数|注解|
|:-|:-|
|0分|未提交|
|10分|没有按要求 (本题的硬性要求)|
|30分|提交但运行不正确|
|80分|运行正确, 但是没有按照输出格式输出<br>注: 输出格式为`i 的值是 -1`这种|
|100分|运行正确, 输出格式也正确, 码风清晰|