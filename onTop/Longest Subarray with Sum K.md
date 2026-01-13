```c
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mapp; 
        mapp[0]=-1; // 
        int sum = 0 , ans = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(mapp.find(sum-k)!=mapp.end()){
                ans = max(ans , i-mapp[sum-k]);
            }
            if (mapp.find(sum) == mapp.end()) { // small index stored
                mapp[sum] = i;
            }
        }
        return ans ;
    }
};
```
