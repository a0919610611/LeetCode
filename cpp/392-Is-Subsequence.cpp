class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx_s = 0;
        if(s=="") return true;
        for(int i=0;i<t.size();i++){
            if(t[i]==s[idx_s]){
                idx_s++;
                if(idx_s ==s.size()) return true;
            }
        }
        return false;
    }
};
