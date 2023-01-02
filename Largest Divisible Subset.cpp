Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
  
Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]

vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<int>dp(len,1);
        int maxi=1;
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    if(maxi<dp[i]){
                        maxi=dp[i];
                    }
                }
            }
        }
        int prev=-1;
        vector<int>ans;
        for(int i=len-1;i>=0;i--){
            if(dp[i]==maxi && (prev==-1 || prev%nums[i]==0)){
                ans.push_back(nums[i]);
                maxi-=1;
                prev=nums[i];
            }
        }
        return ans;
    }
