class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        string ans = "";
        vector<string> strs;
        for (int& num : nums) {
            // to_string(num);
            strs.push_back(intToString(num));
        }
        sort(strs.begin(), strs.end(), [](string& s1, string& s2) { return s1 + s2 > s2 + s1; });
        string first = "";
        for (string& s : strs) {
            if (first == "0" && s == "0")
                break;
            if (first == "")
                first = s;
            ans += s;
        }
        return ans;
    }

private:
    string intToString(int& num)
    {
        stringstream ss;
        string ans = "";
        ss << num;
        ss >> ans;
        return ans;
    }
};
