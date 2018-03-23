class Solution {
public:
    int arrayPairSum(vector<int>& nums)
    {
        vector<int> Num = nums;
        sort(Num.begin(), Num.end());
        int ans = 0;
        for (int i = 0; i < Num.size(); i += 2) {
            ans += Num[i];
        }
        return ans;
    }
};
