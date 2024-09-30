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