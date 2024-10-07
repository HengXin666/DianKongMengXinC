# 题目

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

## 答案

- 参考答案1: (老污龟写的)

```C
#include <stdio.h>

int main() {
    char str[1024];
    char *p = str;          // 用于间接寻址
    char *pos[1024] = {0};  // 记录每个单词的地址
    int len = 0;
    int cChar = 0, cWord = 0; // cChar 统计字符数, cWord 统计单词数
    int max = 0, i = 0, j;

    printf("请输入一个英文句子：");
    // 接收输入，顺带统计用户实际输入了多少个字符
    while ((str[len++] = getchar()) != '\n' && len + 1 < 1024)
        ;
    str[len-1] = '\0'; // str[len]存放的是'\n'，将其替换为'\0'

    if (*p != ' ') {
        pos[i++] = p; // 记录第一个单词的地址
        cWord++;
    }

    while (len--) {
        if (*p++ == ' ') {
            // 判断最大字符数
            max = cChar > max ? cChar : max;
            cChar = 0;

            // 到底了，退出循环
            if (*p == '\0') {
                break;
            }

            // 单词数加一
            if (*p != ' ') {
                pos[i++] = p;
                cWord++;
            }
        } else { // 没有else会把空格统计进去
            cChar++;
        }
    }
    max = --cChar > max ? cChar : max; // 最后会算多一个'\0'，所以减去

    // 申请可变长数组，max+1，否则'\0'放不下
    char result[cWord][max+1];

    // 将分割好的单词放进二维数组里
    for (i = 0; i < cWord; i++) {
        for (j = 0; *(pos[i] + j) != ' ' && *(pos[i]+j) != '\0'; j++) {
            result[i][j] = *(pos[i] + j);
        }
        result[i][j] = '\0';
    }

    // 打印结果
    printf("分割结果已存放到result[%d][%d]的二维数组中...\n", cWord, max+1);
    printf("现在依次打印每个单词：\n");
    for (i = 0; i < cWord; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
```

- 参考答案2: (23年7月学C语言时候写的, 现在只是补充了点注释)

```C
#include <stdio.h>

#define MAX 512

int main() {
    printf("请输入一个英文句子:");
    char str[MAX];
    int i = 0, fg = 1 /* 分割段数 */, cd_max = 0 /* 最大长度 */;

    // 读取用户输入, 直到`\n`(回车); 注: 此时句子的结尾是`\n`而不是`0`
    for (; i < MAX; ++i) {
        // 存放
        scanf("%c", &str[i]);
        if (str[i] == '\n') {
            break;
        }
    }

    // 分割
    for (int j = 0, cd = 0; j <= i; ++j) {   
        if (str[j] == ' ') { // 如果是空格, 代表一段内容结束
            if (j - 1 >= 0 && str[j - 1] != ' ') { // 前面没有空格, 我们就算它是分段的第一个点位
                ++fg;                              // 故 分段 += 1
            }
            A: // 节约行数awa!!
            if (cd > cd_max) { // 更新最大长度
                cd_max = cd;
            }
            cd = 0; // 清零长度计数
        } else if (str[j] == '\n') { // 句子结尾
            goto A; // goto 不是最佳实践!
        } else {
            ++cd;
        }
    }

    // 使用C99的变长数组
    char result[fg][cd_max + 1]; // +1 存放'\0'

    // 拷贝内容
    for (int j = 0, n = 0; j < fg; ++j) {
        for (int k = 0; k <= cd_max; ++k) {   
            if (str[n] == '\n' || (((str[n - 1] != ' ' && n - 1 >= 0) && str[n] == ' ') || k == cd_max)) {
                result[j][k] = '\0';
                break;
            } else {
                while (str[n] == ' ') {
                    ++n;
                }
                result[j][k] = str[n];
            }
            ++n;
        }
        ++n;
    }
    printf("分割结果已存放到result[%d][%d]的二维数组中...\n", fg, cd_max + 1);
    printf("现在依次打印每个单词:\n");

    // 打印结果
    for (int j = 0; j < fg; ++j) {
        printf("%s\n", result[j]);
    }
    return 0;
}
```

- 评分标准:

|分数|注解|
|:-|:-|
|0分|未提交|
|10分|没有按要求 (比如: 面向printf的编程 (只有printf))|
|30分|提交但运行不正确, (主要在于提交了)|
|40分|使用了`malloc`(属于没有按要求, 但是如果运行没问题, 则为此分)|
|60分|运行大致没问题, 但是使用了非`stdio.h`文件的库, 且 **不支持** 区分多空格|
|70分|运行大致没问题, 但是使用了非`stdio.h`文件的库|
|80分|运行大致没问题, 但是 **不支持** 区分多空格|
|90分|运行正确, 但是没有注释|
|100分|运行正确, 有基本的注释, 代码风格统一|

> 注: 如果无法编译等其他原因, 酌情给分

> [!TIP]
> 注意细节: 需要输出`result[%d][%d]`这个提示; 其中`result[%d][%d]`是定义数组时候的大小
>
> 例如: `char result[%d][%d] = {"1", "2", "3"};`
>
> 那么`result[%d][%d]`应该是`result[3][2]`
>
> - 3 是因为这个是定义数组时候的大小
> - 2 是因为一个`字符` + 一个`'\0'`
>
> 没写是多大扣10分, 写错扣5分.