//59. Spiral Matrix II
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    int loop = n / 2;
    int x = 0, y = 0, count = 1, offset = 1;
    int** array = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        array[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    while (loop--) {
        for (int j = y; j < n - offset; j++) {
            array[x][j] = count;
            count++;
            y = j + 1;
        }
        for (int i = x; i < n - offset; i++) {
            array[i][y] = count;
            count++;
            x = i + 1;
        }
        for (int j = y; j >= offset; j--) {
            array[x][j] = count;
            count++;
            y = j - 1;
        }
        for (int i = x; i >= offset; i--) {
            array[i][y] = count;
            count++;
            x = i - 1;
        }
        x = x + 1;
        y = y + 1;
        offset += 1;
    }
    if (n % 2 == 1) {
        array[n / 2][n / 2] = n * n;
    }
    return array;
}