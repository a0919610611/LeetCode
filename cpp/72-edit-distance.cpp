class Solution {
public:
    int minDistance(string word1, string word2)
    {
        str1 = word1;
        str2 = word2;
        dp = vector<vector<int> >(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return solve(word1.size(), word2.size());
    }

private:
    vector<vector<int> > dp;
    string str1, str2;
    int solve(int s1, int s2)
    {
        if (dp[s1][s2] != -1)
            return dp[s1][s2];
        int ans = 0;
        if (s1 == 0)
            return dp[s1][s2] = s2;
        else if (s2 == 0)
            return dp[s1][s2] = s1;
        if (str1[s1 - 1] == str2[s2 - 1])
            return dp[s1][s2] = solve(s1 - 1, s2 - 1);
        ans = 1 + solve(s1 - 1, s2);
        ans = min(ans, 1 + solve(s1, s2 - 1));
        ans = min(ans, 1 + solve(s1 - 1, s2 - 1));
        dp[s1][s2] = ans;
        return dp[s1][s2];
    }
};
