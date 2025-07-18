class Solution {
public:

bool solve(int i,vector<int>&nums,vector<int>&dp){

if(i>=nums.size()-1){
return 1;
}
if(dp[i]!=-1){
    return dp[i];
}
if(i!=nums.size()-1 and nums[i]==0){
    return dp[i]=0;
}

for(int j=nums[i];j>=1;j--){
 if(solve(i+j,nums,dp)){
     return dp[i]= 1;
 }
}

return dp[i]=0;
}

    bool canJump(vector<int>& nums) {
      int n=nums.size();
      vector<int>dp(n+1,-1);
      return solve(0,nums,dp); 
    }
};