class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K)
    {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                dp[i][j] = 0;
            }
        }
        return go(A, 0, K);
    }
    double go(vector<int>& A, int now, int remain)
    {
        if (now >= A.size())
            return 0;
        double& ans = dp[now][remain];
        if (ans > 0)
            return ans;
        double sum = 0;
        int cnt = 0;
        if (remain == 1) {
            for (int i = now; i < A.size(); i++) {
                sum += A[i];
                cnt++;
            }
            ans = sum / cnt;
        } else {
            for (int i = now; i < A.size(); i++) {
                sum += A[i];
                cnt++;
                ans = max(ans, sum / cnt + go(A, i + 1, remain - 1));
            }
        }
        return ans;
    }

private:
    double dp[100][100];
};
