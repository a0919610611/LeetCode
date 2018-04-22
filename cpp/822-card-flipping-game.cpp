class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ans = INT_MAX;
        vector<bool> cant(2001,false);
        int size = fronts.size();
        for(int i=0;i<size;i++){
            if(fronts[i]==backs[i]) cant[fronts[i]] = true;
        }
        for(int i=0;i<size;i++){
            if(!cant[fronts[i]]) ans=min(ans,fronts[i]);
            if(!cant[backs[i]]) ans =min(ans,backs[i]);
        }
        return ans==INT_MAX?0:ans;
    }
};
