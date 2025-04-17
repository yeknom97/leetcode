//209. Minimum Size Subarray Sum
//Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target.
// If there is no such subarray, return 0 instead.
/*
int minSubArrayLen(int target, int* nums, int numsSize) {
    int subsum = 0, result = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            if (sum == target) {
                subsum = j - i + 1;
                if (subsum > 0 && subsum < result) {
                    result = subsum;
                }
            }
        }
    }
    if (result != INT_MAX) {
        return result;
    }
    else
        return 0;
}
*/

//滑動窗口
int minSubArrayLen(int target, int* nums, int numsSize) {
    //初始化最小长度为INT_MAX
    int minLength = INT_MAX;
    int sum = 0;

    int left = 0, right = 0;
    //右边界向右扩展
    for (; right < numsSize; ++right) {
        sum += nums[right];
        //当sum的值大于等于target时，保存长度，并且收缩左边界
        while (sum >= target) {
            int subLength = right - left + 1;
            minLength = minLength < subLength ? minLength : subLength;
            sum -= nums[left++];
        }
    }
    //若minLength不为INT_MAX，则返回minLnegth
    return minLength == INT_MAX ? 0 : minLength;
}