class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        unordered_map<char, int> mpp,mp;
        for (int i = 0; i < n1; i++) {
            mpp[s1[i]]++;
        }
        mp=mpp;
        int l = 0;
        int r = 0;
        int cnt = 0;
        while (r < n2) {
            if (mpp.find(s2[r]) != mpp.end()) {
                mpp[s2[r]]--;
                cnt++;
                while (mpp[s2[r]] < 0) {
                    mpp[s2[l]]++;
                    cnt--;
                    l++;
                }
            } else {
                l=r+1;
                cnt=0;
                mpp=mp;
            }
            if (cnt == n1 && r - l + 1 == n1) {
                return true;
            }
            r++;
        }
        return false;
    }
};