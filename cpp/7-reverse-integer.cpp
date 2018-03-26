class Solution {
public:
    int reverse(int x) {
        bool minus = (x<0);
        int value = abs(x);
        long long  ans = 0;
        while(value > 0){
            ans = ans *10 + value %10;
            if(ans > INT_MAX) return 0;
            value/=10;
        }
        return minus?-ans:ans;
    }
};
