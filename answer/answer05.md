# 题目 & 答案
学习 P 22 后完成:

6. `str[3]`用指针法如何表示?

> 答：*(str + 3)
>
> 恕我直言：写成 str + 3 或 *str + 3 的童鞋请面壁去... (<--老污龟说的)

7. 请问`str[20]`是否可以写成`20[str]`?

> 答：可以。
>
> 因为在访问数组的元素的时候，数组名被解释为数组第一个元素的地址。
>
> 所以 `str[20] == *(str + 20) == *(20 + str) == [20]str`
>
> 不信你自己试试看?

学习 P 23 后完成:

8. 为什么不能使用`if (str1 == str2)`这样的形式来比较两个字符串?

> 答：因为这样比较的是指向两个字符串的指针，而不是字符串本身。

学习 P 24 后完成:

9. 请问`array[x][y][z]`用指针法如何表示?

> 答：`*(*(*(array+i)+j)+k)`

10. 编程题: 编写一个程序, 接收用户的输入, 并将前 n * n 个字符以正方形矩阵(n * n)的方式输出, 注: 要求程序自动计算用户输入的字符, 并以最大的正方形矩阵输出, 比如 用户输入了 21 个字符, 则一个输出其前 4 * 4 = 16 个字符, 拼成的正方形矩阵; 下面是运行示例:

```C
请输入: 0123456789abcdef01234
最大矩阵为 4 * 4
0 1 2 3
4 5 6 7
8 9 a b
c d e f
```

- 标准答案:
```C
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1024

int main() {
    int length, aver;
    int i, j;
    char str[MAX];

    scanf("%s", str);

    length = strlen(str);
    aver = sqrt(length);
    printf("最大矩阵为 %d * %d\n", aver, aver);
    for (i = 0; i < aver; ++i) {
        for (j = 0; j < aver; ++j) {
            printf("%c ", str[i * aver + j]);
        }
        printf("\n");
    }

    return 0;
}
```

这个是只使用`stdio.h`的版本 (23年7月我学C语言时候写的, CV到下面了):
```C
#include <stdio.h>

#define MAX 1024

int main() {
    char str[MAX] = {0};
    int i, j;
    fgets(str, MAX, stdin); // stdin 是输入流 这里等价于 scnaf("%s", str);

    // 计算长度
    for (i = 0; i < MAX; ++i) {
        if (str[i] == '\0') {
            break;
        }
    }

    // 计算正方格大小
    for (j = 0; j < MAX; ++j) {
        if ((j + 1) * (j + 1) > i) {
            break; // 边长为 j, 其实开方i + 1取整更快
        }
    }
    printf("最大矩阵为 %d * %d\n", j, j);

    // 打印
    for (int x = 0; x < j * j; ++x) {
        if (x % j == 0 && x != 0) {
            printf("\n%c ", str[x]);
        } else {
            printf("%c ", str[x]);
        }
    }
    return 0;
}
```

- 评分标准: 简答题, `6, 8, 9`严格计分 (一个简答题 $10$ 分)

编程题评分: 满分依旧100分

|分数|注解|
|:-|:-|
|0分|未提交|
|10分|没有按要求 (比如: 面向printf的编程 (只有printf))|
|30分|提交但运行不正确|
|90分|运行正确|
|100分|运行正确, 码风清晰|

> 有问题, 酌情给分