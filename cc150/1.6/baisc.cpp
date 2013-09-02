#include <stdio.h>
#include <stdlib.h>


void fill_matrix(int *s, int row, int col)
{
    int v = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *(s + i * col + j) = ++v;
        }
    }
}

void print_matrix(int *s, int row, int col)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d\t", *(s + i * col + j));
        }
        printf("\n");
    }
}

int *rotate_90_degree(int *s, int row, int col)
{
    int *t = (int *)malloc(sizeof(int) * (row * col));
    int nrow = col, ncol = row;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int newi = j;
            int newj = ncol - i - 1;
            *(t + newi * ncol + newj) = *(s + i * col + j);
            //*(t + j * ncol+ ncol - i - 1) = *(s + i * col + j);
        }
    }
    return (int *)t;
}

/*
void move_element(int *s, int i, int j, int len)
{
    int newi = j;
    int newj = len - i - 1;
    if (newi == 0 && newj == 0) {
        *s = *(s + i * len + j);
        return;
    }

    int tmp = *(s + i * len + j);
    move_element(s, newi, newj, len);
    *(s + newi * len + newj) = tmp;
}

int *rotate_90_degree2(int *s, int len)
{
    move_element(s, 0, 0, len);
    return (int *)s;
}
*/

int *rotate_90_degree2(int *s, int len)
{
    for (int layer = 0; layer < len/2; ++layer) {
        int offset = layer;
        int layerLen = len - layer*2;
        for (int i = 0; i < layerLen-1; ++i) {
            int topIndex = (i + offset) + offset * len;
            //printf("top x:%d, y:%d\n", (i + offset), offset);
            int rightIndex = (len - 1 - offset) + (offset + i) * len;
            //printf("right x:%d, y:%d\n", (len - 1 - offset), offset + i);
            int bottomIndex = (len - 1 - offset - i) + (len - 1 - offset) * len;
            //printf("bottom x:%d, y:%d\n", (len - 1 - offset - i), (len - 1 - offset));
            int leftIndex = offset + (len - 1 - offset - i) * len;
            //printf("left x:%d, y:%d\n", offset, (len - 1 - offset - i));
            int tmp = *(s+topIndex);
            *(s+topIndex) = *(s+leftIndex);
            *(s+leftIndex) = *(s+bottomIndex);
            *(s+bottomIndex) = *(s+rightIndex);
            *(s+rightIndex) = tmp;
        }
    }
    return (int *)s;
}

int main() {

    int m[5][5];
    fill_matrix((int *)m, 5, 5);

    printf("original matrix: m\n");
    print_matrix((int *)m, 5, 5);

    int *ret = rotate_90_degree((int *)m, 5, 5);

    printf("rotated matrix: ret\n");
    print_matrix(ret, 5, 5);

    int *ret2 = rotate_90_degree2((int *)m, 5);

    printf("rotated matrix: ret2\n");
    print_matrix(ret2, 5, 5);

    return 0;
}
