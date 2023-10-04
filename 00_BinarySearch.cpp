int bst(vector<int> &nums, int target, int left, int right)
{
    int mid = (left + right)/2;

    if(nums[mid] == target)
        return mid;
    if(left > right)
    {
        return -1;
    }
    if(nums[mid] < target)
    {
        return bst(nums, target, mid + 1, right);
    }
    else{
        return bst(nums, target, left, mid-1);
    }
}

int search(vector<int> &nums, int target) {
    // Write your code here.
    return bst(nums, target, 0, nums.size() - 1);
}
