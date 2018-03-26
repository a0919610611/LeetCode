class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int index=  -1;
        for(int i=0;i+1<nums.size();i++){
            if(nums[i]>nums[i+1]) {
                if(index !=-1) return false;
                index = i ;
            }
        }
        if(index==-1) return true;
        if(index == 0 || index == nums.size()-2) return true;
        if(nums[index-1] <= nums[index+1]) return true;
        if(nums[index] <=nums[index+2]) return true;
        return false;
    }

};
