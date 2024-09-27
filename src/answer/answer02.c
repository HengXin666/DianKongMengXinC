#include <stdio.h>

int main() {
    int p = 0, q = 0; 

    printf("请输入p和q: ");
    scanf("%d %d", &p, &q);

    printf("\n这个是 %d * %d 的余数表\n", p, q);
    for (int i = 1; i <= p; ++i) {
        if (!(i % 6)) // i % 6 == 0
            continue;
        _Bool tag = 0; // 用于控制 , 号
        for (int j = 1; j <= i && j <= q; ++j) {
            if (!(j % 6)) // j % 6 == 0
                continue;
            if (tag) {
                printf(", %d ÷ %d = %d ... %d", i, j, i / j, i % j);
            } else {
                printf("%d ÷ %d = %d ... %d", i, j, i / j, i % j);
                tag = 1;
            }
        }
        putchar('\n');
    }
    return 0;
}