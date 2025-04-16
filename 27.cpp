//27. Remove Element
//Given an integer array "nums" and an integer "val", remove all occurrences of "val" in nums in-place. The order of the elements may be changed. 
//Then return the number of elements in "nums" which are not equal to "val".
//Consider the number of elements in "nums" which are not equal to "val" be "k", to get accepted, you need to do the following things :
//Change the array "nums" such that the first "k" elements of "nums" contain the elements which are not equal to "val".
//The remaining elements of "nums" are not important as well as the size of "nums".
//Return "k".

// 時間複雜度：O(n^2)
// 空間複雜度：O(1)
int removeElement(int* nums, int numsSize, int val) {
    for (int i = 0; i < numsSize; i++) {
        int f = i;
        if (val == nums[i]) {
            while (f < numsSize - 1) {
                nums[f] = nums[f + 1];
                f++;
            }
            i--;
            numsSize--;
        }
    }
    return numsSize;
}

int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // k 指向下一個有效元素的位置

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) { // 只保留不等於 val 的數字
            nums[k] = nums[i];
            k++; // 只有當元素保留下來時才遞增 k
        }
    }

    return k; // 返回新的陣列大小
}