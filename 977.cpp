//977
//Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    if (!result) return NULL; // malloc 失敗時返回 NULL
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i] * nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        int min = i;
        for (int j = i + 1; j < numsSize; j++) {
            if (result[j] < result[min]) {
                min = j;
            }
        }
        int temp = result[min];
        result[min] = result[i];
        result[i] = temp;
    }
    *returnSize = numsSize;
    return result;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    if (!result) return NULL; // malloc 失敗時返回 NULL
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i] * nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        int temp = result[i];
        int j = i - 1;
        while (j >= 0 && temp < result[j]) {
            result[j + 1] = result[j];
            j--;
            if (j == -1) {
                break;
            }
        }
        result[j + 1] = temp;
    }
    *returnSize = numsSize;
    return result;
}



/* 插入排序 */
void insertionSort(int nums[], int size) {
    // 外迴圈：已排序區間為 [0, i-1]
    for (int i = 1; i < size; i++) {
        int base = nums[i], j = i - 1;
        // 內迴圈：將 base 插入到已排序區間 [0, i-1] 中的正確位置
        while (j >= 0 && nums[j] > base) {
            // 將 nums[j] 向右移動一位
            nums[j + 1] = nums[j];
            j--;
        }
        // 將 base 賦值到正確位置
        nums[j + 1] = base;
    }
}


int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    if (!result) return NULL; // malloc 失敗時返回 NULL

    int left = 0, right = numsSize - 1;
    int pos = numsSize - 1; // 從陣列尾部填入最大平方值

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[pos] = leftSquare;
            left++;
        }
        else {
            result[pos] = rightSquare;
            right--;
        }
        pos--; // 向前填充
    }

    *returnSize = numsSize;
    return result;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    if (!result) return NULL; // malloc 失敗時返回 NULL
    int left = 0, right = numsSize - 1, i = numsSize - 1;
    while (left <= right) {
        if (nums[left] * nums[left] > nums[right] * nums[right]) {
            result[i] = nums[left] * nums[left];
            left++;
        }
        else {
            result[i] = nums[right] * nums[right];
            right--;
        }
        i--;
    }
    *returnSize = numsSize;
    return result;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result;
    *returnSize = numsSize;
    result = (int*)malloc(*returnSize * sizeof(int));
    if (!result)
        return NULL;
    int left = 0, right = numsSize - 1;
    int index = numsSize - 1;
    while (left <= right) {
        int leftsq = nums[left] * nums[left];
        int rightsq = nums[right] * nums[right];
        if (leftsq > rightsq) {
            result[index] = leftsq;
            index--;
            left++;
        }
        else {
            result[index] = rightsq;
            index--;
            right--;
        }
    }
    return result;
}