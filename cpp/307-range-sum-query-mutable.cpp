class NumArray {
public:
    NumArray(vector<int> nums) {
        BIT.resize(nums.size()+1);
        fill(BIT.begin(),BIT.end(),0);
        for(int i=0;i<nums.size();i++){
            update(i,nums[i]);
        }
    }

    void update(int i, int val) {
        i++;
        int diff = val-sumRange(i-1,i-1);
        while(i<BIT.size()){
            BIT[i]+=(diff);
            i+=lowbit(i);
        }
    }
    int sum(int i){
        int ans=0;
        i++;
        while(i>0){
            ans+=BIT[i];
            i-=lowbit(i);
        }
        return ans;
    }
    int sumRange(int i, int j) {
        return sum(j)-sum(i-1);
    }
private:
    vector<int> BIT;
    int lowbit(int x){
        return x&(-x);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
