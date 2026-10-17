class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(n>m){
            return "";
        }
        unordered_map<char,int>mpp;
        for(int i=0; i<n; i++){
            mpp[t[i]]++;
        }
        string ans;
        int minlen=m+1;
        int l=0;
        int r=0;
        int cnt=0;
        int start=-1;
        while(r<m){
            if(mpp[s[r]]>0){
                cnt++;
            }
            mpp[s[r]]--;
            while(cnt==n){
                if(minlen>r-l+1){
                    minlen=r-l+1;
                    start=l;
                }
                 mpp[s[l]]++;
                 if(mpp[s[l]]>0) cnt--;
                 l++;
            }
           r++;
        }
        if(start==-1) return ans;
        ans=s.substr(start,minlen);
        return ans;
    }
};