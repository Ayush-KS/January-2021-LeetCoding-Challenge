// Kth Largest Element in an Array

class Solution {
public:
    
    int helper(vector<int>& nums, int k, int i, int j) {
        if(i > j)
            return -1;
        int pivot = nums[i];
        swap(nums[i], nums[j]);
        int tempi = i;
        int tempj = i;
        while(tempj < j) {
            if(nums[tempj] < pivot) {
                swap(nums[tempj], nums[tempi]);
                tempi++;
            }
            tempj++;
        }
        swap(nums[tempi], nums[j]);
        if(nums.size() - tempi == k)
            return nums[tempi];
        else if(nums.size() - tempi > k)
            return helper(nums, k, tempi + 1, j);
        else
            return helper(nums, k, i, tempi - 1);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, k, 0, nums.size() - 1);
    }
};