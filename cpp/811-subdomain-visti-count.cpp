class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains)
    {
        vector<pair<int, string> > v;
        for (auto& domain : cpdomains) {
            istringstream iss(domain);
            int count;
            iss >> count;
            string d;
            iss >> d;
            v.push_back({ count, d });
        }
        map<string, int> m;
        for (auto& p : v) {
            int count = p.first;
            string domain = p.second;
            m[domain] += count;
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    m[domain.substr(i + 1)] += count;
                }
            }
        }
        vector<string> ans;
        for (auto it : m) {
            string tmp = "";
            tmp = to_string(it.second);
            tmp += " ";
            tmp += it.first;
            ans.push_back(tmp);
        }
        return ans;
    }
};
