# 题目
## 练习
- 练习: 使用函数实现, 动态分配内存给结构体(指针)变量, 及其释放

> 略

## 作业
- 张三最近被`黑神话: 悟空`虐爆了! 因为他真的非常的菜! (真不知道他是怎么成为法外狂徒的!); 但是他依旧为了展示他的实力, 需要记录打过的Boss的名称以及失败的次数; 但是非常不凑巧的是, 某些Boss有二阶段, 他希望可以区分一个Boss是在第一个阶段被虐的多还是第二阶段; 可是非常不巧的是, 张三是一个垃圾佬(电脑是捡垃圾组装的), 因此内存十分的小!
    
    - 而我的朋友, 你(请假装你是李四, 是C语言大佬!)今天的任务就是帮助张三, 以展示他的实力! 你精心为他设计了一个超级节约内存的C语言程序--内置两种结构体, 通过malloc动态内存分配的超级无敌世吞mk-2.exe

    - 其包含以下功能:
        1. 内置两种结构体 (分别存放了: `{Boss名称, 被虐次数}`, `{Boss名称, 一阶段被虐次数, 二阶段被虐次数}`)

        2. 只能存储一只的Boss数据, 如果张三打到下一只, 那么就 **不需要** 这些数据了, 请**清空**!

        3. 打印函数, 打印当前Boss, 张三被虐的次数

        4. 显而易见的录入函数

        5. ~~一身破烂, 难怪登门 (李四的设计也太鸡肋了吧...)~~

## 答案

- 参考答案1:

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // 请保证当前操作系统为windows (非必要头文件)

// BossType
#define SINGLE 1
#define MULTI 2

#define NAME_MAX_LEN 128

// 只有一个阶段的boss信息
struct SingleStageBoss {
    char* bossName;
    int defeatedCount;
};

// 有俩个阶段的boss信息
struct MultiStageBoss {
    char* bossName;
    int stage1DefeatedCount;
    int stage2DefeatedCount;
};

// 使用一个辅助结构体, 存放Boss信息
// 通过type判断结构体的`data`字段是哪种类型, 然后进行处理 (PS: 有点像多态 (只是有点..))
struct Boss {
    void *data;
    int type;
};

void startBoss(struct Boss *boss) {
    char name[NAME_MAX_LEN] = {0};
    int stages = 0, nameStrLen = 0;

    printf("请问Boss的名称: ");
    scanf("%s", name);
    printf("请问Boss有几个阶段(1 ~ 2): ");
    scanf("%d", &stages);

    nameStrLen = strlen(name);

    // 根据 名称的长度, 动态分配恰好的字符数组的长度
    // 并且将局部的`name`拷贝到字符数组内, 然后初始化结构体对应的字段
    if (stages == 1) {
        boss->data = malloc(sizeof(struct SingleStageBoss));
        boss->type = SINGLE;
        struct SingleStageBoss *singleBoss = (struct SingleStageBoss *)boss->data;
        singleBoss->bossName = (char *)malloc((nameStrLen + 1) * sizeof(char));
        strcpy(singleBoss->bossName, name);
        singleBoss->defeatedCount = 0;
    } else if (stages == 2) {
        boss->data = malloc(sizeof(struct MultiStageBoss));
        boss->type = MULTI;
        struct MultiStageBoss *multiBoss = (struct MultiStageBoss *)boss->data;
        multiBoss->bossName = (char *)malloc((nameStrLen + 1) * sizeof(char));
        strcpy(multiBoss->bossName, name);
        multiBoss->stage1DefeatedCount = 0;
        multiBoss->stage2DefeatedCount = 0;
    } else {
        printf("\n无效的阶段!\n");
    }
}

void defeatedBoss(struct Boss *boss) {
    if (boss->type == SINGLE) {
        struct SingleStageBoss *singleBoss = (struct SingleStageBoss *)boss->data;
        ++singleBoss->defeatedCount;
        printf("\n猴头留着下酒, 剩下的交给大王~\n");
    } else if (boss->type == MULTI) {
        int stage = 0;
        printf("\n请问在第几阶段击败的(1 ~ 2): ");
        scanf("%d", &stage);
        struct MultiStageBoss *multiBoss = (struct MultiStageBoss *)boss->data;
        if (stage == 1) {
            ++multiBoss->stage1DefeatedCount;
            printf("\n六丁六甲, 从不吃素!\n");
        } else if (stage == 2) {
            ++multiBoss->stage2DefeatedCount;
            printf("\n朽木不可雕也!\n");
        } else {
            printf("\n无效的阶段!\n");
        }
    }
}

void printRecord(struct Boss *boss) {
    if (boss->type == SINGLE) {
        struct SingleStageBoss *singleBoss = (struct SingleStageBoss *)boss->data;
        printf("Boss名称: %s\n", singleBoss->bossName);
        printf("被虐次数: %d 次\n", singleBoss->defeatedCount);
    } else if (boss->type == MULTI) {
        struct MultiStageBoss *multiBoss = (struct MultiStageBoss *)boss->data;
        printf("Boss名称: %s\n", multiBoss->bossName);
        printf("一阶段被虐次数: %d 次\n", multiBoss->stage1DefeatedCount);
        printf("二阶段被虐次数: %d 次\n", multiBoss->stage2DefeatedCount);
    }
}

void clearBoss(struct Boss *boss) {
    if (boss->data) {
        // 释放 分配的字符数组
        // 因为 在结构体 SingleStageBoss, MultiStageBoss 中, bossName 类型都是一样的, 并且在第一个字段
        // 因此可以直接`((struct SingleStageBoss *)boss->data)->bossName`访问
        free(((struct SingleStageBoss *)boss->data)->bossName);

        // 释放整个`boss->data`指针指向的内存
        free(boss->data);
        boss->data = NULL;
        boss->type = 0;
    }
}

void printMenu() {
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("a. 我要开始打Boss了\n");
    printf("b. 被Boss击败了\n");
    printf("c. 击败这个Boss了\n");
    printf("p. 查看战绩\n");
    printf("请选择: ");
}

int main() {
    struct Boss boss = {NULL, SINGLE};
    char choice;

    while (1) {
        printMenu();
        scanf(" %c", &choice);

        switch (choice) {
        case 'a': // 我要开始打Boss了
            clearBoss(&boss);
            startBoss(&boss);
            break;
        case 'b': // 被Boss击败了
            if (boss.data) {
                defeatedBoss(&boss);
            } else {
                printf("\n请先开始打Boss!\n");
            }
            break;
        case 'c': // 击败这个Boss了
            if (boss.data) {
                printf("\n满城百姓, 感谢不尽!\n");
                clearBoss(&boss);
            } else {
                printf("\n请先开始打Boss!\n");
            }
            break;
        case 'p': // 查看战绩
            if (boss.data) {
                printRecord(&boss);
            } else {
                printf("\n请先开始打Boss!\n");
            }
            break;
        default:
            printf("\n无效选择!\n");
            break;
        }

        Sleep(500); // 需要 <windows.h> 头文件 (只是为了美化输出)
                    // 阻塞 500 ms
    }

    clearBoss(&boss);
    return 0;
}
```

- 评分标准:

|分数|注解|
|:-|:-|
|0分|未提交|
|30分|提交但运行不正确, (主要在于提交了)|
|50分|运行基本正确, 但是没有动态内存分配|
|60分|运行基本正确, 但是没有使用两个结构体|
|80分|运行基本正确, 但是忘记(懒得)释放内存|
|90分|运行正确, 但是没有注释/代码叙利亚风格|
|100分|运行正确, 有基本的注释, 代码风格统一, 并且按照要求使用了两个结构体; 且使用了动态内存分配进行存储Boss名称; 并且没有内存泄漏|

> 对于节约内存, 实际上按照题目的要求实现的话, 也节约不了多少...
>
> 如果使用了动态内存分配进行存储Boss名称, 可以在当前分数上 + 10 分 (如果没有90分的话, 总分不超过100)
>
> 其他问题, 酌情给分.