class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        int ans=0;
        unordered_map<char,int>mpp;
        while(r<n){
            if(mpp.find(s[r])!=mpp.end() && l<=mpp[s[r]]){
                l=mpp[s[r]];
                l++;
                mpp[s[r]]=r;
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                ans=max(ans,r-l+1);
                mpp[s[r]]=r;
                r++;
            }
        }
        return ans;
    }
};