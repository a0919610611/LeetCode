vector<int> Edge[500];
bool isSource[500];
bool isTarget[500];
int dis[500];
class Solution {
public:
    int numBusesToDestination(vector<vector<int> >& routes, int S, int T)
    {
        if (S == T)
            return 0;
        for (int i = 0; i < 500; i++) {
            Edge[i].clear();
            isSource[i] = isTarget[i] = false;
        }
        memset(dis, -1, sizeof(dis));
        queue<int> q;
        for (int i = 0; i < routes.size(); i++) {
            sort(routes[i].begin(), routes[i].end());
            for (int j = 0; j < routes[i].size(); j++) {
                int v = routes[i][j];
                if (v == S) {
                    isSource[i] = true;
                    if (dis[i] == -1) {
                        dis[i] = 0;
                        q.push(i);
                    }
                }
                if (v == T)
                    isTarget[i] = true;
            }
        }
        for (int i = 0; i < routes.size(); i++) {
            for (int j = i + 1; j < routes.size(); j++) {
                vector<int> v3;
                vector<int>& v1 = routes[i];
                vector<int>& v2 = routes[j];
                set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
                if (v3.size() > 0) {
                    Edge[i].push_back(j);
                    Edge[j].push_back(i);
                }
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            // cout << now <<endl;
            if (isTarget[now])
                return dis[now] + 1;
            for (int& v : Edge[now]) {
                if (dis[v] == -1) {
                    dis[v] = dis[now] + 1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
};
