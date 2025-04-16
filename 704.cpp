//704. Binary Search
//Given an array of integers "nums" which is sorted in ascending order, and an integer "target", write a function to search "target" in nums. 
//If "target" exists, then return its index. Otherwise, return "-1".
//You must write an algorithm with 'O(log n)' runtime complexity.

int search(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (target > nums[middle]) {
			left = middle + 1;
		}
		else if (target < nums[middle]) {
			right = middle - 1;
		}
		else
			return middle;
	}
	return -1;
}


/*
//左閉右闭区间 [left, right]
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int middle = 0;
    //若left小于等于right，说明区间中元素不为0
    while (left <= right) {
        //更新查找下标middle的值
        middle = (left + right) / 2;
        //此时target可能会在[left,middle-1]区间中
        if (nums[middle] > target) {
            right = middle - 1;
        }
        //此时target可能会在[middle+1,right]区间中
        else if (nums[middle] < target) {
            left = middle + 1;
        }
        //当前下标元素等于target值时，返回middle
        else if (nums[middle] == target) {
            return middle;
        }
    }
    //若未找到target元素，返回-1
    return -1;
}
*/