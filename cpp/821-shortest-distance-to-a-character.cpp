class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> dis(S.size(),0);
        vector<int> location;
        for(int i=0;i<S.size();i++){
            if(S[i]==C) location.push_back(i);
        }
        for(int i=0;i<S.size();i++){
            if(S[i]!=C){
                auto it = upper_bound(location.begin(),location.end(),i);
                if(it==location.begin()){
                    dis[i] = *it - i;
                }else if(it==location.end()){
                    dis[i] = i - *(--it);
                }else {
                    auto prev = it;
                    prev--;
                    dis[i] = min(*it-i,i-*(prev));
                }
            }
        }
        return dis;
    }
};
