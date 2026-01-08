## 🔑 Memory Trick
- S-M-A-R-T
    - Sorted
    - Monotonic
    - Access (random)
    - Repeatable comparison
    - Time reduction by half

## First and Last Occuremce
```c
class Solution {
public:
int findFirst(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            ans = mid;
            high = mid - 1;   // move left
        }
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int findLast(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            ans = mid;
            low = mid + 1;    // move right
        }
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);

        result[0] = findFirst(nums, target);
        if (result[0] == -1) return result;   // target not found

        result[1] = findLast(nums, target);
        return result;
    }
};
```

## 