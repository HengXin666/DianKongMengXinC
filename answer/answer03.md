# 题目

- 练习: 实现二维坐标数组(默认值全0), 交互式输入 (x, y), 对 `arr[y][x]` 进行加法, 然后打印结果.

> [!WARNING]
> #### 第三次作业 (最晚提交时间: `9.29 23:59:59`)

- 实现一个`长 * 宽`=`11 * 9`的二维`int`数组, 并且初始化全部为`0`, 除了`arr[6][6]`需要赋值为`6`, 使用一个`while (1)`作为主循环, 我们可以输入`wasd`其中一个字母, `6`就会往那个方向移动一格, 并且打印移动后的结果, 如果碰到了边界, 我们不能移动`6`, 而是输出一句`"前面的路 请以后再来探索~"`.
	
- 你可以自由定义打印的样式, 但必须可以区分`6`和`0` (即, 你可以尝试使用`"空地"`和`"玩家"`来代替`0`和`6`)

## 答案

- 练习:

```C
#include <stdio.h>

#define WIDTH 6
#define HEIGHT 6

int main() {
    int n = WIDTH, m = HEIGHT;
    /*  // 下面代码可以支持可变大小的数组
        printf("请输入数组大小 (x * y): ");
        scanf("%d %d", &n, &m);
        int arr[n][m]; // C99 以后, 可以使用这样的语法糖 (变长数组(Variable Length Arrays, VLA))
    */
    int arr[n][m];

    // 初始化全部为 0
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            arr[i][j] = 0;

    // 主循环
    while (1) {
        int x = 0, y = 0;
        printf("\n请输入 (x, y): ");
        scanf("%d %d", &x, &y);
        if (y < 0 || y >= n || x < 0 || x >= m) {
            printf("输入范围不正确! 请重新输入!\n");
            continue;
        }

        ++arr[y][x];

        // 打印数组
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", arr[i][j]);
            }
            putchar('\n');
        }
    }

    return 0;
}
```

- 作业:

- 标准版本:
```C
#include <stdio.h>

#define ROWS 11
#define COLS 9

int main() {
    int arr[ROWS][COLS] = {0}; // 初始化数组
    int y = 6, x = 6; // 6 的初始位置
    arr[y][x] = 6;

    char command;
    _Bool isError = 0; // 注明移动是否有问题, 如果有问题, 就不打印地图

    while (1) {
        if (!isError) {
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
            printf("请输入方向 (w: 上, a: 左, s: 下, d: 右): ");
        } else {
            printf("请输入正确的方向 (w: 上, a: 左, s: 下, d: 右): ");
        }
        scanf(" %c", &command); // 注意前面的空格，用于忽略空白字符

        // 移动的目标坐标
        int newX = x, newY = y;

        // 根据输入更新目标坐标
        switch (command) {
            case 'w': // 上
                newY--;
                break;
            case 'a': // 左
                newX--;
                break;
            case 's': // 下
                newY++;
                break;
            case 'd': // 右
                newX++;
                break;
            default:
                printf("无效的输入，请输入 w, a, s 或 d.\n");
                isError = 1;
            continue;
        }

        // 检查边界
        if (newX < 0 || newX >= COLS || newY < 0 || newY >= ROWS) {
            printf("前面的路 请以后再来探索~\n");
            isError = 1;
        } else {
            arr[y][x] = 0; // 清空原位置
            // 更新位置
            y = newY;
            x = newX; 
            arr[y][x] = 6; // 移动到新位置
            isError = 0;
        }
    }

    return 0;
}
```

- 拓展版本(自由定义打印的样式, 但必须可以区分`6`和`0` (即, 你可以尝试使用`"空地"`和`"玩家"`来代替`0`和`6`))

```C
#include <stdio.h>

#define ROWS 11
#define COLS 9

int main() {
    int arr[ROWS][COLS] = {0}; // 初始化数组
    int y = 6, x = 6; // 6 的初始位置
    arr[y][x] = 6;

    char command;
    _Bool isError = 0; // 注明移动是否有问题, 如果有问题, 就不打印地图

    while (1) {
        if (!isError) {
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    printf("%s ", arr[i][j] ? "<人>" : "[空]"); // 或者 printf("%s ", arr[i][j] ? "玩家" : "空地"); 等
                }
                printf("\n");
            }
            printf("请输入方向 (w: 上, a: 左, s: 下, d: 右): ");
        } else {
            printf("请输入正确的方向 (w: 上, a: 左, s: 下, d: 右): ");
        }
        scanf(" %c", &command); // 注意前面的空格，用于忽略空白字符

        // 移动的目标坐标
        int newX = x, newY = y;

        // 根据输入更新目标坐标
        switch (command) {
            case 'w': // 上
                newY--;
                break;
            case 'a': // 左
                newX--;
                break;
            case 's': // 下
                newY++;
                break;
            case 'd': // 右
                newX++;
                break;
            default:
                printf("无效的输入，请输入 w, a, s 或 d.\n");
                isError = 1;
            continue;
        }

        // 检查边界
        if (newX < 0 || newX >= COLS || newY < 0 || newY >= ROWS) {
            printf("前面的路 请以后再来探索~\n");
            isError = 1;
        } else {
            arr[y][x] = 0; // 清空原位置
            // 更新位置
            y = newY;
            x = newX; 
            arr[y][x] = 6; // 移动到新位置
            isError = 0;
        }
    }

    return 0;
}
```

- 评分标准:

|分数|注解|
|:-|:-|
|0分|未提交|
|10分|没有按要求 (比如: 面向printf的编程 (只有printf))|
|30分|提交但运行不正确|
|60分|移动逻辑不正确 (比如只能移动一次(初始化位置索引放到了循环内, 导致每次移动都从`[6][6]`重新开始))|
|90分|运行基本正确, 但是缺少必要的注释/代码混乱|
|100分|运行正确, 码风清晰, (非必须-->)有所拓展(例如输入错误就不打印地图/地图样式美化等)|

> 注: 如果无法编译等其他原因, 酌情给分
>
> 依旧的, `arr[长][宽]`和`arr[宽][长]`都一样的!

值得注意的是, 并不是一定需要打印整个地图, 只需要表达清楚你所在的位置即可, 例如下面这种也没有问题(毕竟题目只是要求`打印移动后的结果`)

```C
当前位置(6,6)
请输入wasd控制角色移动: a

当前位置 (5,6)
请输入wasd控制角色移动: q // 退出

// 注: 同样应该有 越界提醒...
```