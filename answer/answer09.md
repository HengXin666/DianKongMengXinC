# 题目
## 练习
- 写一个`int* initArr(int len)`函数, 作用: 动态分配长度为`len`的数组, 并且返回其指针. 另外实现一个`freeArr(int** arr)`函数, 释放`arr`数组的内存空间, 并且置`arr`为`NULL`. (思考: 为什么传参是`int** arr`, `int *arr`不行吗?)

```C
#include <stdio.h>
#include <stdlib.h>

int* initArr(int len) {
    return (int *)malloc(len * (sizeof(int)));
}

void freeArr(int** arr) {
    free(*arr);
    *arr = NULL;
}

int main() {
    int* arr = initArr(3);
    freeArr(&arr);
    if (!arr)
        printf("arr == NULL\n"); // 会被打印
    return 0;
}
```

> 为什么传参是`int** arr`, `int *arr`不行吗?
>
> 回答: 不行; 如果为函数声明为`freeArr(int* arr)`, 并且以`freeArr(arr);`调用, 即以按值拷贝的方式传参, 那么你在`freeArr`置`NULL`时候, 赋值的 arr 是函数的局部变量, 不会对外部的 arr 产生影响.

> [!TIP]
> [梅开二度]
>
> 那么对于上面的代码, 你知道为什么`int* initArr(int len)`可以直接返回`int *`吗? 我则和上面的回答矛盾吗?

<details>
<summary>查看答案: </summary>

并不矛盾，因为在`initArr`函数中，返回的是指向动态分配内存的指针，而这个指针是由`malloc`函数分配的，存储在堆上，函数结束后不会被销毁。因此可以直接返回`int*`。而在`freeArr`中需要通过`int**`来修改原始指针的值（使其指向`NULL`），因为指针本身是局部变量，不能直接改变外部指针的值。

</details>

## 作业
- 实现一个`长 * 宽`=`n * m`阶梯型的二维数组, 要求其内存刚刚好, 例如: 需要申请 $3 \times 3$ 的阶梯型的二维数组, 那么它的内存模型大致可以是这样的:
    - [我来助你!]：需要用到指针的知识!

```C
[ ]         // 索引 [0][0], 如果 [0][1] 则下标越界
[ ] [ ]     // 索引 [1][0]、[1][1] 合法, 如果 [1][2] 则下标越界
[ ] [ ] [ ] // 索引 [2][0]、[2][1]、[2][2] 均合法
```

- 参考答案:

```C
#include <stdio.h>
#include <stdlib.h>

int** createStairArray(int n, int m) {
    // 创建指针数组
    int** arr = (int**)malloc(n * sizeof(int*));
    // 为每一行分配相应的列
    for (int i = 0; i < n; ++i) {
        arr[i] = (int*)malloc((i + 1) * sizeof(int));
    }
    return arr;
}

void freeStairArray(int** arr, int n) {
    for (int i = 0; i < n; ++i) {
        free(arr[i]); // 释放每一行的内存
    }
    free(arr); // 释放指针数组
}

void printStairArray(int** arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 3; // 行数
    int m = 3; // 最大列数, 但实际列数随行数递增
    int** stairArray = createStairArray(n, m);

    // 填充数组 (示例填充为行号和列号的和)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            stairArray[i][j] = i + j;
        }
    }

    // 打印数组
    printStairArray(stairArray, n);

    // 释放内存
    freeStairArray(stairArray, n);
    return 0;
}
```

- 评分标准:

|分数|注解|
|:-|:-|
|0分|未提交|
|30分|提交但运行不正确, (主要在于提交了)|
|80分|运行基本正确, 但是忘记(懒得)释放内存|
|90分|运行正确, 但是没有注释/代码叙利亚风格|
|100分|运行正确, 有基本的注释, 代码风格统一|

> [!TIP]
> 最终只看代码, 是否是一个二维的长短不一的数组!, 使用`int arr[len][len]`给`30分`

> 注: 主要看代码, 是否在内存上实现的这种 (比如使用: 数组指针数组) (推荐使用函数式编程)
>
> 打印不是必须的, 因为无法从打印判断是否正确, 只能看代码 (当然, 打印地址理论上可以)
>
> 注: 如果无法编译等其他原因, 酌情给分