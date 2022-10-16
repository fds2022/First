#include <stdlib.h>
#include <stdio.h>
void foo(int **arr, int m, int n)
{
    int i,j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int **alloc_2d(int m, int n)
{
	int **arr;
    arr = (int**) malloc(m * sizeof(int));
    int i;
    for (i = 0; i < m; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    return arr;
}

int main()
{
    int **joe = alloc_2d(2, 3);
    joe[0][0] = 1;
    joe[0][1] = 2;
    joe[0][2] = 3;
    joe[1][0] = 4;
    joe[1][1] = 5;
    joe[1][2] = 6;
    foo(joe,2,3);
    return 0;
}
