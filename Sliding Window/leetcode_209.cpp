class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int l=0;
        int r=0;
        int n=nums.length;
        int sum=0;
        int ans=n+1;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                ans=Math.min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(ans==n+1) return 0;
        return ans;
    }
}