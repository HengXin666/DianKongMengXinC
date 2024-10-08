#include <stdio.h>
#include <stdlib.h>

int** createStairArray(int n, int m) {
    // 创建指针数组
    int** arr = (int**)malloc(n * sizeof(int*));
    // 为每一行分配相应的列, 最多为 m 列
    for (int i = 0; i < n; ++i) {
        arr[i] = (int*)malloc((i < m ? i + 1 : m) * sizeof(int));
    }
    return arr;
}

void freeStairArray(int** arr, int n) {
    for (int i = 0; i < n; ++i) {
        free(arr[i]); // 释放每一行的内存
    }
    free(arr); // 释放指针数组
}

void printStairArray(int** arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (i < m ? i + 1 : m); ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // n * m = 长 * 宽, n >= m
    int n = 6; // 行数
    int m = 3; // 最大列数
    int** stairArray = createStairArray(n, m);

    // 填充数组 (示例填充为行号和列号的和)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (i < m ? i + 1 : m); ++j) {
            stairArray[i][j] = i + j;
        }
    }

    // 打印数组
    printStairArray(stairArray, n, m);

    // 释放内存
    freeStairArray(stairArray, n);
    return 0;
}
