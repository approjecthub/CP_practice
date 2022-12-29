// https://leetcode.com/problems/single-element-in-a-sorted-array/

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        int prevElement = (mid - 1) >= 0 ? nums[mid - 1] : -1;
        int nextElement = (mid + 1) < n ? nums[mid + 1] : -1;

        if (nums[mid] != prevElement && nums[mid] != nextElement)
        {
            return nums[mid];
        }
        else if (nums[mid] == prevElement)//current value is same as previous
        {
            if ((mid - l + 1) % 2 == 0)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 2;
            }
        }
        else//current value is same as next
        {
            if ((mid - l) % 2 == 0)
            {
                l = mid + 2;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return -1;
}