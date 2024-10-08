#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NAME_LEN_MAX 64

// 洗牌函数(玩家1的牌, 玩家2的牌, 玩家3的牌, 地主牌)
void xi_pai(int *n1_p, int *n2_p, int *n3_p, int *dzp);

// 打印牌的函数(玩家1的牌, 玩家2的牌, 玩家3的牌, 玩家1的名字, 玩家2的名字, 玩家3的名字)
void pai_printf(int *n1_p, int *n2_p, int *n3_p, char *n1, char *n2, char *n3);

void xi_pai(int *n1_p, int *n2_p, int *n3_p, int *dzp) {
    // 洗牌: 传入数组, 在函数通过指针进行修改数组.
    // md, 代码要求的图片里面每个人才14张牌, lztm直接写个正规的斗地主.. 先每人17站牌先, 地主牌都给你分好!! (2024-9-24注: 然后我就忘记要写地主牌这回事了qwq...)
    time_t t;
    srand((unsigned)time(&t)); // 使用当前时间值初始化伪随机数种子序列
    int qb[54]; // 暂时存放54张牌
    int j; // 暂时存放伪随机数
    int *p[] = {n1_p, n2_p, n3_p}; // 指针数组

    for (int i = 0; i < 54; i++) { // 开始洗牌
        while (1) {
            j = rand() % 100;// 输出 0 ~ 99 的伪随机数
            if (j < 54) { // 这样子概率应该比 54 以上的 - 50 的概率平衡
                for (int k = 0; k < i; k++) { // 判断该随机数在不在已知中
                    if (qb[k] == j) { // 发现重复
                        goto OUT;
                    }
                }
                qb[i] = j; // 合格
                break;
            } else {
                OUT:
                continue;
            }
        }
    }

    // 传出 玩家牌(分牌于不同数组方便整理什么的)
    for (int i = 0; i < 3; i++) {
        for (int k = (i + 1) * 17 - 1; k >= i * 17; k--) { // k++ 的方法, 哪天写一下试试!(数学问题) 
            *(*(p + i) + k - i * 17) = qb[k]; // 我发现指针真tm nb, 要是写函数怎么能这么短?!
        }
    }

    for (int i = 51, k = 0; i < 54; i++, k++) {
        *(dzp + k) = qb[i];
    }
}

void pai_printf(int *n1_p, int *n2_p, int *n3_p, char *n1, char *n2, char *n3) {
    // 显示牌: 4 * 13 = 52
    // ですから, 0 - 9 方块, 10 - 19 梅花, 20 - 29 红桃, 30 - 39 黑桃,  的 1~10
    // 40-43(J), 44-47(Q), 48-51(K), 52 - 53 大小王; [被JQK背刺了,没有注意到不能直接数字化输出呢!]
    int *p[] = {n1_p, n2_p, n3_p};
    char *name_p[] = {n1, n2, n3};
    int j; // 缓存牌
    printf("方 = 方块,  梅 = 梅花,  红 = 红桃,  黑 = 黑桃\n");

    for (int i = 0; i < 3; i++) {   
        printf("玩家 [%s] 手上的是: ", *(name_p + i));
        for (int k = 0; k < 17; k++) {
            j = *(*(p + i) + k);
            if (j < 10) {
                printf("方%d  ", j + 1);
            } else if (j >= 10 && j < 20) {
                printf("梅%d  ", j - 9);
            } else if (j >= 20 && j < 30) {
                printf("红%d  ", j - 19);
            } else if (j >= 30 && j < 40) {
                printf("黑%d  ", j - 29);
            } else {
                switch (j) {
                    case 40: {
                        printf("方J ");
                        break;
                    }
                    case 41: {
                        printf("梅J ");
                        break;
                    }
                    case 42: {
                        printf("红J ");
                        break;
                    }
                    case 43: {
                        printf("黑J ");
                        break;
                    }
                    case 44: {
                        printf("方Q ");
                        break;
                    }
                    case 45: {
                        printf("梅Q ");
                        break;
                    }
                    case 46: {
                        printf("红Q ");
                        break;
                    }
                    case 47: {
                        printf("黑Q ");
                        break;
                    }
                    case 48: {
                        printf("方K ");
                        break;
                    }
                    case 49: {
                        printf("梅K ");
                        break;
                    }
                    case 50: {
                        printf("红K ");
                        break;
                    }
                    case 51: {
                        printf("黑K ");
                        break;
                    }
                    case 52: {
                        printf("小王 ");
                        break;
                    }
                    case 53: {
                        printf("大王 ");
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
}

int main() {
    // 0. 实现一个洗牌程序。所谓洗牌程序，就是将所有的扑克牌放入一个数组中，要求把数组内的扑克牌顺序随机打乱，然后输出。
    // 这道题需要你进行一些额外的学习，比如既然是洗牌，那就是要求随机打乱一个数组内的所有元素。
    // 这个“随机”如何实现呢？我们可以通过 C 语言 stdlib.h 库的 srand 函数和 rand 函数来实现
    // 那方角、梅花、红桃和黑桃如何表示呢？
    // 你可以使用整数 1~54 来代表扑克的 54 张牌
    // 建议：洗牌、[发牌]、显示分别用独立的函数来封装，实现模块化编程。(发牌我用指针数组更快捏)
    char name_1[NAME_LEN_MAX], name_2[NAME_LEN_MAX], name_3[NAME_LEN_MAX]; // 存放名字
    int name_1p[17], name_2p[17], name_3p[17], di_zu_pai[3]; // 存放牌的编码
    char yes_or_no = '\0';
    // 暂时除支持中文(本机的问题)
    printf("请输入 1号 玩家的名字:");
    scanf("%s", name_1);
    printf("请输入 2号 玩家的名字:");
    scanf("%s", name_2);
    printf("请输入 3号 玩家的名字:");
    scanf("%s", name_3);
    
    while (1) {
        // 觉得要把 \n 处理了
        getchar();
        xi_pai(name_1p, name_2p, name_3p, di_zu_pai); // 洗牌
        pai_printf(name_1p, name_2p, name_3p, name_1, name_2, name_3);
        printf("是否重新洗牌?(y/n):");
        scanf("%c", &yes_or_no);
        if (yes_or_no == 'n') {
            break;
        }
        printf("\n\t---重新洗牌---\n");
    }
    return 0;
}