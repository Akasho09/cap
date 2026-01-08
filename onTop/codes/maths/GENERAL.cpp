#include <iostream>
using namespace std ;


class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            // 2nd condition taken careoff by input alredy
            // bcz 8 cant be 1st digit then input>INT_MAX
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;

            rev = rev * 10 + digit;
        }
        
        return rev;
    }
};


class Solution {
public:
 int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        int ans = 0;
        unordered_map<int , int > preMap ;
        preMap[0] = 1; // Important: base case for subarray starting at index 0

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            if(preMap.find(sum-k)!=preMap.end()) ans += preMap[sum - k];

            preMap[sum]++;

        }
        return ans ;
    }
};