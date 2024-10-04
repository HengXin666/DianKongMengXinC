# 题目 & 答案
## 练习
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

> 答：建议回答“4”的童鞋自己打一次代码, 不出意外应该显示: `67108864`
>
> 为何如此邪乎？
>
> 我们把代码修改如下，你或许就会知道答案:

```C
#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int *pi = &array[2];
    void *pv;

    pv = pi;
    printf("%p, %p\n", pv, pi);

    pv++;
    pi = pv;
    printf("%p, %p\n", pv, pi);

    printf("%d\n", *pi);

    return 0;
}
```

> 由于`pv`是`void`类型指针，所以编译器并不知道其“跨度”是多少，因此`pv++`只是简单的将地址加`1`
>
> 那么地址不正确，打印出来的值肯定就是错误的!
>
> **那打印出来的是“乱码”吗？**
>
> 不是！如果没有猜错，你在电脑上得到的结果应该是`67108864`
>
> 这里只是把`array[2]`和`array[3]`的二进制位给混在一起了
>
> 解释需要你懂得[小端和大端的原理](https://fishc.com.cn/thread-75394-1-1.html), 有兴趣的可以看看
> 
> pi 指向的是数组的第三个元素（即 array[2]，其值为 3）
>
> 那么 array[2] 和 array[3] 在内存中的存放形式（小端）应该如下:
>
> <table><tbody><tr><td><br></td><td colspan="4" width="200"><div align="center"><strong>array[2]</strong></div></td><td colspan="4" width="200"><div align="center"><strong>array[3]</strong></div></td></tr><tr><td><div align="center"><strong>数据</strong></div></td><td><div align="center">03</div></td><td><div align="center">00</div></td><td><div align="center">00</div></td><td><div align="center">00</div></td><td><div align="center">04</div></td><td><div align="center">00</div></td><td><div align="center">00</div></td><td><div align="center">00</div></td></tr><tr><td><div align="center"><strong>地址</strong></div></td><td><div align="center">0xbf93b10c</div></td><td><div align="center">0xbf93b10d</div></td><td><div align="center">0xbf93b10e</div></td><td><div align="center">0xbf93b10f</div></td><td><div align="center">0xbf93b110</div></td><td><div align="center">0xbf93b111</div></td><td><div align="center">0xbf93b112</div></td><td><div align="center">0xbf93b113</div></td></tr></tbody></table>
>
> pv = pi 使得 pv 也是指向 0xbf93b10c 地址。
>
> pv++ 刚才我们解释了，编译器只知道机械将其地址加 1，即 pv 现在指向的是 0xbf93b10d 地址。
>
> pi = pv 使得 pi 被 pv 带上了歪路...
>
> 以整型的跨度打印 pi，那么编译器会从 pi 指向的地址开始（0xbf93b10d），找到四个字节的数据（0x00000004），并将它们打印出来。
>
> 由于是小端，所以 0x00000004 对应的人类可读十六进制就是 0x04000000，转换为十进制就是大家所看到的 67108864。

## 作业

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

> 答：会报错！那`void`既然是无类型，我们就不应该用它来定义一个变量，如果你一定要这么做，那么程序就会给你报错
>
> `sizeof(void *)`: 答：如果你回答是 4 个字节或 8 个字节，那么本题不能算你答对。因为指针的尺寸是与编译器的目标平台相关的。比如目标平台是 32 位的，那么`sizeof(void*)`就是 4，如果是 64 位的，那么`sizeof(void *)`就是 8，如果是 16 位的，那么就是 2 啦。

12. 如何有效地避免出现悬空指针?

> 注：悬空指针就是指向了不确定的内存区域的指针，通常对这种指针进行操作会使程序发生不可预知的错误。
>
> 答：当你的指针不知道指向哪儿的时候，那么将它指向 NULL，以后就不会有太多的麻烦。比如定义一个指针变量的时候，你可以把它初始化为 NULL，这样至少可以确保它不是一个垂悬指针。

13. 对`NULL`指针进行解引用, 结果是什么?

> 答：报错。无论什么操作系统，对空指针进行解引用都是非法的。

学习 P 26 后完成

14. 请问什么时候`*&p`和`p`等价, 什么时候`&*p`和`p`等价?

> `&`运算符的操作数必须是左值，因为只有左值才表示一个内存单元，才会有地址，运算结果是指针类型（地址）; `*`运算符的操作数必须是指针类型（地址），运算结果可以做左值。
>
> 结论：如果表达式`p`可以做左值，那么`*&p`和`p`等价；如果表达式`p`是指针类型（地址），那么`&*p`和`p`等价。

15. 如果有`int a[10];`, 请问`&a`和`&a[0]`表达式的类型有何不同

> 答：`a`是一个数组，在`&a`这个表达式中，数组类型做左值，`&a`表示取整个数组的首地址，类型是`int (*)[10]`; `&a[0]`则表示数组`a`的第一个元素的首地址，虽然两个地址的数值相同，但后者的类型是`int *`。

- 评分标准:

|分数|注解|
|:-|:-|
|0分|未提交|
|100分|提交了|

> [!TIP]
> 本作业只是为了监督, 交了就有分数 (不然就惨不忍睹了)! 别高兴太早! 快对答案吧~