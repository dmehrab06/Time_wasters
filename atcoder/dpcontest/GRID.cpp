#include <stdio.h>

int main()
{
    int x[3][4] = { 1,  2,  3,  4,
                    5,  6,  7,  8,
                    9, 10, 11, 12};
    int m = 3;
    int n = 4;
    for (int slice = (m+n-2); slice >=0; --slice) {
        printf("Slice %d: ", slice);
        int z1 = slice < n ? 0 : slice - n + 1;
        int z2 = slice < m ? 0 : slice - m + 1;
        for (int j = slice - z2; j >= z1; --j) {
                printf("%d ", x[j][slice - j]);
        }
        printf("\n");
    }
    return 0;
}