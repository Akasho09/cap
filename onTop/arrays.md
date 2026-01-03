## rotate
- Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
> reverse the full array,  then upto k the k->n-1;
```c
class Solution {
public:
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k%n ;

    reverse(nums.begin(), nums.end());

    int s = 0 ;
    int e = k-1 ;
    while(s<e){
        swap(nums[s],nums[e]); s++; e--;
    }
    
     s = k ;
     e = n-1 ;
    while(s<e){
        swap(nums[s],nums[e]); s++; e--;
    }

    }
};
```

## Remove Duplicates
```c
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1 ;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};
```
