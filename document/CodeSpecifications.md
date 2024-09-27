# 代码规范指北 -- 以 C 语言为例
> 待更新

![来源于网络, 本项目只用于教学目的, 侵权联系删除~](document\img\zhihu_20240511_161619.png)

## 0x00 整体代码

- 代码不需要一行一行的写注释, 只需要写清楚作用即可!
    - 清楚的变量命名, 是最好的注释! (因为注释也可能会骗人(因为年久失修, 改了代码却没人维护注释), 但代码不会!)

```C
// 代码开头导入头文件
// 最上面的应该是标准库文件
#include <stdio.h>
#include <stdlib.h>

// 空一行, 再写自定义的库文件
#include "xxx.h"
#include <yyy/zzz.h>

// 往下才是宏定义, PS: 宏的命名规范是, 全大写, 使用下划线分割
#define PI 3.14

// 然后是结构体, 命名规范是, 大写字母开头, 然后驼峰命名
struct Node {
    struct Node* next; // 成员命名一般是: `m_next`, `_next`, `next_`这种
    int data;
};

struct _TreeNode { // 如果某个东西是内部使用的, 请在前面加上`_`, 标识这个是内部使用的(所有命名规范都适用)

};

// 自定义函数的声明, 一般在函数声明处编写函数文档:
/**
 * @brief 函数说明 (如: 申请一段长度为`len`的`int`数组)
 * @param arr [in, out] 传入传出参数 (注: 如果是传出参数, 可以加上`[out]`表示)
 * @param len 数组长度
 * @return 错误码 (小于0, 即为错误)
 */
int newArr(int** arr, int len); // 命名也可以为 new_arr
                                // 函数和变量的命名规范都是: 首字母小写 + (下划线 / 驼峰命名) 

// 函数实现
int newArr(int** arr, int len) {
    *arr = (int *)malloc(len * sizeof(int));
    if (!*arr) { // 申请失败
        return -1;
    }
    return 0;
}

int main() {
    int* arr = NULL;
    int n = 10; // 数组长度
    
    if (newArr(&arr, n) < 0) {
        return -1;
    }
    
    // 往数组装平方数, 并且打印
    for (int i = 0; i < n; ++i) {
        arr[i] = i * i;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    // TODO@Heng_Xin: 这里没有释放内存!!!
    // 注: 使用`TODO`可以标识这里是一个临时方案, 之后会改
    // @Heng_Xin 就是说明这个是誰写在这里的, 一般留下邮箱或者名字, 方便找负责人
    return 0;
}
```