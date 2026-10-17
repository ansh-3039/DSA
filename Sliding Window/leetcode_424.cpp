class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        int l=0;
        int r=0;
        int maxlen=0;
        unordered_map<char,int>mpp;
        int mfreq=0;
        while(r<n){
            mpp[s[r]]++;
            mfreq=max(mpp[s[r]],mfreq);
            int len=r-l+1;
            if(len-mfreq<=k){
                maxlen=max(maxlen,len);
            }
            else{
                while((len-mfreq)>k && l<n){
                    mpp[s[l]]--;
                    mfreq=0;
                    for(auto it:mpp){
                        mfreq=max(mfreq,it.second);
                    }
                    l++;
                    len=r-l+1;
                }
            }
            r++;
        }
        return maxlen;
    }
};