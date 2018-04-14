class Solution {
public:
    double calArea(vector<int>& point1, vector<int>& point2, vector<int>& point3)
    {
        int x1 = point1[0], y1 = point1[1];
        int x2 = point2[0], y2 = point2[1];
        int x3 = point3[0], y3 = point3[1];
        int vx1 = x2 - x1, vy1 = y2 - y1;
        int vx2 = x3 - x1, vy2 = y3 - y1;
        double area = 0.5 * abs(vx1 * vy2 - vx2 * vy1);
        return area;
    }
    double largestTriangleArea(vector<vector<int> >& points)
    {
        double ans = -1;
        int size = points.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                for (int k = j + 1; k < size; k++) {
                    double area = calArea(points[i], points[j], points[k]);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
